#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

//coloca o Cursor na posicao X,Y
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


//desenha um retangulo com linhas duplas na posicao X,Y com as dimensoes Width e Height 
void drawRect(int x, int y, int width, int height)
{
	int i;
	gotoxy(x, y);
	printf("%c", 201);
	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 187);
	gotoxy(x, height + y);
	printf("%c", 200);

	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 188);

	for (i = y + 1; i < height + y; i++)
	{
		gotoxy(x, i);
		printf("%c", 186);

		gotoxy(x + width, i);
		printf("%c", 186);

	}
}

void instrucoes()
{
	printf("1. Regras do jogo :\n"
		"Inicio do jogo:\n"
		"\n\tPasso 1: Baralham-se as cartas e distribuem-se 7 cartas a cada jogador"
		"— mão do jogo;\n"
		"\tPasso 2: Coloca-se 1 carta no centro da mesa de jogo"
		"Turno: uma sequência de rodadas.\n"
		"\tPasso 3: rodada — cada jogador joga uma vez. Cada jogador joga de"
		"acordo com as seguintes regras:\n\n"
		"\t\t1. Escolhe a carta de valor mais alto. Mas também a de valor"
		"numérico mais próximo da última carta colocada no centro da\n"
		"\t\tmesa; coloca na mesa a carta selecionada em cima das cartas"
		"existentes;"
		"\n\t\tObservação: É obrigatório jogar uma carta de valor superior à carta da mesa,"
		"caso possua uma. No entanto a escolha da carta mais\n\t\tpróxima do valor"
		" numérico da carta da mesa é opcional."
		"\n\t\t2. Se apenas possuir cartas com um número inferior à última carta"
		"do centro da mesa, recolhe a série de cartas em jogo (as cartas do\n"
		"\t\tcentro da mesa), que guarda num monte à parte — o monte"
		"pessoal; retira depois uma carta do baralho que coloca no centro"
		"da mesa;"
		"\n\t\t3. As cartas recolhidas em cada rodada são colocadas no seu monte "
		"pessoal, que vai empilhando até ao fim do jogo;Esta sequência de \n\t\tações é repetida por cada jogador, em cada rodada.\n"
		"\t\tRepetem-se as rodadas até que todos os jogadores fiquem sem cartas: fim "
		"de turno."
		"\n\n\tPasso 4: Quando acaba o turno, conta-se o número de cabeças de boi do "
		"monte pessoal de cada jogador nesse turno e o jogo reinicia-se (voltar \n\t\t para "
		"Passo 1)."
		"Os turnos repetem-se até que algum dos jogadores atinja 66 cabeças de "
		"boi."
		"\n\n\tPasso 5: O vencedor é declarado com base no menor número de cabeças "
		"de boi."); 
}

