
#include "test-competencias.h"
#include "jjoo.h"

/*
 * Mocks
 */


 Lista<Lista<Competencia> > mockCronogramas(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregar(mockCompetencias());
    crons.agregar(mockCompetencias());
    crons.agregar(mockCompetencias());
    crons.agregar(mockCompetencias());
    return crons;
 }

 JJOO mockJJOO(){
    return JJOO(2012 , mockAtletas() , mockCronogramas());
 }



/*
 * Tests
 */

void testJJOO_matiSeLaLastra(){

}

void testJJOO_nuevoJJOO(){

}


