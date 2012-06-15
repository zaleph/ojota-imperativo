#include <iostream>
#include "atleta.h"


Atleta::Atleta(){
}


Atleta::Atleta(const string nombre,const Sexo sexo, const int anio, const Pais pais, const int ciaNumber){
    _nombre = nombre;
    _sexo = sexo;
    _anioNacimiento = anio;
    _nacionalidad = pais;
    _ciaNumber = ciaNumber;
    _deportes = Lista<pair<Deporte , int> >();
}


string Atleta::nombre() const{
    return _nombre;
}


Sexo Atleta::sexo() const{
    return _sexo;
}


int Atleta::anioNacimiento() const{
    return _anioNacimiento;
}


Pais Atleta::nacionalidad() const{
    return _nacionalidad;
}


int Atleta::ciaNumber() const{
    return _ciaNumber;
}


Lista<Deporte> Atleta::deportes() const{
    Lista<Deporte> deportesList = Lista<Deporte>();
    //Lista<Deporte> deportesList;
    int i = 0;
    while(i<_deportes.longitud() ){
        deportesList.agregarAtras(_deportes.iesimo(i).first);
        i++;
    }
    return deportesList;
}


int Atleta::capacidad(const Deporte d) const{
    int i = 0;
    while ( d != _deportes.iesimo(i).first) {
        i++;
    }
    return _deportes.iesimo(i).second;
}


void Atleta::entrenarNuevoDeporte(const Deporte deporte, const int capacidad){

    pair<Deporte,int> par = pair<Deporte,int>(deporte,capacidad);
    Lista<pair<Deporte, int> > nuevaLista = Lista<pair<Deporte , int > > ();

    if(_deportes.longitud()==0){
        _deportes.agregar(par);
    } else{
        if(!deportes().pertenece(deporte)){
            //string d1 = _deportes.cabeza().first;
            //string d2 = deporte;
            //while (_deportes.longitud() != 0 && d1<d2){
            while (_deportes.longitud() != 0 && _deportes.cabeza().first<deporte){
                nuevaLista.agregarAtras(_deportes.cabeza());
                _deportes.eliminarPosicion(0);
               // if (_deportes.longitud() != 0){
               //     d1 = _deportes.cabeza().first;
               // }
            }
            nuevaLista.agregarAtras(par);
            nuevaLista.concatenar(_deportes);
            _deportes = nuevaLista;
        } else {
            while (_deportes.longitud()!= 0 && _deportes.cabeza().first!=deporte){
                nuevaLista.agregarAtras(_deportes.cabeza());
                _deportes.eliminarPosicion(0);
            }
            _deportes.eliminarPosicion(0);
            nuevaLista.agregarAtras(par);
            nuevaLista.concatenar(_deportes);
            _deportes = nuevaLista;
        }
    }
}


bool Atleta::operator==(const Atleta& a) const{
    return (nombre() == a.nombre() && sexo() == a.sexo() && anioNacimiento() == a.anioNacimiento()
        && nacionalidad() == a.nacionalidad() && ciaNumber() == a.ciaNumber() && _deportes == a._deportes);
}


void Atleta::mostrar(std::ostream& os) const{
}


void Atleta::guardar(std::ostream& o) const{
    o << "A |" << nombre() << "| |" << ( sexo() ? "Masculino" : "Femenino")  << "| "
    << anioNacimiento() << " |" << nacionalidad() << "| " << ciaNumber() <<  " " << "[ ";

    /*
     * Se imprimen los deportes de los atletas
     */
     int i=0; while(i<deportes().longitud() ){
        Deporte d = deportes().iesimo(i);
        int c = capacidad(d);
        o << "( |" <<  d << "| , " << c << ")" ;
        i++;
        if(i != deportes().longitud()){
            o << " , ";
        }
    }
    o << " ]" << endl;
}


void Atleta::cargar (std::istream& is){

    char dummy;
    string temp;

    //descarto hasta el primer "|"
    getline(is , temp , '|');

    //leo el nombre hasta el ultimo "|" descartandolo
    getline(is , _nombre , '|');

    //leo hata el primer "|" que rodea el sexo descartando
    getline(is , temp , '|');

    //leo el sexo hasta el ultimo "|"
    getline(is , temp , '|');
    _sexo = temp.compare("Masculino") ? Masculino : Femenino ;

    //leo el año de nacimiento
    is >> _anioNacimiento;

    //leo y descarto hasta el primer "|" de la nacionalidad
    getline(is , temp , '|');

    //leo la nacionalidad hasta el ultimo "|" que la rodea
    getline(is , _nacionalidad , '|');

    // leo el cia number
    is >> _ciaNumber;

    //leo el "[" que indica el comienzo de la lista
    getline(is , temp , '[');

    Deporte deporte;
    int capacidad;

    while( dummy != ']'){

        // leo hasta el "(" descarandolo
        getline(is , temp , '(');

        //descarto el "|"
        is >> dummy;

        // leo el deporte
        getline(is , deporte , '|');

        // descarto la ","
        is >> dummy;

        //leo la capacidad
        is >> capacidad;

        //descarto el ultimo ")"
        is >> dummy;

        //leo el siguiente token "," o "]"
        is >> dummy;

        entrenarNuevoDeporte(deporte, capacidad);
    }

}


std::ostream & operator<<(std::ostream & os,const Atleta & a){
    os << "Nombre: " << a.nombre() << endl
    << "Sexo: " << a.sexo() << endl
    << "CiaNumber: " << a.ciaNumber() << endl
    << "Nacionalidad: " << a.nacionalidad() << endl
    << "Año Nacimiento: " << a.anioNacimiento() << endl
    << "Deportes: " << a.deportes();
    return os;
}

