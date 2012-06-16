#include <iostream>
#include "competencia.h"


Competencia::Competencia(){
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
}


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

    bool result = mismasAtletas(c.participantes() , participantes()) && c.categoria() == categoria() && c.finalizada() == finalizada();

    if(result && finalizada()){
        result = c.ranking() == ranking() && mismasAtletas(c.lesTocoControlAntidoping(),lesTocoControlAntidoping());
        if(result){
            int i = 0;
            while( i < c.lesTocoControlAntidoping().longitud() && result){
                result = result && c.leDioPositivo(c.lesTocoControlAntidoping().iesimo(i))==leDioPositivo(c.lesTocoControlAntidoping().iesimo(i));
                i++;
            }
        }
    }
    return result;
}


void Competencia::mostrar(std::ostream& os) const{
    if(finalizada()){
        os << endl << "Categoria: (" << categoria().first << " , " << categoria().second << " )" << endl
        << "Participantes: " << participantes()
        << endl <<"Ranking: " << ranking() ;
    } else {
        os << endl << "Categoria: (" << categoria().first << " , " << categoria().second << " )" << endl
        << "Participantes: " << participantes() ;
    }
}


void Competencia::guardar(std::ostream& os) const{
}


void Competencia::cargar (std::istream& is){
}


std::ostream & operator<<(std::ostream & os,const Competencia & c){
    c.mostrar(os);
    return os;
}

