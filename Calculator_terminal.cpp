#include <iostream>
#include <list>
#include <string>
#include <cmath>

using namespace std;

//list of the operations
list<string> Calculadora(){
    // Lista de operaciones soportadas
    list<string> list_operaciones = {"+","-","*","/","^","√"};
    return list_operaciones;
}


int main(){
    //opcion and num1 and num2 as a int and double
    int opcion = 0;
    double num1 = 0.0, num2 = 0.0, resultado_para_num1 = 0.0, resultado_para_num2 = 0.0;
    //call the calculador list on a variable
    list<string> operaciones = Calculadora();

    //while until its option 5
    while (true) {
        //instructions
        cout << "=== Calculadora Cientifica ===\n";
        cout << "1) Sumar (a + b)\n";
        cout << "2) Restar (a - b)\n";
        cout << "3) Multiplicar (a * b)\n";
        cout << "4) Dividir (a / b)\n";
        cout << "5) Potencia (a ^ b)\n";
        cout << "6) Raiz Cuadrada (√ b) || (√ a)\n";
        cout << "7) Salir\n";
        cout << "Elige la opcion de calculadora: ";

        //making obligatory to put a option number 
        if (!(cin >> opcion)) {
            cout << "Entrada inválida. Por favor ingresa un número de opción.\n";
            cin.clear();
            continue;
        }

        //if its 5, exi t
        if (opcion == 7) {
            cout << "Saliendo...\n";
            break;
        }

        //if its outsit the options, throw an error
        if (opcion < 1 || opcion > 7) {
            cout << "Opción no válida. Intenta de nuevo.\n";
            continue;
        }

        //loop while taking num1 and clearing if its not valid
        cout << "Ingresa el primer número: ";
        while (!(cin >> num1)) {
            cout << "Número inválido. Intenta de nuevo: ";
            cin.clear();
        }

        //same as num1
        cout << "Ingresa el segundo número: ";
        while (!(cin >> num2)) {
            cout << "Número inválido. Intenta de nuevo: ";
            cin.clear();
        }

        //putting on a variable a float value as the result
        double resultado = 0.0;
        //switch with the 6 options and its logics
        switch (opcion) {
            case 1:
                resultado = num1 + num2;
                cout << "Resultado: " << num1 << " + " << num2 << " = " << resultado << "\n";
                break;
            case 2:
                resultado = num1 - num2;
                cout << "Resultado: " << num1 << " - " << num2 << " = " << resultado << "\n";
                break;
            case 3:
                resultado = num1 * num2;
                cout << "Resultado: " << num1 << " * " << num2 << " = " << resultado << "\n";
                break;
            case 4:
                if (num2 == 0.0) {
                    cout << "Error: división por cero no permitida.\n";
                } else {
                    resultado = num1 / num2;
                    cout << "Resultado: " << num1 << " / " << num2 << " = " << resultado << "\n";
                }
                break;
            case 5:
                resultado = pow(num1,num2);
                cout << "Resultado: " << num1 << " ^ " << num2 << " = " << resultado << "\n";
                break;
            case 6: {
                int eleccion = 0;
                cout << "Has elegido Raíz Cuadrada.\n";
                cout << "¿De cuál número quieres obtener la raíz?\n";
                cout << "1) Del primer número (" << num1 << ")\n";
                cout << "2) Del segundo número (" << num2 << ")\n";
                cout << "Elige 1 o 2: ";
                cin >> eleccion;

                if (eleccion == 1) {
                    if (num1 < 0)
                        cout << "Error: no se puede calcular la raíz de un número negativo.\n";
                    else {
                        resultado = sqrt(num1);
                        cout << "Resultado: √" << num1 << " = " << resultado << "\n";
                    }
                } 
                else if (eleccion == 2) {
                    if (num2 < 0)
                        cout << "Error: no se puede calcular la raíz de un número negativo.\n";
                    else {
                        resultado = sqrt(num2);
                        cout << "Resultado: √" << num2 << " = " << resultado << "\n";
                    }
                } 
                else {
                    cout << "Opción inválida. Se esperaba 1 o 2.\n";
                }
                break;
            }
            default:
                cout << "Opción no implementada.\n";
        }

        cout << "\n";
    }
}
