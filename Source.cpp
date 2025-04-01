#include <iostream>
#include<string.h>
#include<Windows.h>
using namespace std;

struct datos;
void insertarDatos(char[], int, int, int);
void menu();
void mostrarDatos();
void Quicksort(datos*,int, int);
int particion(datos*, int, int);
void ListaToArray(datos*, int&);
void mostrarNuevoArreglo(datos* , int );

struct datos {
	char nombre[40];
	int edad;
	int ID;
	int calificacion;
	datos* siguiente;
	datos* anterior;
}*origen, *aux;

datos* arrayDatos;

int main() {
	menu();
	return 0;
}


void insertarDatos(char nombre[], int edad, int ID, int calificacion) {
	datos* nuevos_datos = new datos;
	strcpy_s(nuevos_datos->nombre, nombre);
	nuevos_datos->edad = edad;
	nuevos_datos->ID = ID;
	nuevos_datos->calificacion = calificacion;

	if (origen==NULL) {
		origen = nuevos_datos;
		origen->siguiente = NULL;
		origen->anterior = NULL;
		aux = origen;
	}
	else
	{
		aux->siguiente = nuevos_datos;
		nuevos_datos->siguiente = NULL;
		nuevos_datos->anterior = origen;
		aux = nuevos_datos;
	}

	cout << "Elemento insertado"<<endl;
}

void menu() {
	int op;
	char nombre[40];
	int edad;
	int ID=0;
	int calificacion;
	int final;
	int inicio = 0;

	do
	{
		cout << "1. Insertar elementos"<<endl;
		cout << "2. Mostrar lista"<<endl;
		cout << "3. Ordenar Lista"<<endl;
		cout << "4. Mostrar nueva lista"<<endl;
		cout << "5. Salir"<<endl;
		cout << "Escoje una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Ingrese su nombre: ";
			cin >> nombre;
			cout << endl << "Ingrese su edad: ";
			cin >> edad;
			cout << endl << "Ingrese su calificacion: ";
			cin >> calificacion;
			ID++;
			insertarDatos(nombre, edad, ID, calificacion);
			system("pause");
			break;
		case 2:
			mostrarDatos();
			system("pause");
			break;
		case 3:
			final = aux->ID;
			arrayDatos = new datos[final];
			ListaToArray(origen, inicio);
			inicio = 0;
			Quicksort(arrayDatos, inicio, final);
			system("pause");
			break;
		case 4:
			mostrarNuevoArreglo(arrayDatos, final);
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (op!=5);
}

void mostrarDatos() {
	datos* actual = new datos;
	actual = origen;

	if (origen!=NULL) 
	{
		while (actual!=NULL) {
			cout << actual->ID << endl;
			cout << actual->nombre << endl;
			cout << actual->edad << endl;
			cout << actual->calificacion << endl;
			actual = actual->siguiente;
		}
	}
	else
	{
		cout << "Lista vacia";
	}
}

void ListaToArray(datos* origen, int& indice) {
	if (origen==NULL) {
		return;
	}
	else
	{
		strcpy_s(arrayDatos[indice].nombre, origen->nombre);
		arrayDatos[indice].edad = origen->edad;
		arrayDatos[indice].calificacion = origen->calificacion;
		arrayDatos[indice].ID = origen->ID;
		indice++;
		ListaToArray(origen->siguiente, indice);
	}
}

int particion(datos* arrayDatos, int inicio, int final) {
	//final = aux->calificacion;
	int pivote = arrayDatos[inicio].calificacion;
	int i = inicio + 1;
	for (int j = i; j <= final; j++) {
		if (arrayDatos[j].calificacion < pivote) {
			swap(arrayDatos[i].nombre, arrayDatos[j].nombre);
			swap(arrayDatos[i].edad, arrayDatos[j].edad);
			swap(arrayDatos[i].calificacion, arrayDatos[j].calificacion);
			swap(arrayDatos[i].ID, arrayDatos[j].ID);
			i++;
		}
	}
	swap(arrayDatos[inicio], arrayDatos[i-1]);
	
	return i-1;
}

void Quicksort(datos* arrayDatos, int inicio, int final) {
	if (inicio<final) {
		int pivote = particion(arrayDatos, inicio, final);
		Quicksort(arrayDatos, inicio, pivote-1);
		Quicksort(arrayDatos, pivote+1, final);
	}
}

void mostrarNuevoArreglo(datos* arrayDatos, int final) {
	for (int i = 0; i < final; i++) {
		cout << "ID: " << arrayDatos[i].ID<<endl;
		cout << arrayDatos[i].nombre << endl;
		cout << arrayDatos[i].edad << endl;
		cout << arrayDatos[i].calificacion << endl;
	}
}