
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


Lista<Lista<Competencia> > mockCronograDia0(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregarAtras(mockCompetenciasDia1NoFinal());//dia 1;
    crons.agregarAtras(mockCompetenciasDia2NoFinal());//dia 2;
    crons.agregarAtras(mockCompetenciasDia3NoFinal());//dia 3;
    crons.agregarAtras(mockCompetenciasDia4Vacio());//dia 4;
    crons.agregarAtras(mockCompetenciasDia5NoFinal());//dia 5;
    crons.agregarAtras(mockCompetenciasDia6Vacio());//dia 6;
    return crons;
}

Lista<Lista<Competencia> > mockCronograDia1(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregarAtras(mockCompetenciasDia1Final());//dia 1;
    crons.agregarAtras(mockCompetenciasDia2NoFinal());//dia 2;
    crons.agregarAtras(mockCompetenciasDia3NoFinal());//dia 3;
    crons.agregarAtras(mockCompetenciasDia4Vacio());//dia 4;
    crons.agregarAtras(mockCompetenciasDia5NoFinal());//dia 5;
    crons.agregarAtras(mockCompetenciasDia6Vacio());//dia 6;
    return crons;
}

Lista<Lista<Competencia> > mockCronograDia2(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregarAtras(mockCompetenciasDia1Final());//dia 1;
    crons.agregarAtras(mockCompetenciasDia2Final());//dia 2;
    crons.agregarAtras(mockCompetenciasDia3NoFinal());//dia 3;
    crons.agregarAtras(mockCompetenciasDia4Vacio());//dia 4;
    crons.agregarAtras(mockCompetenciasDia5NoFinal());//dia 5;
    crons.agregarAtras(mockCompetenciasDia6Vacio());//dia 6;
    return crons;
}

Lista<Lista<Competencia> > mockCronograDia3(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregarAtras(mockCompetenciasDia1Final());//dia 1;
    crons.agregarAtras(mockCompetenciasDia2Final());//dia 2;
    crons.agregarAtras(mockCompetenciasDia3Final());//dia 3;
    crons.agregarAtras(mockCompetenciasDia4Vacio());//dia 4;
    crons.agregarAtras(mockCompetenciasDia5NoFinal());//dia 5;
    crons.agregarAtras(mockCompetenciasDia6Vacio());//dia 6;
    return crons;
}

Lista<Lista<Competencia> > mockCronograDia5(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregarAtras(mockCompetenciasDia1Final());//dia 1;
    crons.agregarAtras(mockCompetenciasDia2Final());//dia 2;
    crons.agregarAtras(mockCompetenciasDia3Final());//dia 3;
    crons.agregarAtras(mockCompetenciasDia4Vacio());//dia 4;
    crons.agregarAtras(mockCompetenciasDia5Final());//dia 5;
    crons.agregarAtras(mockCompetenciasDia6Vacio());//dia 6;
    return crons;
}

Lista<Lista<Competencia> > mockCronograDiaERRONEODIA2(){
    Lista<Lista<Competencia> > crons =  Lista<Lista<Competencia> > ();
    crons.agregarAtras(mockCompetenciasDia1Final());//dia 1;
    crons.agregarAtras(mockCompetenciasDia2NoFinal());//dia 2;
    crons.agregarAtras(mockCompetenciasDia3Final());//dia 3;
    crons.agregarAtras(mockCompetenciasDia4Vacio());//dia 4;
    crons.agregarAtras(mockCompetenciasDia5Final());//dia 5;
    crons.agregarAtras(mockCompetenciasDia6Vacio());//dia 6;
    return crons;
}

//JUEGO CON NIGUNA COMPETENCIA FINALIZADA
JJOO mockJJOODia0(){
    JJOO jjoo =JJOO(2012 , mockAtletasFull() , mockCronograDia0() );
    jjoo._jornadaActual = 1;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 1 FINALIZADAS
JJOO mockJJOODia1(){
    JJOO jjoo =JJOO(2012 , mockAtletasFull() , mockCronograDia1() );
    jjoo._jornadaActual = 2;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 2 FINALIZADAS
JJOO mockJJOODia2(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia2() );
    jjoo._jornadaActual = 3;
    return jjoo;
}
//JUEGO CON LAS COMPETENCIAS DEL DIA 3 FINALIZADAS
JJOO mockJJOODia3(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia3() );
    jjoo._jornadaActual = 4;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 4 que en realidad esta vacio
JJOO mockJJOODia4(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia3() );
    jjoo._jornadaActual = 5;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 5 FINALIZADAS
JJOO mockJJOODia5(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia5() );
    jjoo._jornadaActual = 6;
    return jjoo;
}

//JUEGO ERRONEO CON COMPETENCIAS SIN FINALIZAR EN EL DIA 2
JJOO mockJJOODiaERRONEODIA2(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDiaERRONEODIA2() );
    jjoo._jornadaActual = 6;
    return jjoo;
}


/*
 * Tests
 */


void testJJOO_nuevoJJOO(){
    JJOO jjoo = mockJJOO();
    cout << jjoo << endl;
}

void testJJOO_JJOO(){
    JJOO jjoo = mockJJOODia0();
    cout << jjoo << endl;
}

void testJJOO_cronogramaAll(){
    JJOO jjoo = mockJJOODia5();
    int i = 0;
    while (i<jjoo.cantDias()){
        cout << endl;
        cout << "#### DIA " << i << endl;
        cout << jjoo.cronograma(i) << endl;
        i++;
    }
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

void testJJOO_stevenBradbury(){
    JJOO jjoo = mockJJOODia1();
    cout<< "steven: " << jjoo.stevenBradbury() << endl;
}

void testSequiaOlimpica(){
    JJOO jjoo0 = mockJJOODia0();
    JJOO jjoo1 = mockJJOODia1();
    JJOO jjoo2 = mockJJOODia2();
    JJOO jjoo3 = mockJJOODia3();
    JJOO jjoo4 = mockJJOODia4();
    JJOO jjoo5 = mockJJOODia5();
    JJOO jjooERRONEO = mockJJOODiaERRONEODIA2();

    cout << "SEQUIA OLIMPICA AL DIA 0" << endl;
    cout << jjoo0.sequiaOlimpica() <<endl;
    cout << "SEQUIA OLIMPICA AL DIA 1" << endl;
    cout << jjoo1.sequiaOlimpica() <<endl;
    cout << "SEQUIA OLIMPICA AL DIA 2" << endl;
    cout << jjoo2.sequiaOlimpica() <<endl;
    cout << "SEQUIA OLIMPICA AL DIA 3" << endl;
    cout << jjoo3.sequiaOlimpica() <<endl;
    cout << "SEQUIA OLIMPICA AL DIA 4" << endl;
    cout << jjoo4.sequiaOlimpica() <<endl;
    cout << "SEQUIA OLIMPICA AL DIA 5" << endl;
    cout << jjoo5.sequiaOlimpica() <<endl;
    cout << "SEQUIA OLIMPICA AL DIA 6" << endl;
    cout << jjooERRONEO.sequiaOlimpica() <<endl;
}

void testCompetenciasFinalizadasConOroEnPodio(){
    JJOO jjoo0 = mockJJOODia0();
    JJOO jjoo3 = mockJJOODia3();
    JJOO jjoo5 = mockJJOODia5();
    JJOO jjooERRONEO = mockJJOODiaERRONEODIA2();

    cout<< endl;
    cout<< "COMPETENCIAS CON OROS DIA 0" << endl;
    cout<< jjoo0.competenciasFinalizadasConOroEnPodio()<<endl;
    cout<< endl;
    cout<< "COMPETENCIAS CON OROS DIA 3" << endl;
    cout<< jjoo3.competenciasFinalizadasConOroEnPodio()<<endl;
    cout<< endl;
    cout<< "COMPETENCIAS CON OROS DIA 5" << endl;
    cout<< jjoo5.competenciasFinalizadasConOroEnPodio()<<endl;
    cout<< endl;
    cout<< "COMPETENCIAS CON OROS DIA ERRONEO" << endl;
    cout<< jjooERRONEO.competenciasFinalizadasConOroEnPodio()<<endl;
}

//NO BORRAR PORQUE QUIZAS HAY QUE INCLUIRLA OJO
void mostrarMedallero(Lista<pair<Pais,Lista<int> > > ls){
    int i = 0;
    while (i<ls.longitud()){
        pair<Pais,Lista<int> > par = ls.iesimo(i);
        string ps = par.first;
        Lista<int> medals = par.second;
        cout << "Pais: " << ps << " Medallero: " << medals << endl;
        i++;
    }
}

void testMedallero(){
    JJOO jjoo0 = mockJJOODia0();
    JJOO jjoo1 = mockJJOODia1();
    JJOO jjoo2 = mockJJOODia2();
    JJOO jjoo3 = mockJJOODia3();
    JJOO jjoo4 = mockJJOODia4();
    JJOO jjoo5 = mockJJOODia5();
    JJOO jjooERRONEO = mockJJOODiaERRONEODIA2();

    cout << "MEDALLERO AL DIA 0" << endl;
    mostrarMedallero(jjoo0.medallero());
    cout << "MEDALLERO AL DIA 1" << endl;
    mostrarMedallero(jjoo1.medallero());
    cout << "MEDALLERO AL DIA 2" << endl;
    mostrarMedallero(jjoo2.medallero());
    cout << "MEDALLERO AL DIA 3" << endl;
    mostrarMedallero(jjoo3.medallero());
    cout << "MEDALLERO AL DIA 4" << endl;
    mostrarMedallero(jjoo4.medallero());
    cout << "MEDALLERO AL DIA 5" << endl;
    mostrarMedallero(jjoo5.medallero());
    cout << "MEDALLERO AL DIA ERRONEO" << endl;
    mostrarMedallero(jjooERRONEO.medallero());
}

