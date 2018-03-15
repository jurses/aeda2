#ifndef MAQUINA_H
#define MAQUINA_H

#define BI2UNI (i, j, n) i * n + j

#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <utility>
#include <set>

#include "hormiga.hpp"
#include "rejilla.hpp"

namespace AEDA{
	typedef std::vector<Hormiga> ristraH_t;
	class Maquina{
		private:
			ristraH_t vHormigas_;
			Rejilla* rej_;

		public:
			Maquina(int, int);	// altura, anchura, i, j
			Maquina();
			~Maquina();
			void cargarHormigaF(std::istream &);	// insertar una nueva hormiga en i, j
			void cargarColores(std::istream &);
			void desplazamiento(int, int);	// desplazamiento por la rejilla (paralaje)
			virtual void sigGen(void);
			virtual std::string devHormiguero(void);
	};

	typedef std::vector<Hormiga *> ristraPH_t;
	class MaquinaV2 : public Maquina{
		private:
			ristraPH_t vHormigas_;
			Rejilla *rej_;

		public:
			MaquinaV2(int, int);	// altura, anchura, i, j
			virtual ~MaquinaV2();
			void cargarHormiga(Hormiga *);
			void cargarColores(std::istream &);	// pequeña duda... no se puede heredar
			void desplazamiento(int, int);	// desplazamiento por la rejilla (paralaje)
			void sigGen(void);
			std::string devHormiguero(void);
	};
}

#endif	// MAQUINA_H
