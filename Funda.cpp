#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

using namespace std;

int acumulado(int Acumulado,int i,bool salioacu)
{
	//Suma del acumulado
	//Si "i" es menor a 10 y mayor a 0 y no ha salido el acumulado, entonces suma 20000000 al valor del acumulado
	if (i < 10 && i > 0 && !salioacu)
	{
		Acumulado = Acumulado + 20000000;
	}
	else if (i < 20 && i + 1 > 10 && !salioacu) {
		Acumulado = Acumulado + 30000000;
	}
	return Acumulado;
}
//Generar un numero random para elegir el premio
int GenPremios(int acudis, int disponibilidadDelPremioUno, int disponibilidadDelPremioDos, int disponibilidadDelPremioTres, int disponibilidadDelPremioCuatro, int disponibilidadDelPremioCinco, int disponibilidadDelPremioSeis, int Acumulado)
{
	int premio,Nrandom;
	srand(time(nullptr)); //random sea aleatorio
	//este bucle no parará hasta que alguno de estos if se cumple
	while(true)
	{
		Nrandom = rand() % 51;
		//Si Nrandom es menor o igual a 9 y la disponibilidad es mayor que 0 entonces el premio será de 2 millones
		if(Nrandom <= 9 && disponibilidadDelPremioUno > 0)
		{
			disponibilidadDelPremioUno--;
			premio = 2000000;
			return premio;
		}else if(Nrandom <= 19 && disponibilidadDelPremioDos > 0)
		{
			disponibilidadDelPremioDos--;
			premio = 2500000;
			return premio;
		}else if(Nrandom <= 35 && disponibilidadDelPremioTres > 0)
		{
			disponibilidadDelPremioTres--;
			premio = 3000000;
			return premio;
		}else if(Nrandom <= 45 && disponibilidadDelPremioCuatro > 0)
		{
			disponibilidadDelPremioCuatro--;
			premio = 5000000;
			return premio;
		}else if(Nrandom <= 47 && disponibilidadDelPremioCinco > 0)
		{
			disponibilidadDelPremioCinco--;
			premio = 10000000;
			return premio;
		}else if(Nrandom == 48 && disponibilidadDelPremioSeis > 0)
		{
			disponibilidadDelPremioSeis--;
			premio = 15000000;
			return premio;
		}else if(Nrandom == 49 && acudis == 1)
		{
			acudis--;
			premio = Acumulado;
			return premio;
		}else if(Nrandom > 48 && Nrandom < 50 && acudis == 2)
		{
			acudis--;
			premio = Acumulado;
			return premio;
		}
	}
}
int main()
{
	//Seed del generador random con la libreria de tiempo
	srand(time(nullptr));
	//Declaramos todas las variables de tipo Int (Todos los enteros)
	int Acumulado = 100000000, acudis = 1, disponibilidadDelPremioUno = 10, disponibilidadDelPremioDos = 10, disponibilidadDelPremioTres = 16, disponibilidadDelPremioCuatro = 10, disponibilidadDelPremioCinco = 2, disponibilidadDelPremioSeis = 1,acudiv,premioElegido,numeroG, numeroGExtra, serieG, serieGExtra;
	//Declaramos todlas las variables de tipo bool (son verdaderas o falsas)
	bool salioAcu = false,bolitaB = false,SorteoExtra = false;
	//Comienza todo le programa dentro de un bucle "for" que va del 0 al 49
	for (int i = 0; i <= 49; i++)
	{
		//Si hay sorteo extra, el bucle termina en 49
		if(i == 49 && SorteoExtra)
		{
			break; //break termina el bucle
		}
		//Si "i" es mayor o igual a 11 y no ha salido el acumulado y no hay bolita extra, entonces, añade una bolita del acumulado
		if(i >= 11 && !salioAcu && !bolitaB)
		{
			system("CLS"); //se necesita una libreria llamada <stdlib.h>
			acudis++;
			bolitaB = true;
			cout << "				Una nueva bolita de acumulado ha sido agregada!"<<endl;
			Sleep(3000); //Espera 3 segundos
			system("ClS");
		}else if(i >= 20 && !salioAcu && !SorteoExtra) //si i es mayor o igual a 20 y no ha salido el acumulado y no hay sorteo extra
		{
			system("CLS");
			acudis = 0;
			SorteoExtra = true;
			acudiv = Acumulado / 60;
			cout << "		El acumulado no salio, por lo tanto el premio se dividira en 60 partes iguales al final del sorteo";
			Sleep(5000); //Espera 5s
			system("CLS");
		}
		
		Acumulado = acumulado(Acumulado, i, salioAcu);
		system("CLS");
		//Sorteo de Numeros y Series
		numeroG = rand() % 100;
		serieG = rand() % 1000;
		premioElegido = GenPremios(acudis,disponibilidadDelPremioUno,disponibilidadDelPremioDos,disponibilidadDelPremioTres,disponibilidadDelPremioCuatro,disponibilidadDelPremioCinco,disponibilidadDelPremioSeis,Acumulado);
		//Cada vez que salga un premio, disminuye la cantidad de veces que este esta disponible
		switch (premioElegido)
		{
		case 2000000:
			disponibilidadDelPremioUno--;
			break;
		case 2500000:
			disponibilidadDelPremioDos--;
			break;
		case 3000000:
			disponibilidadDelPremioTres--;
			break;
		case 5000000:
			disponibilidadDelPremioCuatro--;
			break;
		case 10000000:
			disponibilidadDelPremioCinco--;
			break;
		case 15000000:
			disponibilidadDelPremioSeis--;
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
		cout << "				|   2000000             |                " << disponibilidadDelPremioUno << "	|" << endl;
		cout << "				-------------------------------------------------"<<endl;
		cout << "				|   2500000             |                " << disponibilidadDelPremioDos << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   3000000             |                " << disponibilidadDelPremioTres << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   5000000             |                " << disponibilidadDelPremioCuatro << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   10000000            |                " << disponibilidadDelPremioCinco << "	|" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   15000000            |                " << disponibilidadDelPremioSeis << "	|" << endl;
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
