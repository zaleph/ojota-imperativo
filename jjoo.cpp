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
    int indexDia = dia-1;
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
    Lista<Competencia> comps = Lista<Competencia>();
    Lista<Competencia> compsConOro = Lista<Competencia>();

    comps = competencias();

    int i=0;
    while (i<comps.longitud()){
        Competencia comp = comps.iesimo(i);
        if(!comp.finalizada()){
            i++;
        }else if(comp.ranking().longitud()>0){
            compsConOro.agregarAtras(comp);
            i++;
        }else{
            i++;
        }
    }
    return compsConOro;
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
 /*   Lista<Competencia> comps = finalizadasYConRanking(competencias());
    Lista<Atleta> atletas = ganadoresDeCompetencias(comps, 0);
    int i = 0;
    Deporte d1 = comps.iesimo(0).categoria().first;
    Deporte d2 = comps.iesimo(1).categoria().first;
    while (i<_competenciasPorDia.longitud()){
        if (atletas.longitud()<=1){
            i = comps.longitud();
        } else{
            if (atletas.iesimo(0).capacidad(d1)<=atletas.iesimo(i).capacidad(d2)){
        atletas.sacar(atletas.iesimo(1));
        comps.sacar(comps.iesimo(1));
         }  else {
            atletas.sacar(atletas.iesimo(0));
            comps.sacar(comps.iesimo(0));
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
    Lista<Pais> secosOlimpicos = Lista<Pais>();
    Lista<Pais> paisesDelJuego = paisesUnicosDeAtletas(atletas());

    int maxSequiaJuegos = maxDiasSinMedalla();

    int i = 0;

    while (i<paisesDelJuego.longitud()){
        Pais p = paisesDelJuego.iesimo(i);
        Lista<int> diasBuenos = diasConMedalla(p , _competenciasPorDia , jornadaActual());
        int maxSequiaDelPais = maximoEnteros(diferenciaEntreConsecutivos(diasBuenos));

        if(maxSequiaDelPais == maxSequiaJuegos){
            secosOlimpicos.agregarAtras(p);
            i++;
        } else {
            i++;
        }
    }
    return secosOlimpicos;
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



