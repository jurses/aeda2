#include <stdio.h>
#include <stdarg.h>

void foo(int, ...);

int main(){
	foo(4, "Hola", "Adiós", "¿Qué tal?", "Pues bien");
}

void foo(int arg, ...){
	va_list vl;
	for(int i = 0; i < arg; i++){
		printf("%s, ", va_arg(vl, char *));
	}
}
