#include <iostream>
#include "interfaz.h"


using namespace std;


Atleta atletaProdigio(const JJOO & j) {

    //tomo el último elemento de la lista de competencias finalizadas que tienen al menos oro (ver problema oro en podio de jjoo)
    int i= j.competenciasFinalizadasConOroEnPodio().longitud()-1;
    //me quedo con el atleta ganador del oro
    Atleta a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
    while (i>0){
        //quiero el anterior al que ya tengo, así que le resto 1 a i,
        i--;
        //si el año de nacimiento del primer atleta que agarré es menor (lo cual significa que es mas viejo) que el nuevo atleta que agarro...
        if (a.anioNacimiento() <= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
           //me quedo con el nuevo atleta,...
            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
        } //sino, me quedo con el que ya tengo
    }
    return a;
}


/* PROBLEMA RESUELTO DE MANERA ALTERNATIVA empezando a revisar desde el principio
Atleta atletaProdigio(const JJOO & j) {

    int i= 0;
    Atleta a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
    while (i<j.competenciasFinalizadasConOroEnPodio().longitud()-1){
        i++;
        if (a.anioNacimiento() <= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
        }
    }
    return a;
}
*/








int main()
{
    MenuPrincipal();
    return 0;
}


