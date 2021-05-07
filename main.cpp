#include <iostream>
#include <cstdlib>
#include <string>

using namespace std; 

int menu(); 

void arreglodescomprimido(char*, int );

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
				arreglodescomprimido(arreglo, indice);
				cout << "-------FINAL EJERCICIO 1------" <<endl; 
				break; 
				}
			case 2:
				{
				cout << "-------EJERCICIO 2------" <<endl; 
				
				cout << "-------FINAL EJERCICIO 2------" <<endl; 
				break; 
				}
			case 3: 
				{
				cout << "-------EJERCICIO 3------" <<endl; 
				
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

void arreglodescomprimido(char* arreglo, int indice){
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
					cout << "n: "<<n; 
					cout << "num: " <<num;  
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
	cout << num; 
	for (char elem: num){  
		int ascii = elem; 
		if (ascii != 59){
			cadena += elem; 
		}else {
			numeros [iterador] = atoi(cadena.c_str());
			cout << numeros [iterador] << " "; 
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
	
	
	cout << "["; 
	for (int c = 0; c < indice2;c++){
		cout << comprimir [c] << " ";
	}
	cout << "]"; 
	
	
	
	 
}










