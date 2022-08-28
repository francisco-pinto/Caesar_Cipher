#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "lab.h"


void Menu(char *);
void Desencripta(char *);
void SubtraiLetras(char *, char *, int);
void abecedario(char *);
void Inserir(char *);
void Encripta(char *, char *);
void SomaLetras(char *, int, char *);


void main(){

	char abc[26];
	
	SetConsoleTitle("Cifra de Cesar");
	//Preenche vetor com abecedario
	abecedario(abc);
	
	Menu(abc);
}

void Menu(char *abc){
	
	char key = ' ';
	char frase[100000];
	
	system("cls");
	
	gotoxy(1, 1);
	printf("                                      _       _     \n"          
"  ___ __ _  ___  ___  __ _ _ __    ___(_)_ __ | |__   ___ _ __ \n"
" / __/ _` |/ _ \\/ __|/ _` | '__|  / __| | '_ \\| '_ \\ / _ \\ '__|\n"
"| (_| (_| |  __/\\__ \\ (_| | |    | (__| | |_) | | | |  __/ |   \n"
" \\___\\__,_|\\___||___/\\__,_|_|     \\___|_| .__/|_| |_|\\___|_|  \n" 
"                                        |_|                    \n");


	gotoxy(30, 14);
	printf("1 - Encriptar");
	
	gotoxy(30, 16);
	printf("2 - Desencriptar");
	
	gotoxy(30, 18);
	printf("3 - Sair\n");
	

	do{
		key = getch();
	
		switch(key){
			case '1':
				Inserir(frase);
				Encripta(frase, abc);
				break;	
			case '2':
				Desencripta(abc);
				break;
			case '3':
				exit(1);
				break;	
			case '4':
				gotoxy(0, 20);
				printf("Insira um valor correto");
		}
	}while(key != '1' && key != '2' && key != '3');
}

void Desencripta(char *abc){
	
	char texto[100000];
	int flag = 0, rotacao = 0, i = 0;
	
	system("cls");
	
	printf("Insira o texto a desincriptar: ");
	gets(texto);
	
	//Número de rotações a fazer
	do{
		/*Flagg serve para que 
		a rotação seja entre 0 e 26*/
		flag = 0;
		printf("Insira o numero de rotacoes a inserir(de 0 a 26): ");
		scanf("%d", &rotacao);
		
		if(rotacao > 26 || rotacao < 0){
			flag = 1;
		}
	}while(flag == 1);
	
	SubtraiLetras(abc, texto, rotacao);
	
	/*Fazer print no ecra*/
	printf("Frase desencriptada: ");
	for(i = 0; i < strlen(texto); i++){
		printf("%c", texto[i]);
	}
	
	getch();
	fflush(stdin);
	Menu(abc);
}

void SubtraiLetras(char *abc, char* texto, int rotacao){
	
	int i = 0;
	int letra = 0;
	int valor = 0;
	/*Valor irá servir para calcular o num
	de rotaçºoes que faltam, voltando ao 
	início do abecedário*/
	
	system("cls");
	
	while(texto[i] != '\0'){
		
		//Letras minusculas
		if(texto[i] > 96 && texto[i] < 123){
			letra = texto[i] - rotacao;
			
			if(letra > 96 && letra < 123){
				texto[i] = letra;			
			}else{
				/*Calcula a posição da letra 
				do alfabeto para a qual a 
				letra vai mudar*/
				valor = 26 - (96 - (texto[i] - rotacao));
				texto[i] = abc[valor];
			}
			i++;
		//Letras maiusculas	
		}else if(texto[i] > 64 && texto[i] < 91){
			letra = texto[i] - rotacao;
			
			if(letra > 64 && letra < 91){
				texto[i] = letra;			
			}else{
				/*Calcula a posição da letra 
				do alfabeto para a qual a 
				letra vai mudar*/
				valor = 26 - (96 - (texto[i] - rotacao));
				texto[i] = abc[valor];
			}
			i++;
		}else if(texto[i] == ' '){
			texto[i] = texto[i];
			i++;
		}
	}
}

void abecedario(char *abc){
	
	int i = 0, j = 0;
	
	//Atribui cada posição à letra do abecedário
	for(i = 0; i < 26; i++){
		abc[i] = 97+i;
	}
} 

void Encripta(char *frase, char *abc){
	
	int rotacao = 0;
	int i = 0, flag = 0;
	char LetraI = ' ';
	FILE *F = NULL;
	
	F = fopen("Encriptação.txt", "w");
	
	if(F == NULL){
		printf("Nao foi possivel criar um ficheiro");
	}
	
	//Passa Palavra para ficheiro
	fprintf(F, "Palavra: %s\n", frase);
	
	//Número de rotações a fazer
	do{
		/*Flag serve para que 
		a rotação seja entre 0 e 26*/
		flag = 0;
		printf("Insira o numero de rotacoes a inserir(de 0 a 26): ");
		scanf("%d", &rotacao);
		
		if(rotacao > 26 || rotacao < 0){
			flag = 1;
		}
	}while(flag == 1);
	
	//Troca a posição das letras(Encripta)
	SomaLetras(frase, rotacao, abc);
	
	//Passa Palavra encriptada para ficheiro
	fprintf(F, "Palavra: %s\n", frase);
	fclose(F);
	
	/*Fazer print no ecra*/
	printf("Frase encriptada: ");
	for(i = 0; i < strlen(frase); i++){
		printf("%c", frase[i]);
	}
	
	getch();
	fflush(stdin);
	Menu(abc);
	
}

void SomaLetras(char *frase, int rotacao, char *abc){
	
	int i = 0;
	int letra = 0;
	int valor = 0;
	/*Valor irá servir para calcular o num
	de rotaçºoes que faltam, voltando ao 
	início do abecedário*/
	
	system("cls");
	
	while(frase[i] != '\0'){
		
		//Letras minusculas
		if(frase[i] > 96 && frase[i] < 123){
			letra = frase[i] + rotacao;
			
			if(letra > 96 && letra < 123){
				frase[i] = letra;			
			}else{
				/*Calcula a posição da letra 
				do alfabeto para a qual a 
				letra vai mudar*/
				valor = ((frase[i] + rotacao) - 123);
				frase[i] = abc[valor];
			}
			i++;
		//Letras maiusculas	
		}else if(frase[i] > 64 && frase[i] < 91){
			letra = frase[i] + rotacao;
			
			if(letra > 64 && letra < 91){
				frase[i] = letra;			
			}else{
				/*Calcula a posição da letra 
				do alfabeto para a qual a 
				letra vai mudar*/
				valor = ((frase[i] + rotacao) - 91);
				frase[i] = abc[valor];
			}
			i++;
		}else if(frase[i] == ' '){
			frase[i] = frase[i];
			i++;
		}
	}	
}

void Inserir(char *frase){
	
	int i = 0;
	
	system("cls");
	
	printf("Insira o texto: ");
	gets(frase);
}
