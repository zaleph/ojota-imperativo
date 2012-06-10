

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

    // Atleta(const string nombre,const Sexo sexo, const int anio, const Pais pais, const int ciaNumber);

    Atleta atleta1 = newAtleta();
    atleta1.entrenarNuevoDeporte("tenis" , 64);

    cout << atleta1.capacidad("tenis") ;

}
