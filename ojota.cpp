#include <iostream>
#include "interfaz.h"


using namespace std;


Atleta atletaProdigio(const JJOO & j) {

    int i= j.competenciasFinalizadasConOroEnPodio().longitud()-1;
    Atleta a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
    while (i>0){
        i--;
        if (a.anioNacimiento() <= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
        }
    }
    return a;
}


int main()
{
    MenuPrincipal();
    return 0;
}


