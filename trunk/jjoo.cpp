#include <iostream>
#include "jjoo.h"


JJOO::JJOO(){
    _atletas = Lista<Atleta>();
    _competenciasPorDia = Lista<Lista<Competencia> >();
}


JJOO::JJOO(const int anio, const Lista<Atleta>& atletas, const Lista<Lista<Competencia> >& competenciasPorDia){
    _anio = anio;
    _atletas = atletas;
    _competenciasPorDia = competenciasPorDia;
    _jornadaActual = 1;
}


int JJOO::anio() const{
    return _anio;
}


Lista<Atleta> JJOO::atletas() const{
    return _atletas;
}


int JJOO::cantDias() const{
    return _competenciasPorDia.longitud();
}


int JJOO::jornadaActual() const{
    return _jornadaActual;
}


Lista<Competencia> JJOO::cronograma(const int dia) const{
    int indexDia = dia-1;
    return _competenciasPorDia.iesimo(indexDia);
}


Lista<Competencia> JJOO::competencias() const{
    Lista<Competencia> comps = Lista<Competencia>();
    int i = 0;
    while( i< _competenciasPorDia.longitud() ){
        comps.concatenar(_competenciasPorDia.iesimo(i));
        i++;
    }
    return comps;
}


Lista<Competencia> JJOO::competenciasFinalizadasConOroEnPodio() const{
    Lista<Competencia> comps = Lista<Competencia>();
    Lista<Competencia> compsConOro = Lista<Competencia>();

    comps = competencias();

    int i=0;
    while (i<comps.longitud()){
        Competencia comp = comps.iesimo(i);
        if(!comp.finalizada()){
            i++;
        }else if(comp.ranking().longitud()>0){
            compsConOro.agregarAtras(comp);
            i++;
        }else{
            i++;
        }
    }
    return compsConOro;
}


Lista<Atleta> JJOO::dePaseo() const{
    Lista<Atleta> paseadores = Lista<Atleta>();
    int i = 0;
    while (i<atletas().longitud()){
        Atleta at = atletas().iesimo(i);
        if (!atletasParticipantesUnicos().pertenece(at)){
            paseadores.agregarAtras(at);
        }
        i++;
    }
    return paseadores;
}


Lista<pair<Pais,Lista<int> > > JJOO::medallero() const{
    Lista<pair<Pais,Lista<int> > > medallasDePaises = Lista<pair<Pais,Lista<int> > >();
    Lista<Pais> paisesGanadores = Lista<Pais>();

    Lista<Atleta> orosDelJuego = medallistas(0);
    Lista<Atleta> platasDelJuego = medallistas(1);
    Lista<Atleta> broncesDelJuego = medallistas(2);

    Lista<Atleta> atletasGanadores = orosDelJuego;
    atletasGanadores.concatenar(platasDelJuego);
    atletasGanadores.concatenar(broncesDelJuego);

    paisesGanadores = paisesUnicosDeAtletas(atletasGanadores);

    int i=0;

    while (i<paisesGanadores.longitud()){
        Pais p = paisesGanadores.iesimo(i);
        int oros = filtrarAtletasPorPais(orosDelJuego,p).longitud();
        int platas = filtrarAtletasPorPais(platasDelJuego,p).longitud();
        int bronces = filtrarAtletasPorPais(broncesDelJuego,p).longitud();

        Lista<int> medalleroDelPais = Lista<int>();
        medalleroDelPais.agregarAtras(oros);
        medalleroDelPais.agregarAtras(platas);
        medalleroDelPais.agregarAtras(bronces);

        pair<Pais,Lista<int> > medallasDelPais = pair<Pais,Lista<int> >(p,medalleroDelPais);

        medallasDePaises = agregarOrdenado(medallasDePaises,medallasDelPais);
        i++;
    }
    return medallasDePaises;
}


int JJOO::boicotPorDisciplina(const Categoria cat, const Pais p){

    int sacados = 0;
    Lista<Atleta> atletasSacados = Lista<Atleta> ();

    Lista<Lista<Competencia> > nuevoCronograma = Lista<Lista<Competencia> > ();

    int dia = 1;
    while (dia<=cantDias()){
        Lista<Competencia> compsDelDiaOld = cronograma(dia);
        Lista<Competencia> compsDelDiaNew = Lista<Competencia>();

        int j = 0;

        while (j<compsDelDiaOld.longitud()){
            Competencia comp = compsDelDiaOld.iesimo(j);

            if (comp.categoria()==cat && paisesUnicosDeAtletas(comp.participantes()).pertenece(p)){
                Deporte d = comp.categoria().first;
                Sexo s = comp.categoria().second;
                Lista<Atleta> participantesNew = Lista<Atleta>();

                int f = 0;
                while (f<comp.participantes().longitud()){
                    Atleta a = comp.participantes().iesimo(f);
                    if (a.nacionalidad()!= p){
                        participantesNew.agregarAtras(a);
                    } else {
                        atletasSacados.agregarAtras(a);
                    }
                    f++;
                }

                Competencia newComp = Competencia(d,s,participantesNew);

                if(comp.finalizada()){
                    Lista<int> rankingNew = Lista <int>();
                    Lista<pair<int,bool> > controlAntidoping = Lista<pair<int,bool> >();

                    int n = 0;

                    while (n<comp.ranking().longitud()){
                        Atleta at = comp.ranking().iesimo(n);
                        if (!atletasSacados.pertenece(at)){
                            rankingNew.agregarAtras(at.ciaNumber());
                        }
                        n++;
                    }

                    int m = 0;

                    while (m<comp.lesTocoControlAntidoping().longitud()){
                        Atleta at2 = comp.lesTocoControlAntidoping().iesimo(m);
                        if (!atletasSacados.pertenece(at2)){
                            bool control = comp.leDioPositivo(at2);
                            pair<int,bool> par = pair<int,bool>(at2.ciaNumber(),control);
                            controlAntidoping.agregarAtras(par);
                        }
                        m++;
                    }
                    newComp.finalizar(rankingNew,controlAntidoping);
                }

                compsDelDiaNew.agregarAtras(newComp);
            } else {
                compsDelDiaNew.agregarAtras(comp);
            }
            j++;
        }

        nuevoCronograma.agregarAtras(compsDelDiaNew);
        dia++;
    }

    _competenciasPorDia = nuevoCronograma;

    sacados = atletasSacados.longitud();

    return sacados;
}


Lista<Atleta> JJOO::losMasFracasados(const Pais p) const{

    Lista<Atleta> noGanaronMedallasYUltraParticipan = Lista<Atleta>();


    if (paisesUnicosDeAtletas(atletas()).pertenece(p)){
        Lista<Atleta> atletasDelPais = filtrarAtletasPorPais(atletas(),p);
        Lista<Atleta> losMasParticipantes = ultraParticipan(atletasDelPais);

        noGanaronMedallasYUltraParticipan = noGanaronMedallas(losMasParticipantes);
    }
    return noGanaronMedallasYUltraParticipan;
}


void JJOO::liuSong(const Atleta& a, const Pais p){
    Atleta newAtleta = Atleta (a.nombre(),a.sexo(), a.anioNacimiento() , p , a.ciaNumber() );

    Lista<Deporte> deportesLiu = a.deportes();

    int k = 0;

    while (k<deportesLiu.longitud()){
        Deporte d = deportesLiu.iesimo(k);
        int c = a.capacidad(d);
        newAtleta.entrenarNuevoDeporte(d,c);
        k++;
    }

    Lista<Atleta> atletasOld = atletas();
    Lista<Atleta> atletasNew = Lista<Atleta>();

    int i = 0;
    while (i<atletasOld.longitud()){
        if (a == atletasOld.iesimo(i)){
            atletasNew.agregarAtras(newAtleta);
            i++;
        } else{
            atletasNew.agregarAtras(atletasOld.iesimo(i));
            i++;
        }
    }

    _atletas = atletasNew;


    Lista<Lista<Competencia> > nuevoCronograma = Lista<Lista<Competencia> > ();

    int dia = 1;
    while (dia<=cantDias()){
        Lista<Competencia> compsDelDiaOld = cronograma(dia);
        Lista<Competencia> compsDelDiaNew = Lista<Competencia>();

        int j = 0;

        while (j<compsDelDiaOld.longitud()){

            Competencia comp = compsDelDiaOld.iesimo(j);

            if (comp.participantes().pertenece(a)){
                Deporte d = comp.categoria().first;
                Sexo s = comp.categoria().second;
                Lista<Atleta> participantesNew = comp.participantes();
                participantesNew.sacar(a);
                participantesNew.agregarAtras(newAtleta);

                Competencia newComp = Competencia(d,s,participantesNew);

                if(comp.finalizada()){
                    Lista<int> rankingNew = Lista <int>();
                    Lista<pair<int,bool> > controlAntidoping = Lista<pair<int,bool> >();

                    int n = 0;

                    while (n<comp.ranking().longitud()){
                        Atleta at = comp.ranking().iesimo(n);
                        rankingNew.agregarAtras(at.ciaNumber());
                        n++;
                    }

                    int m = 0;

                    while (m<comp.lesTocoControlAntidoping().longitud()){
                        Atleta at2 = comp.lesTocoControlAntidoping().iesimo(m);
                        bool control = comp.leDioPositivo(at2);
                        pair<int,bool> par = pair<int,bool>(at2.ciaNumber(),control);
                        controlAntidoping.agregarAtras(par);
                        m++;
                    }
                    newComp.finalizar(rankingNew,controlAntidoping);
                }

                compsDelDiaNew.agregarAtras(newComp);

            } else {
                compsDelDiaNew.agregarAtras(comp);
            }
            j++;
        }

        nuevoCronograma.agregarAtras(compsDelDiaNew);
        dia++;
    }

    _competenciasPorDia = nuevoCronograma;
}


Atleta JJOO::stevenBradbury() const{

    int i = 0;

    Lista<Competencia> comps = competenciasFinalizadasConOroEnPodio();

    Atleta steven;
    int peorCapacidad = -1;

    while( i < comps.longitud() ){
        Competencia comp = comps.iesimo(i);
        Atleta atleta = comp.ranking().iesimo(0);

        if( atleta.capacidad( comp.categoria().first ) <= peorCapacidad
           || peorCapacidad == -1){
            peorCapacidad = atleta.capacidad( comp.categoria().first );
            steven = atleta;
        }

        i++;
    }

    return steven;
}


Pais JJOO::obtegerElMejorPais(Lista<Pais> paises ) const{

    int i=0;
    int cant= 0;
    Pais pais;
    while(i<paises.longitud()){

        if( paises.cantidadDeApariciones(paises.iesimo(i)) > cant){
            cant = paises.cantidadDeApariciones(paises.iesimo(i));
            pais = paises.iesimo(i);
        }else if( paises.cantidadDeApariciones(paises.iesimo(i)) >= cant){
            if( paises.iesimo(i) < pais )
                pais = paises.iesimo(i);
        }

        i++;
    }

    return pais;
}


Pais JJOO::mejorPaisDeCompetencias(Lista<Competencia> comps) const{

    Lista<Pais> paises = Lista<Pais>();
    int i=0;
    while(i < comps.longitud()){

        Competencia comp = comps.iesimo(i);
        Pais pais;
        if(comp.finalizada() && comp.ranking().longitud() >= 1){
            pais = comp.ranking().iesimo(0).nacionalidad();
            paises.agregarAtras(pais);
        }

        i++;
    }
    return obtegerElMejorPais(paises);
}


bool JJOO::uyOrdenadoAsiHayUnPatron() const{

    int dia = 1;
    Lista<Competencia> comps ;

    Lista<Pais> paises = Lista<Pais>();
    while(dia <= jornadaActual()){

        comps = cronograma(dia);

        if( comps.longitud() != 0){

            Pais p = mejorPaisDeCompetencias(comps);
            paises.agregarAtras(p);
        }

        dia++;
    }

    Lista<Pais> patron = Lista<Pais>();
    int i=0;
    bool patronFinalizado = false;
    while(i<paises.longitud() && !patronFinalizado){

        if(!patron.pertenece(paises.iesimo(i))){
            patron.agregarAtras(paises.iesimo(i));
        }else {
            patronFinalizado = true;
        }

        i++;
    }

    i=0;
    int patronIndex = 0;
    bool comparacionOk = true;
    while(i<paises.longitud() && comparacionOk){

        comparacionOk = comparacionOk && (paises.iesimo(i) == patron.iesimo(patronIndex));

        i++;
        patronIndex++;

        if(patronIndex == patron.longitud())
            patronIndex = 0;
    }


    return comparacionOk;
}


Lista<Pais> JJOO::sequiaOlimpica() const{
    Lista<Pais> secosOlimpicos = Lista<Pais>();
    Lista<Pais> paisesDelJuego = paisesUnicosDeAtletas(atletas());

    int maxSequiaJuegos = maxDiasSinMedalla();

    int i = 0;

    while (i<paisesDelJuego.longitud()){
        Pais p = paisesDelJuego.iesimo(i);
        Lista<int> diasBuenos = diasConMedalla(p);
        int maxSequiaDelPais = maximoEnteros(diferenciaEntreConsecutivos(diasBuenos));

        if(maxSequiaDelPais == maxSequiaJuegos){
            secosOlimpicos.agregarAtras(p);
            i++;
        } else {
            i++;
        }
    }
    return secosOlimpicos;
}


void JJOO::transcurrirDia(){
    Lista<Competencia> comps = cronograma(jornadaActual());
    Lista<Lista<Competencia> > nuevoCronograma = Lista<Lista<Competencia> > ();
    Lista<Competencia> nuevoDiaActual = Lista<Competencia>();


    int i = 0;
    while (i<comps.longitud()){

        Competencia comp = comps.iesimo(i);

        if (!comp.finalizada()){

            Categoria cat = comp.categoria();

            Deporte d = cat.first;

            Lista <Atleta> posiciones = Lista<Atleta>();
            Lista <int> posicionesPorCia = Lista <int>();
            Lista<pair<int,bool> > controlAntidoping = Lista<pair<int,bool> >();
            pair<int, bool> par = pair<int, bool>();

            int j = 0;
            while (j<comp.participantes().longitud()){
                //ordeno de mayor capacidad a menor capacidad
                posiciones = agregarOrdenadoPorCapacidad(posiciones,comp.participantes().iesimo(j),d) ;
                j++;
            }

            int k = 0;
            while (k<posiciones.longitud()){
                posicionesPorCia.agregarAtras(posiciones.iesimo(k).ciaNumber());
                k++;
            }

            if (posicionesPorCia.longitud()>=1){
                par = make_pair(posicionesPorCia.cabeza() , false);
                controlAntidoping.agregarAtras(par);
            }

            comp.finalizar(posicionesPorCia , controlAntidoping);
            nuevoDiaActual.agregarAtras(comp);
        } else {
            nuevoDiaActual.agregarAtras(comp);
        }
        i++;
    }

    int dia = 1;

    while (dia<=cantDias()){
        if (dia!=jornadaActual()){
            nuevoCronograma.agregarAtras(cronograma(dia));
        } else {
            nuevoCronograma.agregarAtras(nuevoDiaActual);
        }
        dia++;
    }
    _competenciasPorDia = nuevoCronograma;
    _jornadaActual = _jornadaActual+1;
}


bool JJOO::operator==(const JJOO& j) const{

    bool result = j.anio() == anio() && j.cantDias() == cantDias() && j.jornadaActual() == jornadaActual()
        && mismasAtletas(j.atletas() , atletas()) ;

    if(result){
        int i=1;
        while( i <= cantDias() && result ){
            result = result & mismasCompetencias(j.cronograma(i) , cronograma(i));
            i++;
        }
    }

    return result;
}


void JJOO::mostrar(std::ostream& os) const {
    os << "Año: " << anio() << endl
    << "Atletas: " << atletas() << endl
    << "Cantidad de días: " << cantDias() << endl
    << "Jornada actual: " << jornadaActual();
}


void JJOO::guardar(std::ostream& os) const {

    os << (char) ENCABEZADO_ARCHIVO << " " << anio() << " " << jornadaActual() << " ";

    os << "[";
    int i=0; while(i < atletas().longitud()){
        Atleta a = atletas().iesimo(i);
        os << "(";
        a.guardar(os);
        os << ")";
        i++;

        if( i != atletas().longitud())
            os << ", ";
    }
    os << "] ";

    os << "[";
    i=1;
    while(i <= cantDias()){
        os << "[";
        Lista<Competencia> comps = cronograma(i);
        int j=0; while( j <comps.longitud()){
            Competencia c = comps.iesimo(j);
            os << "(";
            c.guardar(os);
            os << ")";
            j++;
            if( j != comps.longitud())
                os << ", ";
        }
        os << "]";
        i++;
        if(i <= cantDias())
            os << ", ";
    }
    os << "]";

    /**/
}


void JJOO::cargar (std::istream& is) {
    char dummy;
    string temp;
    //buscamos el J
    is >> dummy;

    is >> _anio;
    is >> _jornadaActual;

    //buscamos los atletas...
    //buscamos el "["
    is >> dummy;

    if(is.peek() != ']'){
        //inicializamos con basura
        dummy = is.peek();
        Atleta a;
        while( dummy != ']'){

            //buscamos el "("
            is >> dummy;
            a = Atleta();
            a.cargar(is);

            //buscamos el ")"
            is >> dummy;
            _atletas.agregarAtras(a);

            //buscamos el "," o "]"
            is >> dummy;
        }
    }else{
        getline(is , temp, ']' );
    }

    //buscamos el cronograma ...
    //buscamos el "["
    is >> dummy;

    while(dummy != ']'){

        Lista<Competencia> comps = Lista<Competencia>();

        //buscamos el "["
        is >> dummy;

        //cout << "leyendo lista de competencias" << endl;

        //si la lista de competencias no esta vacia
        if(is.peek() != ']'){

            while( dummy != ']'){

                //buscamos el "("
                is >> dummy;

                Competencia comp = Competencia();
                comp.cargar(is);
                comps.agregarAtras(comp);

                //cout << "agregando competencia" << endl;

                //buscamos el ")"
                is >> dummy;

                //buscamos el "," o "]"
                is >> dummy;
            }
        }else{
            //si la lista de competencias esta vacia leemos el corchete del buffer
            getline(is , temp, ']' );
        }

        _competenciasPorDia.agregarAtras(comps);

        //cout << "agregando lista de competencias " << endl;

        //buscamos el "]"
        is >> dummy;

        //buscamos el "]" o ","
        is >> dummy;
    }


}


std::ostream & operator<<(std::ostream & os,const JJOO & j){
    j.mostrar(os);
    return os;
}


bool JJOO::mismasCompetencias(Lista<Competencia> l1, Lista<Competencia> l2) const {
    bool iguales = (l1.longitud() == l2.longitud()) ;
    int i=0;
    while(i < l1.longitud() && iguales ){
        if( !l2.pertenece( l1.iesimo(i) ) || !l1.pertenece( l2.iesimo(i) ) )
            iguales = false;
        i++;
    }
    return iguales;
}


bool JJOO::mismasAtletas(Lista<Atleta> l1, Lista<Atleta> l2) const {
    bool iguales = (l1.longitud() == l2.longitud()) ;
    int i=0;
    while(i < l1.longitud() && iguales ){
        if( !l2.pertenece( l1.iesimo(i) ) || !l1.pertenece( l2.iesimo(i) ) )
            iguales = false;
        i++;
    }
    return iguales;
}


Lista<Atleta> JJOO::ganadoresDeCompetencias(Lista<Competencia> comps , int posicion) const{
    Lista<Atleta> atletas = Lista<Atleta>();
    int i = 0;
    while(i<comps.longitud()){
        Competencia compIesima = comps.iesimo(i);
        if ( compIesima.finalizada()){
            if ( (compIesima.ranking().longitud() >= 1 && posicion<1) || (compIesima.ranking().longitud() >= 2 && posicion<2) || (compIesima.ranking().longitud() >= 3 && posicion<3) ){
                atletas.agregarAtras((comps.iesimo(i)).ranking().iesimo(posicion));
            }
            i++;
        } else {
            i++;
        }
    }
    return atletas;
}


Lista<Pais> JJOO::paisesUnicosDeAtletas(Lista<Atleta> atletas) const{
    Lista<Pais> nacionalidades = Lista<Pais>();
    int i = 0;
    while (i<atletas.longitud()){
        Atleta a1 = atletas.iesimo(i);
        if (!nacionalidades.pertenece( a1.nacionalidad() ) ){
            nacionalidades.agregarAtras(a1.nacionalidad());
            i++;
        } else {
            i++;
        }
    }
    return nacionalidades;
}


Lista<int> JJOO::diasConMedalla(Pais p) const{
    Lista<int> diasQueGanoMedalla = Lista<int>();
    diasQueGanoMedalla.agregarAtras(0);
    int dia = 1;
    while (dia<jornadaActual()){
        Lista<Competencia> comps = cronograma(dia);
        Lista<Atleta> ganadoresDelDia = ganadoresDeCompetencias(comps,0);
        ganadoresDelDia.concatenar(ganadoresDeCompetencias(comps,1));
        ganadoresDelDia.concatenar(ganadoresDeCompetencias(comps,2));

        if(paisesUnicosDeAtletas(ganadoresDelDia).pertenece(p)){
            diasQueGanoMedalla.agregarAtras(dia);
            dia++;
        } else {
            dia++;
        }
    }
    diasQueGanoMedalla.agregarAtras(jornadaActual());
    return diasQueGanoMedalla;
}


Lista<int> JJOO::diferenciaEntreConsecutivos(Lista<int> enteros) const{
    Lista<int> diffs = Lista<int>();
    int i = enteros.longitud();
    while (i>0){
        int valor1 = enteros.iesimo(i);
        int valor2 = enteros.iesimo(i-1);
        int valor3 = valor1-valor2;
        diffs.agregarAtras(valor3);
        i--;
    }
    return diffs;
}


int JJOO::maximoEnteros(Lista<int> enteros) const {
    int max = 0;
    int i=0;
    while (i<enteros.longitud()){
        if (enteros.iesimo(i)>=max){
            max = enteros.iesimo(i);
            i++;
        } else {
            i++;
        }
    }
    return max;
}


int JJOO::maxDiasSinMedalla() const{
    Lista<int> maxSequiaPorPais = Lista<int>();
    Lista<Pais> paises = paisesUnicosDeAtletas(atletas());
    int max = 0;
    int i=0;
    while(i<paises.longitud()){
        Pais p = paises.iesimo(i);
        Lista<int> diasBuenos = diasConMedalla(p);
        int maxSequiaDelPais = maximoEnteros(diferenciaEntreConsecutivos(diasBuenos));
        maxSequiaPorPais.agregarAtras(maxSequiaDelPais);
        i++;
    }
    max = maximoEnteros(maxSequiaPorPais);
    return max;
}


Lista<Atleta> JJOO::medallistas(int posicion) const{
    Lista<Atleta> capos = Lista<Atleta>();
    int dia=1;
    while (dia<=jornadaActual()){
        Lista<Competencia> comps = Lista<Competencia>();
        comps = cronograma(dia);
        Lista<Atleta> ganadoresDelDia = ganadoresDeCompetencias(comps,posicion);
        capos.concatenar(ganadoresDelDia);
        dia++;
    }
    return capos;
}


Lista<Atleta> JJOO::filtrarAtletasPorPais(Lista<Atleta> atls, Pais p) const{
    Lista<Atleta> atletaFiltrada = Lista<Atleta>();
    int i = 0;
    while (i<atls.longitud()){
        Atleta a = atls.iesimo(i);
        if(a.nacionalidad()==p){
            atletaFiltrada.agregarAtras(a);
            i++;
        } else {
            i++;
        }
    }
    return atletaFiltrada;
}


Lista<pair<Pais,Lista<int> > > JJOO::agregarOrdenado(Lista<pair<Pais,Lista<int> > > l , pair<Pais,Lista<int> > par) const{
    Lista<pair<Pais,Lista<int> > > listadoOrdenado = Lista<pair<Pais,Lista<int> > >();

    if (l.longitud()==0){
        listadoOrdenado.agregarAtras(par);
    } else {
        while( (l.longitud()!=0) && ( (l.cabeza().second.iesimo(0)>par.second.iesimo(0) ) || (l.cabeza().second.iesimo(0)==par.second.iesimo(0) && l.cabeza().second.iesimo(1)>par.second.iesimo(1) ) || (l.cabeza().second.iesimo(0)==par.second.iesimo(0) && l.cabeza().second.iesimo(1)==par.second.iesimo(1) && l.cabeza().second.iesimo(2)>=par.second.iesimo(2) ))){
            listadoOrdenado.agregarAtras(l.cabeza());
            l.eliminarPosicion(0);
        }
        listadoOrdenado.agregarAtras(par);
        listadoOrdenado.concatenar(l);
    }
    return listadoOrdenado;
}



Lista<Atleta> JJOO::agregarOrdenadoPorCapacidad(Lista<Atleta> l , Atleta a , Deporte d) const{
    Lista<Atleta> listadoOrdenado = Lista<Atleta>();

    if (l.longitud()==0){
        listadoOrdenado.agregarAtras(a);
    } else {
        while( l.longitud() != 0 && l.cabeza().capacidad(d) > a.capacidad(d)){
            listadoOrdenado.agregarAtras(l.cabeza());
            l.eliminarPosicion(0);
        }
        listadoOrdenado.agregarAtras(a);
        listadoOrdenado.concatenar(l);
    }
    return listadoOrdenado;
}


/*
Lista<int> JJOO::capacidades (Lista<Atleta> atlets , Deporte sport) const{
    Lista<int> cap = Lista<int>();
    int i = 0;
    while (i<atlets.longitud()){
        Atleta a = atlets.iesimo(i);
        cap.agregarAtras(a.capacidad(sport));
        i++;
    }
    return cap;
}
*/

/*
 bool JJOO::ordenado (Lista<int> lista1 ) const{
    int i = 0;
    bool eval = true;
    while(i<lista1.longitud()-1 && eval){
        eval = lista1.iesimo(i) <= lista1.iesimo(i+1);
        i++;
    }
    return eval;
}
*/


Lista<Atleta> JJOO::atletasParticipantesUnicos () const{
    Lista<Atleta> ats = Lista<Atleta>();
    Lista<Competencia> comps = competencias();
    int i=0;
    while (i<comps.longitud()){
        Competencia comp = comps.iesimo(i);

        int j=0;
        while (j<comp.participantes().longitud()){
            Atleta a = comp.participantes().iesimo(j);
            if (!ats.pertenece(a)){
                ats.agregarAtras(a);
            }
            j++;
        }
        i++;
    }
    return ats;
}


Lista<Atleta> JJOO::atletasParticipantes () const{
    Lista<Atleta> ats = Lista<Atleta>();
    Lista<Competencia> comps = competencias();
    int i=0;
    while (i<comps.longitud()){
        Competencia comp = comps.iesimo(i);
        ats.concatenar(comp.participantes());
        i++;
    }
    return ats;
}


Lista<Atleta> JJOO::ultraParticipan (Lista<Atleta> ats) const {

    int maxParticipacion = maximoEnteros(participacion(ats));
    Lista<Atleta> ultraParticipantes = Lista<Atleta>();
    int i = 0;
    while(i<ats.longitud()){
        Atleta a = ats.iesimo(i);
        if (atletasParticipantes().cantidadDeApariciones(a)==maxParticipacion){
            ultraParticipantes.agregarAtras(a);
        }
        i++;
    }
    return ultraParticipantes;
}


Lista<int> JJOO::participacion (Lista<Atleta> ats) const {
    Lista<int> apariciones = Lista<int>();

    int i = 0;
    while (i<ats.longitud()){
        Atleta a = ats.iesimo(i);
        int ap = atletasParticipantes().cantidadDeApariciones(a);
        apariciones.agregarAtras(ap);
        i++;
    }
    return apariciones;
}


Lista<Atleta> JJOO::medallistasDelJuego() const{
    Lista <Atleta> ats = Lista<Atleta>();
    int i = 0;
    while (i<competencias().longitud()){
        Competencia comp = competencias().iesimo(i);

        if (comp.finalizada()&&comp.ranking().longitud()>=1){
            ats.agregarAtras(comp.ranking().iesimo(0));

            if (comp.ranking().longitud()>=2){
                ats.agregarAtras(comp.ranking().iesimo(1));

                if (comp.ranking().longitud()>=3){
                    ats.agregarAtras(comp.ranking().iesimo(2));
                }
            }
        }
        i++;
    }
    return ats;
}


Lista<Atleta> JJOO::noGanaronMedallas(Lista<Atleta> ats) const{
    Lista<Atleta> atsRes = Lista<Atleta>();
    int i=0;
    while (i<ats.longitud()){
        Atleta a = ats.iesimo(i);
        if (!medallistasDelJuego().pertenece(a)){
            atsRes.agregarAtras(a);
        }
        i++;
    }
    return atsRes;
}


Lista<Deporte> JJOO::deportesQuePractican() const {
    Lista<Deporte> deps = Lista<Deporte>();
    int i = 0;
    while (i<atletas().longitud()){
        Atleta a = atletas().iesimo(i);
        int j = 0;
        while (j<a.deportes().longitud()){
            if (!deps.pertenece(a.deportes().iesimo(j))){
                deps.agregarAtras(a.deportes().iesimo(j));
            }
            j++;
        }
        i++;
    }
    return deps;
}

Lista<Deporte> JJOO::deportesNoOlimpicos() const{

    Lista<Deporte> deps = deportesQuePractican();

    int k=0;
    while (k<competencias().longitud()){
        Competencia comp = competencias().iesimo(k);
        Categoria cat = comp.categoria();

        if (deps.pertenece(cat.first)){
            deps.sacar(cat.first);
        }
        k++;
    }

    return deps;
}
