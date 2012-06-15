
#include <iostream>
#include "atleta.h"

Atleta newAtleta(int cia){
    return Atleta("Fulano" , Masculino , 1980 , "Guatemala" , cia);
}

Atleta newAtleta(){
    return Atleta("Fulano" , Masculino , 1980 , "Guatemala" , 1000);
}

Atleta mockLazyAtleta(){
    Atleta atleta1 = Atleta("atleta1" , Masculino , 1980 , "Guatemala" , 1000);
    return atleta1;
}

Lista<Atleta> mockAtletas(){
    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregar(newAtleta(1));
    lista.agregar(newAtleta(2));
    lista.agregar(newAtleta(3));
    lista.agregar(newAtleta(4));
    return lista;
}

Atleta mockAtleta1(){
    Atleta atleta1 = Atleta("atleta1" , Masculino , 1980 , "Guatemala" , 1000);
    atleta1.entrenarNuevoDeporte("Tenis",5);
    atleta1.entrenarNuevoDeporte("Futbol",50);
    atleta1.entrenarNuevoDeporte("Hockey",10);
    atleta1.entrenarNuevoDeporte("Natacion",20);
    return atleta1;
}

Atleta mockAtleta2(){
    Atleta atleta2 = Atleta("atleta2" , Masculino , 1985 , "Brazil" , 2000);
    atleta2.entrenarNuevoDeporte("Tenis",50);
    atleta2.entrenarNuevoDeporte("Futbol",10);
    atleta2.entrenarNuevoDeporte("Natacion",30);
    return atleta2;
}

Atleta mockAtleta3(){
    Atleta atleta3 = Atleta("atleta3" , Masculino , 1977 , "Argentina" , 3000);
    atleta3.entrenarNuevoDeporte("Tenis",80);
    atleta3.entrenarNuevoDeporte("Hockey",2);
    atleta3.entrenarNuevoDeporte("Natacion",25);
    return atleta3;
}

Atleta mockAtleta4(){
    Atleta atleta4 = Atleta("atleta4" , Masculino , 1968 , "Bolivia" , 4000);
    atleta4.entrenarNuevoDeporte("Tenis",10);
    atleta4.entrenarNuevoDeporte("Futbol",40);
    atleta4.entrenarNuevoDeporte("Hockey",20);
    atleta4.entrenarNuevoDeporte("Natacion",40);
    return atleta4;
}

Atleta mockAtleta5(){
    Atleta atleta5 = Atleta("atleta5" , Masculino , 1983 , "Chile" , 5000);
    atleta5.entrenarNuevoDeporte("Tenis",20);
    atleta5.entrenarNuevoDeporte("Futbol",30);
    atleta5.entrenarNuevoDeporte("Hockey",40);
    atleta5.entrenarNuevoDeporte("Natacion",10);
    return atleta5;
}
Atleta mockAtleta6(){
    Atleta atleta6 = Atleta("atleta6" , Femenino , 1983 , "Italia" , 6000);
    atleta6.entrenarNuevoDeporte("Tenis",20);
    atleta6.entrenarNuevoDeporte("Futbol",30);
    atleta6.entrenarNuevoDeporte("Hockey",40);
    atleta6.entrenarNuevoDeporte("Polo",10);
    return atleta6;
}

Atleta mockAtleta7(){
    Atleta atleta7 = Atleta("atleta7" , Femenino , 1983 , "Francia" , 7000);
    atleta7.entrenarNuevoDeporte("Tenis",60);
    atleta7.entrenarNuevoDeporte("Futbol",80);
    atleta7.entrenarNuevoDeporte("Hockey",90);
    atleta7.entrenarNuevoDeporte("Polo",100);
    return atleta7;
}
Atleta mockAtleta8(){
    Atleta atleta8 = Atleta("atleta8" , Femenino , 1983 , "Uruguay" , 8000);
    atleta8.entrenarNuevoDeporte("Tenis",60);
    atleta8.entrenarNuevoDeporte("Futbol",80);
    atleta8.entrenarNuevoDeporte("Hockey",90);
    atleta8.entrenarNuevoDeporte("Polo",100);
    return atleta8;
}
Atleta mockAtleta9(){
    Atleta atleta9 = Atleta("atleta9" , Femenino , 1983 , "Islandia" , 9000);
    atleta9.entrenarNuevoDeporte("Tenis",60);
    atleta9.entrenarNuevoDeporte("Futbol",80);
    atleta9.entrenarNuevoDeporte("Hockey",90);
    atleta9.entrenarNuevoDeporte("Polo",100);
    return atleta9;
}

Atleta mockAtleta10(){
    Atleta atleta10 = Atleta("atleta10" , Femenino , 1983 , "Guatemala" , 10000);
    atleta10.entrenarNuevoDeporte("Tenis",60);
    atleta10.entrenarNuevoDeporte("Futbol",80);
    atleta10.entrenarNuevoDeporte("Hockey",90);
    atleta10.entrenarNuevoDeporte("Polo",100);
    return atleta10;
}

Lista<Atleta> mockAtletasFull(){
    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregarAtras(mockAtleta1());
    lista.agregarAtras(mockAtleta2());
    lista.agregarAtras(mockAtleta3());
    lista.agregarAtras(mockAtleta4());
    lista.agregarAtras(mockAtleta5());
    lista.agregarAtras(mockAtleta6());
    lista.agregarAtras(mockAtleta7());
    lista.agregarAtras(mockAtleta8());
    lista.agregarAtras(mockAtleta9());
    lista.agregarAtras(mockAtleta10());
    return lista;
}

/*
LISTAS DE ATLETAS POR CATEGORIA
*/


Lista<Atleta> mockAtletasTenisMasc(){
    Atleta atleta1 = mockAtleta1();
    Atleta atleta2 = mockAtleta2();
    Atleta atleta3 = mockAtleta3();
    Atleta atleta4 = mockAtleta4();
    Atleta atleta5 = mockAtleta5();

    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregarAtras(atleta1);
    lista.agregarAtras(atleta2);
    lista.agregarAtras(atleta3);
    lista.agregarAtras(atleta4);
    lista.agregarAtras(atleta5);

    return lista;
}

Lista<Atleta> mockAtletasFutbolMasc(){

    Atleta atleta1 = mockAtleta1();
    Atleta atleta2 = mockAtleta2();
    Atleta atleta4 = mockAtleta4();
    Atleta atleta5 = mockAtleta5();

    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregarAtras(atleta1);
    lista.agregarAtras(atleta2);
    lista.agregarAtras(atleta4);
    lista.agregarAtras(atleta5);

    return lista;
}

Lista<Atleta> mockAtletasHockeyMasc(){

    Atleta atleta1 = mockAtleta1();
    Atleta atleta3 = mockAtleta3();
    Atleta atleta4 = mockAtleta4();
    Atleta atleta5 = mockAtleta5();

    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregarAtras(atleta1);
    lista.agregarAtras(atleta3);
    lista.agregarAtras(atleta4);
    lista.agregarAtras(atleta5);

    return lista;
}


Lista<Atleta> mockAtletasNatacionMasc(){

    Atleta atleta1 = mockAtleta1();
    Atleta atleta3 = mockAtleta3();
    Atleta atleta4 = mockAtleta4();
    Atleta atleta5 = mockAtleta5();

    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregarAtras(atleta1);
    lista.agregarAtras(atleta3);
    lista.agregarAtras(atleta4);
    lista.agregarAtras(atleta5);

    return lista;
}


Lista<Atleta> mockAtletasPoloFem(){

    Atleta atleta6 = mockAtleta6();
    Atleta atleta7 = mockAtleta7();
    Atleta atleta8 = mockAtleta8();
    Atleta atleta9 = mockAtleta9();
    Atleta atleta10 = mockAtleta10();

    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregarAtras(atleta6);
    lista.agregarAtras(atleta7);
    lista.agregarAtras(atleta8);
    lista.agregarAtras(atleta9);
    lista.agregarAtras(atleta10);
    return lista;
}


/*
TESTS
*/



void testAtleta_capacidad(){
    Atleta atleta1 = newAtleta();
    atleta1.entrenarNuevoDeporte("tenis" , 64);
    cout << atleta1.capacidad("tenis") ;
}


void testAtleta_deportes_y_entrenarDeportes(){
    Atleta a = newAtleta();
    a.entrenarNuevoDeporte("Futbol" , 5);
    a.entrenarNuevoDeporte("Tenis" , 3);
    a.entrenarNuevoDeporte("Voley" , 80);
    a.entrenarNuevoDeporte("Jockey" , 8);
    a.entrenarNuevoDeporte("Jockey" , 10);
    a.entrenarNuevoDeporte("Jockey" , 20);
    a.entrenarNuevoDeporte("Futbol" , 50);

    cout << a.deportes() << endl;
    cout << a.capacidad("Jockey") << endl;
    cout << a.capacidad("Futbol") << endl;
}


void testAtleta_igualdad(){
    Atleta a1 = newAtleta(1);
    Atleta a2 = newAtleta(2);
    Atleta a3 = newAtleta(1);
    cout << "son iguales ? : " << ((a1 == a2) ? "si" : "no") << endl;
    cout << "son iguales ? : " << ((a1 == a3) ? "si" : "no") << endl;
}

void testLazyAtleta(){
    Atleta a = mockLazyAtleta();
    cout << a.deportes() << endl;
}

void testAtleta_guardar(){
    ofstream salida ("/home/gonzalo/salida.txt");

    Atleta a = newAtleta();
    a.entrenarNuevoDeporte("tenis" , 1);
    a.entrenarNuevoDeporte("futbol" , 2);
    a.entrenarNuevoDeporte("jockey" , 3);
    a.entrenarNuevoDeporte("rugby" , 4);
    a.entrenarNuevoDeporte("jockey" , 5);

    a.guardar(salida);

    salida.close();
}


void testAtleta_cargar(){
    ifstream archivo ("/home/gonzalo/salida.txt");
    Atleta a = Atleta();
    a.cargar(archivo);
    archivo.close();
    cout << a << endl;
}
