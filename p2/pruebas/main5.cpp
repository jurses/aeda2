#include <cstdio>

class Cuadrado{
	int w;
	int h;
	friend void foo(const Cuadrado &);
	protected:
		int x;
		int y;
	public:
		Cuadrado() : w(10), h(10){
			printf("Empieza cuadrado\n");
		}
};

//class Rectangulo : public Cuadrado{
//	public:
//		Rectangulo(): x(15), y(23){
//		}
//		void foo(void){
//			printf("%d, %d\n", x, y);
//		}
//
//};

class Rectangulo : public Cuadrado{
	public:
		Rectangulo(){
			x = 15;
			y = 23;
			printf("Empieza rectángulo\n");
		}
		void foo(void){
			x = 15;
			y = 23;
			printf("%d, %d\n", x, y);
		}
};

void foo(const Cuadrado &c){
	printf("%d, %d\n", c.w, c.h);
}

int main(void){
	Rectangulo r;
	r.foo();
}
