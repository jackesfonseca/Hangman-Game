/*
HANGMAN  - THE GAME
Versão 2.14.20

O projeto visa desenvolver uma versão simples do Hangman Game 
usando características da linguagem orientada a objetos como classe, encapsulamente além do uso de ponteiro.

Por Jackes Tiago Ferreira da fonseca
*/

#include <iostream>
#include <stdlib.h>
#define TAM 30
#define MAX 100

using namespace std;

class Forca
{
public:
	char palavra[TAM], letra[1], secreta[TAM], dica[MAX];
	int i, tam, chances, acertos;
	bool acerto;
	
	int tamanho_palavra(char palavra[]);
	void preenche_secreta();
	void jogo();
};

int Forca::tamanho_palavra(char palavra[])
{
	while(palavra[i] != '\0')
	{
		tam++;
		i++;
	}
	return tam;
}

void Forca::preenche_secreta()
{
	for(i=0; i<30;acerto>i++)
	{
		secreta[i] = '-';
	}
}

void Forca::jogo()
{
	while(chances > 0 && acertos < tam)
	{
		cout << "Chances " << chances << endl << endl;
		cout << "Dica: " << dica << endl << endl;
		cout << "Palavra secreta: ";
		for(i=0; i<tam; i++)
		{
			cout << secreta[i];
		}
		cout << endl << endl;
		cout << "Informe uma letra: ";
		cin >> letra[0];
		
		for(i=0; i<tam; i++)
		{
			if(letra[0] == palavra[i])
			{
				acerto = true;
				secreta[i] = palavra[i];
				acertos++;
			}
		}
		if(!acerto)
		{
			chances--;
		}
		acerto = false;
		system("cls");	
	}
	
	if(acertos == tam)
	{
		cout << "Game won!" << endl << endl;	
	}
	else
	{
		cout << "Game lose!" <<  endl << endl;	
	}
}

int main(int argc, char* argv[])
{
	Forca jogo;
	Forca* j = &jogo;
	
	j->chances = 6;
	j->acerto = 0;
	j->i = 0;
	j->tam = 0;
	j->acerto = false;
	
	cout << "Hangman - The Game" << endl << endl;
	cout << "Informe a palavra secreta: ";
	cin >> j->palavra;
	cout << "Dica: ";
	cin >> j->dica;
	
	j->tamanho_palavra(j->palavra);
	
	system("cls");
	
	j->preenche_secreta();
	
	j->jogo();
	
	system("pause");
	
	return 0;
}
