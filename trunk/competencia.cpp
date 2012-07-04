#include <iostream>
#include "competencia.h"


Competencia::Competencia(){
    _finalizada = false;
    _categoria = pair<Deporte, Sexo>();
    _participantes = Lista<Atleta>();
}


Competencia::Competencia(const Deporte d, const Sexo s, const Lista<Atleta>& participantes){
    _finalizada = false;
    _categoria = pair<Deporte, Sexo>(d,s);
    _participantes = participantes;
}


Categoria Competencia::categoria() const{
    return _categoria;
}


Lista<Atleta> Competencia::participantes() const{
    return _participantes;
}


bool Competencia::finalizada() const{
    return _finalizada;
};


Lista<Atleta> Competencia::ranking() const{
    return findAtletasByCia(_ranking);
}


Lista<Atleta> Competencia::lesTocoControlAntidoping() const{
    int largo = _controlAntidoping.longitud();
    int i = 0;
    Lista<Atleta> atletas = Lista<Atleta> ();
    while(i<largo){
        atletas.agregar(findAtletaByCiaNumber(_controlAntidoping.iesimo(i).first));
        i++;
    }
    return atletas;
}


bool Competencia::leDioPositivo(const Atleta& a) const{
    int i = 0;
    while( _controlAntidoping.iesimo(i).first != a.ciaNumber() )
        i++;

    return _controlAntidoping.iesimo(i).second;
}


void Competencia::finalizar(const Lista<int>& posiciones, const Lista<pair<int, bool> >& control){
    _ranking = posiciones;
    _controlAntidoping = control;
    _finalizada = true;
}


void Competencia::linfordChristie(const int ciaNum){
    Atleta linford = findAtletaByCiaNumber(ciaNum);
    _participantes.sacar(linford);
}


bool Competencia::gananLosMasCapaces() const{
    Deporte d = categoria().first;
    Lista<Atleta> rank = ranking();
    int i = 0;
    bool res;

    while (i<_ranking.longitud()){
        if (rank.longitud()<=1){
            res = true;
            i = _ranking.longitud();
        } else {
            if(rank.iesimo(0).capacidad(d) >= rank.iesimo(1).capacidad(d)){
                rank.sacar(rank.iesimo(0));
            } else {
                res = false;
                i = _ranking.longitud();
            }
        }
    }
    return res;
}


void Competencia::sancionarTramposos(){
    int atletaIndex = 0;
    while( atletaIndex < participantes().longitud() ){
        if( ranking().pertenece(participantes().iesimo(atletaIndex))
           && leDioPositivo(participantes().iesimo(atletaIndex)) ){
            _ranking.sacar( participantes().iesimo(atletaIndex).ciaNumber() );
        }
        atletaIndex++;
    }
}


bool Competencia::operator==(const Competencia& c) const{

    bool result = mismasAtletas(c.participantes() , participantes())
    	&& c.categoria() == categoria() && c.finalizada() == finalizada();

    if(result && finalizada()){
        result = c.ranking() == ranking()
        	&& mismasAtletas(c.lesTocoControlAntidoping(),lesTocoControlAntidoping());
        if(result){
            int i = 0;
            while( i < c.lesTocoControlAntidoping().longitud() && result){
                result = result && c.leDioPositivo(c.lesTocoControlAntidoping().iesimo(i))
                		== leDioPositivo(c.lesTocoControlAntidoping().iesimo(i));
                i++;
            }
        }
    }
    return result;
}


void Competencia::mostrar(std::ostream& os) const{
    if(finalizada()){
        os << endl << "Categoria: (" << categoria().first << " , "
        << (categoria().second == Masculino? "Masculino":"Femenino" ) << " )" << endl
        << "Finalizada: True" << endl << "Participantes: " << participantes()
        << endl <<"Ranking: " << _ranking << " Control Antidoping: ";
        printControl(os);
    } else {
        os << endl << "Categoria: (" << categoria().first << " , "
         << (categoria().second == Masculino? "Masculino":"Femenino") << " )" << endl
        << "Finalizada: False" << endl << "Participantes: " << participantes();
    }
}


void Competencia::guardar(std::ostream& os) const{
    os << (char) ENCABEZADO_ARCHIVO << " (|" << categoria().first << "|, |"
    << ((categoria().second == Masculino)? "Masculino" : "Femenino") << "|) |"
    << ( finalizada()? "True" : "False") << "| ";

    os << "[" ;

    int i;
    if( participantes().longitud() != 0 ){
        i=0;
        while(i<participantes().longitud()){
            os << "(";

            participantes().iesimo(i).guardar(os);
            i++;

            if(i == participantes().longitud()){
                os << ")] ";
            }else{
                os << "), ";
            }
        }

    }else{
        os << "]";
    }

    if( finalizada() ){
        os << "[" ;
        i=0;
        while( i< _ranking.longitud()){
            os << _ranking.iesimo(i);
            i++;

            if(i != _ranking.longitud()){
                os << ", ";
            }
        }
        os << "] ";

        os << "[" ;
        i=0;
        while( i<_controlAntidoping.longitud()){

            os << "(" << _controlAntidoping.iesimo(i).first << ", "
            << ((_controlAntidoping.iesimo(i).second )? "|True|" : "|False|") << ")";

            i++;

            if(i != _controlAntidoping.longitud()){
                os << ", ";
            }

        }
        os << "] ";

    }else {
        os << "[] []";
    }
}


void Competencia::cargar (std::istream& is){

    char dummy;
    string temp;

    //descarto hasta el primer "|"
    getline(is , temp , '|');

    //leo el nombre hasta el ultimo "|" descartandolo
    getline(is , _categoria.first , '|');

    //leo hata el primer "|" que rodea el sexo descartando
    getline(is , temp , '|');

    //leo el sexo hasta el ultimo "|"
    getline(is , temp , '|');
    _categoria.second = (temp == "Masculino"? Masculino : Femenino);

    //descarto hasta el primer "|" del estado
    getline(is , temp , '|');

    //descarto hasta el primer "|" del estado
    getline(is , temp , '|');
    _finalizada = (temp == "True"? true : false);

    //leo el "[" que indica el comienzo de la lista
    getline(is , temp , '[');

    Atleta atleta;

    // si tiene atletas los cargamos
    if( is.peek() != ']' ){

        //busco el "("
        is >> dummy;

        while( dummy != ']'){

            atleta = Atleta();
            atleta.cargar(is);
            _participantes.agregarAtras(atleta);

            //busco el ")"
            is >> dummy;

            //busco el "," o el "]"
            is >> dummy;

            if(dummy == ','){
                //busco el "(" que viene
                is >> dummy;
            }
        }
    }else{
        getline(is , temp, ']');
    }


    //leo hasta el "[" que indica el comienzo de la lista de ranking y lo descarto
    getline(is , temp , '[');

    if( is.peek() != ']' ){

        //inicializamos el dummy con basura
        dummy = is.peek();
        int ciaNumber;
        Lista<int> cias = Lista<int>();

        while(dummy != ']'){
            is >> ciaNumber;
            cias.agregarAtras(ciaNumber);

            //leemos el ","
            is >> dummy;
        }

        _ranking = cias;
    }else{
        getline(is , temp, ']');
    }
    //leo hasta el "[" que indica el comienzo de la lista de ranking y lo descarto
    getline(is , temp , '[');

    if( is.peek() != ']' ){
        //inicializamos el dummy con basura
        dummy = is.peek();
        int ciaNumber;
        Lista<pair<int,bool> > control = Lista<pair<int,bool> >();

        while(dummy != ']'){
            //buscamos el "("
            is >> dummy;
            //buscamos el cia
            is >> ciaNumber;
            //buscamos la ","
            is >> dummy;
            //buscamos la "|"
            is >> dummy;
            getline(is , temp , '|');
            control.agregarAtras(pair<int,bool>(ciaNumber , (temp == "True" ? true : false)));

            //leemos el ")"
            is >> dummy;
            //leemos el "," o "]"
            is >> dummy;
        }
        _controlAntidoping = control;
    }else{
        getline(is , temp, ']');
    }
}


std::ostream & operator<<(std::ostream & os,const Competencia & c){
    c.mostrar(os);
    return os;
}


void Competencia::printControl(std::ostream& os) const {
    int i=0;
    os << "[";
    while(i<_controlAntidoping.longitud()){
        os << "("<< _controlAntidoping.iesimo(i).first
        << ", |" << (_controlAntidoping.iesimo(i).second?"True":"False") << "|)";
        i++;

        if(i != _controlAntidoping.longitud())
            os << ", ";
    }
    os << "]";
}


bool Competencia::mismasAtletas(Lista<Atleta> l1, Lista<Atleta> l2) const {
    bool iguales = (l1.longitud() == l2.longitud()) ;
    int i=0;
    while(i < l1.longitud() && iguales ){
        if( !l2.pertenece( l1.iesimo(i) ) || !l1.pertenece( l2.iesimo(i) ) )
            iguales = false;
        i++;
    }
    return iguales;
}


Atleta Competencia::findAtletaByCiaNumber(int ciaNumber) const {
    Atleta atleta;
    int atletaIndex = 0;
    bool encontrado = false;
    while(atletaIndex < participantes().longitud() && !encontrado ){
        if( participantes().iesimo(atletaIndex).ciaNumber() == ciaNumber  ){
            atleta = participantes().iesimo(atletaIndex);
            encontrado = true;
        }
        atletaIndex++;
    }
    return atleta;
}


Lista<Atleta> Competencia::findAtletasByCia(Lista<int> cias) const {
    int i = 0;
    Lista<Atleta> atletas = Lista<Atleta>();
    while( i < cias.longitud()){
        atletas.agregarAtras(findAtletaByCiaNumber(cias.iesimo(i)));
        i++;
    }
    return atletas;
}


void Competencia::clasificoTarde(const Atleta& a){
    _participantes.agregarAtras(a);
}
