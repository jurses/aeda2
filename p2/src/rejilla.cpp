#include "rejilla.hpp"

namespace AEDA{
	Rejilla::Rejilla():
		altura_(30),
		anchura_(30)
	{
		matrizColores_.resize(altura_);
		for(int i = 0; i < altura_; i++)
			matrizColores_[i].resize(anchura_);
	}

	Rejilla::Rejilla(int altura, int anchura):
		altura_(altura),
		anchura_(anchura)
	{
		matrizColores_.resize(altura_);
		for(int i = 0; i < altura_; i++)
			matrizColores_[i].resize(anchura_);
	}

	void Rejilla::redimAltura(int nuevaAltura, int nuevaAnchura){
		matriz_t mcopia = matrizColores_;
		matrizColores_.resize(nuevaAltura);
		altura_ = nuevaAltura;
		for(int i = 0; i < altura_; i++)
			matrizColores_[i].resize(nuevaAnchura);
		anchura_ = nuevaAnchura;
		copiaRejilla(mcopia);
	}

	void Rejilla::cargarColores(std::istream &scolores){
		int n;
		char c;
		codColor_t aux;
		while (!scolores.eof()){
			scolores >> n;
			scolores >> c;
			aux.first = n;
			aux.second = c;
			colores_.insert(aux);
		}
	}

	void Rejilla::copiaRejilla(matriz_t m1){
		for (int i = 0; i < m1.size(); i++)
			for (int j = 0; j < m1[i].size(); j++){
				int ir = i + (matrizColores_.size() - m1.size()) / 2;
				int jr = j + (matrizColores_[ir].size() - m1[i].size())/ 2;
				matrizColores_[ir][jr] = m1[i][j];
			}
	}

	void Rejilla::redimAnchura(int anchura){
		matriz_t mcopia = matrizColores_;
		for(int i = 0; i < altura_; i++)
			matrizColores_[i].resize(anchura);
		anchura_ = anchura;
		copiaRejilla(mcopia);
	}

	char Rejilla::obtColor(int i, int j){
		int id = matrizColores_[i][j];
		for (conjCodColor_t::iterator it = colores_.begin(); it != colores_.end(); it++)
			if(it->first == id)
				return it->second;
		assert(false);
	}
}
