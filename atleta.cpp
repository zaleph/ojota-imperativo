
#include <iostream>

#include "atleta.h"

Atleta::Atleta(){
}

Atleta::Atleta(const string nombre,const Sexo sexo, const int anio, const Pais pais, const int ciaNumber){
    _nombre = nombre;
    _sexo = sexo;
    _anioNacimiento = anio;
    _nacionalidad = pais;
    _ciaNumber = ciaNumber;
}

string Atleta::nombre() const{
    return _nombre;
}

Sexo Atleta::sexo() const{
    return _sexo;
}

int Atleta::anioNacimiento() const{
    return _anioNacimiento;
}

Pais Atleta::nacionalidad() const{
    return _nacionalidad;
}

int Atleta::ciaNumber() const{
    return _ciaNumber;
}

Lista<Deporte> Atleta::deportes() const{

    Lista<Deporte> deportesList = Lista<Deporte>();

    int i = 0;
    while(i<_deportes.longitud() ){
        deportesList.agregar(_deportes.iesimo(i).first);
        i++;
    }

    return deportesList;
}

int Atleta::capacidad(const Deporte d) const{
    int i = 0;
    while ( d != _deportes.iesimo(i).first) {
        i++;
    }
    return _deportes.iesimo(i).second;
}

void Atleta::entrenarNuevoDeporte(const Deporte deporte, const int capacidad){
    pair<Deporte,int> par = pair<Deporte,int>(deporte,capacidad);
    _deportes.agregar(par);
}

bool Atleta::operator==(const Atleta& a) const{

    return (nombre() == a.nombre() && sexo() == a.sexo() && anioNacimiento() == a.anioNacimiento()
        && nacionalidad() == a.nacionalidad() && ciaNumber() == a.ciaNumber() && _deportes == a._deportes);


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
