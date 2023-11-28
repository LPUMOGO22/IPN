#include <iostream>
#include <stdio.h>
#define MAX 5

char pila[MAX];
int i, j, cima = -1;
char op;

void apilar();
void desapilar();
void mostrar();

int main() {
    for (;;) {
        std::cout << "1. Apilar" << std::endl;
        std::cout << "2. Desapilar" << std::endl;
        std::cout << "3. Mostrar" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingresa la deseada Opcion: ";
        std::cin >> op;

        if (op == '1') {
            apilar();
        }
        if (op == '2') {
            desapilar();
        }
        if (op == '3') {
            mostrar();
        }
        if (op == '4') {
            std::cout << "Fin del programa" << std::endl;
            break;
        }
    }

    return 0;
}

void apilar() {
    if (cima == MAX - 1) {
        std::cout << "La pila esta llena" << std::endl;
    } else {
        std::cout << "Ingresa el dato: ";
        std::cin >> pila[cima + 1];
        cima++;
    }
}

void desapilar() {
    if (cima == -1) {
        std::cout << "La pila esta vacia" << std::endl;
    } else {
        std::cout << "El dato eliminado es: " << pila[cima] << std::endl;
        cima--;
    }
}

void mostrar() {
    if (cima == -1) {
        std::cout << "La pila esta vacia" << std::endl;
    } else {
        for (i = cima; i >= 0; i--) {
            std::cout << pila[i] << std::endl;
        }
    }
}
