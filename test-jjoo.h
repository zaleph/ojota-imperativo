
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
    //jjoo. = 1;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 1 FINALIZADAS
JJOO mockJJOODia1(){
    JJOO jjoo =JJOO(2012 , mockAtletasFull() , mockCronograDia1() );
    //jjoo._jornadaActual = 1;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 2 FINALIZADAS
JJOO mockJJOODia2(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia2() );
   // jjoo._jornadaActual = 2;
    return jjoo;
}
//JUEGO CON LAS COMPETENCIAS DEL DIA 3 FINALIZADAS
JJOO mockJJOODia3(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia3() );
    //jjoo._jornadaActual = 3;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 4 que en realidad esta vacio
JJOO mockJJOODia4(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia3() );
    //jjoo._jornadaActual = 4;
    return jjoo;
}

//JUEGO CON LAS COMPETENCIAS DEL DIA 5 FINALIZADAS
JJOO mockJJOODia5(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDia5() );
    //jjoo._jornadaActual = 6;
    return jjoo;
}

//JUEGO ERRONEO CON COMPETENCIAS SIN FINALIZAR EN EL DIA 2
JJOO mockJJOODiaERRONEODIA2(){
    JJOO jjoo = JJOO(2012 , mockAtletasFull() , mockCronograDiaERRONEODIA2() );
    //jjoo._jornadaActual = 2;
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

void testTranscurrirDia(){

    JJOO jjoo0 = mockJJOODia0();
    JJOO jjoo1 = mockJJOODia1();
    JJOO jjoo2 = mockJJOODia2();
    JJOO jjoo3 = mockJJOODia3();
    JJOO jjoo4 = mockJJOODia4();
    JJOO jjoo5 = mockJJOODia5();
    JJOO jjooERRONEO = mockJJOODiaERRONEODIA2();

    cout << "JORNADA ACTUAL DIA 0" << endl;
    jjoo0.transcurrirDia();
    cout << jjoo0.jornadaActual() << endl;
    cout << "JORNADA ACTUAL DIA 1" << endl;
    jjoo1.transcurrirDia();
    cout << jjoo1.jornadaActual() << endl;
    cout << "JORNADA ACTUAL DIA 2" << endl;
    jjoo2.transcurrirDia();
    cout << jjoo2.jornadaActual() << endl;
    cout << "JORNADA ACTUAL DIA 3" << endl;
    jjoo3.transcurrirDia();
    cout << jjoo3.jornadaActual() << endl;
    cout << "JORNADA ACTUAL DIA 4" << endl;
    jjoo4.transcurrirDia();
    cout << jjoo4.jornadaActual() << endl;
    cout << "JORNADA ACTUAL DIA 5" << endl;
    jjoo5.transcurrirDia();
    cout << jjoo5.jornadaActual() << endl;
    cout << "JORNADA ACTUAL DIA ERRONEO" << endl;
    jjooERRONEO.transcurrirDia();
    cout << jjooERRONEO.jornadaActual() << endl;

}

void testDePaseo(){
    JJOO jjoo0 = mockJJOODia0();
    cout << "ATLETAS QUE PASEAN" << endl;
    jjoo0.mostrar(cout);
}

void testLiuSong(){
    JJOO jjoo1 = mockJJOODia1();

    cout << "LIU SONG EN EL DIA 1" << endl;
    jjoo1.liuSong(mockAtleta1() , "PANAMA");
    cout << jjoo1.atletas() << endl;

    cout << "COMPETENCIAS CON LIU SONG" << endl;

    int dia = 1;
    while (dia<jjoo1.cantDias()){
        Lista<Competencia> comps = jjoo1.cronograma(dia);
        int i = 0;
        while (i<comps.longitud()){
            Competencia comp = comps.iesimo(i);
            Deporte d = comps.iesimo(i).categoria().first;
            Sexo s = comps.iesimo(i).categoria().second;
            cout << "CATEGORIA: " << d << " "<< s << endl;
            cout << comp.participantes() << endl;
            i++;
        }
        dia++;
    }

    cout << "COMPETENCIAS" << endl;
    cout << endl;

    int dia1 = 1;
    while (dia1<jjoo1.cantDias()){
        Lista<Competencia> comps = jjoo1.cronograma(dia1);
        int i = 0;
        while (i<comps.longitud()){
            if (comps.iesimo(i).finalizada()){
                Deporte d = comps.iesimo(i).categoria().first;
                Sexo s = comps.iesimo(i).categoria().second;
                cout << "CATEGORIA: " << d << " "<< s << endl;
                cout << comps.iesimo(i).ranking() << endl;
                cout << comps.iesimo(i).lesTocoControlAntidoping()<<endl;
            }
            i++;
        }
        dia1++;
    }
}

void testLosMasFracasados(){
    JJOO jjoo5 = mockJJOODiaERRONEODIA2();
    cout<<jjoo5.losMasFracasados("Islandia")<<endl;
}

void testBoicot(){
    JJOO jjoo5 = mockJJOODia5();
    Categoria cat = Categoria("Futbol",Masculino);
    cout<<jjoo5.boicotPorDisciplina(cat,"Bolivia")<<endl;

    int dia = 1;
    while (dia<jjoo5.cantDias()){
        Lista<Competencia> comps = jjoo5.cronograma(dia);
        int i = 0;
        while (i<comps.longitud()){
            Competencia comp = comps.iesimo(i);
            Deporte d = comps.iesimo(i).categoria().first;
            Sexo s = comps.iesimo(i).categoria().second;
            cout << "CATEGORIA: " << d << " "<< s << endl;
            cout << comp.participantes() << endl;
            i++;
        }
        dia++;
    }

    cout << "COMPETENCIAS FINALIZADAS" << endl;
    cout << endl;

    int dia1 = 1;
    while (dia1<jjoo5.cantDias()){
        Lista<Competencia> comps = jjoo5.cronograma(dia1);
        int i = 0;
        while (i<comps.longitud()){
            if (comps.iesimo(i).finalizada()){
                Deporte d = comps.iesimo(i).categoria().first;
                Sexo s = comps.iesimo(i).categoria().second;
                cout << "CATEGORIA: " << d << " "<< s << endl;

                cout << "RANKING" << endl;
                cout << endl;
                cout << comps.iesimo(i).ranking() << endl;
                cout << "CONTROL" << endl;
                cout << endl;
                cout << comps.iesimo(i).lesTocoControlAntidoping()<<endl;
            }
            i++;
        }
        cout << endl;
        dia1++;
    }
}

void testJJOO_cargar(){
    ifstream salida ("/home/gonzalo/salida.txt");
    JJOO j = JJOO();
    j.cargar(salida);
    salida.close();
}


void testJJOO_guardar(){
    ofstream salida ("/home/gonzalo/salida.txt");
    JJOO j = mockJJOODia1();
    j.guardar(salida);
    salida.close();
}


void testJJOO_guardarYCargar(){
    cout << "guardando juego olimpico : " << endl;
    ofstream salida1 ("/home/gonzalo/salida.txt");
    JJOO j1 = mockJJOODia1();
    j1.guardar(salida1);
    salida1.close();

    cout << endl << endl;
    cout << "cargano juego olimpico : " << endl;
    ifstream salida2 ("/home/gonzalo/salida.txt");
    JJOO j2 = JJOO();
    j2.cargar(salida2);
    salida2.close();
    cout << endl << endl;

    cout << "son iguales? " << ((j1 == j2) ? "True" : "False") << endl;

}



void testJJOO_stevenBradbury(){
    JJOO jjoo = mockJJOODia5();

    cout<< "steven: " << jjoo.stevenBradbury() << endl;
}



void testJJOO_uyOrdenadoSiHayPatron(){
    JJOO jjoo = mockJJOODia5();

    cout << jjoo.cantDias() << endl;

    cout<< "cumple patron: " << (jjoo.uyOrdenadoAsiHayUnPatron() ? "true" : "false" )<< endl;
}
