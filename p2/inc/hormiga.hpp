#ifndef HORMIGA_H
#define HORMIGA_H

#include <fstream>
#include <vector>
#include <cassert>

enum DIR{
	ARRIBA,		// 0
	DERECHA,	// 1
	ABAJO,		// 2
	IZQUIERDA,	// 3
	TDIR		// 4
};

typedef std::vector<std::vector<int>> reglas_t;

struct Pos{
	int i;
	int j;
};

namespace AEDA{
	class Maquina;
	class Hormiga{
		private:
			int direccion_;	
			struct Pos ph_;
			reglas_t regla_;
			void giro(int);
			void desp(int);

		public:
			Hormiga();
			Hormiga(const Hormiga&);
			void mover(int);
			int devPosI(void){ return ph_.i; }
			int devPosJ(void){ return ph_.j; }
			int devDir(void){ return direccion_; }
			void posicionar(int i, int j){ ph_.i = i; ph_.j = j; }
			const char dirHormiga(void);
			void cargarConfHormiga(std::istream &);
			int devColor(int);
	};
}

#endif	// HORMIGA_H
