#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

/* para compilar com as biblioteca :
gcc -c fun.c -o fun
gcc -c escopa.c -o escopa
gcc fun escopa -o start*/

int main(){
	
	TpPecaBaralho *baralho = NULL;
	TpPecaBaralho *embaralhado = NULL;
	TpPecaBaralho *cartasPC = NULL;
	TpPecaBaralho *cartasPlay = NULL;
	TpPecaBaralho *cartasMesa = NULL;
	TpPecaBaralho *montePC = NULL;
	TpPecaBaralho *montePlay = NULL;
	TpPecaBaralho *auxiliar = NULL;
	TpPecaBaralho *teste = NULL;
	int i, x, menu, submenu, combina , qtdcartas, soma, controle = 0, carta = 0, *p = NULL, *vetor = NULL;
	int escopasplay = 0, escopasPC = 0;

	while(menu != 0){
		system("clear");
		menu_principal();
		scanf("%d",&menu);
		getchar();
		system("clear");
		switch (menu){
			case 1:
				baralho = NULL;
				embaralhado = NULL;
				cartasPC = NULL;
				cartasPlay = NULL;
				cartasMesa = NULL;
				montePC = NULL;
				montePlay = NULL;
				auxiliar = NULL;
				teste = NULL;
				
				printf("Embaralhando...\n");
				geth();
				system("clear");
				baralho = init();
				baralho = new_baralho(baralho);
				p = lottery(40);
				for (i=0;i<40;i++){
					auxiliar = busca(baralho,p[i]);
					embaralhado = insertInicio(embaralhado, auxiliar->number,auxiliar->naipe, auxiliar->cod);
				}
				//Sorteio das cartas do computador.
				for (i=0; i < 3; i++){
					auxiliar = retiraCarta(embaralhado);
					cartasPC = insertInicio(cartasPC, auxiliar->number,auxiliar->naipe, auxiliar->cod);
					embaralhado = exclui (embaralhado, auxiliar->cod);
					auxiliar = NULL;
				}
				//Sorteio das cartas do play.
				for (i=0; i < 3; i++){
					auxiliar = retiraCarta(embaralhado);
					cartasPlay = insertInicio(cartasPlay, auxiliar->number,auxiliar->naipe, auxiliar->cod);
					embaralhado = exclui (embaralhado, auxiliar->cod);
					auxiliar = NULL;
				}
				//Sorteio das cartas da mesa.
				for (i=0; i < 4; i++){
					auxiliar = retiraCarta(embaralhado);
					cartasMesa = insertInicio(cartasMesa, auxiliar->number,auxiliar->naipe, auxiliar->cod);
					embaralhado = exclui (embaralhado, auxiliar->cod);
					auxiliar = NULL;
				}
				while(1){
					if(cartasPlay == NULL && cartasPC == NULL && embaralhado == NULL)
						break;
					while(controle != 10){
						system("clear");
						exibirCartas(cartasPlay,cartasPC,cartasMesa);
						menuplayer();
						scanf(" %d",&submenu);
						getchar();
						switch(submenu){
							case 1:
								while(1){
									printf("Carta que deseja descartar:\n");
									scanf(" %d",&carta);
									getchar();
										if(carta < contacartas(cartasPlay) && carta >= 0){
											system("clear");
											break;
										}else{
											printf("Opção inválida! Selecione outra carta:\n\n");
										}
								}
								auxiliar = search(cartasPlay,carta);
								cartasPlay = exclui(cartasPlay,auxiliar->cod);
								cartasMesa = insertInicio(cartasMesa, auxiliar->number, auxiliar->naipe, auxiliar->cod);
								auxiliar = NULL;
								controle = 10;
								break;
							case 0:
								if(cartasMesa == NULL){
									printf("Jogada não permitida! Descarte uma carta...\n");
									geth();
									break;
								}
								while(1){
									while(1){
										controle = 0;
										system("clear");
										exibirCartas(cartasPlay,cartasPC,cartasMesa);
										linha();
										printf("Selecione uma carta de sua mão para fazer a jogada:\n");
										scanf(" %d",&carta);
										getchar();
											if(carta < contacartas(cartasPlay) && carta >= 0){
												break;
											}else{
												printf("Opção inválida! Selecione outra carta:\n\n");
											}
										}
										auxiliar = search(cartasPlay,carta);
										teste = insertInicio(teste, auxiliar->number, auxiliar->naipe, auxiliar->cod);
										auxiliar = NULL;
									while(controle != 1){	
										while(1){
											printf("Selecione a carta da mesa que deseja combinar com sua carta selecionada\n");
											scanf(" %d",&carta);
											getchar();
												if(carta < contacartas(cartasMesa) && carta >= 0){
													break;
												}else{
													printf("Opção inválida! Selecione outra carta:\n\n");
													geth();
												}
										}
										auxiliar = search(cartasMesa,carta);
										teste = insertInicio(teste, auxiliar->number, auxiliar->naipe, auxiliar->cod);
										auxiliar = NULL;
										printf("0--para adicionar outra carta\n1--para finalizar a jogada\n");
										scanf(" %d",&controle);
										getchar();
									}
									soma = TesteEscopa(teste);
									if(soma == 15){
										montePlay = CopiaMonte(montePlay,teste);
										while(teste->right != NULL){
											cartasMesa = exclui(cartasMesa,teste->cod);
											teste = teste->right;
										}
										cartasPlay = exclui(cartasPlay,teste->cod);
										teste = teste->right;
										controle = 10;
										if(cartasMesa == NULL)
											escopasplay++;
										break;
									}else{
										system("clear");
										printf(" ### VOCE NÂO SOMOU 15 PONTOS! ###\n\n      TENTE NOVAMENTE!\n\n");
										teste = NULL;
										printf("0--para tentar novamente\n1--para voltar ao menu e descartar uma carta ou fazer uma jogada\n");
										scanf(" %d",&controle);
										getchar();
										if(controle == 1)
											break;
									}
								}
								break;
							default:
								printf("\n---OPÇÂO INVALIDA!---\n");
								geth();
								system("clear");
								break;
						}
					}
					system("clear");
					exibirCartas(cartasPlay,cartasPC,cartasMesa);
					printf("\n##########   VEZ DA MAQUINA    ###############\n\n");
					printf("A inteligência artificial está fazendo uma jogada...");
					geth();
					if(cartasMesa == NULL){
						auxiliar = retiraCarta(cartasPC);
						cartasMesa = insertInicio(cartasMesa, auxiliar->number, auxiliar-> naipe, auxiliar->cod);
						cartasPC = exclui(cartasPC, auxiliar->cod);
						auxiliar = NULL;
						system("clear");
						exibirCartas(cartasPlay,cartasPC,cartasMesa);
					}else{
						for(x = 0; x < contacartas(cartasPC); x++){
							auxiliar = search(cartasPC, x);
							teste = insertInicio(teste, auxiliar->number, auxiliar->naipe, auxiliar->cod);
							auxiliar = NULL;
							qtdcartas = contacartas(cartasMesa);		
							combina = potencia( 2 , qtdcartas) - 1;
							while(combina != 0){
								vetor = gera_vetor(qtdcartas , combina);
								for(i = 0; i < qtdcartas; i++){
									if(vetor[i] == 1){
										auxiliar = search(cartasMesa, i);
										teste = insertInicio(teste, auxiliar->number, auxiliar->naipe, auxiliar->cod);
										auxiliar = NULL;
									}
								}
								if(TesteEscopa(teste) == 15){
									montePC = CopiaMonte(montePC, teste);
									printf("\nCartas selecionadas pela maquina:\n\n");
									print_menu(teste);
									linha();
									geth();
									while(teste->right != NULL){
										cartasMesa = exclui(cartasMesa,teste->cod);
										teste = teste->right;
									}
									cartasPC = exclui(cartasPC,teste->cod);
									teste = teste->right;
									controle = 20;
									if(cartasMesa == NULL)
										escopasPC++;
									break;
								}else{
									while(teste->right != NULL){
											exclui(teste,teste->cod);
											teste = teste->right;
									}
								}
								combina --;
							}
							teste = NULL;
							if(controle == 20)
								break;
						}
						if(controle != 20){
							auxiliar = retiraCarta(cartasPC);
							cartasMesa = insertInicio(cartasMesa, auxiliar->number, auxiliar-> naipe, auxiliar->cod);
							cartasPC = exclui(cartasPC, auxiliar->cod);
							auxiliar = NULL;
						}
					}
					system("clear");
					exibirCartas(cartasPlay,cartasPC,cartasMesa);
					if(cartasPlay == NULL && cartasPC == NULL && embaralhado != NULL){
						for (i=0; i < 3; i++){
							auxiliar = retiraCarta(embaralhado);
							cartasPlay = insertInicio(cartasPlay, auxiliar->number,auxiliar->naipe, auxiliar->cod);
							embaralhado = exclui (embaralhado, auxiliar->cod);
							auxiliar = NULL;
						}
						for (i=0; i < 3; i++){
							auxiliar = retiraCarta(embaralhado);
							cartasPC = insertInicio(cartasPC, auxiliar->number,auxiliar->naipe, auxiliar->cod);
							embaralhado = exclui (embaralhado, auxiliar->cod);
							auxiliar = NULL;
						}
						system("clear");
						printf("Distribuindo novas cartas...");
						geth();
					}
					controle = 0;
				}
				system("clear");
				exibirCartas(cartasPlay,cartasPC,cartasMesa);
				linha();
				printf("######################   Fim de jogo!   #####################\n\n");
				printf("Pressione enter para continuar...");
				geth();
				system("clear");
				Conta_Pontos(escopasplay,escopasPC,montePlay,montePC);
				geth();
				break;
			case 2:
				desenvolvedores();
				geth();
				system("clear");
				break;
			case 0:
				break;
			default:
				printf("\n---OPÇÂO INVALIDA!---\n");
				geth();
				system("clear");
				break;
		}
	}	
	return 0;
}
