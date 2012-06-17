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

Competencia mockCompetenciaTenisMasc(){
    return Competencia("Tenis",Masculino,mockAtletasTenisMasc());
}


Competencia mockCompetenciaTenisMascYUnAtletaSinDeportes(){
    Lista<Atleta> atletas = mockAtletasTenisMasc();
    atletas.agregarAtras(newAtleta(123));
    return Competencia("Tenis",Masculino,atletas);
}

Competencia mockCompetenciaFutbolMasc(){
    return Competencia("Futbol",Masculino,mockAtletasFutbolMasc());
}

Competencia mockCompetenciaHockeyMasc(){
    return Competencia("Hockey",Masculino,mockAtletasHockeyMasc());
}

Competencia mockCompetenciaNatacionMasc(){
    return Competencia("Natacion",Masculino,mockAtletasNatacionMasc());
}

Competencia mockCompetenciaPoloFem(){
    return Competencia("Polo",Femenino,mockAtletasPoloFem());
}


Lista<int> mockRankingTenisMasc(){
    Lista<int> lista = Lista<int>();
    lista.agregarAtras(4000); //primero
    lista.agregarAtras(2000); //segundo
    lista.agregarAtras(3000); //tercero
    return lista;
}

Lista<int> mockRankingFutbolMasc(){
    Lista<int> lista = Lista<int>();
    lista.agregarAtras(5000); //primero
    lista.agregarAtras(1000); //segundo
    lista.agregarAtras(4000); //tercero
    lista.agregarAtras(2000); //cuarto
    return lista;
}

Lista<int> mockRankingHockeyMasc(){
    Lista<int> lista = Lista<int>();
    lista.agregarAtras(5000); //primero
    lista.agregarAtras(1000); //segundo
    lista.agregarAtras(4000); //tercero
    lista.agregarAtras(3000); //cuarto
    return lista;
}

Lista<int> mockRankingNatacionMasc(){
    Lista<int> lista = Lista<int>();
    lista.agregarAtras(5000); //primero
    return lista;
}

Lista<int> mockRankingPoloFem(){
    Lista<int> lista = Lista<int>();
    lista.agregarAtras(6000); //primero
    lista.agregarAtras(7000); //segundo
    lista.agregarAtras(8000); //tercero
    lista.agregarAtras(10000); //cuarto
    lista.agregarAtras(9000); //quinto
    return lista;
}

Lista<pair<int , bool> > mockControlAntidopingTenisMasc(){
    Lista<pair<int , bool> > lista = Lista< pair<int , bool> >();
    lista.agregar(pair<int,bool>(1000,true));
    lista.agregar(pair<int,bool>(2000,false));
    lista.agregar(pair<int,bool>(3000,true));
    lista.agregar(pair<int,bool>(4000,false));
    return lista;
}

Lista<pair<int , bool> > mockControlAntidopingFutbolMasc(){
    Lista<pair<int , bool> > lista = Lista< pair<int , bool> >();
    lista.agregar(pair<int,bool>(1000,true));
    lista.agregar(pair<int,bool>(2000,false));
    lista.agregar(pair<int,bool>(5000,true));
    lista.agregar(pair<int,bool>(4000,false));
    return lista;
}

Lista<pair<int , bool> > mockControlAntidopingHockeyMasc(){
    Lista<pair<int , bool> > lista = Lista< pair<int , bool> >();
    lista.agregar(pair<int,bool>(1000,true));
    lista.agregar(pair<int,bool>(5000,true));
    lista.agregar(pair<int,bool>(4000,false));
    return lista;
}

Lista<pair<int , bool> > mockControlAntidopingNatacionMasc(){
    Lista<pair<int , bool> > lista = Lista< pair<int , bool> >();
    lista.agregar(pair<int,bool>(1000,true));
    lista.agregar(pair<int,bool>(4000,false));
    return lista;
}

Lista<pair<int , bool> > mockControlAntidopingPoloFem(){
    Lista<pair<int , bool> > lista = Lista< pair<int , bool> >();
    lista.agregar(pair<int,bool>(6000,true));
    return lista;
}

Competencia mockCompetenciaTenisMascFinalizada(){
    Competencia comp = mockCompetenciaTenisMasc();
    comp.finalizar(mockRankingTenisMasc(),mockControlAntidopingTenisMasc());
    return comp;
}

Competencia mockCompetenciaTenisMascFinalizada_noFinalizaronTodos(){
    Competencia comp = mockCompetenciaTenisMasc();
    comp.finalizar(mockRankingTenisMasc(),mockControlAntidopingTenisMasc());
    return comp;
}

Competencia mockCompetenciaFutbolMascFinalizada(){
    Competencia comp = mockCompetenciaFutbolMasc();
    comp.finalizar(mockRankingFutbolMasc(),mockControlAntidopingFutbolMasc());
    return comp;
}

Competencia mockCompetenciaHockeyMascFinalizada(){
    Competencia comp = mockCompetenciaHockeyMasc();
    comp.finalizar(mockRankingHockeyMasc(),mockControlAntidopingHockeyMasc());
    return comp;
}

Competencia mockCompetenciaNatacionMascFinalizada(){
    Competencia comp = mockCompetenciaNatacionMasc();
    comp.finalizar(mockRankingNatacionMasc(),mockControlAntidopingNatacionMasc());
    return comp;
}

Competencia mockCompetenciaPoloFemFinalizada(){
    Competencia comp = mockCompetenciaPoloFem();
    comp.finalizar(mockRankingPoloFem(),mockControlAntidopingPoloFem());
    return comp;
}

Lista<Competencia> mockCompetenciasDia1NoFinal(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaTenisMasc());
    comps.agregarAtras(mockCompetenciaFutbolMasc());
    return comps;
}

Lista<Competencia> mockCompetenciasDia1Final(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaTenisMascFinalizada());
    comps.agregarAtras(mockCompetenciaFutbolMascFinalizada());
    return comps;
}

Lista<Competencia> mockCompetenciasDia2NoFinal(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaHockeyMasc());
    return comps;
}

Lista<Competencia> mockCompetenciasDia2Final(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaHockeyMascFinalizada());
    return comps;
}

Lista<Competencia> mockCompetenciasDia3NoFinal(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaPoloFem());
    return comps;
}

Lista<Competencia> mockCompetenciasDia3Final(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaPoloFemFinalizada());
    return comps;
}

Lista<Competencia> mockCompetenciasDia4Vacio(){
    Lista<Competencia> comps = Lista<Competencia> ();
    return comps;
}

Lista<Competencia> mockCompetenciasDia5NoFinal(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaNatacionMasc());
    return comps;
}

Lista<Competencia> mockCompetenciasDia5Final(){
    Lista<Competencia> comps = Lista<Competencia> ();
    comps.agregarAtras(mockCompetenciaNatacionMascFinalizada());
    return comps;
}

Lista<Competencia> mockCompetenciasDia6Vacio(){
    Lista<Competencia> comps = Lista<Competencia> ();
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
    cout << "ranking de participantes: " << comp.ranking() << endl;
}

void testCompetencia_lesTocoControlAntidoping(){
    Competencia comp = mockCompetencia();
    comp.finalizar(mockPosiciones() , mockControlAntidoping());
    cout <<"controles: " << comp.lesTocoControlAntidoping() <<endl;
 }


void testCompetencia_gananLosMasCapaces(){
    Competencia comp = mockCompetenciaTenisMasc();
    comp.finalizar(mockRankingTenisMasc(),mockControlAntidopingTenisMasc());
    cout << "ganan los mas capaces: " << comp.gananLosMasCapaces() << endl;
}

void testCompetencia_operadorIgual(){
    Competencia comp1 = mockCompetenciaFutbolMascFinalizada();
    Competencia comp2 = mockCompetenciaTenisMascFinalizada();
    Competencia comp3 = mockCompetenciaFutbolMasc();
    Competencia comp4 = mockCompetenciaTenisMascFinalizada();

    cout << "Son iguales? " << ( comp1 == comp1) << endl;
    cout << "Son iguales? " << ( comp1 == comp2) << endl;
    cout << "Son iguales? " << ( comp3 == comp3) << endl;
    cout << "Son iguales? " << ( comp3 == comp4) << endl;
    cout << "Son iguales? " << ( comp1 == comp3) << endl;
    //resultado esperado = 1 0 1 0 0
}



void testCompetencia_linfordChristi(){

    Competencia comp1 = mockCompetencia();
    comp1.linfordChristie(1);
    cout << comp1.participantes() << endl;

    Competencia comp2 = mockCompetencia();
    comp2.linfordChristie(4);
    cout << comp2.participantes() << endl;

    Competencia comp3 = mockCompetencia();
    comp3.linfordChristie(3);
    cout << comp3.participantes() << endl;

    Competencia comp4 = mockCompetencia();
    comp4.linfordChristie(2);
    cout << comp4.participantes() << endl;
}


void testCompetencia_mostrar(){
    Competencia c = mockCompetencia();
    c.mostrar(cout);
}


void testCompetencia_cargar(){
    ifstream archivo ("/home/gonzalo/salida.txt");
    Competencia comp = Competencia();
    comp.cargar(archivo);
    comp.mostrar(cout);
}


void testCompetenciaJuly(){
    Lista<Competencia> comps = mockCompetenciasDia3Final();
    cout << comps << endl;
}


void testCompetencia_guardar_noFinalizada(){
    ofstream archivo ("/home/gonzalo/salida.txt");
    Competencia comp = mockCompetenciaTenisMascYUnAtletaSinDeportes();
    comp.guardar(archivo );
    archivo.close();
}
void testCompetencia_guardarFinalizada(){
    ofstream salida ("/home/gonzalo/salida.txt");
    Competencia comp2 = mockCompetenciaTenisMascFinalizada();
    comp2.guardar(salida);
    salida.close();
}

void testCompetencia_guardarYCargar(){

    cout << "Competencia no finalizada: " << endl;
    testCompetencia_guardar_noFinalizada();
    cout << "cargando" << endl;
    testCompetencia_cargar();

    cout << endl<< endl;
    cout << "Competencia finalizada: " << endl;
    testCompetencia_guardarFinalizada();
    testCompetencia_cargar();
    cout << endl<< endl;
}
