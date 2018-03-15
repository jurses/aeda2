#ifndef MAQUINAV2_H
#define MAQUINAV2_H

#define BI2UNI (i, j, n) i * n + j

#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <utility>
#include <set>
#include <cassert>

#include "maquina.hpp"

namespace AEDA{
	typedef std::vector<Hormiga *> ristraPH_t;
	class MaquinaV2 : public Maquina{
		private:
			ristraPH_t vHormigas_;
			Rejilla *rej_;

		public:
			MaquinaV2(int, int);	// altura, anchura, i, j
			~MaquinaV2();
			void cargarHormiga(Hormiga *);
			void cargarColores(std::istream &);
			void desplazamiento(int, int);	// desplazamiento por la rejilla (paralaje)
			void sigGen(void);
			std::string devHormiguero(void);
	};
}

#endif	// MAQUINAV2_H
