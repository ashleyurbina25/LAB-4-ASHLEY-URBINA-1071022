// LAB 4 ASHLEY URBINA 1071022.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 71
#include<cstdlib>

using namespace::std;
const int Tamaño_Arreglo = 70;

void Imprime_Pista(char A[], int);
int Avance_Liebre(int);
int Avance_Tortuga(int);

int main()
{ // Abre main

	cout << "\n\nEl siguiente programa muestra la carrera entre ";
	cout << "la liebre (l) y la tortuga (t)!" << endl;
	cout << "Ambas inician en la casilla 1" << endl;
	cout << "\t\t\tpreparen sus apuestas :)! " << endl << endl;

	srand(time(0));


	char Pista[Tamaño_Arreglo + 1] = { 0, 'E', 0, 0 };
	int Posicion_Tortuga = 1;
	int tortuga = 1;
	int Posicion_Liebre = 1;
	int liebre = 1;
	int centinela = 0;
	int numero;
	int contador = 1;
	Imprime_Pista(Pista, Tamaño_Arreglo);


	while (0 == centinela)
	{ // según la condición

		cout << "\nIntroduzca un numero: " << endl;
		cin >> numero;

		cout << "\t\t\t\tBANG!" << endl;
		cout << "\t\t\t Y ARRANCAN!" << endl;

		for (int x = 1; x <= Tamaño_Arreglo; x++)
		{
			Pista[x] = 0;
		}

		Posicion_Tortuga = Avance_Tortuga(Posicion_Tortuga);
		tortuga = Posicion_Tortuga;
		Posicion_Liebre = Avance_Liebre(Posicion_Liebre);
		liebre = Posicion_Liebre;
		//cout << Posicion_Liebre <<endl;
		// cout << Posicion_Tortuga <<endl;
	


		if ((1 <= Posicion_Liebre) && (Tamaño_Arreglo > Posicion_Liebre))
		{ // Abre if
			Pista[Posicion_Liebre] = 'L';
		} // Cierra if

		if (1 > Posicion_Liebre)
		{
			// cout << "Menor " <<endl;
			// Descomentar

			Posicion_Liebre = 1;
			Pista[Posicion_Liebre] = 'L';
		}
		if ((Posicion_Tortuga >= 1) && (Tamaño_Arreglo > Posicion_Liebre))
		{ // si la posición de la tortuga es mayor o igual a 1, abre if

			if (Posicion_Tortuga == Posicion_Liebre)
			{
				Pista[Posicion_Tortuga] = 'E';
			}
			else
			{
				Pista[Posicion_Tortuga] = 'T';
			}
		} // Cierra if

		if (Posicion_Tortuga < 1)
		{
			Posicion_Tortuga = 1;
			if (1 == Posicion_Liebre)
				Pista[Posicion_Tortuga] = 'E';
			else
				Pista[Posicion_Tortuga] = 'T';
		}

		if (Posicion_Liebre >= Tamaño_Arreglo)

		{ // Abre if
			centinela = -1;
			if (Posicion_Tortuga > Tamaño_Arreglo)
				cout << "\nQUE CIERRE! LA LIEBRE Y LA TORTUGA EMPATARON! " << endl;
			else
				cout << "\nNI HABLAR, GANO LA LIEBRE! " << endl;

			Pista[Tamaño_Arreglo] = 'L';
		} // Cierra if


		if (Posicion_Tortuga >= Tamaño_Arreglo)
		{ // Abre if
			centinela = -1;
			if (Posicion_Liebre < Tamaño_Arreglo)
			{
				Pista[Tamaño_Arreglo] = 'T';
				cout << "\nZanahoria y lechugas frescas para la tortuga ganadora";
				

			}
			else
			{
				Pista[Tamaño_Arreglo] = 'E';
				cout << "\nLa tortuga y la liebre empatan!! " << endl;
			}
		} // Cierra if


		Imprime_Pista(Pista, Tamaño_Arreglo);

		if ('E' == Pista[Posicion_Tortuga])
		{ // Abre if

			switch (contador)

			{ // Abre switch
			case 1:
			{
				cout << "\aauch! La tortuga ha mordido la liebre! " << endl;
				contador++;
				break;
			}
			case 2:
			{
				cout << "\a¡auch! No se vale, la tortuga vuelve a hacerlo >:c" << endl;
				contador++;
				break;
			}
			case 3:
			{
				cout << "\a¡auch! Vuelven a morder a la liebre!" << endl;
				contador++;
				break;
			}
			default:
			{
				cout << "\aauch!!! de qué se trata?" << endl;
				break;
			}
			} // cierra switch

		} // Cierra if

	} // Cierra centinela

	cin.get();
	getch();
	return 0;

} // Cierra main


//Funcion lista

void Imprime_Pista(char A[], int n)

{ 

	cout << "*   *   *";
	for (int i = 1; i <= n; i++)
	{ // Abre for
		if (0 == A[i])
			cout << " ";
		else
			cout << A[i];
	} // Cierra for

	cout << "****";
	cout << endl;

} // Cierra Imprime pista


//inicia el avance de la lista


int Avance_Liebre(int l)

{ // Avance Liebre
	srand(time(0));
	int ruleta;
	ruleta = 1 + rand() % 10;



	if (2 >= ruleta)
		return l;

	if (4 >= ruleta)
		return (l + 9);

	if (5 >= ruleta)
		return l - 12;

	if (8 >= ruleta)
		return l + 1;

	if (10 >= ruleta)
		return l - 2;

} // Cierra Avance de Liebre



//inicia avance de tortuga

int Avance_Tortuga(int t)

{ // Abre Avance de tortuga
	srand(time(0));
	int dados = 1 + rand() % 10;


	if (5 >= dados)
		return (t + 3);

	if (7 >= dados)
		return (t - 6);

	if (10 >= dados)
		return (t + 1);

} // Cierra Avanza tortuga