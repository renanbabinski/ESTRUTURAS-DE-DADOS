#include <stdio.h>
#include <stdlib.h>

int main(){

	int *p,n,i;

	printf("Digite o tamanho do seu vetor:\n");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));

	if(p){
		printf("Memória alocada com sucesso");
	}else{
		printf("Não foi possivel alocar a memória");
		return 0;
	}
	printf("\nDigite valores para seu vetor:\n");
	for(i=0;i<n;i++){
		scanf("%d",p);
		p++;
	}
	p--;
	printf("Valores digitados na ordem inversa:\n");
	for(i=0;i<n;i++){
		printf("%d\n",*p);
		p--;
	}
	return 0;
}

