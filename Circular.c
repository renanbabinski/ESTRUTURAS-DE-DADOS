#include <stdio.h>
#include <stdlib.h>

typedef struct _lista{
	int info;
	struct _lista *prox;
}TpLista;

void imprimecircular(){
	TpLista* p = l;
	if(p == NULL){
		printf("A lista está vazia!\n")
	}else{
		do{
			printf("%d",p->info);
			p = p->prox;
		}while(p != l);
	}

}

TpLista *insert(TpLista *head,int e){
	TpLista *p = head,*anterior = NULL;
	TpLista *novo = (TpLista *)malloc(sizeof(TpLista));
	if(novo!= NULL){
		novo->info = e;
	}else{
		return head;
	}

	do{




		while(p != head && p->info < e){
			anterior = p;
			p = p->prox;

	}
	
	if(head == NULL){
		novo->prox = novo;
		return novo;
	}


	return *head;
}

int main(){
	TpLista *head = init();
	head = insert
}








return 0;

}