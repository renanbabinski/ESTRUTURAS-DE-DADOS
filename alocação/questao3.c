#include <stdio.h>
#include <stdlib.h>

int main(){

	int *p,i=1,*pNEw,*pp;


	p=(int*)malloc(5*sizeof(int));
	pp=p;

	printf("\nDigite valores para seu vetor:\n");
	while(1){
		scanf("%d",pp);
		pp++;
		if(i%5==0){
			pNEw=(int*)realloc(p,(5+i)*sizeof(int));
			p=pNEw;
			printf("Mais 5 posições alocadas!\n");
		}
		if(scanf("%d",pp)==0)
			break;
		i++;
	}
	return 0;
}