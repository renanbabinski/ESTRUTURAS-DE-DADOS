#include <stdio.h>
#include <stdlib.h>




typedef struct _lista{
	int info;
	struct _lista *prox;
}TpLista;





TpLista* inicializa(){
	return NULL;
}

TpLista* insereini(TpLista *l, int e){
	TpLista* novo = (TpLista *) malloc(sizeof(TpLista));
	novo->info = e;
	novo->prox = l;
	return novo;
}

void imprime(TpLista* l){
	TpLista* p;
	for(p = l; p != NULL; p = p->prox){
		printf(”Informação = %d\n”, p->info);
	}
}

int evazia(TpLista* l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

TpLista* busca(TpLista* l, int e){
	TpLista* p;
	for(p = l; p != NULL; p=p->prox){
		if(p->info == e){
			return p;
		}
	}
	return NULL; //O elemento não está na lista
}

Lista * exclui(TpLista * l, int e){
	TpLista * anterior = NULL; // ponteiro para o elemento anterior
	TpLista * p = l; // ponteiro para percorrer a lista
	
	/* procura elemento na lista e guarda o anterior */
	while(p != NULL && p->info != e){
		anterior = p;
		p = p->prox;
	}
	
	/* verifica se achou elemento */
	if(p == NULL){
		return l; // não achou o elemento, retorna a lista original
	}
	/* retira elemento */
	if(anterior == NULL){ // então retirar o primeiro elemento
		l = p->prox;
	}else{ // retira elemento do meio da lista
		anterior->prox = p->prox; 
	}
	free(p);
	return l;
} // fim de Lista * exclui...

int main(){

	TpLista l;
	l = inicializa();
	printf("Lista inicializada!\n");

	while(1){
		printf("Escolha uma das opções abaixo:\n");
		printf("--1--Inserir um novo valor no inicio da lista\n");
		printf("--2--Listar os elementos na lista\n");
		printf("--0--Finalizar o prgrama\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Digite um numero para inserir no inicio da lista:\n");
				scanf("%d",&num);
				insereini(l,num);
				break;
			case 2:
				imprime(l);
				
				
				break;
			case 0:
				return 0;

		}
	}

