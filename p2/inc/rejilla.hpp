#ifndef REJILLA_H
#define REJILLA_H

#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <set>
#include <cassert>

typedef std::vector<std::vector<int>> matriz_t;
typedef std::pair<int, char> codColor_t;
typedef std::set<codColor_t> conjCodColor_t; 

namespace AEDA{
	class Maquina;
	class Rejilla{
		private:
			matriz_t matrizColores_;
			int altura_;
			int anchura_;
			void redimAltura(int, int);
			void redimAnchura(int);
			void copiaRejilla(matriz_t); // copia la rejilla y la centra
			conjCodColor_t colores_;
		public:
			Rejilla();
			Rejilla(int, int);
			void cargarColores(std::istream &);
			int obtIdColor(int i, int j){ return matrizColores_[i][j]; }
			void ponColor(int i, int j, int c){ matrizColores_[i][j] = c; }
			void desplazamiento(int, int);
			int obtAltura(void){ return altura_; }
			int obtAnchura(void){ return anchura_; }
			char obtColor(int, int);
	};
}
#endif	// REJILLA_H
