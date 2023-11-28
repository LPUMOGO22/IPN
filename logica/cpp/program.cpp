#include <iostream>

using namespace std;

int main() {
    int n;

    while (true) {
      cout << "Ingrese un numero entero para mostrar su tabla (o ingrese -3 para poder salir): ";
      cin >> n;

      if (n == -3) {
        break; 
      }

      for (int i = 1; i <= 10; i++) {
         cout << n << " x " << i << " = " << (n * i) << endl;
      }
    }

    return 0;
}
