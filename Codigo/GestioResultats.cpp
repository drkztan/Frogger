#include "GestioResultats.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void iniciaTaulaTopPlayers(TipusJugador TMillorsJugadors[])
{
	int i;
	for (i = 0; i < MAX_MILLORSJUGADORS; i++)
	{
		strcpy(TMillorsJugadors[i].nom, "--------------");
		TMillorsJugadors[i].puntuacio = 0;
	}
}

int haMilloratPuntuacio(TipusJugador TMillorsJugadors[], int punts)
{
	int i = 0;
	int trobat = 0;

	do
	{
		if (TMillorsJugadors[i].puntuacio < punts)
		{
			trobat = 1;
		}
		i++;
	} while ((i < MAX_MILLORSJUGADORS) && (!trobat));
	if (trobat)
	{
		return (i - 1);
	}
	else
	{
		return -1;
	}
}

void desplacaArray(TipusJugador TMillorsJugadors[], int posicio)
{
	int i;

	for (i = MAX_MILLORSJUGADORS - 1; i > posicio; i--)
	{
		strcpy(TMillorsJugadors[i].nom, TMillorsJugadors[i - 1].nom);
		TMillorsJugadors[i].puntuacio = TMillorsJugadors[i - 1].puntuacio;
	}
}

void emplenaPosicioArray(TipusJugador &TMillorsJugadors, int punts)
{
	printf("Enter your name\n");
	scanf("%s", &(TMillorsJugadors.nom));
	(TMillorsJugadors).puntuacio = punts;
}

void escriuRanking(TipusJugador TMillorsJugadors[])
{
	int i;
	for (i = 0; i < MAX_MILLORSJUGADORS; i++)
	{
		printf("%d.- %s %d\n", i + 1, TMillorsJugadors[i].nom, TMillorsJugadors[i].puntuacio);
	}
}
