
#include <iostream>
#include "atleta.h"


Atleta newAtleta(int cia){
    return Atleta("Fulano" , Masculino , 1980 , "Guatemala" , cia);
}

Atleta newAtleta(){
    return Atleta("Fulano" , Masculino , 1980 , "Guatemala" , 1000);
}


Lista<Atleta> mockAtletas(){
    Lista<Atleta> lista = Lista<Atleta>();
    lista.agregar(newAtleta(1));
    lista.agregar(newAtleta(2));
    lista.agregar(newAtleta(3));
    lista.agregar(newAtleta(4));
    return lista;
}


void testAtleta_capacidad(){
    Atleta atleta1 = newAtleta();
    atleta1.entrenarNuevoDeporte("tenis" , 64);
    cout << atleta1.capacidad("tenis") ;
}


void testAtleta_deportes_y_entrenarDeportes(){
    Atleta a = newAtleta();
    a.entrenarNuevoDeporte("futbol" , 5);
    a.entrenarNuevoDeporte("tenis" , 3);
    a.entrenarNuevoDeporte("jockey" , 8);
    a.entrenarNuevoDeporte("jockey" , 8);
    a.entrenarNuevoDeporte("jockey" , 8);
    cout << a.deportes() << endl;
}


void testAtleta_igualdad(){
    Atleta a1 = newAtleta(1);
    Atleta a2 = newAtleta(2);
    Atleta a3 = newAtleta(1);
    cout << "son iguales ? : " << ((a1 == a2) ? "si" : "no") << endl;
    cout << "son iguales ? : " << ((a1 == a3) ? "si" : "no") << endl;
}

