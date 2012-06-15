
#include "test-jjoo.h"


int main(){

    //testCompetencia_lesTocoControlAntidoping();
    //testAtleta_capacidad();
    //testCompetencia_finalizada();
    //testCompetencia_leDioPositivo();
    //testCompetencia_sancionarTramposos();
    //testCompetencia_participantes();
    //testCompetencia_ranking();
    testCompetencia_gananLosMasCapaces();
    //testAtleta_deportes_y_entrenarDeportes();
    //testLazyAtleta();
    //testJJOO_nuevoJJOO();
    //testJJOO_competencias();
    //testJJOO_cronogramas();
    //testAtleta_igualdad();
    //testJJOO_operadorIgual();

    //testCompetencia_operadorIgual();

    string word1 = "tenis";
    string word2 = "futbol";
    string word3 = "rugby";
    string word4 = "jockey";

    cout << (word1 < word2) << endl;
    cout << (word2 < word3) << endl;
    cout << (word3 < word4) << endl;
    cout << (word4 < word1) << endl;


    return EXIT_SUCCESS;
}
