#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
//Piedra papel Tijer
class juego_completo
{
//privado el id y el num cell
private:
vector<string> operaciones;
string nombre;

//publico el nombre, fecha 
public:
string id;
string eleccion;
                        //inicio del juego

//datos
juego_completo(string n,string i , string e = ""){
    nombre = n;
    eleccion = e;
    id = i;
    operaciones = {"Tijera","Papel","Piedra"};
}
//coger el tiempo actual
string tiempo(){
    time_t time_now=time(nullptr);
    char lista[80];
    strftime(lista,sizeof(lista),"%d/%m/%Y %H:%M:%S",localtime(&time_now));
    return string(lista);
}

//getnombre funcion
string getnombre(){
    return nombre;
}

//Bienvenida
static void bienvenida(juego_completo& j1, juego_completo& j2)
    {
        cout << "====================================================\n";
        cout << "   BIENVENIDOS AL JUEGO DE PIEDRA, PAPEL Y TIJERA   \n";
        cout << "====================================================\n";
        cout << "La fecha de hoy es: " << j1.tiempo() << "\n\n";
        cout<<"Jugador 1: "<<j1.getnombre() << "(ID: "<< j1.id << ") \n";
        cout<<"Jugador 2: "<<j2.getnombre() << "(ID: "<< j2.id << ") \n";
    }

//recorrer lista 
void recorrer_operaciones(){
    for (int i = 0;i < operaciones.size();i++){
        cout << operaciones[i];
        if (i != operaciones.size() - 1) cout << ", ";
    }
}
//eleccion jugador
void jugador_auto_elegir() {
    int opcion = rand() % operaciones.size();
    eleccion = operaciones[opcion];
    cout << nombre << " eligio: " << eleccion << endl;
}
//ganador o perder
static void ganar_perder(juego_completo& j1, juego_completo& j2)
{
    cout << "\n-------- Resultado ----------------";
    if (j1.eleccion == j2.eleccion){
        cout << "\nEmpate, estan empates ambos eligieron: " << j1.eleccion << endl;
    } else if (
        (j1.eleccion == "Tijera" && j2.eleccion == "Papel") ||
        (j1.eleccion == "Papel"  && j2.eleccion == "Piedra") ||
        (j1.eleccion == "Piedra" && j2.eleccion == "Tijera")
    )
    {
        cout << "\n";
        cout << "Gana: " << "( " << j1.getnombre() << "," << j1.id << " )" << " " << "Con: " << j1.eleccion << endl;
    } else 
    { 
        cout << "\n";
        cout << "Gana: " << "( " << j2.getnombre() << "," << j2.id << " )" << " " << "Con: " << j2.eleccion << endl;
    }

}
};




int main(){

    //juagdores
    juego_completo jugador1("Adrian","J1");
    juego_completo jugador2("Maria","J2");

    //bienvenida
    juego_completo::bienvenida(jugador1, jugador2);

    //eleccion jugador
    srand(time(nullptr));
    jugador1.jugador_auto_elegir();
    jugador2.jugador_auto_elegir();

    //decision
    juego_completo::ganar_perder(jugador1,jugador2);
}