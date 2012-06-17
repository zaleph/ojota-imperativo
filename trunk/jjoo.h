#ifndef JJOO_H
#define JJOO_H

#include "competencia.h"

typedef pair<int, pair<int, int> > infoM;

class JJOO{
    public:

        int _jornadaActual;

        JJOO();
        // |cronograma|==cantDias. Si un día no hay competencias,q esté la lista vacía.
        JJOO(const int anio, const Lista<Atleta>& atletas, const Lista<Lista<Competencia> >& competenciasPorDia);

        int anio() const;
        Lista<Atleta> atletas() const;
        int cantDias() const;
        int jornadaActual() const;
        Lista<Competencia> cronograma(const int dia) const;

        Lista<Competencia> competencias() const;
        Lista<Competencia> competenciasFinalizadasConOroEnPodio() const;

        Lista<Atleta> dePaseo() const;
        Lista<pair<Pais,Lista<int> > > medallero() const;
        int boicotPorDisciplina(const Categoria cat, const Pais p);
        Lista<Atleta> losMasFracasados(const Pais p) const;
        void liuSong(const Atleta& a, const Pais p);
        Atleta stevenBradbury() const;

        bool uyOrdenadoAsiHayUnPatron() const;

        Lista<Pais> sequiaOlimpica() const;
        void transcurrirDia();

		bool operator==(const JJOO& j) const;

        void mostrar(std::ostream& os) const;
		void guardar(std::ostream& os) const;
		void cargar (std::istream& is);

    private:
        int _anio;
        Lista<Atleta> _atletas;
        Lista<Lista<Competencia> > _competenciasPorDia;         // En la i-ésima posición de la lista, las competencias del día i+1.
        //int _jornadaActual;
        enum {ENCABEZADO_ARCHIVO = 'J'};

        bool mismasCompetencias(Lista<Competencia> l1, Lista<Competencia> l2) const {
            bool iguales = (l1.longitud() == l2.longitud()) ;
            int i=0;
            while(i < l1.longitud() && iguales ){
                if( !l2.pertenece( l1.iesimo(i) ) || !l1.pertenece( l2.iesimo(i) ) )
                    iguales = false;
                i++;
            }
            return iguales;
        }

        bool mismasAtletas(Lista<Atleta> l1, Lista<Atleta> l2) const {
            bool iguales = (l1.longitud() == l2.longitud()) ;
            int i=0;
            while(i < l1.longitud() && iguales ){
                if( !l2.pertenece( l1.iesimo(i) ) || !l1.pertenece( l2.iesimo(i) ) )
                    iguales = false;
                i++;
            }
            return iguales;
        }


        Lista<Atleta> ganadoresDeCompetencias(Lista<Competencia> comps , int posicion) const{
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

        Lista<Pais> paisesUnicosDeAtletas(Lista<Atleta> atletas) const{
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

        Lista<int> diasConMedalla(Pais p) const{
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

        Lista<int> diferenciaEntreConsecutivos(Lista<int> enteros) const{
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

        int maximoEnteros(Lista<int> enteros) const {
            int max = 0;
            int i=0;
            while (i<enteros.longitud()){
                if (enteros.iesimo(i)>max){
                    max = enteros.iesimo(i);
                    i++;
                } else {
                    i++;
                }
            }
            return max;
        }

        int maxDiasSinMedalla() const{
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


        Lista<Atleta> medallistas(int posicion) const{
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

        Lista<Atleta> filtrarAtletasPorPais(Lista<Atleta> atls, Pais p) const{
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

        Lista<pair<Pais,Lista<int> > > agregarOrdenado(Lista<pair<Pais,Lista<int> > > l , pair<Pais,Lista<int> > par) const{
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

        Lista<int> capacidades (Lista<Atleta> atlets , Deporte sport) const{
            Lista<int> cap = Lista<int>();
            int i = 0;
            while (i<atlets.longitud()){
                Atleta a = atlets.iesimo(i);
                cap.agregarAtras(a.capacidad(sport));
                i++;
            }
            return cap;
        }

        bool ordenado (Lista<int> lista1 ) const{
            int i = 0;
            bool eval = true;
            while(i<lista1.longitud()-1 && eval){
                eval = lista1.iesimo(i) <= lista1.iesimo(i+1);
                i++;
            }
            return eval;
        }

        Lista<Atleta> atletasParticipantes () const{
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



};

std::ostream & operator<<(std::ostream & os,const JJOO & j);

#endif // JJOO_H
