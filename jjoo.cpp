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
    int indexDia = _competenciasPorDia.longitud() - dia;
    return _competenciasPorDia.iesimo(indexDia);
}


Lista<Competencia> JJOO::competencias() const{
    Lista<Competencia> comps = Lista<Competencia>();
    int i = 0;
    while( i< _competenciasPorDia.longitud() ){
        comps.concatenar(_competenciasPorDia.iesimo(i));
        i++;
    }
    return comps;
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
 /*   Lista<Competencia> comps = competencias();
    Lista<Atleta> atletas = ganadoresDeCompetencias(comps);
    int i = 0;
    Deporte d = comps.iesimo(i).categoria().first;
    while (i<_competenciasPorDia.longitud()){
        if (atletas.longitud()<=1){
            i = comps.longitud();
        } else{
            if (atletas.iesimo(i).capacidad(d)<=atletas.iesimo(i+1).capacidad(d)){
        atletas.sacar(atletas.iesimo(i+1));
         }  else {
            atletas.sacar(atletas.iesimo(i));
            }
        }
    }
    return atletas.iesimo(0);*/
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

    bool result = j.anio() == anio() && j.cantDias() == cantDias() && j.jornadaActual() == jornadaActual()
        && mismasAtletas(j.atletas() , atletas()) ;

    if(result){
        int i=1;
        while( i <= cantDias() && result ){
            result = result & mismasCompetencias(j.cronograma(i) , cronograma(i));
            i++;
        }
    }

    return result;
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


Lista<Atleta> JJOO::ganadoresDeCompetencias(Lista<Competencia> comps){
            Lista<Atleta> atletas = Lista<Atleta>();
            int i = 0;
            while(i<comps.longitud()){
                atletas.agregarAtras((comps.iesimo(i)).ranking().iesimo(0));
                i++;
                }
            return atletas;

            }
