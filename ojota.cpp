#include <iostream>
#include "interfaz.h"


using namespace std;


Atleta atletaProdigio(const JJOO & j) {

    Atleta a = j.competenciasFinalizadasConOroEnPodio().cabeza().ranking().iesimo(0);
    int i= 1;

    // Vale Pc: |competenciasConOroEnPodio(j)| > 0 && i == 1 && a == cab ([cab(ranking(c)) | c <- competenciasConOroEnPodio(j)]);
	// Implica  1 <= i <= |competenciasConOroEnPodio|;
	// Implica  (∀c ∈ competenciasConOroEnPodio(j)[0..1)) añoNacimiento(a) >= añoNacimiento(campeon(c));
	// Implica  1 <= i <= |competenciasConOroEnPodio| && esCampeon(a,j) && (∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c));
	// Luego, Pc -> I.

    while (i<j.competenciasFinalizadasConOroEnPodio().longitud()){
        // Guarda B: i < |competenciasConOroEnPodio(j)|
        // Invariante I: 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a,j) && (∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c));
		// Variante V: |compentenciasConOroEnPodio(j)| - i;
		// Cota C: 0;

		// Estado E1;
		// Vale I && B;

        if (a.anioNacimiento() <= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
            // Estado IF1;
			// Vale i == i@E1 && añoNacimiento(a@E1) <= añoNacimiento(campeon(competenciasConOroEnPodio(j)[i]));

            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
            // Estado G
			// Vale i == i@E1 && añoNacimiento(a@E1) <= añoNacimiento(campeon(competenciasConOroEnPodio(j)[i])) && a == campeon(competenciasConOroEnPodio(j)[i]);
        }

        // Estado E2
        // Vale G || H;
		// Implica (añoNacimiento(a@E1) <= añoNacimiento(campeon(competenciasConOroEnPodio(j)[i])) && a == campeon(competenciasConOroEnPodio(j)[i])) || (añoNacimiento(a@E1) > añoNacimiento(campeon(competenciasConOroEnPodio(j)[i])) && a == a@E1)
        // Implica añoNacimiento(a) > añoNacimiento(campeon(competenciasConOroEnPodio(j)[i]));
        // Implica esCampeon(a,j);
        // Implica (∀c ∈ competenciasConOroEnPodio(j)[0..i]) añoNacimiento(a) >= añoNacimiento(campeon(c));

        i++;

		// Estado E3
		// Vale    i == i@E2 + 1 && esCampeon(a,j) && (∀c ∈ competenciasConOroEnPodio(j)[0..i@E2]) añoNacimiento(a) >= añoNacimiento(campeon(c));
		// Implica 1 < i
		// Implica i == i@E2 + 1 < |competenciasConOroEnPodio(j)| + 1 <= |competenciasConOroEnPodio(j)|
		// Implica 1 <= i <= |competenciasConOroEnPodio(j)|
		// Implica i@E2 == i - 1
		// Implica (∀c ∈ competenciasConOroEnPodio(j)[0..i - 1]) añoNacimiento(a) >= añoNacimiento(campeon(c));
		// Implica 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a) && (∀c ∈ competenciasConOroEnPodio[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c));
		//
		// Luego, E3 -> I.
		//
		// Vale    V = |competenciasConOroEnPodio(j)| - i@E3
		// Implica V = |competenciasConOroEnPodio(j)| - (i@E1 + 1)
		// Implica V = |competenciasConOroEnPodio(j)| - i@E1 - 1 < |competenciasConOroEnPodio(j)| - i@E1 == V@E1
		//
		// Luego, V@E3 < V@E1.
		//
		// Supongo V <= C.
		// Vale    I && (V <= C)
		// Implica 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a,j) &&
		//         ((∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c))) &&
		//         (|competenciasConOroEnPodio(j)| - i <= 0)
		// Implica |competenciasConOroEnPodio(j)| <= i
		// Implica i == |competenciasConOroEnPodio(j)|
		// Implica ¬(i < |competenciasConOroEnPodio(j)|)
		//
		// Luego, I && (V <= C) -> ¬B.
    }




    return a;









}

int main()
{
    MenuPrincipal();
    return 0;
}


