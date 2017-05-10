#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int num;
	struct Node *prox;
}node;

node *inicio,*fim;

void initfila(){
	inicio=NULL;
	fim=NULL;
}

void push(int n){
	node *pointer = (node*)malloc(sizeof(node));
	node *temp;
	if(inicio==NULL){
		inicio = pointer;
	}
		pointer->num = n;
		temp = fim;
		fim = pointer;
	
	if(temp!=NULL){
		temp->prox = fim;
		temp = NULL;
	}
	printf("Inserido!!!\n");
}

void pop(){
	if(inicio == NULL){
		printf("Pilha vazia!");
	}else{
	node *temp;
	int retorno;
	temp = inicio;
	retorno = inicio->num;
	inicio = inicio->prox;
	free(temp);
	printf("Valor removido:     %d    \n",retorno);
	}}



int main()
{
	int opt,num;


	printf("Bem vindo ao programa!\n");
	initfila();

	while(1){
		printf("Escolha uma das opções abaixo:\n");
		printf("--1--Inserir novo valor\n");
		printf("--2--Remover um valor\n");
		printf("--0--Finalizar o prgrama\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Digite um numero para inserir na fila:\n");
				scanf("%d",&num);
				push(num);
				break;
			case 2:
				pop();
				break;
			case 0:
				return 0;

		}
	}

    return 0;
}
