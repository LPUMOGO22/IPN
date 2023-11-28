
#include <iostream>
using namespace std;

int main() {
    int numero;
    bool salir = true;

    while (salir) {
        cout << "Ingrese el número del que quiere imprimir la tabla o -3 para salir: ";
        cin >> numero;

        if (numero == -3) {
            cout << "Gracias!";
            salir = false;
        }
        else{
           cout << "Tabla de multiplicar de " << numero << ":" << endl;
           for (int i = 1; i <= 10; i++) {
              cout << numero << " x " << i << " = " << numero * i << endl;
           }
        }

    }

    return 0;
}
