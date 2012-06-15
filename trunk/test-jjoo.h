
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


 Lista<Lista<Competencia> > mockCronogramas2(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregar(mockCompetencias("tenis"));
    crons.agregar(mockCompetencias("jockey"));
    crons.agregar(mockCompetencias("basquet"));
    crons.agregar(mockCompetencias("futbol"));
    crons.agregar(mockCompetencias("rugby"));
    return crons;
 }


    Lista<Lista<Competencia> > mockCronogramas23(){
        Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
        //dia 5
        crons.agregar(mockCompetencias("tenis"));
        //dia 4
        crons.agregar(mockCompetencias("jockey"));
        //dia 3
        crons.agregar(mockCompetencias("basquet"));
        //dia2
        crons.agregar(mockCompetencias("futbol"));

        Lista<Competencia> comps = Lista<Competencia> ();
        //dia 1
        comps.agregar(mockCompetencia("rugby"));
        comps.agregar(mockCompetencia("rugby"));
        comps.agregar(mockCompetencia("rugby"));
        comps.agregar(mockCompetencia("rugby"));
        comps.agregar(mockCompetencia("rugby"));

        crons.agregar(comps);

        return crons;
    }


 JJOO mockJJOO(){
    return JJOO(2012 , mockAtletas() , mockCronogramas23());
 }

JJOO mockJJOO2(){
    return JJOO(2012 , mockAtletas() , mockCronogramas2());
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
    cout << "Competencias del dia 1: " << jjoo.cronograma(1) << endl;
}

void testJJOO_operadorIgual(){
    JJOO jjoo1 = mockJJOO();
    JJOO jjoo2 = mockJJOO2();

    cout << "Son iguales? " << ( jjoo1 == jjoo2) << endl;

}
