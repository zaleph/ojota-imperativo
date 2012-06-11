#include <stdlib.h>

#include "test-atletas.h"
#include "competencia.h"


 /*
  * Mocks
  */

Lista<pair<int , bool> > mockControlAntidoping(){
    Lista<pair<int , bool> > lista = Lista< pair<int , bool> >();
    lista.agregar(pair<int,bool>(1,true));
    lista.agregar(pair<int,bool>(2,false));
    lista.agregar(pair<int,bool>(3,true));
    lista.agregar(pair<int,bool>(4,false));
    return lista;
}

Lista<int> mockPosiciones(){
    Lista<int> lista = Lista<int>();
    lista.agregar(2); //cuarto
    lista.agregar(4); //tercero
    lista.agregar(1); //segundo
    lista.agregar(3); //primero
    return lista;
}

Competencia mockCompetencia(){
    return Competencia("tenis", Masculino, mockAtletas());
}

Competencia mockCompetencia(Deporte d){
    return Competencia(d, Masculino, mockAtletas());
}


Lista<Competencia> mockCompetencias(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregar(mockCompetencia());
    comps.agregar(mockCompetencia());
    comps.agregar(mockCompetencia());
    comps.agregar(mockCompetencia());
    return comps;
}

Lista<Competencia> mockCompetencias(Deporte d){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregar(mockCompetencia(d));
    comps.agregar(mockCompetencia(d));
    comps.agregar(mockCompetencia(d));
    comps.agregar(mockCompetencia(d));
    return comps;
}




/*
 * Tests
 */

void testCompetencia_finalizada_y_finalizar(){
    Competencia comp = mockCompetencia();

    cout << "Finalizada: " << comp.finalizada() << endl;

    comp.finalizar(mockPosiciones() , mockControlAntidoping());

    cout << "Finalizada: " << comp.finalizada() << endl;

}

void testCompetencia_leDioPositivo(){
    Competencia comp = mockCompetencia();
    comp.finalizar(mockPosiciones() , mockControlAntidoping());

    cout << "Le tiene que dar positivo: " << comp.leDioPositivo(newAtleta(1)) << endl;
    cout << "No le tiene que haber dado positivo: " << comp.leDioPositivo(newAtleta(2)) << endl;

}


void testCompetencia_participantes(){
    Competencia comp = mockCompetencia();
    cout << "participantes: " << comp.participantes() << endl;
}

void testCompetencia_sancionarTramposos(){

    Competencia comp = mockCompetencia();
    comp.finalizar(mockPosiciones() , mockControlAntidoping());
    cout << "Se finaliza la competencia y el ranking quedo: " << comp.ranking() << endl;
    comp.sancionarTramposos();
    cout << "pero se encontraron tramposos, asi que el ranking luego de la sancion es: " << comp.ranking() << endl;
}

void testCompetencia_ranking(){
    Competencia comp = mockCompetencia();
    comp.finalizar(mockPosiciones() , mockControlAntidoping());
    cout << "ranking posta: " << endl;
    cout << "ranking de participantes: " << comp.ranking() << endl;
}

void testCompetencia_lesTocoControlAntidoping(){
    Competencia comp = mockCompetencia();
    comp.finalizar(mockPosiciones() , mockControlAntidoping());
    cout <<"controles: " << comp.lesTocoControlAntidoping() <<endl;
 }


void testCompetencia_gananLosMasCapaces(){
    Competencia comp = mockCompetencia();
    comp.finalizar(mockPosiciones() , mockControlAntidoping());
    cout << "ganan los mas capaces: " << endl;
}
