#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fun.h"

void menuplayer(){
	linha();
	printf("Selecione sua ação:\n\n");
	printf("0--Fazer uma jogada\n");
	printf("1--Descartar uma carta\n");
}

void desenvolvedores(){
	printf("#######    DESENVOLVEDORES     ########\n\n");
	printf("----- RENAN LUIZ BABINSKI -----\n\n");
	printf("----- CLEITON PICCINI -----\n\n");
	printf("*ALUNOS DA SEGUNDA FASE DO CURSO CIÊNCIA DA COMPUTAÇÃO DA UFFS\n\n");
	printf("---PROFESSOR : JACSON LUIZ MATTE\n");
	printf("\n\nPresione ENTER para continuar...\n");
}

void menu_principal(){
	printf("######    ESCOPA DE 15     ########\n\n\n");
	printf("1---INICIAR UM NOVO JOGO\n");
	printf("2---CREDITOS\n");
	printf("0---EXIT GAME\n");
}

TpPecaBaralho * init (){
	return NULL;
}

TpPecaBaralho * insertInicio (TpPecaBaralho *pont, int number, int naipe, int cod){
	TpPecaBaralho *novo = NULL;
	TpPecaBaralho *p = pont;
	novo = (TpPecaBaralho*) malloc (sizeof(TpPecaBaralho));
	if (novo == NULL){
		printf ("Erro, não foi possivel alocar memória\n");
		return pont;
	}
	novo->number = number;
	novo->naipe = naipe;
	novo->cod = cod;
	if(pont == NULL){
		p = novo;
		p->left = NULL;
		p->right = NULL;
		return p;
	}else{
		while (p->left != NULL){
			p = p->left;
		}
		novo->right = p;
		novo->left = NULL;
		p->left = novo;
		return novo;
	}
};

TpPecaBaralho * new_baralho (TpPecaBaralho *pont){
	int indice, cBasto = 1, cEspada = 1, cOuro = 1, cCopa = 1;
	for (indice = 0; indice < 40; indice++){
		if (indice < 10){
			pont = insertInicio (pont, cBasto, 0, indice);
			if(cBasto == 7){
				cBasto = 9;
			}
			cBasto++;
			continue;
		}
		if (indice < 20){
			pont = insertInicio (pont, cEspada, 1, indice);
			if(cEspada == 7){
				cEspada = 9;
			}
			cEspada++;
			continue;
		}
		if (indice < 30){
			pont = insertInicio (pont, cOuro, 2, indice);
			if(cOuro == 7){
				cOuro = 9;
			}
			cOuro++;
			continue;
		}
		pont = insertInicio (pont, cCopa, 3, indice);
		if(cCopa == 7){
			cCopa = 9;
		}
		cCopa++;
	}
	return pont;
};

int * lottery (int max){
	int *nRando, indice=0, comparador=0;
	nRando = (int*) malloc (40 * (sizeof(int)));
	srand(time(NULL));
	while (indice < 40){
		nRando[indice] = ( int ) ( max * ( rand () / ( RAND_MAX + 1.0 )));
		for (comparador=0; comparador < 40 && indice != comparador; comparador++){
			if (nRando[indice] == nRando[comparador]){
				indice--;
				break;
			}
		}
		indice++;
	}
	return nRando;
};

TpPecaBaralho * exclui (TpPecaBaralho *pont, int cod){
	TpPecaBaralho *p = pont, *aux;
	TpPecaBaralho *anterior = NULL;
	
	while(p != NULL && p->cod != cod){
		anterior = p;
		p = p->right;	
	}
	if(p->right == NULL && p->left == NULL)
		return NULL;

	if (p == NULL){
		printf ("Baralho vazio, ou não possui esta carta\n");
		return pont;
	}
	if (anterior == NULL){
		aux = p->right;
		aux->left = NULL;
		return aux;
	}
	if(p->right == NULL){
		anterior->right = NULL;
		return pont;
	}

	aux = p->right;
	anterior->right = aux;
	aux->left = anterior;
	
	return pont;
};

TpPecaBaralho * retiraCarta (TpPecaBaralho *pont){
	TpPecaBaralho *p = pont;
	TpPecaBaralho *retorno;
	
	if (p == NULL){
		printf ("Baralho vazio\n");
		return pont;
	}
	
	retorno = p;
	//p = p->right;	

	return retorno;
};

TpPecaBaralho * busca (TpPecaBaralho *pont, int cod){
	TpPecaBaralho *p = pont;
	TpPecaBaralho *anterior = NULL;
	
	
	while(p != NULL && p->cod != cod){
		anterior = p;
		p = p->right;	
	}
	if (p == NULL){
		printf("Baralho vazio ou não possui esta carta\n");
		return pont;
	}
	if (anterior == NULL){
		return p;
	}
	return p;
};

void print_menu (TpPecaBaralho *pont){
	TpPecaBaralho *p = pont;
	int i=0;
	
	while (p != NULL){
		printf ("(%d)  %d", i, p->number);
		if(p->naipe == 0)
			printf(" de basto\n");
		if(p->naipe == 1)
			printf(" de espada\n");
		if(p->naipe == 2)
			printf(" de ouro\n");
		if(p->naipe == 3)
			printf(" de copa\n");
		p = p->right;
		i++;
	}
};

void exibirCartas(TpPecaBaralho* Play, TpPecaBaralho* pc, TpPecaBaralho* mesa){
	int x;

	printf ("\nCARTAS DO PC\n\n");
	for(x = 0; x < contacartas(pc); x++){
		printf("(%d)  XXXXXXXXXX\n",x);
	}
	linha();
	printf ("\nCARTAS DA MESA\n\n");
	print_menu (mesa);
	linha();
	printf ("\nSUAS CARTAS\n\n");
	print_menu (Play);
}

int geth(){
	char s;
	scanf("%c",&s);
	return 0;
}

void linha(){
	int i;
	for(i=0;i<80;i++){
		printf("-");
	}
	printf("\n");
}

int valorcarta(int n){
	if(n==10 || n==11 || n==12){
		return n-2;
	}else{
		return n;
	}
};

int contacartas(TpPecaBaralho* pont){
	int cont=0;
	if(pont == NULL){
		return 0;
	}else{
		while(pont!=NULL){
			pont = pont->right;
			cont++;
		}
	}
	return cont;
}

TpPecaBaralho * search(TpPecaBaralho* carta , int i){
	while(i > 0){
		carta = carta->right;
		i--;
	}
	return carta;
}

int TesteEscopa(TpPecaBaralho* teste){
	int soma = 0;
	while(teste != NULL){
		soma += valorcarta(teste->number);
		teste = teste->right;
	}
	return soma;
}

TpPecaBaralho* CopiaMonte(TpPecaBaralho* monte, TpPecaBaralho* teste){
	while(teste != NULL){
		monte = insertInicio(monte, teste->number, teste->naipe, teste->cod);
		teste = teste->right;
	}
	return monte;
}

int potencia(int n, int e){
	int i,pot = 1;
	for(i = e; i>0 ; i--){
		pot = pot*n;
	}
	return pot;
}

int *gera_vetor(int qtdcartas, int combina ){
	int *vetor = NULL, i;
	vetor = (int*)malloc(qtdcartas*sizeof(int));
	for(i = 0; i < qtdcartas; i++){
		if(combina == 0)
			vetor[i] = combina;

		if(combina == 1){
			vetor[i] = combina;
			combina --;
		}
		if(combina > 1){
			vetor[i] = combina % 2;
			combina = combina / 2;
		}
	}
	return vetor;
}

int verificaOuro(TpPecaBaralho* monte){
	int cont;
	while(monte != NULL){
		if(monte->naipe == 2)
			cont++;
		monte = monte->right;
	}
	return cont;
}

int verificaBelo(TpPecaBaralho* monte){
	while(monte != NULL){
		if(monte->number == 7 && monte->naipe == 2){
			return 1;
		}
		monte = monte->right;
	}
	return 0;
}

int verifica7(TpPecaBaralho* monte){
	int cont;
	while(monte != NULL){
		if(monte->number == 7)
			cont++;
		monte = monte->right;
	}
	return cont;
}

void Conta_Pontos(int escopasplay, int escopasPC, TpPecaBaralho* montePlay, TpPecaBaralho* montePC){
	printf("######################   Fim de jogo!   #####################\n\n");
	printf("Seus pontos:\n\n");
	printf("--Escopas : %d\n",escopasplay);
	printf("--Ter todas as cartas de ouro : ");
	if(verificaOuro(montePlay) == 10){
		printf("2\n");
		escopasplay += 2;
	}else{
		printf("0\n");
	}
	printf("--Ter a maioria das cartas de ouro : ");
	if(verificaOuro(montePlay) > 5){
		printf("1\n");
		escopasplay += 1;
	}else{
		printf("0\n");
	}
	printf("--Ter o sete de ouro (belo) : %d \n",verificaBelo(montePlay));
	escopasplay += verificaBelo(montePlay);
	printf("--Ter todos os 7 : ");
	if(verifica7(montePlay) == 4){
		printf("3\n");
		escopasplay += 3;
	}else{
		printf("0\n");
	}
	printf("--Ter a maioria dos 7 : ");
	if(verifica7(montePlay) > 2){
		printf("1\n");
		escopasplay += 1;
	}else{
		printf("0\n");
	}
	printf("--Adversário possuir menos de 10 cartas : ");
	if(contacartas(montePC) < 10){
		printf("2\n");
		escopasplay += 2;
	}else{
		printf("0\n");
	}

	printf("\nTOTAL : %d\n",escopasplay);

	linha();

	printf("Pontos PC:\n\n");
	printf("--Escopas : %d\n",escopasPC);
	printf("--Ter todas as cartas de ouro : ");
	if(verificaOuro(montePC) == 10){
		printf("2\n");
		escopasPC += 2;
	}else{
		printf("0\n");
	}
	printf("--Ter a maioria das cartas de ouro : ");
	if(verificaOuro(montePC) > 5){
		printf("1\n");
		escopasPC += 1;
	}else{
		printf("0\n");
	}
	printf("--Ter o sete de ouro (belo) : %d \n",verificaBelo(montePC));
	escopasPC += verificaBelo(montePC);
	printf("--Ter todos os 7 : ");
	if(verifica7(montePC) == 4){
		printf("3\n");
		escopasPC += 3;
	}else{
		printf("0\n");
	}
	printf("--Ter a maioria dos 7 : ");
	if(verifica7(montePC) > 2){
		printf("1\n");
		escopasPC += 1;
	}else{
		printf("0\n");
	}
	printf("--Adversário possuir menos de 10 cartas : ");
	if(contacartas(montePlay) < 10){
		printf("2\n");
		escopasPC += 2;
	}else{
		printf("0\n");
	}

	printf("\nTOTAL : %d\n",escopasPC);

	linha();
	if(escopasplay > escopasPC)
		printf("##################### VOCÊ VENCEU!!! ########################");
	if(escopasplay < escopasPC)
		printf("##################### VOCÊ PERDEU!!! ########################");
	if(escopasplay == escopasPC)
		printf("############ EMPATE!!! #############");
}