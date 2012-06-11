
#include "test-competencias.h"
#include "jjoo.h"

/*
 * Mocks
 */


 Lista<Lista<Competencia> > mockCronogramas(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregar(mockCompetencias("tenis"));
    crons.agregar(mockCompetencias("jockey"));
    crons.agregar(mockCompetencias("basquet"));
    crons.agregar(mockCompetencias("futbol"));
    return crons;
 }



 JJOO mockJJOO(){
    return JJOO(2012 , mockAtletas() , mockCronogramas());
 }



/*
 * Tests
 */


void testJJOO_nuevoJJOO(){
    JJOO jjoo = mockJJOO();
    cout << jjoo << endl;
}


void testJJOO_competencias(){
    JJOO jjoo = mockJJOO();
    cout << "Cantidad de competencias: " << jjoo.competencias().longitud() << endl;
}


void testJJOO_cronogramas(){
    JJOO jjoo = mockJJOO();
    cout << "Competencias del dia 1: " << jjoo.cronograma(4) << endl;
}
