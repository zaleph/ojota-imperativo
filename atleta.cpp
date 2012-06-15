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
    _deportes = Lista<pair<Deporte , int> >();
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
    //Lista<Deporte> deportesList;
    int i = 0;
    while(i<_deportes.longitud() ){
        deportesList.agregarAtras(_deportes.iesimo(i).first);
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
    Lista<pair<Deporte, int> > nuevaLista = Lista<pair<Deporte , int > > ();

    if(_deportes.longitud()==0){
        _deportes.agregar(par);
    } else{
        if(!deportes().pertenece(deporte)){
            //string d1 = _deportes.cabeza().first;
            //string d2 = deporte;
            //while (_deportes.longitud() != 0 && d1<d2){
            while (_deportes.longitud() != 0 && _deportes.cabeza().first<deporte){
                nuevaLista.agregarAtras(_deportes.cabeza());
                _deportes.eliminarPosicion(0);
               // if (_deportes.longitud() != 0){
               //     d1 = _deportes.cabeza().first;
               // }
            }
            nuevaLista.agregarAtras(par);
            nuevaLista.concatenar(_deportes);
            _deportes = nuevaLista;
        } else {
            while (_deportes.longitud()!= 0 && _deportes.cabeza().first!=deporte){
                nuevaLista.agregarAtras(_deportes.cabeza());
                _deportes.eliminarPosicion(0);
            }
            _deportes.eliminarPosicion(0);
            nuevaLista.agregarAtras(par);
            nuevaLista.concatenar(_deportes);
            _deportes = nuevaLista;
        }
    }
}


bool Atleta::operator==(const Atleta& a) const{
    return (nombre() == a.nombre() && sexo() == a.sexo() && anioNacimiento() == a.anioNacimiento()
        && nacionalidad() == a.nacionalidad() && ciaNumber() == a.ciaNumber() && _deportes == a._deportes);
}


void Atleta::mostrar(std::ostream& os) const{
}


void Atleta::guardar(std::ostream& o) const{
    o << "A |" << nombre() << "| |" << ( sexo() ? "Masculino" : "Femenino")  << "| "
    << anioNacimiento() << " |" << nacionalidad() << "| " << ciaNumber() <<  " " << "[ ";

    /*
     * Se imprimen los deportes de los atletas
     */
     int i=0; while(i<deportes().longitud() ){
        Deporte d = deportes().iesimo(i);
        int c = capacidad(d);
        o << "( |" <<  d << "| , " << c << ")" ;
        i++;
        if(i != deportes().longitud()){
            o << " , ";
        }
    }
    o << " ]" << endl;
}


void Atleta::cargar (std::istream& is){

    string temp;
    is >> temp;

    is >> temp;
    _nombre = temp.substr(1 , temp.length() - 2 );

    is >> temp;
    _sexo = temp.compare("|Masculino|") ? Masculino : Femenino ;

    is >> _anioNacimiento;
    is >> _nacionalidad;
    is >> _ciaNumber;

}


std::ostream & operator<<(std::ostream & os,const Atleta & a){
    os << "Nombre: " << a.nombre() << endl
    << "Sexo: " << a.sexo() << endl
    << "CiaNumber: " << a.ciaNumber() << endl
    << "Año Nacimiento: " << a.anioNacimiento() << endl
    << "Deportes: " << a.deportes();
    return os;
}

