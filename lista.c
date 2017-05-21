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
		printf("Informação = %d\n", p->info);
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
TpLista * exclui(TpLista * l, int e){
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

TpLista* insereordenado(TpLista* l, int e){
	TpLista *p = l;
	TpLista *anterior = NULL, *novo;
	novo = (TpLista*) malloc(sizeof(TpLista));
	if(novo == NULL)
		return l;
	novo->info = e;
	while( p != NULL && p->info < e){
		anterior = p;
		p = p->prox;
	}
	if(p == NULL){       // se inserido no final
		anterior->prox = novo;
		novo->prox = NULL;
		return l;
	}
	if(anterior == NULL){
		novo->prox = p;
		l = novo;
	}else{
		novo->prox = p;
		anterior->prox = novo;
	}
	return l;

}

int main(){

	int opt,num;
	TpLista *l;
	TpLista *original;
	l = inicializa();
	printf("Lista inicializada!\n");

	while(1){
		printf("Escolha uma das opções abaixo:\n");
		printf("--1--Inserir um novo valor no inicio da lista\n");
		printf("--2--Listar os elementos na lista\n");
		printf("--3--Procurar um elemento na lista\n");
		printf("--4--Excluir um elemento da lista\n");
		printf("--5--Inserir em ordem crescente\n");
		printf("--0--Finalizar o programa\n");
		scanf("%d",&opt);
		system("clear");
		switch(opt){
			case 1:
				printf("Digite um numero para inserir no inicio da lista:\n");
				scanf("%d",&num);
				l = insereini(l,num);
				break;
			case 2:
				if(evazia(l)){
					printf("Lista Vazia!\n");
				}else{
				imprime(l);
				}
				break;
			case 3:
				if(evazia(l)){
					printf("Lista Vazia!\n");
				}else{
					printf("Digite o numero a ser buscado:\n");
					scanf("%d",&num);
					if(busca(l,num)){
						printf("O elemento está na lista!\n");
					}else{
						printf("O elemento não está na lista!\n");
					}
				}
				break;
			case 4:
				if(evazia(l)){
					printf("Lista Vazia!\n");
				}else{
					original = l;
					printf("Digite o elemento que deseja excluir:\n");
					scanf("%d",&num);
					l = exclui(l,num);
					if(l == original){
						printf("Elemento não encontrado!\n");
					}else{
						printf("Elemento excluido!\n");
					}
				}
				break;
			case 5:
				if(evazia(l)){
					printf("A lista está vazia!\nInsira pelo menos um numero na lista\n");
				}else{
					printf("Digite um numero para inserir ordenado:\n");
					scanf("%d",&num);
					insereordenado(l,num);
				}
				break;
			case 0:
				return 0;

		}
	}
	return 0;
}

