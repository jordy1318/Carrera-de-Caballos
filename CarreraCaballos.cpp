#include <iostream>
#include <cstdlib> 
#include <unistd.h>
#include <string>
#include <random>

using namespace std;

void Ganador (string caballo1 , string caballo2){
    int lon=caballo1.length();
    if(caballo1[lon-2]=='*'){
        cout<<"\n------------ GANADOR CABALLO 1 ------------"<<endl;
    }
    else if(caballo2[lon-2]=='*'){
        cout<<"\n------------ GANANDOR CABALLO 2 ------------"<<endl;
    }
}
void MensajeBienvenida(){
    system("clear");
    cout<<"\t\t\t\t --- Carrera de Caballos --- \n\n\n";
    cout<<" Selecciona un caballo: \n primera fila (caballo 1) \n segunda fila (caballo 2)\n";
}
int NumeroRandom(){
  std::random_device rd;  // Obtiene un valor aleatorio del hardware (puede ser lento)
    std::mt19937 gen(rd()); // Inicializa el generador Mersenne Twister con el valor obtenido

    // Definir una distribución de números enteros en el rango [0, 1]
    std::uniform_int_distribution<> dis(0, 1);

    // Generar un número aleatorio en el rango [0, 1]
    int random_value = dis(gen);
    return random_value;
}
void mapa(string techo,string carril1,string carril2,string piso){
    cout<<techo<<endl;
    cout<<carril1<<endl;
    cout<<carril2<<endl;
    cout<<piso<<endl;

}

int main(){
    string techo = " ------------------------------------------------- ";
    string carril1 ="|*                                               |";
    string carril2 ="|*                                               |";
    string piso = " ------------------------------------------------- ";
    int lon = carril1.length();
    int count;
    int ant1=1,ant2 =1;
    int pos1=2,pos2 =2;

    MensajeBienvenida();
    sleep(5);
    system("clear");
    mapa(techo,carril1,carril2,piso);
    sleep(1);


    while(carril1[lon-2] != '*' && carril2[lon-2]!='*'){
    count=NumeroRandom();
    system("clear");
    if (count == 0){
        
        carril1[ant1]=' ';
        carril1[pos1]='*';
        ant1=pos1;
        pos1++;
    }
    else if(count==1){
        carril2[ant2]=' ';
        carril2[pos2]='*';
         ant2=pos2;
         pos2++;

    }
    
    mapa(techo,carril1,carril2,piso);
    usleep(100000);
    
    }
    Ganador(carril1,carril2);
    return 0;
}