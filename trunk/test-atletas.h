
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

void testLazyAtleta(){
    Atleta a = mockLazyAtleta();
    cout << a.deportes() << endl;
}


Lista<Atleta> mockAtletas(){
    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregar(newAtleta(1));
    lista.agregar(newAtleta(2));
    lista.agregar(newAtleta(3));
    lista.agregar(newAtleta(4));
    return lista;
}


Lista<Atleta> mockAtletasTenisMasc(){
    Atleta atleta1 = Atleta("atleta1" , Masculino , 1980 , "Guatemala" , 1000);
    Atleta atleta2 = Atleta("atleta2" , Masculino , 1985 , "Brazil" , 2000);
    Atleta atleta3 = Atleta("atleta3" , Masculino , 1977 , "Argentina" , 3000);
    Atleta atleta4 = Atleta("atleta4" , Masculino , 1968 , "Bolivia" , 4000);
    Atleta atleta5 = Atleta("atleta5" , Masculino , 1983 , "Chile" , 5000);

    atleta1.entrenarNuevoDeporte("Tenis",5);
    atleta1.entrenarNuevoDeporte("Futbol",50);
    atleta1.entrenarNuevoDeporte("Hockey",10);
    atleta1.entrenarNuevoDeporte("Natacion",20);

    atleta2.entrenarNuevoDeporte("Tenis",50);
    atleta2.entrenarNuevoDeporte("Futbol",10);
    atleta2.entrenarNuevoDeporte("Natacion",30);

    atleta3.entrenarNuevoDeporte("Tenis",80);
    atleta3.entrenarNuevoDeporte("Hockey",2);
    atleta3.entrenarNuevoDeporte("Natacion",25);

    atleta4.entrenarNuevoDeporte("Tenis",10);
    atleta4.entrenarNuevoDeporte("Futbol",40);
    atleta4.entrenarNuevoDeporte("Hockey",20);
    atleta4.entrenarNuevoDeporte("Natacion",40);

    atleta5.entrenarNuevoDeporte("Tenis",20);
    atleta5.entrenarNuevoDeporte("Futbol",30);
    atleta5.entrenarNuevoDeporte("Hockey",40);
    atleta5.entrenarNuevoDeporte("Natacion",10);

    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregar(atleta1);
    lista.agregar(atleta2);
    lista.agregar(atleta3);
    lista.agregar(atleta4);
    lista.agregar(atleta5);

    return lista;

}

Lista<Atleta> mockAtletasFutbolMasc(){
    Atleta atleta1 = Atleta("atleta1" , Masculino , 1980 , "Guatemala" , 1000);
    Atleta atleta2 = Atleta("atleta2" , Masculino , 1985 , "Brazil" , 2000);
    Atleta atleta4 = Atleta("atleta4" , Masculino , 1968 , "Bolivia" , 4000);
    Atleta atleta5 = Atleta("atleta5" , Masculino , 1983 , "Chile" , 5000);

    atleta1.entrenarNuevoDeporte("Tenis",5);
    atleta1.entrenarNuevoDeporte("Futbol",50);
    atleta1.entrenarNuevoDeporte("Hockey",10);
    atleta1.entrenarNuevoDeporte("Natacion",20);

    atleta2.entrenarNuevoDeporte("Tenis",50);
    atleta2.entrenarNuevoDeporte("Futbol",10);
    atleta2.entrenarNuevoDeporte("Natacion",30);

    atleta4.entrenarNuevoDeporte("Tenis",10);
    atleta4.entrenarNuevoDeporte("Futbol",40);
    atleta4.entrenarNuevoDeporte("Hockey",20);
    atleta4.entrenarNuevoDeporte("Natacion",40);

    atleta5.entrenarNuevoDeporte("Tenis",20);
    atleta5.entrenarNuevoDeporte("Futbol",30);
    atleta5.entrenarNuevoDeporte("Hockey",40);
    atleta5.entrenarNuevoDeporte("Natacion",10);


    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregar(atleta1);
    lista.agregar(atleta2);
    lista.agregar(atleta4);
    lista.agregar(atleta5);

    return lista;

}


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
