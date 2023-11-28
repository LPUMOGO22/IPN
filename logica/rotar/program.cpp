#include <iostream>
#include <string>
char rotar(int rotacion, char letra);

int main()
{
  std::string cadena;
  int cantRotar;
  std::cout << "Ingrese una cadena:\n" << std::endl;
  std::cin >> cadena ;
  std::cout << "Ingrese la cantidad de caracteres que desea rotar\n" << std::endl;
  std::cin >> cantRotar;
  for (char &caracter : cadena) {
    caracter = rotar(cantRotar, caracter);
  }
  std::cout << "La cadena rotada 1 posición es: "<< cadena << std::endl;
  return 0;
}

char rotar(int rotacion, char letra)
{
  int ultima = 0;
  bool enRango = false;
  if(letra >= 65 && letra <= 90)
  { //Mayuscula
      ultima = 90;
      enRango = true;
  }
  if(letra >= 97 && letra <= 122)
  { //Minuscula
    ultima = 122;
    enRango = true;
  }
  if (enRango){
      if(letra + rotacion > ultima){
        return (letra + rotacion) - 26;
      }
      return letra + rotacion;
  }
  return letra;
}
