#include <stdio.h>

int main(){
  int numero;
  char entrada[100]; // Almacenar la entrada como cadena

  do {
        printf("Ingresa un número entero: ");
        fgets(entrada, sizeof(entrada), stdin); // Leer como cadena
  } while (sscanf(entrada, "%d", &numero) != 1 || numero<0);

  if (numero%2==0){
    printf("El número es PAR\n");
  }
  else{
    printf("El número es IMPAR\n");
  }

  return 0;
}
