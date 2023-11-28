/*
 * EXAMEN SEGUNDO PARCIAL
 * AUTOR: MORA GÓMEZ LUIS ENRIQUE
 * BOLETA: 2020600600
 * MANEJO DE UNA LISTA UTILIZANDO LISTAS LIGADAS
 * FECHA DE COMPILACIÓN: 17/NOV/2023
 */


#include <iostream>

// Declaramos la clase que nos servirá para todos los nodos

class Nodo {
public:
    // Campos
    int id; // Común
    char nombreGen[15]; // A-C, D-L, S-Z
    char nombre10[10]; // M-R
    char telefono[12]; // A-C
    float salario; // A-C
    int edad; // D-L
    char email[25]; // D-L
    char apellidos[12]; // M-R
    char genero; // M-R
    float estatura; // M-R
    char domicilio[30]; // S-Z
    float peso; // S-Z
    int tipo;

    Nodo* siguiente; // Puntero al siguiente nodo 


    // Constructor
    Nodo(int id, const char* nombreGen, const char* nombre10,
         const char* telefono, float salario, int edad,
         const char* email, const char* apellidos,
         char genero, float estatura, const char* domicilio,
         float peso, int tipo) {
        this->id = id;

        // Copiamos los caracteres del parametro recibido uno a uno para evitar un overflow, 
        // no empleamos directamente la longitud como límite del bucle, porque ... 
        // si el parametro fuese más corto tendriamos problemas.
        for (int i = 0; i < sizeof(this->nombreGen); ++i) {
            this->nombreGen[i] = nombreGen[i];
        }

        for (int i = 0; i < sizeof(this->nombre10); ++i) {
            this->nombre10[i] = nombre10[i];
        }

        for (int i = 0; i < sizeof(this->telefono); ++i) {
            this->telefono[i] = telefono[i];
        }

        this->salario = salario;
        this->edad = edad;


        for (int i = 0; i < sizeof(this->email); ++i) {
            this->email[i] = email[i];
        }


        for (int i = 0; i < sizeof(this->apellidos); ++i) {
            this->apellidos[i] = apellidos[i];
        }

        this->genero = genero;
        
        this->estatura = estatura;

  
        for (int i = 0; i < sizeof(this->domicilio); ++i) {
            this->domicilio[i] = domicilio[i];
        }

        this->peso = peso;

        this->tipo = tipo;

        this->siguiente = nullptr; 
    }
};

// Declaramos la clase que definirá nuestra lista ligada

class ListaLigada{
  private:
    Nodo* primeroDeLista; //Puntero que apunta al primer elemento de la lista
    Nodo* cola;
    int longitud;
  public:
    // Método CONSTRUCTOR
    ListaLigada(int id, const char* nombreGen, const char* nombre10,
                const char* telefono, float salario, int edad,
                const char* email, const char* apellidos,
                char genero, float estatura, const char* domicilio,
                float peso, int tipo){
      // Creamos un nuevo Nodo mediante el constructor de la clase nodo, y apuntamos hacía él con el puntero nuevoNodo 
      Nodo* nuevoNodo = new Nodo(id, nombreGen, nombre10,
                                 telefono, salario, edad, 
                                 email, apellidos, genero, 
                                 estatura, domicilio, peso, tipo);
      // Apuntamos al nodo recien creado como el primero en la lista
      primeroDeLista = nuevoNodo;
      // Como la lista es nueva, tendrá un único elemento al princio, por eso la cola apunta al mismo (único) nodo que primeroDeLista. 
      cola = nuevoNodo;
      // La longitud es uno, porque al crear una nueva lista insertamos el primer nodo únicamente para que la lista exista.
      longitud = 1;

    }

    // Sobreescribimos el método DESTRUCTOR de la lista ligada, para que elimine los nodos, no solo los apuntadores
    ~ListaLigada(){
      Nodo* temporal = primeroDeLista;
      // Recorremos la lista mediante la condición que el primero de la lista apunte a un nodo, es decir, que no sea null
      while (primeroDeLista != nullptr){
        primeroDeLista = primeroDeLista->siguiente;
        delete temporal;
        temporal = primeroDeLista;
      }
    }

    // Método para BUSCAR un nodo dado su índice
     Nodo* buscar(int indice){
      if (indice < 0 || indice >= longitud){ // Validamos el índice 
        return nullptr;
      }
      Nodo* temporal = primeroDeLista; 
      for (int i = 0; i < indice; i++){ // Este bucle iterara por toda la lista hasta llegar a la posicion que desea el usuario
        temporal = temporal->siguiente; // Recorrera el arreglo un nodo adelante
      }
      return temporal;
    }

    // Esta función sirve para actualizar valores de un nodo dado su índice
    bool actualizar(int indice, int id, const char* nombreGen, const char* nombre10,
                    const char* telefono, float salario, int edad,
                    const char* email, const char* apellidos,
                    char genero, float estatura, const char* domicilio,
                    float peso, int tipo){
      Nodo* temporal = buscar(indice);
      if (temporal != nullptr){
        temporal->id = id;
        for (int i = 0; i < sizeof(temporal->nombreGen); ++i) {
            temporal->nombreGen[i] = nombreGen[i];
        }
        //temporal->nombreGen = nombreGen;
        for (int i = 0; i < sizeof(temporal->nombre10); ++i) {
            temporal->nombre10[i] = nombre10[i];
        }
        //temporal->nombre10 = nombre10;
        for (int i = 0; i < sizeof(temporal->telefono); ++i) {
            temporal->telefono[i] = telefono[i];
        }
        //temporal->telefono = telefono;
        temporal->salario = salario;
        temporal->edad = edad;
        for (int i = 0; i < sizeof(temporal->email); ++i) {
            temporal->email[i] = email[i];
        }
        //temporal->email = email;
        for (int i = 0; i < sizeof(temporal->apellidos); ++i) {
            temporal->apellidos[i] = apellidos[i];
        }
        //temporal->apellidos = apellidos;
        temporal->genero = genero;
        temporal->estatura = estatura;
        for (int i = 0; i < sizeof(temporal->domicilio); ++i) {
            temporal->domicilio[i] = domicilio[i];
        }        
        //temporal->domicilio = domicilio;
        temporal->peso = peso;
        temporal->tipo = tipo;
        return true;
      }
      return false;
    }
      
    // Esta función sirve para insertar un nuevo nodo como el último elemento de la lista
    void insertarAlFinal(int id, const char* nombreGen, const char* nombre10,
                const char* telefono, float salario, int edad,
                const char* email, const char* apellidos,
                char genero, float estatura, const char* domicilio,
                float peso, int tipo){
      Nodo* nuevoNodo = new Nodo(id, nombreGen, nombre10,
                                 telefono, salario, edad, 
                                 email, apellidos, genero, 
                                 estatura, domicilio, peso, tipo);
      // Primer caso, se insertará un nodo en una lista vacía, también podríamos evaluar que el primer elemento de la lista apunte a null.
      if (longitud == 0){
        primeroDeLista = nuevoNodo;
        cola = nuevoNodo;
      }else{ // La lista no esá vacía
        cola->siguiente = nuevoNodo;
        cola = nuevoNodo;
      }
      longitud++;
    }

    // Esta función sirve para insertar un nuevo nodo como el último elemento de la lista
    void insertarAlPrincipio(int id, const char* nombreGen, const char* nombre10,
                const char* telefono, float salario, int edad,
                const char* email, const char* apellidos,
                char genero, float estatura, const char* domicilio,
                float peso, int tipo){
      Nodo* nuevoNodo = new Nodo(id, nombreGen, nombre10,
                                 telefono, salario, edad, 
                                 email, apellidos, genero, 
                                 estatura, domicilio, peso, tipo);
      // Primer caso, se insertará un nodo en una lista vacía, también podríamos evaluar que el primer elemento de la lista apunte a null.
      if (longitud == 0){
        primeroDeLista = nuevoNodo;
        cola = nuevoNodo;
      }else{ // La lista no esá vacía
        nuevoNodo->siguiente = primeroDeLista;
        primeroDeLista = nuevoNodo;
      }
      longitud++;
    }
    

    // Esta función sirve para insertar un nodo en la posición determinada por un índice
    bool insertar(int indice, int id, const char* nombreGen, const char* nombre10,
                  const char* telefono, float salario, int edad,
                  const char* email, const char* apellidos,
                  char genero, float estatura, const char* domicilio,
                  float peso, int tipo){
      if (indice < 0 || indice > longitud) return false; // Validamos que sea un índice válido
      if (indice == 0){
        insertarAlPrincipio(id, nombreGen, nombre10,
                            telefono, salario, edad, 
                            email, apellidos, genero, 
                            estatura, domicilio, peso, tipo);
        return true;
      }
      if (indice == longitud){
        insertarAlFinal(id, nombreGen, nombre10,
                        telefono, salario, edad, 
                        email, apellidos, genero, 
                        estatura, domicilio, peso, tipo);
        return true;
      }
      Nodo* nuevoNodo = new Nodo (id, nombreGen, nombre10,
                                 telefono, salario, edad, 
                                 email, apellidos, genero, 
                                 estatura, domicilio, peso, tipo);
      Nodo* temporal = buscar (indice - 1);
      nuevoNodo->siguiente = temporal->siguiente;
      temporal->siguiente = nuevoNodo;
      longitud++;
      return true;
    }


    void borrarUltimo(){
      if(longitud == 0) return; // Si no hay nada que borrar terminamos la función

      Nodo* temporal = primeroDeLista; // Este puntero iterará por cada elemento hasta llegar al último
      Nodo* previo = primeroDeLista; // Este puntero siempre irá un nodo detrás de temporal
      
      while(temporal->siguiente != nullptr){ // iteramos por toda la lista hasta que temporal llegue al último nodo
        previo = temporal;
        temporal = temporal->siguiente;
      }
      cola = previo; // Movemos el valor de cola al penultimo elemento 
      cola->siguiente = nullptr; // Convertimos el penultimo en el último
      longitud--; // Reducimos la longitud de la lista en un elemento
      // Si después de realizar estas operaciones la lista queda vacía realizamos lo siguiente:
      if (longitud == 0){
        primeroDeLista = nullptr; // Apuntamos todo a null para indicar que la lista está vacía
        cola = nullptr;
      }

      delete temporal; //liberamos memoria
    }

    void borrarPrimero(){
      if (longitud == 0) return; // Si la lista está vacía no hay nada que borrar
      Nodo* temporal = primeroDeLista;
      if (longitud == 1){ // Si solo hay un elemento en la lista
        primeroDeLista = nullptr; // Apuntamos todo a null para indicar que la lista queda vacía
        cola = nullptr;
      }else{
        primeroDeLista = primeroDeLista->siguiente; // Desplazamos un nodo al primero de la lista
      }
      delete temporal; // Liberamos memoria
      longitud--; // Reducimos la longitud de la lista en un elemento 
    }

    void borrar(int indice){
      if (indice < 0 || indice >= longitud) return;
      if (indice == 0) return borrarPrimero();
      if (indice == longitud - 1) return borrarUltimo();

      Nodo* previo = buscar(indice - 1);
      Nodo* temporal = previo->siguiente;

      previo->siguiente = temporal->siguiente;
      delete temporal;
      longitud--;
    } 


    // Método para MOSTRAR el contenido de la lista
    void mostrarLista(){
      int indice = 0;
      Nodo* temporal = primeroDeLista; // puntero que comenzará apuntando al primer nodo y se recorrerá hasta apuntar a null, si está en null quiere decir que ya está en el último elemento de la lista. 
      while (temporal != nullptr) {
        std::cout <<  "El ID del alumno es: " << indice + 1 << std::endl; // Mediante -> accedemos a las propiedades del objeto temp porque es un puntero, sustituye a la sintaxis (temp).value
         switch (temporal->tipo) {
        // A - C
        case 1:
          std::cout << "El nombre del alumno es: "<< temporal->nombreGen << std::endl;
          std::cout << "El teléfono del alumno es: "<< temporal->telefono << std::endl;
          std::cout << "El salario del alumno es: "<< temporal->salario << std::endl;
          break;
        // D - L
        case 2:
          std::cout << "El nombre del alumno es: "<< temporal->nombreGen << std::endl;
          std::cout << "La edad del alumno es: "<< temporal->edad << std::endl;
          std::cout << "El correo electrónico del alumno es: "<< temporal->email << std::endl;
          break;
        // M - R
        case 3:
          std::cout << "El nombre del alumno es: "<< temporal->nombre10 << std::endl;
          std::cout << "Los apellidos del alumno son: " << temporal->apellidos << std::endl;
          std::cout << "El genero del alumno es: "<< temporal->genero << std::endl;
          std::cout << "La estatura del alumno es: "<< temporal->estatura << std::endl;
          break;
        // S - Z
        case 4:
          std::cout << "El nombre del alumno es: "<< temporal->nombreGen << std::endl;
          std::cout << "El domicilio del alumno es: "<< temporal->domicilio << std::endl;
          std::cout << "El peso del alumno es: "<< temporal->peso << std::endl;
          break;

        default:
          std::cout << "error, tipo no valido" << std::endl;
          break;
      }
        indice++;
        std::cout << "\n";
        temporal = temporal->siguiente;
      }
    }
    int obtenerLongitud(){
      return longitud;
    }

};

// Fin de la clase ListaLigada

// Declaración de funciones para interacción con el usuario
ListaLigada* miPrimerListaLigada;

void clearConsole() {
    // Imprimir 50 líneas nuevas para "limpiar" la consola
    for (int i = 0; i < 25; ++i) {
        std::cout << '\n';
    }
}

void menuInicial();
void menuPrincipal();
void insertarAlumnoPrimeraVez(){
  int id; char nombreGen[15]; char nombre10[10]; char telefono[12]; float salario;
  int edad; char email[25]; char apellidos[12]; char genero; float estatura; char domicilio[30]; float peso; int tipo;
  clearConsole();
  std::cout<<"Seleccione la opción correcta:"<<std::endl;
  std::cout<<"1. Para alumnos con apellido iniciando de la A a la C"<<std::endl;
  std::cout<<"2. Para alumnos con apellido iniciando de la D a la L"<<std::endl;
  std::cout<<"3. Para alumnos con apellido iniciando de la M a la R"<<std::endl;
  std::cout<<"4. Para alumnos con apellido iniciando de la S a la Z"<<std::endl;
  std::cin>>tipo;
  std::cin.ignore();
  switch (tipo)
  {
    case 1:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombreGen,15);
      std::cout<<"Ingrese el teléfono del alumno: "<<std::endl;
      std::cin.getline(telefono,12);
      std::cout<<"Ingrese el salario del alumno: "<<std::endl;
      std::cin>>salario;
    //miPrimerListaLigada->insertar(0,1, "Luis", "Mora", "123456789", 1000.0, 25, "juan@example.com", "Perez", 'M', 1.75, "Calle 123", 70.5,2);
    // ListaLigada* miPrimerListaLigada = new ListaLigada(1, "Juan", "Apellido", "123456789", 1000.0, 25, "juan@example.com", "Perez", 'M', 1.75, "Calle 123", 70.5,1);
      miPrimerListaLigada = new ListaLigada(0, nombreGen, "", telefono, salario, 0, "", "", ' ', 0.0, "", 0.0,tipo); 
      std::cin.get();
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();
      break;
    }
    case 2:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombreGen,15);
      std::cout<<"Ingrese el email del alumno: "<<std::endl;
      std::cin.getline(email,25);
      std::cout<<"Ingrese la edad del alumno: "<<std::endl;
      std::cin>>edad;
    // ListaLigada* miPrimerListaLigada = new ListaLigada(1, "Juan", "Apellido", "123456789", 1000.0, 25, "juan@example.com", "Perez", 'M', 1.75, "Calle 123", 70.5,1);
      miPrimerListaLigada = new ListaLigada(0, nombreGen, "", "", 0.0, edad, email, "", ' ', 0.0, "", 0.0, tipo);
      std::cin.get();
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();
      break;
    }
    case 3:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombre10,10);
      std::cout<<"Ingrese los apellidos del alumno: "<<std::endl;
      std::cin.getline(apellidos,12);
      std::cout<<"Ingrese el genero del alumno: "<<std::endl;
      std::cin>>genero;
      std::cout<<"Ingrese la estatura del alumno: "<<std::endl;
      std::cin>>estatura;
      miPrimerListaLigada = new ListaLigada(0, "", nombre10, "", 0.0, 0, "", apellidos, genero, estatura, "", 0.0,tipo);
      std::cin.get();
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();      
      menuPrincipal();
      break;
    }
    case 4:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombreGen,15);
      std::cout<<"Ingrese el domicilio del alumno: "<<std::endl;
      std::cin.getline(domicilio,30);
      std::cout<<"Ingrese el peso del alumno: "<<std::endl;
      std::cin>>peso;
      miPrimerListaLigada = new ListaLigada(0, nombreGen, "", "", 0.0, 0, "", "", ' ', 0.0, domicilio, peso,tipo);
      std::cin.get();
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();      
      menuPrincipal();
      break;
    }
    default:
      std::cout<<"Opción no válida"<<std::endl;
      menuInicial();
      break;
  }
}
void menuInsertar(){
  int id; char nombreGen[15]; char nombre10[10]; char telefono[12]; float salario;
  int edad; char email[25]; char apellidos[12]; char genero; float estatura; char domicilio[30]; float peso; int tipo;
  char opcion_insertar;
  int id_auto;
  bool continuar = true;
  id_auto = miPrimerListaLigada->obtenerLongitud()+1; 
  clearConsole();
  std::cout<<"Seleccione la opción correcta:"<<std::endl;
  std::cout<<"1. Para alumnos con apellido iniciando de la A a la C"<<std::endl;
  std::cout<<"2. Para alumnos con apellido iniciando de la D a la L"<<std::endl;
  std::cout<<"3. Para alumnos con apellido iniciando de la M a la R"<<std::endl;
  std::cout<<"4. Para alumnos con apellido iniciando de la S a la Z"<<std::endl;
  std::cin>>tipo;
  std::cin.ignore();
  switch (tipo)
  {
    case 1:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombreGen,15);
      std::cout<<"Ingrese el teléfono del alumno: "<<std::endl;
      std::cin.getline(telefono,12);
      std::cout<<"Ingrese el salario del alumno: "<<std::endl;
      std::cin>>salario;
      std::cin.get();
      std::cout<<"(ENTER para seleccionar posicion)"<<std::endl;
      std::cin.get();
      clearConsole();
      std::cout<<"Seleccione la posición en la que desea insertar el alumno: \n(\"p\" al principio, \"f\" al final o \"i\" si tiene un índice específico)"<<std::endl;
      do{
        std::cin>>opcion_insertar;
        opcion_insertar = tolower(opcion_insertar);
      }while (opcion_insertar != 'p' && opcion_insertar != 'f' && opcion_insertar != 'i');
      if (opcion_insertar == 'p'){
        miPrimerListaLigada->insertarAlPrincipio(id_auto, nombreGen, "", telefono, salario, 0, "", "", ' ', 0.0, "", 0.0,tipo);
      }
      if (opcion_insertar == 'f'){
        miPrimerListaLigada->insertarAlFinal(id_auto, nombreGen, "", telefono, salario, 0, "", "", ' ', 0.0, "", 0.0,tipo);
      }
      if (opcion_insertar == 'i'){
        int index;
        std::cout<<"Ingrese el índice en el que desea insertar el alumno: "<<std::endl;
        do{
            std::cin>>index;
        }while(index<=0||index>miPrimerListaLigada->obtenerLongitud()+1);

        miPrimerListaLigada->insertar(index-1,id_auto, nombreGen, "", telefono, salario, 0, "", "", ' ', 0.0, "", 0.0,tipo);
      }
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();
      break;
    }
    case 2:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombreGen,15);
      std::cout<<"Ingrese el email del alumno: "<<std::endl;
      std::cin.getline(email,25);
      std::cout<<"Ingrese la edad del alumno: "<<std::endl;
      std::cin>>edad;
      std::cin.get();
      std::cout<<"(ENTER para seleccionar posicion)"<<std::endl;
      std::cin.get();
      clearConsole();
      std::cout<<"Seleccione la posición en la que desea insertar el alumno: \n(\"p\" al principio, \"f\" al final o \"i\" tiene un índice específico)"<<std::endl;
      do{
        std::cin>>opcion_insertar;
        opcion_insertar = tolower(opcion_insertar);
      }while (opcion_insertar != 'p' && opcion_insertar != 'f' && opcion_insertar != 'i');
      opcion_insertar = tolower(opcion_insertar);
      if (opcion_insertar == 'p'){
        miPrimerListaLigada->insertarAlPrincipio(id_auto, nombreGen, "", "", 0.0, edad, email, "", ' ', 0.0, "", 0.0, tipo);
      }
      if (opcion_insertar == 'f'){
        miPrimerListaLigada->insertarAlFinal(id_auto, nombreGen, "", "", 0.0, edad, email, "", ' ', 0.0, "", 0.0, tipo);
      } 
      if (opcion_insertar == 'i'){
        int index;
        std::cout<<"Ingrese el índice en el que desea insertar el alumno: "<<std::endl;
        do{
            std::cin>>index;
        }while(index<=0||index>miPrimerListaLigada->obtenerLongitud()+1);
        miPrimerListaLigada->insertar(index-1,id_auto, nombreGen, "", "", 0.0, edad, email, "", ' ', 0.0, "", 0.0, tipo);
      }
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();
      break;
    }
    case 3:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombre10,10);
      std::cout<<"Ingrese los apellidos del alumno: "<<std::endl;
      std::cin.getline(apellidos,12);
      std::cout<<"Ingrese el genero del alumno: "<<std::endl;
      std::cin>>genero;
      std::cout<<"Ingrese la estatura del alumno: "<<std::endl;
      std::cin>>estatura;
      std::cin.get();
      std::cout<<"(ENTER para seleccionar posicion)"<<std::endl;
      std::cin.get();
      clearConsole();
      std::cout<<"Seleccione la posición en la que desea insertar el alumno: \n(\"p\" al principio, \"f\" al final o \"i\" si tiene un índice específico)"<<std::endl;
      do{
        std::cin>>opcion_insertar;
        opcion_insertar = tolower(opcion_insertar);
      }while (opcion_insertar != 'p' && opcion_insertar != 'f' && opcion_insertar != 'i');
      opcion_insertar = tolower(opcion_insertar);
      if (opcion_insertar == 'p'){
        miPrimerListaLigada->insertarAlPrincipio(id_auto, "", nombre10, "", 0.0, 0, "", apellidos, genero, estatura, "", 0.0,tipo);
      } 
      if (opcion_insertar == 'f'){
        miPrimerListaLigada->insertarAlFinal(id_auto, "", nombre10, "", 0.0, 0, "", apellidos, genero, estatura, "", 0.0,tipo);
      } 
      if (opcion_insertar == 'i'){
        int index;
        std::cout<<"Ingrese el índice en el que desea insertar el alumno: "<<std::endl;
        do{
            std::cin>>index;
        }while(index<=0||index>miPrimerListaLigada->obtenerLongitud()+1);
        miPrimerListaLigada->insertar(index-1,id_auto, "", nombre10, "", 0.0, 0, "", apellidos, genero, estatura, "", 0.0,tipo);
      }
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();
      break;
    }
    case 4:{
      std::cout<<"Ingrese el nombre del alumno: "<<std::endl;
      std::cin.getline(nombreGen,15);
      std::cout<<"Ingrese el domicilio del alumno: "<<std::endl;
      std::cin.getline(domicilio,30);
      std::cout<<"Ingrese el peso del alumno: "<<std::endl;
      std::cin>>peso;
      std::cin.get();
      clearConsole();
      std::cout<<"Seleccione la posición en la que desea insertar el alumno: \n(\"p\" al principio, \"f\" al final o \"i\" si tiene un índice específico)"<<std::endl;
      do{
        std::cin>>opcion_insertar;
        opcion_insertar = tolower(opcion_insertar);
      }while (opcion_insertar != 'p' && opcion_insertar != 'f' && opcion_insertar != 'i');
      opcion_insertar = tolower(opcion_insertar);
      if (opcion_insertar == 'p'){
        miPrimerListaLigada->insertarAlPrincipio(id_auto, nombreGen, "", "", 0.0, 0, "", "", ' ', 0.0, domicilio, peso,tipo);
      } 
      if (opcion_insertar == 'f'){
        miPrimerListaLigada->insertarAlFinal(id_auto, nombreGen, "", "", 0.0, 0, "", "", ' ', 0.0, domicilio, peso,tipo);
      }
      if (opcion_insertar == 'i'){
        int index;
        std::cout<<"Ingrese el índice en el que desea insertar el alumno: "<<std::endl;
        do{
            std::cin>>index;
        }while(index<=0||index>miPrimerListaLigada->obtenerLongitud()+1);
        miPrimerListaLigada->insertar(index-1, id_auto, nombreGen, "", "", 0.0, 0, "", "", ' ', 0.0, domicilio, peso,tipo);
      }
      std::cout<<"El alumno se ha registrado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();
      break;
    }
    default:
      std::cout<<"Opción no válida"<<std::endl; 
      menuInicial();
      break;
  }
}

void menuEliminar(){
  char opcion_eliminar;
  clearConsole();
  std::cout<<"Seleccione cómo desea eliminar al alumno: \n(\"p\" al primero, \"u\" al último o \"i\" por ID)"<<std::endl;
      do{
        std::cin>>opcion_eliminar;
        opcion_eliminar = tolower(opcion_eliminar);
      }while (opcion_eliminar != 'p' && opcion_eliminar != 'u' && opcion_eliminar != 'i');
      if (opcion_eliminar == 'p'){
        miPrimerListaLigada->borrarPrimero();
      }
      if (opcion_eliminar == 'u'){
        miPrimerListaLigada->borrarUltimo();
      }
      if (opcion_eliminar == 'i'){
        int index;
        std::cout<<"Ingrese el ID del alumno que desea eliminar: "<<std::endl;
        do{
            std::cin>>index;
        }while(index<=0||index>miPrimerListaLigada->obtenerLongitud());
        miPrimerListaLigada->borrar(index-1);
      }
      std::cout<<"El alumno se ha eliminado correctamente (ENTER para continuar)"<<std::endl;
      std::cin.get();
      menuPrincipal();


}


void menuInicial(){
  int opcion;
  std::cout<<"Bienvenido al sistema de gestión de alumnos\nPor el momento, no tenemos registros, por favor genere el primer registro"<<std::endl;
  std::cout<<"1. Para Ingresar un nuevo alumno"<<std::endl;
  std::cout<<"2. Para Salir"<<std::endl;
  std::cin>>opcion;
  switch (opcion)
  {
  case 1:
    insertarAlumnoPrimeraVez();
    break;
  case 2:
    std::cout<<"Gracias, hasta luego"<<std::endl;
    break;
  default:
    std::cout<<"Opción no válida"<<std::endl;
    //menuInicial();
    break;
  }
}
void menuPrincipal(){
  clearConsole();
  int opcion;
  std::cout<<"Bienvenido al sistema de gestión de alumnos"<<std::endl;
  std::cout<<"1. Para Mostrar la lista de alumnos"<<std::endl;
  std::cout<<"2. Para Insertar un nuevo alumno"<<std::endl;
  std::cout<<"3. Para Buscar a un alumno"<<std::endl;
  std::cout<<"4. Para Eliminar a un alumno"<<std::endl;
  std::cout<<"5. Para Salir"<<std::endl;
  std::cin>>opcion;
  switch (opcion)
  {
  case 1:
    clearConsole();
    miPrimerListaLigada->mostrarLista();
    std::cin.get();
    std::cout<<"(ENTER para continuar)"<<std::endl;
    std::cin.get();
    menuPrincipal();
    break;
  case 2:
    clearConsole();
    menuInsertar(); 
    break;
  case 3:{
    clearConsole();
    int indice;
    std::cout<<"Ingrese el índice del alumno que desea buscar: "<<std::endl;
    do{
      std::cin>>indice;
    }while(indice<=0||indice>miPrimerListaLigada->obtenerLongitud());
    clearConsole();
    std::cout<<"El alumno que busca es: "<<std::endl;
    std::cout <<  "ID: " << indice << std::endl; // Mediante -> accedemos a las propiedades del objeto temp porque es un puntero, sustituye a la sintaxis (temp).value
    Nodo* resultado = miPrimerListaLigada->buscar(indice-1);
    if (resultado->tipo == 1){
      std::cout << "Nombre: "<< resultado->nombreGen << std::endl;
      std::cout << "Teléfono: "<< resultado->telefono << std::endl;
      std::cout << "Salario: "<< resultado->salario << std::endl;
    }
    if (resultado->tipo == 2){
      std::cout << "Nombre: "<< resultado->nombreGen << std::endl;
      std::cout << "Edad: "<< resultado->edad << std::endl;
      std::cout << "Email: "<< resultado->email << std::endl;
    }
    if (resultado->tipo == 3){
      std::cout << "Nombre: "<< resultado->nombre10 << std::endl;
      std::cout << "Apellidos: " << resultado->apellidos << std::endl;
      std::cout << "Genero: "<< resultado->genero << std::endl;
      std::cout << "Estatura: "<< resultado->estatura << std::endl;
    }
    if (resultado->tipo == 4){
      std::cout << "Nombre: "<< resultado->nombreGen << std::endl;
      std::cout << "Domicilio: "<< resultado->domicilio << std::endl;
      std::cout << "Peso: "<< resultado->peso << std::endl;
    }
    std::cin.get();
    std::cout<<"El consulta realizada correctamente (ENTER para continuar)"<<std::endl;
    std::cin.get();
    menuPrincipal();
    break;    
  }
  case 4:
    clearConsole();
    menuEliminar();
    break;
  default:
    std::cout<<"Gracias, hasta luego"<<std::endl;
    //menuInicial();
    break;
  }
}

int main() {

  menuInicial(); 

  return 0;
}

