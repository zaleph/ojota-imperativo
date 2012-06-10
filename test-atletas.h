

#ifndef TEST-ATLETAS_H_INCLUDED
#define TEST-ATLETAS_H_INCLUDED


#include <iostream>
#include "atleta.h"




Atleta newAtleta(){
    return Atleta("Fulano" , Masculino , 1980 , "Guatemala" , 1000);
}


void testAtleta_capacidad(){

    // Atleta(const string nombre,const Sexo sexo, const int anio, const Pais pais, const int ciaNumber);

    Atleta atleta1 = newAtleta();
    atleta1.entrenarNuevoDeporte("tenis" , 64);

    cout << atleta1.capacidad("tenis") ;

}

#endif
