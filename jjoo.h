#ifndef JJOO_H
#define JJOO_H

#include "competencia.h"

typedef pair<int, pair<int, int> > infoM;

class JJOO{
    public:

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
        int _jornadaActual;
        Lista<Lista<Competencia> > _competenciasPorDia;         // En la i-ésima posición de la lista, las competencias del día i+1.

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


        Lista<Atleta> ganadoresDeCompetencias(Lista<Competencia> comps , int posicion){
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
};

std::ostream & operator<<(std::ostream & os,const JJOO & j);

#endif // JJOO_H
