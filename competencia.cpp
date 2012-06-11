

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

    Lista<Atleta> rankingDeAtletas = Lista<Atleta>();

    int atletaIndex = 0;

    while(atletaIndex < _ranking.longitud() ){
        rankingDeAtletas.agregar( findParticipanteByCiaNumber( _ranking.iesimo(atletaIndex) ) );

        atletaIndex ++;
    }

    return rankingDeAtletas;
}

Lista<Atleta> Competencia::lesTocoControlAntidoping() const{
    return Lista<Atleta>();
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
}

bool Competencia::gananLosMasCapaces() const{
    return true;
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
    return true;
}

void Competencia::mostrar(std::ostream& os) const{
}

void Competencia::guardar(std::ostream& os) const{
}

void Competencia::cargar (std::istream& is){
}

/*
std::ostream & operator<<(std::ostream & os,const Competencia & c){

    if(c.finalizada()){
        os << "Categoria: " << c.categoria() << endl
        << "Participantes: " << c.participantes()
        << endl <<"Ranking: " << c.ranking() ;
    } else {
        os << "Categoria: " << c.categoria() << endl
        << "Participantes: " << c.participantes() ;
    }

    return os;
}
*/


Atleta Competencia::findParticipanteByCiaNumber(int ciaNumber) const {

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
