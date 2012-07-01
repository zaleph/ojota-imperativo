#include <iostream>
#include "interfaz.h"


using namespace std;


Atleta atletaProdigio(const JJOO & j) {

    Atleta a = j.competenciasFinalizadasConOroEnPodio().cabeza().ranking().iesimo(0);

    int i= 1;

    while (i<j.competenciasFinalizadasConOroEnPodio().longitud()){
        //si el año de nacimiento del primer atleta que agarré es menor (lo cual significa que es mas viejo) que el nuevo atleta que agarro...
        if (a.anioNacimiento() <= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
           //me quedo con el nuevo atleta,...
            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
        } //sino, me quedo con el que ya tengo
        i++;
    }
    return a;
}

int main()
{
    MenuPrincipal();
    return 0;
}


