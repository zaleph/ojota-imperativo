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
        Lista<Deporte> deportesNoOlimpicos() const;

        bool operator==(const JJOO& j) const;

        void mostrar(std::ostream& os) const;
		void guardar(std::ostream& os) const;
		void cargar (std::istream& is);

    private:
        int _anio;
        Lista<Atleta> _atletas;
        Lista<Lista<Competencia> > _competenciasPorDia;         // En la i-ésima posición de la lista, las competencias del día i+1.
        int _jornadaActual;
        enum {ENCABEZADO_ARCHIVO = 'J'};
        bool mismasCompetencias(Lista<Competencia> l1, Lista<Competencia> l2) const ;
        bool mismasAtletas(Lista<Atleta> l1, Lista<Atleta> l2) const ;
        Lista<Atleta> ganadoresDeCompetencias(Lista<Competencia> comps , int posicion) const;
        Lista<Pais> paisesUnicosDeAtletas(Lista<Atleta> atletas) const;
        Lista<int> diasConMedalla(Pais p) const;
        Lista<int> diferenciaEntreConsecutivos(Lista<int> enteros) const;
        int maximoEnteros(Lista<int> enteros) const;
        int maxDiasSinMedalla() const;
        Lista<Atleta> medallistas(int posicion) const;
        Lista<Atleta> filtrarAtletasPorPais(Lista<Atleta> atls, Pais p) const;
        Lista<pair<Pais,Lista<int> > > agregarOrdenado(Lista<pair<Pais,Lista<int> > > l , pair<Pais,Lista<int> > par) const;
        Lista<Atleta> agregarOrdenadoPorCapacidad(Lista<Atleta> l , Atleta a , Deporte d) const;
        //Lista<int> capacidades (Lista<Atleta> atlets , Deporte sport) const;
        //bool ordenado (Lista<int> lista1 ) const;
        Lista<Atleta> atletasParticipantesUnicos () const;
        Lista<Atleta> atletasParticipantes () const;
        Lista<Atleta> ultraParticipan (Lista<Atleta> ats) const;
        Lista<int> participacion (Lista<Atleta> ats) const;
        Lista<Atleta> medallistasDelJuego() const;
        Lista<Atleta> noGanaronMedallas(Lista<Atleta> ats) const;
        Pais obtegerElMejorPais(Lista<Pais> paises) const;
        Pais mejorPaisDeCompetencias(Lista<Competencia> comps) const;



};

std::ostream & operator<<(std::ostream & os,const JJOO & j);

#endif // JJOO_H
