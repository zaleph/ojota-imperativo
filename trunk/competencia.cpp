

#include <iostream>

#include "competencia.h"

Competencia::Competencia(){
}

Competencia::Competencia(const Deporte d, const Sexo s, const Lista<Atleta>& participantes){
}

Categoria Competencia::categoria() const{
    return pair<Deporte,Sexo>();
}

Lista<Atleta> Competencia::participantes() const{
    return Lista<Atleta>();
}

bool Competencia::finalizada() const{
    return true;
}

Lista<Atleta> Competencia::ranking() const{
    return Lista<Atleta>();
}

Lista<Atleta> Competencia::lesTocoControlAntidoping() const{
    return Lista<Atleta>();
}

bool Competencia::leDioPositivo(const Atleta& a) const{
    return true;
}

void Competencia::finalizar(const Lista<int>& posiciones, const Lista<pair<int, bool> >& control){
}

void Competencia::linfordChristie(const int ciaNum){
}

bool Competencia::gananLosMasCapaces() const{
    return true;
}

void Competencia::sancionarTramposos(){
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
