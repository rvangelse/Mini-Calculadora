/*************************************************************************************************************
 
 *Este programa es una Mini-Calculadora
 *capaz de realizar las 4 operaciones basicas(Suma, Resta, Multiplicacion y Division)
 *usando varios operandos y con la posibilidad de realizar multiples operaciones secuenciales.
 *El input que recibe son los operandos uno por uno, se indica que el input "termino" ingresando el 0 al final.

*************************************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

// Función para mostrar el menú
void mostrarMenu() {
    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
    cout << "Bienvenido a la Mini-Calculadora!!!" << endl;
    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl; 
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Reiniciar" << endl;
    cout << endl;
    cout << "6. Salir" << endl;   
}

// Función para leer los números
void leerNumeros(vector<double>& numeros) {
    double numero;
    cout << endl;
    cout << "Introduce uno por uno, los numeros a operar (termina ingresando el 0): ";
    cout << endl;
    while (cin >> numero && numero != 0) {
        numeros.push_back(numero);
    }
}

// Funciones para las operaciones matemáticas
double sumar(const vector<double> numeros) {
    double resultado = 0;
    for (double numero : numeros) {
        resultado += numero;
    }
    return resultado;
}

double restar(const vector<double> numeros){
    double resultado = numeros[0];
    for (int i = 1; i < numeros.size(); ++i) {
        resultado -= numeros[i];
    }
    return resultado;
}

double multiplicar(const vector<double> numeros){
    double resultado = 1;
    for (double numero : numeros) {
        resultado *= numero;
    }
    return resultado;
}

double dividir(const vector<double> numeros){
    double resultado = numeros[0];
    for (int i = 1; i < numeros.size(); ++i) {
        if (numeros[i] == 0) {
            cout << "Error: No se puede dividir por 0." << endl;
            break;
        }
        resultado /= numeros[i];
    }
    return resultado;
}

// Función para realizar la operación seleccionada
double realizarOperacion(int opcion, const vector<double> numeros, double resultado_previo, int contador) {
    double resultado;
    switch (opcion) {
        case 1:
            resultado = sumar(numeros);
            resultado += resultado_previo;
            cout << endl;
            cout << "El resultado de la suma es: " << resultado << endl;
            cout << endl;
            break;
        case 2:
            resultado = restar(numeros);
            if (contador > 0) {
                resultado = resultado_previo - resultado;
            }
            cout << endl;
            cout << "El resultado de la resta es: " << resultado << endl;
            cout << endl;
            break;
        case 3:
            resultado = multiplicar(numeros);
            if (contador > 0) {
                resultado = resultado_previo * resultado;
            }
            cout << endl;
            cout << "El resultado de la multiplicacion es: " << resultado << endl;
            cout << endl;
            break;
        case 4:
            resultado = dividir(numeros);
            if (contador > 0 && resultado_previo != 0) {
                resultado = resultado_previo / resultado;
            }
            cout << endl;
            cout << "El resultado de la division es: " << resultado << endl;
            cout << endl;
            break;
    }
    return resultado;
}

int main() {

    //Declaracion de las variables
    vector<double> numeros; // Vector con todos los números a operar
    char continuar; 
    int opcion, contador = 0;
    double resultado = 0, resultado_previo = 0; 

    do { 

        mostrarMenu();

        // Mostrar el resultado de las operaciones realizadas hasta el momento
        if (contador > 0) {
            cout << endl;
            cout << "El resultado previo de las operaciones que realizaste es: " << resultado << endl;
        }

        cout << endl;
        cout << "Escoge la operacion que te gustaria realizar: " << endl; 
        cin >> opcion;

        // Opción de salida rápida
        if (opcion == 6) {
            break;
        }
        
        //Guarda para validar la opcion ingresada
        if (opcion >= 1 && opcion <= 4) {
            leerNumeros(numeros);
            resultado = realizarOperacion(opcion, numeros, resultado_previo, contador);
        } else if (opcion == 5) {
            resultado = 0;
            cout << endl;
            cout << "Reiniciaste el sistema" << endl;
            cout << endl;
        } else {
            cout << "Opción inválida. Intenta nuevamente" << endl;
        }

        numeros.clear(); 
        resultado_previo = resultado;

        cout << "¿Deseas realizar otra operación? (s/n): ";
        cin >> continuar;

        //Guarda para validar si/no
        while(continuar != 's' && continuar != 'n') {
            cout << endl;
            cout << "Por favor, ingrese 's' para realizar otra operación o 'n' para salir: ";
            cin >> continuar;
            if (continuar == 's' || continuar == 'n'){
                break;
            }
        }

        contador++;

    } while (continuar == 's' || continuar == 'S');

    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;
    cout << "Gracias por usar la Mini-Calculadora!!!" << endl;
    cout << endl;
    cout << "*******************************************************************" << endl;
    cout << endl;

    return 0;
}
