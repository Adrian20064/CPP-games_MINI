#include <iostream>
#include <string>
#include <vector>
using namespace std;

//grades statement
void notas_buenas() {
    cout << "Your grade must be greater than 7.5/10 to pass the course\n";
}

int main() {
    //welcoming
    cout << "=============================================\n";
    cout << "     WELCOME TO THE GPA CALCULATOR\n";
    cout << "=============================================\n\n";

    //calling statement
    notas_buenas();
    cout << "\n\n";

    //entering n subject
    int numMaterias;
    cout << "How many courses do you want to enter? ";
    cin >> numMaterias;

    //creating list of subjects and grades
    vector<string> materias(numMaterias);
    vector<double> notas(numMaterias);

    //adding subjects and grades on the list
    for (int i = 0; i < numMaterias; i++) {
        cout << "\nEnter the name of course #" << i + 1 << ": ";
        cin >> materias[i];

        cout << "Enter the grade of " << materias[i] << " (0 - 10): ";
        cin >> notas[i];

        while (notas[i] < 0 || notas[i] > 10) {
            cout << "Invalid grade. Enter a value between 0 and 10: ";
            cin >> notas[i];
        }
    }

    //creating a variable to add all the subjects
    double suma = 0;
    for (double n : notas) {
        suma += n;
    }

    //float variable as the gpa
    double promedio = suma / numMaterias;

    //results part
    cout << "\n=============================================\n";
    cout << "                RESULTS\n";
    cout << "=============================================\n";

    //printing the grades and name of each subject
    for (int i = 0; i < numMaterias; i++) {
        cout << materias[i] << ": " << notas[i] << "/10\n";
    }

    //printing gpa  
    cout << "\nYour GPA is: " << promedio << "/10\n";

    //validatiing if gpa is higher than 7.5 to pass
    if (promedio >= 7.5) {
        cout << "Congratulations! You passed the course!\n";
    } else {
        cout << "You did not pass the course. Keep studying!\n";
    }

    cout << "=============================================\n";

    return 0;
}
