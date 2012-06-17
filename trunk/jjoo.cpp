#include <iostream>
#include "jjoo.h"


JJOO::JJOO(){
};


JJOO::JJOO(const int anio, const Lista<Atleta>& atletas, const Lista<Lista<Competencia> >& competenciasPorDia){
    _anio = anio;
    _atletas = atletas;
    _competenciasPorDia = competenciasPorDia;
    _jornadaActual = 1;
};


int JJOO::anio() const{
    return _anio;
};


Lista<Atleta> JJOO::atletas() const{
    return _atletas;
};


int JJOO::cantDias() const{
    return _competenciasPorDia.longitud();
};


int JJOO::jornadaActual() const{
    return _jornadaActual;
};


Lista<Competencia> JJOO::cronograma(const int dia) const{
    int indexDia = dia-1;
    return _competenciasPorDia.iesimo(indexDia);
};


Lista<Competencia> JJOO::competencias() const{
    Lista<Competencia> comps = Lista<Competencia>();
    int i = 0;
    while( i< _competenciasPorDia.longitud() ){
        comps.concatenar(_competenciasPorDia.iesimo(i));
        i++;
    }
    return comps;
};


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
};


Lista<Atleta> JJOO::dePaseo() const{
    Lista<Atleta> paseadores = Lista<Atleta>();
    int i = 0;
    while (i<atletas().longitud()){
        Atleta at = atletas().iesimo(i);
        if (!atletasParticipantes().pertenece(at)){
            paseadores.agregarAtras(at);
        }
        i++;
    }
    return paseadores;
};


Lista<pair<Pais,Lista<int> > > JJOO::medallero() const{
    Lista<pair<Pais,Lista<int> > > medallasDePaises = Lista<pair<Pais,Lista<int> > >();
    Lista<Pais> paisesGanadores = Lista<Pais>();

    Lista<Atleta> orosDelJuego = medallistas(0);
    Lista<Atleta> platasDelJuego = medallistas(1);
    Lista<Atleta> broncesDelJuego = medallistas(2);

    Lista<Atleta> atletasGanadores = orosDelJuego;
    atletasGanadores.concatenar(platasDelJuego);
    atletasGanadores.concatenar(broncesDelJuego);

    paisesGanadores = paisesUnicosDeAtletas(atletasGanadores);

    int i=0;

    while (i<paisesGanadores.longitud()){
        Pais p = paisesGanadores.iesimo(i);
        int oros = filtrarAtletasPorPais(orosDelJuego,p).longitud();
        int platas = filtrarAtletasPorPais(platasDelJuego,p).longitud();
        int bronces = filtrarAtletasPorPais(broncesDelJuego,p).longitud();

        Lista<int> medalleroDelPais = Lista<int>();
        medalleroDelPais.agregarAtras(oros);
        medalleroDelPais.agregarAtras(platas);
        medalleroDelPais.agregarAtras(bronces);

        pair<Pais,Lista<int> > medallasDelPais = pair<Pais,Lista<int> >(p,medalleroDelPais);

        medallasDePaises = agregarOrdenado(medallasDePaises,medallasDelPais);
        i++;
    }
    return medallasDePaises;
};


int JJOO::boicotPorDisciplina(const Categoria cat, const Pais p){
    return 0;
};


Lista<Atleta> JJOO::losMasFracasados(const Pais p) const{
    return Lista<Atleta>();
};


void JJOO::liuSong(const Atleta& a, const Pais p){

};


Atleta JJOO::stevenBradbury() const{
   /* Lista<Competencia> compets = competencias();
    Lista<Competencia> comps = finalizadasYConRanking(compets);
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
};

bool JJOO::uyOrdenadoAsiHayUnPatron() const{
    return false;
};


Lista<Pais> JJOO::sequiaOlimpica() const{
    Lista<Pais> secosOlimpicos = Lista<Pais>();
    Lista<Pais> paisesDelJuego = paisesUnicosDeAtletas(atletas());

    int maxSequiaJuegos = maxDiasSinMedalla();

    int i = 0;

    while (i<paisesDelJuego.longitud()){
        Pais p = paisesDelJuego.iesimo(i);
        Lista<int> diasBuenos = diasConMedalla(p);
        int maxSequiaDelPais = maximoEnteros(diferenciaEntreConsecutivos(diasBuenos));

        if(maxSequiaDelPais == maxSequiaJuegos){
            secosOlimpicos.agregarAtras(p);
            i++;
        } else {
            i++;
        }
    }
    return secosOlimpicos;
};


void JJOO::transcurrirDia(){
    Lista<Competencia> comps = cronograma(jornadaActual());
    bool eval = true;
    int i = 0;
    while (i<comps.longitud() && eval){
        Competencia comp = comps.iesimo(i);
        Categoria cat =comp.categoria();
        Deporte d = cat.first;
        if (comp.finalizada() && mismasAtletas(comp.ranking(),comp.participantes())){
            Lista <Atleta> posiciones = comp.ranking();
            posiciones.darVuelta();
            if (ordenado(capacidades(posiciones,d))){
                if (comp.ranking().longitud()>=1){
                    eval = comp.lesTocoControlAntidoping().longitud()==1;
                } else {
                    eval = true;
                }
            } else {
                eval = false;
            }
        } else {
            eval = false;
        }
        i++;
    }

    if (eval) {
        _jornadaActual = _jornadaActual+1;
    }
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
};


void JJOO::mostrar(std::ostream& os) const {
    os << "Año: " << anio() << endl
    << "Atletas: " << atletas() << endl
    << "Cantidad de días: " << cantDias() << endl
    << "Jornada actual: " << jornadaActual();
};


void JJOO::guardar(std::ostream& os) const {
    os << (char) ENCABEZADO_ARCHIVO << " " << anio() << " " << jornadaActual() << " ";
    os << "[";

    int i=0; while(i < competencias().longitud()){
        Competencia c = competencias().iesimo(i);
        os << "(";
        c.guardar(os);
        os << ")";
        i++;

        if( i != competencias().longitud())
            os << ", ";
    }
    os << "]";
};


void JJOO::cargar (std::istream& is) {

};


std::ostream & operator<<(std::ostream & os,const JJOO & j){
    j.mostrar(os);
    return os;
};
