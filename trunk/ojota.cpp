#include <iostream>
#include "interfaz.h"
#include "test-jjoo.h"

using namespace std;


Atleta atletaProdigio(const JJOO & j) {

    Atleta a = j.competenciasFinalizadasConOroEnPodio().cabeza().ranking().iesimo(0);
    int i= 1;

	// vale Pc: |competenciasConOroEnPodio(j)| > 0 && i == 1 && |competenciasConOroEnPodio(j)| >0 
		// && a == cab ([campeon(c)| c <- competenciasConOroEnPodio(j)]);
	
	// Quiero ver: Pc -> I;
	// implica 1 <= i <= |competenciasConOroEnPodio|;
	// implica (∀c ∈ competenciasConOroEnPodio(j)[0..1)) añoNacimiento(a) >= añoNacimiento(campeon(c));
	// implica 1 <= i <= |competenciasConOroEnPodio| && esCampeon(a,j) 
		// && (∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c));
	// Luego, Pc -> I;

    while (i<j.competenciasFinalizadasConOroEnPodio().longitud()){
        // B: i < |competenciasConOroEnPodio(j)|
        // I: 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a,j) 
		//&& (∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c));

	// variante V: |competenciasConOroEnPodio(j)| - i;
	// cota C: 0;

	// Estado E1;
	// vale I && B;

        if (a.anioNacimiento() 
        	<= j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0).anioNacimiento() ){
            // Estado IF1;
			// vale i == i@E1 
				// && añoNacimiento(a@E1) <= añoNacimiento(campeon(competenciasConOroEnPodio(j)[i]));

            a = j.competenciasFinalizadasConOroEnPodio().iesimo(i).ranking().iesimo(0);
            // Estado G
			// vale i == i@E1 
				// && añoNacimiento(a@E1) <= añoNacimiento(campeon(competenciasConOroEnPodio(j)[i])) 
				// && a == campeon(competenciasConOroEnPodio(j)[i]);
        }

        // Estado E2;
        // vale G || H;
		// implica (añoNacimiento(a@E1) <= añoNacimiento(campeon(competenciasConOroEnPodio(j)[i])) 
		// && a == campeon(competenciasConOroEnPodio(j)[i])) 
			// || (añoNacimiento(a@E1) > añoNacimiento(campeon(competenciasConOroEnPodio(j)[i])) 
			// && a == a@E1);
        // implica añoNacimiento(a) > añoNacimiento(campeon(competenciasConOroEnPodio(j)[i]));
        // implica esCampeon(a,j);
        // implica (∀c ∈ competenciasConOroEnPodio(j)[0..i]) añoNacimiento(a) >= añoNacimiento(campeon(c))

        i++;

		// Estado E3;
		// vale i == i@E2 + 1 && esCampeon(a,j) 
			// && (∀c ∈ competenciasConOroEnPodio(j)[0..i@E2])
			// añoNacimiento(a) >= añoNacimiento(campeon(c));
		// implica 1 < i;
		// implica i == i@E2 + 1 < |competenciasConOroEnPodio(j)| + 1 <= |competenciasConOroEnPodio(j)|;
		// implica 1 <= i <= |competenciasConOroEnPodio(j)|;
		// implica i@E2 == i - 1;
		// implica (∀c ∈ competenciasConOroEnPodio(j)[0..i - 1]) 
			// añoNacimiento(a) >= añoNacimiento(campeon(c));
		// implica 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a) 
			// && (∀c ∈ competenciasConOroEnPodio[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c));
		
		// Luego, E3 -> I;
		// (El invariante se mantiene)
		//
		// Quiero ver que la función variante disminuye
		// vale V = |competenciasConOroEnPodio(j)| - i@E3;
		// implica V = |competenciasConOroEnPodio(j)| - (i@E1 + 1);
		// implica V = |competenciasConOroEnPodio(j)| - i@E1 - 1 <
			// |competenciasConOroEnPodio(j)| - i@E1 == V@E1;
		// luego, V@E3 < V@E1.
		
		// Quiero Ver: (I && (V <= C)) -> ¬B.
		// Si V <= C, entonces vale I && (V <= C);
		// implica 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a,j) 
			//&& ((∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c))) 
			// && (|competenciasConOroEnPodio(j)| - i <= 0);
			
		// implica |competenciasConOroEnPodio(j)| <= i;
		// implica i == |competenciasConOroEnPodio(j)|;
		// implica ¬(i < |competenciasConOroEnPodio(j)|);
		//
		// Luego, (I && (V <= C)) -> ¬B.
    }

    // vale Qc: i == |competenciasConOroEnPodio(j)| && esCampeon(a,j) 
    	// && (∀c ∈ competenciasConOroEnPodio(j)) añoNacimiento(a) >= añoNacimiento(campeon(c));
    	
    // Quiero Ver: (I && ¬B) -> Qc.
	// vale I && ¬B
	// implica 1 <= i <= |competenciasConOroEnPodio(j)| && esCampeon(a,j) 
		//&& ((∀c ∈ competenciasConOroEnPodio(j)[0..i)) añoNacimiento(a) >= añoNacimiento(campeon(c))) 
		// && ¬(i < |competenciasConOroEnPodio(j)|)
		
	// implica i >= |competenciasConOroEnPodio(j)|
	// implica i == |competenciasConOroEnPodio(j)|
	// implica (∀c ∈ competenciasConOroEnPodio(j)[0..|competenciasConOroEnPodio(j)|)) añoNacimiento(a) >= 
		// añoNacimiento(campeon(c))
	// implica (∀c ∈ competenciasConOroEnPodio(j)) añoNacimiento(a) >= añoNacimiento(campeon(c))
	// implica i == |competenciasConOroEnPodio(j)| && esCampeon(a,j) 
		// && (∀c ∈ competenciasConOroEnPodio(j)) añoNacimiento(a) >= añoNacimiento(campeon(c))
	// luego, (I && ¬B) -> Qc.

    return a;

	// vale      result == a
	// implica   esCampeon(result,j) 
		// && (∀c ∈ competenciasConOroEnPodio(j)) añoNacimiento(result) >= añoNacimiento(campeon(c))
}

int main()
{
    MenuPrincipal();

    return 0;
}


