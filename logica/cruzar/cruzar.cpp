#include <iostream>

bool cruzar(bool var);
void menu();
void mostrar();
void repetir();
bool validar();

bool hombre = false; 
bool gallina = false;
bool maiz = false;
bool lobo = false;

int main () {

  mostrar();  
  menu();

  return 0;
}


bool cruzar(bool var){
  hombre = ! hombre; 
  return var = ! var;
  
}

void menu(){

  int opcion;
  bool valido;
  std::cout << "Hola! Seleccione la opcion deseada:" << std::endl;
  if (gallina == hombre){
    std::cout << "1. Para cruzar a la gallina" << std::endl;
  }
  if (maiz == hombre){
    std::cout << "2. Para cruzar el maíz" << std::endl;
  }
  if (lobo == hombre){
    std::cout << "3. Para cruzar al lobo" << std::endl;
  }
  std::cout << "4. Para cruzar solo al hombre" << std::endl;
  std::cin >> opcion;
  if (opcion == 1){
    gallina = cruzar(gallina);
  }
  if (opcion == 2){
    maiz = cruzar(maiz);
  }
  if (opcion == 3){
    lobo = cruzar(lobo);
  }
  if (opcion == 4){
    hombre = ! hombre;
  }
  if (!validar()){
    if (opcion == 1){
      gallina = cruzar(gallina);
    }
    if (opcion == 2){
      maiz = cruzar(maiz);
    }
    if (opcion == 3){
      lobo = cruzar(lobo);
    }
    if (opcion == 4){
     hombre = ! hombre;
    }
  }
  repetir();
}

void mostrar(){
  std::string izquierdo [4];
  std::string derecho [4];
  if (!hombre){
    izquierdo [0] = "Hombre";
    derecho [0] = "";
  }else{
    derecho [0] = "Hombre";
    izquierdo [0] = "";
  }
  if (!gallina){
    izquierdo [1] = "Gallina";
    derecho [1] = "";
  }
  else{
    derecho[1] = "Gallina";
    izquierdo[1] = "";
  }
  if (!maiz){
    izquierdo [2] = "Maíz";
    derecho [2] = "";
  }else{
    derecho[2] = "Maíz";
    izquierdo[2] = "";
  }
  if (!lobo){
    izquierdo[3] = "Lobo";
    derecho[3] = "";
  }else{
    derecho[3] = "Lobo";
    izquierdo[3] = "";
  }

  for (int i = 0; i<= 3; i++){
    std::cout << izquierdo[i] << "\t\t\t\t" << derecho[i] << std::endl;
  }
  std::cout << "\n\n\n" << std::endl;

}


void repetir(){
  for (int i = 0; i< 50; i++){
    std::cout << "\n" << std::endl;
  }
  mostrar();
  menu();

}

bool validar(){
   if(gallina == lobo && lobo != hombre){
    std::cin.get(); //Arreglar la pausa
    std::cout << "Cuidado, dejarás solos a la gallina y el lobo (PRESIONA ENTER PARA CONTINUAR)" << std::endl;
    std::cin.get(); //Arreglar la pausa
    return false;
  }
  if(gallina == maiz && maiz != hombre){
    std::cin.get(); //Arreglar la pausa
    std::cout << "Cuidado, dejarás solos a la gallina y el maíz (PRESIONA ENTER PARA CONTINUAR) " << std::endl;
    std::cin.get(); //Arreglar la pausa
    return false;
  }
  return true;
}
