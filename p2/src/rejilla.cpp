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
		anchura_(anchura),
		alturaOrig_(altura),
		anchuraOrig_(anchura)
	{
		matrizColores_.resize(altura_);
		for(int i = 0; i < altura_; i++)
			matrizColores_[i].resize(anchura_);
	}

	void Rejilla::filaArriba(void){
		std::vector<int> nVector;
		matrizColores_.insert(matrizColores_.begin(), nVector);
		++altura_;
		for (int j = 0; j < anchura_; j++)
			matrizColores_[0][j] = 0;
	}

	void Rejilla::filaAbajo(void){
		std::vector<int> nVector;
		matrizColores_.push_back(nVector);
		++altura_;
		for (int j = 0; j < anchura_; j++)
			matrizColores_[altura_ - 1][j] = 0;
	}

	void Rejilla::columIzda(void){
		for (int i = 0; i < altura_; i++)
			matrizColores_[i].insert(matrizColores_[i].begin(), 0);
		++anchura_;
	}

	void Rejilla::columDerc(void){
		for (int i = 0; i < altura_; i++)
			matrizColores_[i].push_back(0);
		++anchura_;
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

	void Rejilla::compLimite(int i, int j){
		if (altura_ < i)
			filaAbajo();
		else if (anchura_ < j)
			columDerc();
		else if (alturaOrig_ - altura_ > i)
			filaArriba();
		else if (anchuraOrig_ - anchura_ > j)
			columIzda();
	}

	char Rejilla::obtColor(int i, int j){
		int id = matrizColores_[i][j];
		for (conjCodColor_t::iterator it = colores_.begin(); it != colores_.end(); it++)
			if(it->first == id)
				return it->second;
		assert(false);
	}
}
