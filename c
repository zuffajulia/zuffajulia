/*Exercícios struct*/
/*1-Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado e calculo, o numero de dias entre elas e mostre o resultado no
    video. (vetor de estruturas)
                dia, mes, ano*/
#include <stdio.h>
#include<locale.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

int fev29 (int ano);
unsigned long dist_dias (Data1, Data2);


 /* numero de dias de cada mes(1 vetor para ano bissexto)*/
int dias_mes[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void) {
	Data diaa, diab;
setlocale(LC_ALL,"");
	printf("data incial no formato: dd/mm/aaaa (o usuário deve colocar a /)\n");
	scanf("%d/%d/%d", &diaa.dia, &diaa.mes, &diaa.ano);
	printf("data final no formato: dd/mm/aaaa (o usuário deve colocar a /)\n");
	scanf("%d/%d/%d", &diab.dia, &diab.mes, &diab.ano);

	printf("A distancia em dias: %lu\n", dist_dias (diaa, diab));
	printf("Digite qualquer tecla para encerrar");
	getch();


}


int fev29 (int ano) {
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

unsigned long dist_dias (Data inicio, Data fim) {
	unsigned long idias, fdias;
	unsigned long def_anos = 0;
	register int i;
	int dbissexto;

	idias = inicio.dia;
	dbissexto = fev29 (inicio.ano);
	for (i = inicio.mes - 1; i > 0; --i)
		idias += dias_mes[dbissexto][i];

	fdias = fim.dia;
	dbissexto = fev29 (fim.ano);

	for (i = fim.mes - 1; i > 0; --i)
		fdias += dias_mes[dbissexto][i];

	while (inicio.ano < fim.ano)
		def_anos += 365 + fev29(inicio.ano++);

	return def_anos - idias + fdias;
}


