#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std; 

int menu(); 

char* arreglodescomprimido(char*, int );

char** crearmatriz(int, int, int);

char** secuencia(char*, char**, int, int, int, int , int);

int main(int argc, char** argv) {
	
	int opcion = menu();
	while (opcion != 4){
		switch (opcion){
			case 1:
				{
				cout << "-------EJERCICIO 1------" <<endl; 
				int indice = 0;
				bool v = false; 
				while (v == false){
					cout << " Ingrese la cantidad de elementos del arreglo: (entero mayor a 0)" <<endl;
					cin >> indice;  
					if (indice <= 0){
						cout << "Indice ingresado invalido." <<endl; 
					}else {
						v = true; 
					}
				}//Fin del while.
				char* arreglo; 
				arreglo = new char[indice];
				char caracter;  
				for (int c =0; c < indice;c++){
					cout << "Ingrese el caracter para el elemento " << c << ":" <<endl; 
					cin >> caracter; 
					arreglo [c] = caracter; 
				}
				char* nuevo;
				nuevo = arreglodescomprimido(arreglo, indice);
				delete[] arreglo;
				delete [] nuevo; 
				cout << "-------FINAL EJERCICIO 1------" <<endl; 
				break; 
				}
			case 2:
				{
				cout << "-------EJERCICIO 2------" <<endl; 
				int filas = 0; 
				int columnas = 0; 
				int piedras =0;
				bool v = false; 
				while (v == false){
					cout << " Ingrese la cantidad de filas: (entero mayor a 0)" <<endl;
					cin >> filas;  
					cout << " Ingrese la cantidad de columnas: (entero mayor a 0)" <<endl;
					cin >> columnas; 
					cout << " Ingrese la cantidad de obstaculos: (entero mayor a 0)" <<endl;
					cin >> piedras; 
					if (filas <= 0 || columnas <= 0 || (piedras > (filas * columnas))){
						cout << "Valores ingresados invalidos." <<endl; 
					}else {
						v = true; 
					}
				}//Fin del while.
				char** matriz; 
				matriz = crearmatriz(filas, columnas, piedras);
				for(int i = 0; i<filas;i++){
					if(matriz[i]){
						delete[] matriz[i];
						matriz[i] = 0; 
					}
				}
				if( matriz != NULL ){
					delete[] matriz;
					matriz = 0;
				}
				if(matriz){
					delete[] matriz;
					matriz = 0;
				}
				cout << "-------FINAL EJERCICIO 2------" <<endl; 
				break; 
				}
			case 3: 
				{
				cout << "-------EJERCICIO 3------" <<endl; 
				int indice = 0;
				bool v = false; 
				while (v == false){
					cout << " Ingrese la cantidad de elementos del arreglo: (entero mayor a 0)" <<endl;
					cin >> indice;  
					if (indice <= 0){
						cout << "Indice ingresado invalido." <<endl; 
					}else {
						v = true; 
					}
				}//Fin del while.
				char* arreglo; 
				arreglo = new char[indice];
				char caracter;  
				for (int c =0; c < indice;c++){
					cout << "Ingrese el caracter para el elemento " << c << ":" <<endl; 
					cin >> caracter; 
					arreglo [c] = caracter; 
				}
				int filas = 0; 
				int columnas = 0; 
				int piedras =0;
				bool v2 = false; 
				while (v2 == false){
					cout << " Ingrese la cantidad de filas: (entero mayor a 0)" <<endl;
					cin >> filas;  
					cout << " Ingrese la cantidad de columnas: (entero mayor a 0)" <<endl;
					cin >> columnas; 
					cout << " Ingrese la cantidad de obstaculos: (entero mayor a 0)" <<endl;
					cin >> piedras; 
					if (filas <= 0 || columnas <= 0 || (piedras > (filas * columnas))){
						cout << "Valores ingresados invalidos." <<endl; 
					}else {
						v2 = true; 
					}
				}
				int fila = 0; 
				int columna = 0;
				char* arreglo2 = arreglodescomprimido(arreglo, indice);
				char** matriz = crearmatriz(filas, columnas, piedras);
				bool v3 = false; 
				while (v3 == false){
					cout << " Ingrese la fila para comenzar: (entero mayor a 0)" <<endl;
					cin >> fila;  
					cout << " Ingrese la columna para comenzar: (entero mayor a 0)" <<endl;
					cin >> columna; 
					if (filas <=  fila || columnas <= columna){
						cout << "Valores ingresados invalidos." <<endl; 
					}else {
						char elem = matriz [fila][columna]; 
						if (elem == '#'){
							cout << "Valores ingresados invalidos." <<endl; 
						}else{
							v3 = true; 
						}
					}
				}
				char** matrizsecuencia = secuencia(arreglo2, matriz, fila, columna, filas, columnas, indice);
				delete[] arreglo2; 
				for(int i = 0; i<filas;i++){
					if(matriz[i]){
						delete[] matriz[i];
						matriz[i] = 0; 
					}
				}
				if( matriz != NULL ){
					delete[] matriz;
					matriz = 0;
				}
				if(matriz){
					delete[] matriz;
					matriz = 0;
				}
				for(int i = 0; i<filas;i++){
					if(matrizsecuencia[i]){
						delete[] matrizsecuencia[i];
						matriz[i] = 0; 
					}
				}
				if( matrizsecuencia != NULL ){
					delete[] matrizsecuencia;
					matriz = 0;
				}
				if(matrizsecuencia){
					delete[] matrizsecuencia;
					matriz = 0;
				}
				cout << "-------FINAL EJERCICIO 3------" <<endl; 	
				break; 
				}
		}//Fin del switch.
		cout <<endl; 
		opcion = menu(); 
	}//Fin del while. 
	return 0;
}

int menu(){
	int opcion = 0; 
	while (opcion != 4){
		cout << "--------MENU--------" <<endl;
		cout << " 1) Ejercicio 1. "<<endl;
		cout << " 2) Ejercicio 2. " <<endl; 
		cout << " 3) Ejercicio 3. " <<endl; 
		cout << " 4) Salir. " <<endl; 
		cout << "---------------------" <<endl; 
		cout << " Ingrese la opcion: " <<endl; 
		cin>> opcion; 
		if (opcion == 4){
			cout << "Ha elegido salir del sistema. " <<endl; 
		}else if (opcion > 0 && opcion < 4){
			break; 
		}
	}
	return opcion; 
}

char* arreglodescomprimido(char* arreglo, int indice){
	int indice2 = 0;
	string acum1 = ""; 
	int indicenumeros = 0; 
	int indiceletras = 0; 
	string num = ""; 
	string let = "";
	for (int c = 0; c < indice;c++){
		char elemento = arreglo [c];
		int ascii = elemento; 
		if (ascii >= 48 && ascii <= 57){
			if (c < indice-1 ){
				int ascii2 = arreglo [c + 1]; 
				if (ascii2 >= 48 && ascii2 <= 57){
					acum1 += elemento; 
				}else {
					string h = acum1+elemento+""; 
					int n = atoi(h.c_str());
					indicenumeros++; 
					num += h +";";    
					indice2 += n;
					acum1 = "";
				}			
			}
		}else {
			indiceletras++;
			let += elemento;
		}
	}
	int* numeros; 
	numeros = new int[indicenumeros];
	char* letras; 
	letras = new char[indiceletras];  
	int iterador = 0; 
	string cadena = "";
	for (char elem: num){  
		int ascii = elem; 
		if (ascii != 59){
			cadena += elem; 
		}else {
			numeros [iterador] = atoi(cadena.c_str());
			cadena = "";
			iterador++; 
		}
	}
	for (int c =0; c < indiceletras;c++){
		char elem = let [c];
		letras [c] = elem; 
	}
	
	char* comprimir; 
	comprimir = new char [indice2];
	int iterador3 = 0; 
	int iterador4 = 0;
	for (int c = 0; c < indicenumeros;c++){
		for (int j = 0; j < numeros [c];j++){
			comprimir [iterador3] = letras [iterador4];
			iterador3++;
		}
		iterador4++;
	}
	delete[] numeros;
	delete[] letras;
	cout << "["; 
	for (int c = 0; c < indice2;c++){
		cout << comprimir [c] << " ";
	}
	cout << "]"<<endl; 
	return comprimir; 
	
	
	 
}

char** crearmatriz(int filas, int columnas, int piedras){
	char** matriz = 0; 
	matriz = new char* [filas];
	for(int c = 0; c < filas;c++){
		matriz[c] = new char[columnas];
		//matriz[1][1] = '#';
	}
	bool v = false; 
	int contar = 0; 
	srand(time(NULL));
	while (v == false){
		int num = 1 + rand() % (filas);
		int num2 = 1 + rand() % (columnas);
		if (num >= filas || num2 >= columnas || contar == piedras){
			if (contar == piedras){
				v = true; 
			}
		}else {
			char elem = matriz [num][num2];
			if (elem == '#'){
				
			}else {
				matriz [num][num2] = '#'; 
				contar++; 
			}
		}
	}
	for(int c = 0; c < filas; c++){	
		for(int j= 0; j < columnas;j++){
			char elem = matriz [c][j];
			if (elem == '#'){
				
			}else{
				matriz[c][j] = '-';
			}
		}	
	}
	
	for(int c = 0; c < filas; c++){	
		for(int j= 0; j < columnas;j++){
			cout << matriz [c][j] << " ";
		}	
		cout <<endl; 
	}
	return matriz; 
}

char** secuencia(char* arreglo, char** matriz, int fila, int columna, int filas, int columnas, int indice){
	int comienzo = 0; 
	int mover = 0; 
	for (int h = 0; h < indice;h++){
		char elem = arreglo [h];
		mover = 0; 
		for (int c = 0; c < filas;c++){
			for (int j = 0; j < columnas;j++){
				if (elem == 'U' && mover == 0){
					if (comienzo == 0){
						comienzo++; 
						matriz [c][j] = 186;
					}else if (arreglo [h- 1] == 'L'){
						matriz [c][j] = 186; 
						matriz [c+1][j] = 200;
						break;  
					}else if (arreglo [h- 1] == 'R'){
						matriz [c][j] = 186; 
						matriz [c+1][j] = 188; 
						break; 
					}
				}else if (elem == 'D' && mover ==0){
					if (comienzo == 0){
						comienzo++; 
						matriz [c][j] = 186;
					}else if (arreglo [h- 1] == 'L'){
						matriz [c][j] = 186; 
						matriz [c-1][j] = 201; 
						break; 
					}else if (arreglo [h- 1] == 'R'){
						matriz [c][j] = 186; 
						matriz [c-1][j] = 187; 
						break;
					}	
				}else if (elem == 'L' && mover ==0){
					if (comienzo == 0){
						comienzo++; 
						matriz [c][j] = 205;
					}else if (arreglo [h- 1] == 'U'){
						matriz [c][j] = 205; 
						matriz [c][j-1] = 187; 
						break; 
					}else if (arreglo [h- 1] == 'D'){
						matriz [c][j] = 205; 
						matriz [c][j-1] = 188; 
						break; 
					}
				}else if (elem == 'R' && mover ==0){ 
					if (comienzo == 0){
						matriz [c][j] = 205;
						comienzo++; 
					}else if (arreglo [h - 1] == 'U'){
						matriz [c][j] = 205; 
						matriz [c][j-1] = 201;
						break; 
					}else if (arreglo [h- 1] == 'D'){
						matriz [c][j] = 205; 
						matriz [c][j-1] = 200; 
						break; 
					}
				}
				mover++; 
			}
		}
		for(int c = 0; c < filas; c++){	
			for(int j= 0; j < columnas;j++){
				cout << matriz [c][j] << " ";
			}	
			cout <<endl; 
			cout << endl; 
		}
	}
	return matriz; 
}






