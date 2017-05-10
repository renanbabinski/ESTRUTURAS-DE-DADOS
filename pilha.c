//O ALGORITMO NÃO FICOU IDENTICO À PROPOSTA DE TRABALHO MAS FUNCIONA DA MESMA FORMA;
//TIVE DIFICULDADES EM IMPLEMENTAR NO OUTRO MODELO;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

typedef struct _produto{
	int cod;
	char nome[TAM];
	float preco;
	struct _produto *prox;
}tp_produto;

tp_produto *topo;

void initpilha(){
	topo=NULL;
}

void push(int codigo,char* nomeproduto,float valor,tp_produto *pointer){
	pointer->cod = codigo;
	strcpy(pointer->nome,nomeproduto);
	pointer->preco = valor;
	
	pointer->prox = topo;
	topo = pointer;
}
void pop(){
	tp_produto *temp;
	temp = topo;
	topo = topo->prox;

	printf("Item COD: %d excluido!\n",temp->cod);

	temp->prox = NULL;
}
void desempilhar(tp_produto *pointer){
	printf("\n\nProduto : %s\nCodigo: %d\nPreço: %f\n",pointer->nome,pointer->cod,pointer->preco);
}

int main(){

	tp_produto *p,*pinicio,*paux;
	int tamanho,opt,codigo;
	float valor;
	char nomeproduto[TAM];


	printf("Digite o tamanho de sua pilha:\n");
	scanf("%d",&tamanho);
	getchar();

	p = (tp_produto*)malloc(tamanho*sizeof(tp_produto));
	pinicio = p;

	if(p){
		printf("Memória alocada com sucesso!\n");
		initpilha();
	}else{
		printf("Não foi possível alocar memória");
		return 0;
	}
	while(1){
		printf("Escolha uma opção:\n");
		printf("--1-- Inserir um produto na pilha\n");
		printf("--2-- Excluir um produto da pilha\n");
		printf("--3-- Listar todos os produtos da pilha\n");
		printf("--0-- Finalizar o programa\n");
		scanf("%d",&opt);
		getchar();
	switch(opt){
		case 1:
			printf("Digite o nome do produto:\n");
			fgets(nomeproduto,TAM,stdin);
			printf("Digite o codigo do produto:\n");
			scanf("%d",&codigo);
			getchar();
			printf("Digite o preço do produto:\n");
			scanf("%f",&valor);
			getchar();
			push(codigo,nomeproduto,valor,p);
			printf("Produto inserido na pilha!\n");
			p++;
			break;
		case 2:
			pop();
			p--;
			break;
		case 3:
			paux=p;
			paux--;
			while(pinicio!=paux+1){
				desempilhar(paux);
				paux--;
			}
			printf("TODOS OS PRODUTOS LISTADOS\n");
			break;
		case 0:
			return 0;
			break;
		default:
			printf("Opção inválida\n");
			break;
		}
	}
	return 0;
	}






