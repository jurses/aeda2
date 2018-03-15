#include "hormiga.hpp"

namespace AEDA{
	DDII::DDII(int i, int j){
		direccion_ = ARRIBA;
		ph_.i = i;
		ph_.j = j;
	}

	void DDII::mover(int color){
		switch (color){
			case 0:
				giro(1);
				desp(1);
			break;
			case 1:
				giro(1);
				desp(1);
			break;
			case 2:
				giro(-1);
				desp(1);
			break;
			case 3:
				giro(-1);
				desp(1);
			break;
			default:
				assert(false);
		}
	}

	int DDII::devColor(int color){
		return (color + 1) % 4;
	}
}
