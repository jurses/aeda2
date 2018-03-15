#include "maquina.hpp"

namespace AEDA{
	MaquinaV2::MaquinaV2(int altura, int anchura){
		rej_ = new Rejilla(altura, anchura);
		vHormigas_.clear();
	}

	MaquinaV2::~MaquinaV2(){
		delete rej_;
	}

	void MaquinaV2::cargarHormiga(Hormiga *h){
		assert(h);
		vHormigas_.push_back(h);
	}

	void MaquinaV2::cargarColores(std::istream &scolores){
		rej_->cargarColores(scolores);
	}

	void MaquinaV2::sigGen(void){
		for (int i = 0; i < vHormigas_.size(); i++){
			int colorR = rej_->obtIdColor(vHormigas_[i]->devPosI(), vHormigas_[i]->devPosJ());
			int pi = vHormigas_[i]->devPosI();
			int pj = vHormigas_[i]->devPosJ();
			rej_->ponColor(pi, pj, vHormigas_[i]->devColor(colorR));
			vHormigas_[i]->mover(colorR);
		}
	}

	std::string MaquinaV2::devHormiguero(void){
		std::string hormiguero;
		std::vector<std::string> pisos;
		pisos.resize(rej_->obtAltura());
		for (int i = 0; i < rej_->obtAltura(); i++){
			pisos[i].resize(rej_->obtAnchura());
			for (int j = 0; j < rej_->obtAnchura(); j++)
				pisos[i][j] = rej_->obtColor(i, j);
		}

		for (int h = 0; h < vHormigas_.size(); h++)
			pisos[vHormigas_[h]->devPosI()][vHormigas_[h]->devPosJ()] = vHormigas_[h]->dirHormiga();

		for (int i = 0; i < rej_->obtAltura(); i++){
			for (int j = 0; j < rej_->obtAnchura(); j++){
				hormiguero.push_back(pisos[i][j]);
				hormiguero.push_back(' ');
			}
			hormiguero.push_back('\n');
		}

		return hormiguero;
	}
}
