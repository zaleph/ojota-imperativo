
#include <iostream>

#include "atleta.h"

Atleta::Atleta(){
}

Atleta::Atleta(const string nombre,const Sexo sexo, const int anio, const Pais pais, const int ciaNumber){
}

string Atleta::nombre() const{
    return "";
}

Sexo Atleta::sexo() const{
    return Masculino;
}

int Atleta::anioNacimiento() const{
    return 0;
}

Pais Atleta::nacionalidad() const{
    return "";
}

int Atleta::ciaNumber() const{
    return 0;
}

Lista<Deporte> Atleta::deportes() const{
    return Lista<Deporte>();
}

int Atleta::capacidad(const Deporte d) const{
    return 0;
}

void Atleta::entrenarNuevoDeporte(const Deporte deporte, const int capacidad){
}

bool Atleta::operator==(const Atleta& a) const{
    return true;
}

void Atleta::mostrar(std::ostream& os) const{
}

void Atleta::guardar(std::ostream& os) const{
}

void Atleta::cargar (std::istream& is){
}

std::ostream & operator<<(std::ostream & os,const Atleta & a){

    os << "Nombre: " << a.nombre() << endl
    << "Sexo: " << a.sexo() << endl
    << "CiaNumber: " << a.ciaNumber() << endl
    << "Año Nacimiento: " << a.anioNacimiento() << endl
    << "Deportes: " << a.deportes();

    return os;
}
