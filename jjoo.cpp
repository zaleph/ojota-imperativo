
#include <iostream>

#include "jjoo.h"

JJOO::JJOO(){
}

JJOO::JJOO(const int anio, const Lista<Atleta>& atletas, const Lista<Lista<Competencia> >& competenciasPorDia){
    _anio = anio;
    _atletas = atletas;
    _competenciasPorDia = competenciasPorDia;
    _jornadaActual = 1;
}

int JJOO::anio() const{
    return _anio;
}

Lista<Atleta> JJOO::atletas() const{
    return _atletas;
}

int JJOO::cantDias() const{
    return _competenciasPorDia.longitud();
}

int JJOO::jornadaActual() const{
    return _jornadaActual;
}

Lista<Competencia> JJOO::cronograma(const int dia) const{
    return Lista<Competencia>();
}

Lista<Competencia> JJOO::competencias() const{
    return Lista<Competencia>();
}

Lista<Competencia> JJOO::competenciasFinalizadasConOroEnPodio() const{
    return Lista<Competencia>();
}

Lista<Atleta> JJOO::dePaseo() const{
    return Lista<Atleta>();
}

Lista<pair<Pais,Lista<int> > > JJOO::medallero() const{
    return Lista<pair<Pais,Lista<int> > >();
}

int JJOO::boicotPorDisciplina(const Categoria cat, const Pais p){
    return 0;
}

Lista<Atleta> JJOO::losMasFracasados(const Pais p) const{
    return Lista<Atleta>();
}

void JJOO::liuSong(const Atleta& a, const Pais p){

}

Atleta JJOO::stevenBradbury() const{
    return Atleta();
}

bool JJOO::uyOrdenadoAsiHayUnPatron() const{
    return false;
}

Lista<Pais> JJOO::sequiaOlimpica() const{
    return Lista<Pais>();
}

void JJOO::transcurrirDia(){

}

bool JJOO::operator==(const JJOO& j) const{
    return false;
}

void JJOO::mostrar(std::ostream& os) const {

}

void JJOO::guardar(std::ostream& os) const {

}

void JJOO::cargar (std::istream& is) {

}

std::ostream & operator<<(std::ostream & os,const JJOO & j){

    os << "Año: " << j.anio() << endl
    << "Atletas: " << j.atletas() << endl
    << "Cantidad de días: " << j.cantDias() << endl
    << "Jornada actual: " << j.jornadaActual();

    return os;
}

