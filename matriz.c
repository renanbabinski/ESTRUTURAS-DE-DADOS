// Renan Babinski
// OBS* Mudar o numero de busca na variavel number = "numero" na função main
#include <stdio.h>
#include <stdlib.h>
#define linha 4
#define coluna 5

int *searchMatrix(int *matriz,int *number){
	int i;
	for(i=0;i<linha*coluna;i++){
		if(*number==*(matriz+i))
			return matriz+i;
	}
	return NULL;
}

void searchMatrix1(int *matriz, int *number, int **p){
	int i;
	for(i=0;i<linha*coluna;i++){
		if(*number==*(matriz+i))
			*p=matriz+i;
		}
	}

int main()
{
	int matriz[linha][coluna] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
	int *p,**pp,number=20,*n,*endn;

	p = &matriz[0][0];      //p recebe o endereço do primeiro elemento da Matriz
	n = &number;            //n recebe o endereço de number
	pp= &endn;
	printf("RETORNO DA FUNÇÃO 1== searchMatrix\n\n");
	endn=searchMatrix(p,n);     
	if(endn==NULL){         //se a função retornar null, o retorno não será printado a fim de não gerar uma falha de segmentação
		printf("O numero não está na Matriz!\n\n");
		}else{
			printf("endereço da posição do numero na matriz:%p\n",endn);   //caso contrário, irá printar o endereço do numero na matriz e também o respectivo número
			printf("numero: %d\n\n\n", *endn);   // Note que o numero impresso aqui vem do endereço em que ele está na matriz que a função retornou
		}
	printf(" RETORNO DA FUNÇÃO 2== SearchMatrix1\n\n");
	searchMatrix1(p,n,pp);
	if(endn==NULL){      
		printf("O numero não está na Matriz!\n\n");     
		}else{
			printf("endereço da posição do numero na matriz:%p\n",endn);   
			printf("numero: %d\n\n\n", *endn);  
		}

return 0;
}



