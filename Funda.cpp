#include <iostream>
#include <cstdlib> //System, random, etc..
#include <ctime> //Tiempo (utilizado para el valor random)
#include <windows.h> //Sleep




//Tareas Pendientes
//Invertir la tabla de los premios
//Revisar la funcion del acumulado acorde con lo que dicen las indicaciones
//Replantear los premios extra acorde a como se presenta en las indicaciónes
//Revisar los momentos en los que se sacan bolitas de la tombola



using namespace std;
int actualizaAcumulado(int& Acumulado, int i, bool& salioAcu, int& acudis, int& disponibilidadDelPremioUno, int& disponibilidadDelPremioDos, int& disponibilidadDelPremioTres, int& disponibilidadDelPremioCuatro, int& disponibilidadDelPremioCinco, int& disponibilidadDelPremioSeis, int& premioElegido, double& premioSimplificado, int& premiosExtra, bool& bolitaB, bool noSumarAcumulado,int& premioElegidoDos)
{
	//Suma del acumulado
	//Si "i" es menor a 10 y mayor a 0 y no ha salido el acumulado, entonces suma 20000000 al valor del acumulado
	if(!salioAcu && !noSumarAcumulado){
		if (i <= 10 && i > 0)
		{
			Acumulado += 20000000;
		}
		else if (i <= 20 && i + 1 >= 11) {
			Acumulado += 30000000;
		}
	}
	//Disminuir cantidad de premios disponibles según la primera bolita que salga
	if (!noSumarAcumulado) {
		switch (premioElegido)
		{
		case 2000000:
			disponibilidadDelPremioUno--;
			break;
		case 2500000:
			disponibilidadDelPremioDos--;
			premioSimplificado = 2.5;
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
	}
	//Disminuir la cantidad de premios según una segunda bolita de premio
	if (noSumarAcumulado) {
		switch (premioElegidoDos)
		{
		case 2000000:
			disponibilidadDelPremioUno--;
			break;
		case 2500000:
			disponibilidadDelPremioDos--;
			premioSimplificado = 2.5;
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
	}
	
	//Cantidad de bolitas de premio extra
	premiosExtra = disponibilidadDelPremioUno + disponibilidadDelPremioDos + disponibilidadDelPremioTres + disponibilidadDelPremioCuatro + disponibilidadDelPremioCinco + disponibilidadDelPremioSeis;
	//Cantidad de bolitas del acumulado
	if (i >= 10 && !salioAcu && !bolitaB)
	{
		acudis++;
		bolitaB = true;
	}
	return Acumulado;
}
//Generar un numero random para elegir el premio
int sorteePremios(int acudis, int disponibilidadDelPremioUno, int disponibilidadDelPremioDos, int disponibilidadDelPremioTres, int disponibilidadDelPremioCuatro, int disponibilidadDelPremioCinco, int disponibilidadDelPremioSeis, int Acumulado)
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
			premio = 2000000;
			return premio;
		}else if(Nrandom <= 19 && disponibilidadDelPremioDos > 0)
		{
			premio = 2500000;
			return premio;
		}else if(Nrandom <= 35 && disponibilidadDelPremioTres > 0)
		{
			premio = 3000000;
			return premio;
		}else if(Nrandom <= 45 && disponibilidadDelPremioCuatro > 0)
		{
			premio = 5000000;
			return premio;
		}else if(Nrandom <= 47 && disponibilidadDelPremioCinco > 0)
		{
			premio = 10000000;
			return premio;
		}else if(Nrandom == 48 && disponibilidadDelPremioSeis > 0)
		{
			premio = 15000000;
			return premio;
		}else if(Nrandom == 49 && acudis == 1)
		{
			premio = Acumulado;
			return premio;
		}else if(Nrandom > 48 && Nrandom < 50 && acudis == 2)
		{
			premio = Acumulado;
			return premio;
		}
	}
}
void reiniciar(int& Acumulado, int& acudis, int& disponibilidadDelPremioUno, int& disponibilidadDelPremioDos, int& disponibilidadDelPremioTres, int& disponibilidadDelPremioCuatro, int& disponibilidadDelPremioCinco, int& disponibilidadDelPremioSeis, int& i, bool& salioAcu, bool& bolitaB)
{
	Acumulado = 100000000;
	acudis = 1;
	disponibilidadDelPremioUno = 10;
	disponibilidadDelPremioDos = 10;
	disponibilidadDelPremioTres = 16;
	disponibilidadDelPremioCuatro = 10;
	disponibilidadDelPremioCinco = 2;
	disponibilidadDelPremioSeis = 1;
	i = -1;
	salioAcu = false;
	bolitaB = false;

}
int main()
{
	//Seed del generador random con la libreria de tiempo
	srand(time(nullptr));
	//Declaramos todas las variables de tipo Int (Todos los enteros)
	int Acumulado = 100000000, acudis = 1, disponibilidadDelPremioUno = 10, disponibilidadDelPremioDos = 10, disponibilidadDelPremioTres = 16, disponibilidadDelPremioCuatro = 10, disponibilidadDelPremioCinco = 2, disponibilidadDelPremioSeis = 1, premioElegido, numeroG, serieG, Continuar, proximoAcumulado, premiosExtra,NuSorteo = 1000,premioElegidoDos = 0,premioSimplificadoDos = 0;
	//Declaramos todlas las variables de tipo bool (son verdaderas o falsas)
	bool salioAcu = false, bolitaB = false, noSumarAcumulado = false;
	//Utilizaremos esta variable para poder dividir el premio en 1 millon
	double premioSimplificado;
	//Comienza todo le programa dentro de un bucle "for" que va del 0 al 49
	for (int i = 0; i <= 49; i++)
	{
		NuSorteo++;
		if (i <= 9) {
			proximoAcumulado = 20;
		}
		else if (i >= 10) {
			proximoAcumulado = 30;
		}
		//Sorteo de Numeros y Series
		numeroG = rand() % 100;
		serieG = rand() % 1000;
		premioElegido = sorteePremios(acudis, disponibilidadDelPremioUno, disponibilidadDelPremioDos, disponibilidadDelPremioTres, disponibilidadDelPremioCuatro, disponibilidadDelPremioCinco, disponibilidadDelPremioSeis, Acumulado);
		premioSimplificado = premioElegido / 1000000;
		noSumarAcumulado = false;
		Acumulado = actualizaAcumulado( Acumulado,i,  salioAcu, acudis,  disponibilidadDelPremioUno,  disponibilidadDelPremioDos, disponibilidadDelPremioTres,  disponibilidadDelPremioCuatro,disponibilidadDelPremioCinco,disponibilidadDelPremioSeis, premioElegido,premioSimplificado,  premiosExtra,bolitaB, noSumarAcumulado, premioElegidoDos);
		Sleep(1231.120201001);
		if(i >= 10){
			noSumarAcumulado = true;
			premioElegidoDos = sorteePremios(acudis, disponibilidadDelPremioUno, disponibilidadDelPremioDos, disponibilidadDelPremioTres, disponibilidadDelPremioCuatro, disponibilidadDelPremioCinco, disponibilidadDelPremioSeis, Acumulado);
			premioSimplificadoDos = premioElegidoDos / 1000000;
			Acumulado = actualizaAcumulado(Acumulado, i, salioAcu, acudis, disponibilidadDelPremioUno, disponibilidadDelPremioDos, disponibilidadDelPremioTres, disponibilidadDelPremioCuatro, disponibilidadDelPremioCinco, disponibilidadDelPremioSeis, premioElegido, premioSimplificado, premiosExtra, bolitaB, noSumarAcumulado, premioElegidoDos);
		}
		if (i >= 20 && !salioAcu) //si i es mayor o igual a 20 y no ha salido el acumulado y no hay sorteo extra
		{
			acudis = 0;
			premioElegido = Acumulado / 60;
		}
		system("CLS");

		cout << "		        Sorteo #" << i + 1 << " del premio acumulado de la loteria nacional No." << NuSorteo << endl;
		cout << "		*********************************************************************************" << endl;
		cout << "		*		Monto Acumulado: " << Acumulado/1000000 << " millones de colones			*" << endl;
		cout << "		*	       Bolitas Acumulado: " << acudis << "         Bolitas Premios Extra: " << premiosExtra << "		*" << endl;
		cout << "		*********************************************************************************" << endl << endl << endl;
		cout << "				-------------------------------------------------";
		cout << endl << "				|   Cantidad	  	|   	     Premio     |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   "<< disponibilidadDelPremioUno << "			|          2000000  " << "    |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   " << disponibilidadDelPremioDos << "			|          2500000  " << "    |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   " << disponibilidadDelPremioTres << "			|          3000000  " << "    |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   " << disponibilidadDelPremioCuatro << "			|          5000000  " << "    |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   " << disponibilidadDelPremioCinco << "			|          10000000  " << "   |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   " << disponibilidadDelPremioSeis << "			|          15000000  " << "   |" << endl;
		cout << "				-------------------------------------------------" << endl;
		cout << "				|   " << acudis << "			|          Acumulado  " << "  |" << endl;
		cout << "				-------------------------------------------------" << endl;
		if(i <= 19){
			cout << "Premio: " << premioSimplificado << " Millones de colones" << endl;
			cout << "Numero: " << numeroG << "       Serie: " << serieG << endl;
			if (i >= 10 && i < 20) {
				numeroG = rand() % 100;
				serieG = rand() % 1000;
				cout << "Premio: " << premioSimplificadoDos << " Millones de colones" << endl;
				cout << "Numero: " << numeroG << "       Serie: " << serieG << endl;
			}
			cout << "El premio del Acumulado aumenta en " << proximoAcumulado << " millones para el siguiente sorteo !!!" << endl;
		}
		else {
			cout << "Premio: " << (Acumulado/60)/1000000 << " Millones de colones" << endl;
			for (int k = i; k <= 60; k++) {
				numeroG = rand() % 100;
				serieG = rand() % 1000;
				cout << "Ganador #" << k << ": Numero:" << numeroG << "    Serie:" << serieG <<endl;
				reiniciar(Acumulado, acudis, disponibilidadDelPremioUno, disponibilidadDelPremioDos, disponibilidadDelPremioTres, disponibilidadDelPremioCuatro, disponibilidadDelPremioCinco, disponibilidadDelPremioSeis, i, salioAcu, bolitaB);
			}
		}
		if (premioElegido == Acumulado || premioElegidoDos == Acumulado)
		{
			reiniciar(Acumulado, acudis, disponibilidadDelPremioUno, disponibilidadDelPremioDos, disponibilidadDelPremioTres, disponibilidadDelPremioCuatro, disponibilidadDelPremioCinco, disponibilidadDelPremioSeis, i, salioAcu, bolitaB);
			salioAcu = true;
			acudis = 0;
		}
		cout << "Digite <1> Para continuar" << endl;
		cout << "Digite <2> Para salir" << endl;
		cin >> Continuar;
		if (Continuar != 1) {
			system("CLS");
			break;
		}
	}
}
