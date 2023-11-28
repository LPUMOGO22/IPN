#include <iostream>
using namespace std;

char primeraLetra(string apellido_paterno); 
bool esVocal(char letra);
string obtenerUltimosDosCaracteres(string texto);
char primeraVocalIgnorandoPrimeraLetra(string texto);
string getRFC(string nombre, string apellidoPaterno, string apellidoMaterno, string anno, string mes, string dia);

int main() {

    string nombre, apellidoPaterno, apellidoMaterno, anno, mes, dia, rfc;
    std::cout<<"Por favor ingrese su nombre: ";
    getline(cin, nombre);
    std::cout<<"Por favor ingrese su apelido paterno: ";
    getline(cin, apellidoPaterno);
    std::cout<<"Por favor ingrese su apellido materno: ";
    getline(cin, apellidoMaterno);
    std::cout<<"Por favor ingrese su año de nacimiento (yyyy): ";
    std::cin >> anno;
    std::cout<<"Por favor ingrese su mes de nacimiento (mm): ";
    std::cin >> mes;
    std::cout << "Por favor ingrese su día de nacimiento (dd): ";
    std::cin >> dia;

    rfc = getRFC(nombre, apellidoPaterno, apellidoMaterno, anno, mes, dia);
    std::cout << "Su RFC es: "<< rfc << std::endl;

 
    return 0;
}

char primeraLetra(string apellido_paterno){
  return apellido_paterno[0];
}

bool esVocal(char letra) {
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}

char primeraVocalIgnorandoPrimeraLetra(string texto) {
    for (size_t i = 1; i < texto.length(); i++) {
        if (esVocal(texto[i])) {
            return texto[i];
        }
    }
    return '\0'; // Devolver el carácter nulo si no se encuentra ninguna vocal}
}
string obtenerUltimosDosCaracteres(string texto) {
    if (texto.length() >= 2) {
        return texto.substr(texto.length() - 2);
    } else {
        return texto;
    }
}

string getRFC(string nombre, string apellidoPaterno, string apellidoMaterno, string anno, string mes, string dia){
  string RFC ="";
  RFC = primeraLetra(apellidoPaterno);
  RFC = RFC + primeraVocalIgnorandoPrimeraLetra(apellidoPaterno);
  RFC = RFC + primeraLetra(apellidoMaterno);
  RFC = RFC + primeraLetra(nombre);
  RFC = RFC + obtenerUltimosDosCaracteres(anno);
  RFC = RFC + mes;
  RFC = RFC + dia;

  return RFC;

}

