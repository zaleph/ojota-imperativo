#include <fstream>
#include <iostream>
#include "test-jjoo.h"

using namespace std;



Atleta cargar(){
    Atleta a = Atleta();

    string nombre;
    int anioNac;
    int ciaNumber;
    string sexo;
    Pais pais;
    string basura;

    ifstream archivo ("/home/gonzalo/salida.txt");

    archivo >> basura;
    archivo >> nombre;
    archivo >> sexo;
    archivo >> anioNac;
    archivo >> pais;
    archivo >> ciaNumber;

    archivo.close();


    nombre = nombre.substr(1 , nombre.length() - 2 );



    cout << nombre << " " << sexo << " "  << anioNac << " "  << pais << " "  << ciaNumber << endl;

    return a;

}

int main(){

    //testCompetencia_lesTocoControlAntidoping();
    //testAtleta_capacidad();
    //testCompetencia_finalizada();
    //testCompetencia_leDioPositivo();
    //testCompetencia_sancionarTramposos();
    //testCompetencia_participantes();
    //testCompetencia_ranking();
    //testCompetencia_gananLosMasCapaces();
    //testAtleta_deportes_y_entrenarDeportes();
    //testLazyAtleta();
    //testJJOO_nuevoJJOO();
    //testJJOO_JJOO();
    //testJJOO_competencias();
    //testJJOO_cronogramas();
    //testJJOO_cronogramaAll();
    //testAtleta_igualdad();
    //testJJOO_operadorIgual();
    //testCompetencia_operadorIgual();
    //testCompetencia_linfordChristi();
    //testAtleta_guardar();

    //testCompetencia_linfordChristi();

    //testAtleta_guardar();
    //testAtleta_cargar();

    return EXIT_SUCCESS;
}
