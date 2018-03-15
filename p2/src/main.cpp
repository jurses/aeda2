#include "maquina.hpp"
#include "hormiga.hpp"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

int main(int argc, char **argv){
	std::ifstream fColorConf;
	if (argc == 0){
		AEDA::Hormiga *h1, *h2;	// Declaración de puntero a hormiga
		AEDA::MaquinaV2 m1(20, 20);

		fColorConf.open("./conf/colores.conf", std::ifstream::in);
		m1.cargarColores(fColorConf);

		h1 = new AEDA::DDII(13, 6);	// nueva hormiga
		h2 = new AEDA::DDII(5, 8);	// nueva hormiga
		
		m1.cargarHormiga(h1);
		m1.cargarHormiga(h2);

		do{
			m1.sigGen();
			std::cout << m1.devHormiguero() << std::endl;
		}while (getchar() != 'q');


		fColorConf.close();
		delete h1;
	}
	else if (argc > 1){
		AEDA::MaquinaV2 *mp = nullptr;
		std::vector<AEDA::Hormiga *> vHormigas;
		for (int i = 1; i < argc; i++){
			switch (argv[i][1]){
				case 'm':	// -m alt  anch "fich"
							// ^i ^i+1 ^i+2 ^i+3
					mp = new AEDA::MaquinaV2(atoi(argv[i + 1]), atoi(argv[i + 2]));
					fColorConf.open(argv[i + 3], std::ifstream::in);
					assert(fColorConf.is_open());

					mp->cargarColores(fColorConf);
					i += 3;
				break;
				case 'a':	// a de ant
					while (argv[i + 1][0] != '-'){
						AEDA::Hormiga *h;
						if (strcmp("IDDI", argv[i + 1]) == 0){
							i++;
							h = new AEDA::IDDI(atoi(argv[i + 1]), atoi(argv[i + 2]));
							printf("%s, %s\n", argv[i + 1], argv[i+2]);
							i +=2 ;
						}
						else if (strcmp("DDII", argv[i + 1]) == 0){
							i++;
							h = new AEDA::DDII(atoi(argv[i + 1]), atoi(argv[i + 2]));
							printf("%s, %s\n", argv[i +1], argv[i+2]);
							i +=2 ;
						}
						else{
							fprintf(stderr, "La hormiga: `%s' no existe.\n", argv[i]);
							return 1;
						}
						vHormigas.push_back(h);
						if (i + 1 >= argc)
							break;
					}
				break;
				case 'h':
					printf("`-m <altura> <anchura> <confColores>', `-a <hormiga> <pos. i> <pos. j> ...'.\n");
					return 0;
				break;
				default:
					fprintf(stderr, "No reconozco la opción %s, i = %d.\n", argv[i], i);
					printf("`-m <altura> <anchura> <confColores.conf>', `-a <hormiga> <pos. i> <pos. j> ...'.\n");
					return 1;
			}
		}
		
		assert(mp);

		//llevamos las hormigas a la máquina
		for (int i = 0; i < vHormigas.size(); i++)
			mp->cargarHormiga(vHormigas[i]);

		do{
			mp->sigGen();
			std::cout << mp->devHormiguero() << std::endl;
		}while (getchar() != 'q');

		for (int i = 0; i < vHormigas.size(); i++)
			delete vHormigas[i];

		vHormigas.clear();
		delete mp;
	}
}
