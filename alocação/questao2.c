#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	char endereco[100];
	int matricula;
}estudante;


int main(){

	estudante *p;
	int n,i;

	printf("Digite o tamanho do seu vetor de estruturas:\n");
	scanf("%d",&n);
	getchar();
	p=(estudante*)malloc(n*sizeof(estudante));

	if(p){
		printf("Memória alocada com sucesso");
	}else{
		printf("Não foi possivel alocar a memória");
		return 0;
	}
	printf("\nDigite os dados de sua estrutura:\n");
	for(i=0;i<n;i++){
		printf("Digite o nome:\n");
		fgets(p->nome,50,stdin);
		printf("Digite o endereço:\n");
		fgets(p->endereco,100,stdin);
		printf("Digite a matricula:\n");
		scanf("%d",&p->matricula);
		getchar();
		p++;
	}
	p=p-n;
	for(i=0;i<n;i++){
		printf("Nome: %s \n",p->nome);
		printf("Endereço: %s \n",p->endereco);
		printf("Matricula: %d\n",p->matricula);
		p++;
	}










	return 0;
}
