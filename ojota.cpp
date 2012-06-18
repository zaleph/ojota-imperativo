#include <iostream>
#include "interfaz.h"


using namespace std;


Atleta atletaProdigio(const JJOO & j) {

    int i= j.competenciasFinalizadasConOroEnPodio().longitud()-1;
    // Estado\ e1;
    // vale\ i@e1==|competenciasConOroEnPodio(j)|-1;

    Atleta a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
    // Estado\ e2;
    // vale\ a@e2==campeon(competenciasConOroEnPodio(j)[i@e1]);
    // implica\ a@e2==campeon(competenciasConOroEnPodio(j)[|competenciasConOroEnPodio(j)|-1]);

    //vale\ Pc:i==|competenciasConOroEnPodio(j)|-1\ &&\ i>=0\ &&\ a==a@e2;
    //Bc:i>0;
    while (i>0){
        //invariante\ I:0<=i<=|competenciasConOroEnPodio(j)|-1\ &&\
        //((\forall k\selec[i..|competenciasConOroEnPodio(j)|-1])\ anioNacimiento(campeon(competenciasConOroEnPodio(j)[k]))<=anioNacimiento(a))\ &&\
        //esCampeon(a,j);

        //Estado eC;
        //vale Bc && I;
        i--;
        //estado pif;
        //vale i@pif==i@eC-1;
        //Pif: (\forall k\selec(i@pif..|competenciasConOroEnPodio(j)|-1]) anioNacimiento(campeon(competenciasConOroEnPodio(j)[k]))<=anioNacimiento(a@pif) && esCampeon(a@pif,j)

        //B : anioNacimiento(a@pif) <= anioNacimiento(campeon(competenciasFinalizadasConOroEnPodio(j)[i@pif]));
        if (a.anioNacimiento() <= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
           //estado iif; vale Pif && B;
            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
            //estado if1;
           //vale H: a@if1 == campeon(competenciasFinalizadasConOroEnPodio(j)[i@pif]) && anioNacimiento(a@pif)<=anioNacimiento(a@if1);
        }
        //estado qif;
        //vale i@qif==i@pif;
        //vale (B -> a@qif == a@if1) && vale (-B -> a@qif==a@pif);
        //Qif: (\forall k\selec[i@qif..|competenciasConOroEnPodio(j)|-1]) anioNacimiento(campeon(competenciasConOroEnPodio(j)[k]))<=anioNacimiento(a@qif) && esCampeon(a@qif,j);

    } //v: i ; c == 0;

    //Qc: i == 0 && ((\forall k\selec[i..|competenciasConOroEnPodio(j)|-1]) anioNacimiento(campeon(competenciasConOroEnPodio(j)[k])) <= anioNacimiento(a)) && esCampeon(a,j);

    //estado fc; vale Qc;

    return a;

    //estado fin: vale a == a@fc && result == a;
    //implica Q;


}


int main()
{
    MenuPrincipal();
    return 0;
}


