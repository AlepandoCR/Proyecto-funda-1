#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int acumulado(int acu,int i,bool salioacu)
{
	//Suma del acumulado
	if (i < 10 && i > 0 && !salioacu)
	{
		acu = acu + 20000000;
	}
	else if (i < 20 && i + 1 > 10 && !salioacu) {
		acu = acu + 30000000;
	}
	return acu;
}
//Generar un numero random para elegir el premio
int GenPremios(int premios[],int veces_disponibles[])
{
	srand(time(NULL));
	int premio_elegido;
	do {
		premio_elegido = rand() % 7;
	} while (veces_disponibles[premio_elegido] == 0);
	veces_disponibles[premio_elegido]--;
	return premios[premio_elegido];
}

int main()
{
	//Seed del generador random
	srand(time(NULL));
	int acu = 100000000, acudis = 1, d = 10, dd = 10, ds = 16, ddd = 10, dos = 2, u = 1,acudiv,cantidadDePremios = 49;
	int Pelegidos[50];
	int numeroG[50],numeroGExtra[60];
	int serieG[50],serieGExtra[60];
	bool salioacu = false,bolitaB = false,SorteoExtra = false;
	for (int i = 0; i <= 49; i++)
	{
		if(i == 49 && SorteoExtra)
		{
			break;
		}
		if(i >= 11 && !salioacu && !bolitaB)
		{
			system("CLS");
			acudis++;
			bolitaB = true;
			cout << "Una nueva bolita de acumulado ha sido agregada!"<<endl;
			Sleep(2000);
			system("ClS");
		}else if(i >= 20 && !salioacu && !SorteoExtra)
		{
			system("CLS");
			acudis = 0;
			SorteoExtra = true;
			acudiv = acu / 60;
			cantidadDePremios = 48;
			cout << "El acumulado no salio, por lo tanto el premio se dividira en 60 partes iguales al final del sorteo";
			Sleep(5000);
			system("CLS");
		}
		
		acu = acumulado(acu, i,salioacu);
		int premios[] = { 2000000, 2500000, 3000000, 5000000, 10000000, 15000000,acu };
		int veces_disponibles[] = { d, dd, ds, ddd, dos, u,acudis };
		system("CLS");
		//Sorteo de Numeros y Series
		numeroG[i] = rand() % 100;
		serieG[i] = rand() % 1000;
		Pelegidos[i] = GenPremios(premios, veces_disponibles);
		//Cada vez que salga un premio, disminuye la cantidad de veces que este esta disponible
		switch (Pelegidos[i])
		{
		case 2000000:
			d--;
			break;
		case 2500000:
			dd--;
			break;
		case 3000000:
			ds--;
			break;
		case 5000000:
			ddd--;
			break;
		case 10000000:
			dos--;
			break;
		case 15000000:
			u--;
			break;
		default:
			break;
		}
		if(Pelegidos[i] == acu)
		{
			cout << "Salio el acumulado! con el valor de: " << acu<<endl;
			Sleep(2000);
			system("CLS");
			salioacu = true;
			acudis = 0;
		}
		cout << "Tirada numero " << i + 1 << endl;
		cout << "Ganador #" << i + 1 << ": " << numeroG[i] << " Con la serie: " << serieG[i]<<" y su premio: "<<Pelegidos[i] << endl;
		cout << endl << endl;
		if (!salioacu)
		{
			cout << "Valor del acumulado: " << acu << " de colones" << endl;
		}
		cout << endl << "Premios restantes:"<<endl;
		for(int k = 0;k <= 6;k++)
		{
			
			cout <<premios[k]<< ": " << veces_disponibles[k]<<endl;
		}
		system("pause");
		Sleep(1231.120201001);
	}
	Sleep(4000);
	system("CLS");
	cout << endl << "lista de ganadores:" << endl;
	
	for (int i = 0; i <= cantidadDePremios; i++)
	{
		if(Pelegidos[i] == acu)
		{
			cout << numeroG[i] << " serie: " << serieG[i] << " premio: " << "ACUMULADO! ("<<Pelegidos[i]<<")" << endl;
		}
		else {
			cout << numeroG[i] << " serie: " << serieG[i] << " premio: " << Pelegidos[i] << endl;
		}
	}
	if (SorteoExtra)
	{
		cout << "Para iniciar con el sorteo"<<endl;
		system("pause");
		system("CLS");
		cout << endl << endl << "Los siguientes numeros tienen premio extra de: " << acudiv << endl;
		Sleep(3000);
		for (int i = 0; i <= 59; i++)
		{
			system("CLS");
			cout << "Sorteo Extra #" << i + 1;
			numeroGExtra[i] = rand() % 100;
			serieGExtra[i] = rand() % 1000;
			cout << "Numero: " << numeroGExtra[i] << " Serie: " << serieGExtra[i]<<endl;
			system("pause");
			Sleep(1000);
		}
		cout << "Ganadores Principales"<<endl;
		for (int i = 0; i <= cantidadDePremios; i++)
		{
			if (Pelegidos[i] == acu)
			{
				cout << numeroG[i] << " serie: " << serieG[i] << " premio: " << "ACUMULADO! (" << Pelegidos[i] << ")" << endl;
			}
			else {
				cout << numeroG[i] << " serie: " << serieG[i] << " premio: " << Pelegidos[i] << endl;
			}
		}
		cout << "Ganadores Extra:"<<endl;
		for(int i = 0; i <= 59;i++)
		{
			cout << "Numero: " << numeroGExtra[i] << " Serie: " << serieGExtra[i]<<" Con premio de: "<<acudiv<<endl<<endl<<endl;
		}
		cout << endl << "Para terminar todos los sorteos:";
		system("pause");
	}
	return 0;
}
