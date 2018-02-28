#include "hormiga.hpp"

namespace AEDA{
	Hormiga::Hormiga():
		direccion_(ABAJO)
	{
	}

	Hormiga::Hormiga(const Hormiga &h){
		direccion_ = h.direccion_;
		ph_ = h.ph_;
		regla_ = h.regla_;
	}
	// REHACER
	void Hormiga::cargarConfHormiga(std::istream& fis){
		fis >> ph_.i;
		fis >> ph_.j;
		--ph_.i;
		--ph_.j;
		int nReglas;
		fis >> nReglas;
		regla_.resize(nReglas);
		for (int i = 0; i < nReglas; i++){
			int pasos;
			fis >> pasos;
			regla_[i].resize(2 * pasos + 2);
			for (int j = 0; j < regla_[i].size(); j++)
				fis >> regla_[i][j];
		}
	}

	int Hormiga::devColor(int color){
		for (int i = 0; i < regla_.size(); i++)
			if (regla_[i][0] == color)
				return regla_[i][1];
	}

	// REHACER
	void Hormiga::mover(int color){
		for (int i = 0; i < regla_.size(); i++)
			if (regla_[i][0] == color){	// comprobamos el color
				for (int j = 0; j < regla_[i].size()/4; j += 2){
					giro(regla_[i][j + 2]);
					desp(regla_[i][j + 3]);
				}
			}
	}

	const char Hormiga::dirHormiga(void){
		switch (direccion_){
			case ARRIBA:
				return '^';
			case DERECHA:
				return '>';
			case ABAJO:
				return 'v';
			case IZQUIERDA:
				return '<';
			default:
				assert(false);
		}
	}

	void Hormiga::giro(int g){
		direccion_ = (direccion_ + g) % TDIR;
		if (direccion_ == -1)
			direccion_ = IZQUIERDA;
	}

	void Hormiga::desp(int d){
		switch (direccion_){
			case ARRIBA:
			ph_.i -= d;
			break;
			case DERECHA:
			ph_.j += d;
			break;
			case ABAJO:
			ph_.i += d;
			break;
			case IZQUIERDA:
			ph_.j -= d;
			break;
		}
	}
}
