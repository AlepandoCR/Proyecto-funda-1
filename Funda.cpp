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
int GenPremios(int acudis, int d, int dd, int ds, int ddd, int dos, int u, int acu)
{
	int premio,Nrandom;
	srand(time(NULL));
	while(true)
	{
		Nrandom = rand() % 51;
		if(Nrandom <= 9 && d > 0)
		{
			d--;
			premio = 2000000;
			return premio;
		}else if(Nrandom <= 19 && dd > 0)
		{
			dd--;
			premio = 2500000;
			return premio;
		}else if(Nrandom <= 35 && ds > 0)
		{
			ds--;
			premio = 3000000;
			return premio;
		}else if(Nrandom <= 45 && ddd > 0)
		{
			ddd--;
			premio = 5000000;
			return premio;
		}else if(Nrandom <= 47 && dos > 0)
		{
			dos--;
			premio = 10000000;
			return premio;
		}else if(Nrandom == 48 && u > 0)
		{
			u--;
			premio = 15000000;
			return premio;
		}else if(Nrandom == 49 && acudis == 1)
		{
			acudis--;
			premio = acu;
			return premio;
		}else if(Nrandom > 48 && Nrandom < 50 && acudis == 2)
		{
			acudis--;
			premio = acu;
			return premio;
		}
	}
}
int main()
{
	//Seed del generador random
	srand(time(NULL));
	int Acumulado = 100000000, acudis = 1, d = 10, dd = 10, ds = 16, ddd = 10, dos = 2, u = 1,acudiv,premioElegido,numeroG, numeroGExtra, serieG, serieGExtra;
	bool salioAcu = false,bolitaB = false,SorteoExtra = false;
	for (int i = 0; i <= 49; i++)
	{
		if(i == 49 && SorteoExtra)
		{
			break;
		}
		if(i >= 11 && !salioAcu && !bolitaB)
		{
			system("CLS");
			acudis++;
			bolitaB = true;
			cout << "				Una nueva bolita de acumulado ha sido agregada!"<<endl;
			Sleep(3000);
			system("ClS");
		}else if(i >= 20 && !salioAcu && !SorteoExtra)
		{
			system("CLS");
			acudis = 0;
			SorteoExtra = true;
			acudiv = Acumulado / 60;
			cout << "		El acumulado no salio, por lo tanto el premio se dividira en 60 partes iguales al final del sorteo";
			Sleep(5000);
			system("CLS");
		}
		
		Acumulado = acumulado(Acumulado, i,salioAcu);
		system("CLS");
		//Sorteo de Numeros y Series
		numeroG = rand() % 100;
		serieG = rand() % 1000;
		premioElegido = GenPremios(acudis,d,dd,ds,ddd,dos,u,Acumulado);
		//Cada vez que salga un premio, disminuye la cantidad de veces que este esta disponible
		switch (premioElegido)
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
		if(premioElegido == Acumulado)
		{
			cout << "				Salio el acumulado! con el valor de: " << Acumulado << endl;
			Sleep(2000);
			system("CLS");
			salioAcu = true;
			acudis = 0;
		}
		cout << "		---------------------------------------------------------------------------------" << endl;
		cout << "		|				    Tirada numero " << i + 1 << "				|" << endl;
		cout << "		|		Ganador #" << i + 1 << ": " << numeroG << " Con la serie: " << serieG<<" y su premio: "<< premioElegido << "		|" << endl;
		cout << "		---------------------------------------------------------------------------------" << endl;
		cout << endl << endl;
		cout << "				-------------------------------------------------";
		cout << endl << "				|   Premios	  	|   	     Restantes  |"<<endl;
		cout << "				-------------------------------------------------"<<endl;
		cout << "				|   2000000             |                " << d << "	|" << endl;
		cout << "				-------------------------------------------------"<<endl;
		cout << "				|   2500000             |                " << dd << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   3000000             |                " << ds << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   5000000             |                " << ddd << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   10000000            |                " << dos << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   15000000            |                " << u << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   Acumulado           |                " << acudis << "	|" << endl;
		cout << "				-------------------------------------------------"<<endl<<endl;
		if (!salioAcu && !SorteoExtra)
		{
			cout << "	    -#-#-#-#-#-#-#-#-#-#-#- Valor del acumulado: " << Acumulado << " de Colones -#-#-#-#-#-#-#-#-#-#-#-" << endl << endl;
		}
		system("pause");
		Sleep(1231.120201001);
	}
	Sleep(2000);
	if (SorteoExtra)
	{
		system("CLS");
		cout << "Para iniciar con el sorteo extra"<<endl<<endl;
		system("pause");
		system("CLS");
		cout << endl << endl << "Los siguientes numeros tienen premio extra de: " << acudiv << "colones" << endl;
		Sleep(3000);
		for (int i = 0; i <= 59; i++)
		{
			system("CLS");
			cout << "+---------------------------------------------------+\n";
			cout << "|                   Sorteo Extra #" << i + 1 << "                  |\n";
			cout << "|---------------------------------------------------|\n";
			numeroGExtra = rand() % 100;
			serieGExtra = rand() % 1000;
			cout << "|  Numero: " << numeroGExtra << "  Serie: " << serieGExtra;
			cout << "  Premio: " << acudiv << "         |\n";
			cout << "+---------------------------------------------------+\n";
			system("pause");
			Sleep(1000);
		}
	}
	system("CLS");
	cout << endl << endl << "Para terminar todos los sorteos:";
	system("pause");
	return 0;
}
