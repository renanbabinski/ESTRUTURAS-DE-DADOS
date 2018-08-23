struct _pecaBaralho{
	
	int number; //corresponde ao número de cada carta
	int naipe; //representa a naipe: 0 - Basto, 1- Espada, 2 - Ouro e 3 - Copa
	int cod;
	struct _pecaBaralho *right;
	struct _pecaBaralho *left;

};
typedef struct _pecaBaralho TpPecaBaralho;

TpPecaBaralho * init ();
TpPecaBaralho * insertInicio (TpPecaBaralho *pont, int number, int naipe, int cod);
TpPecaBaralho * new_baralho (TpPecaBaralho *pont);
TpPecaBaralho * exclui (TpPecaBaralho *pont, int cod);
TpPecaBaralho * busca (TpPecaBaralho *pont, int cod);
TpPecaBaralho * retiraCarta (TpPecaBaralho *pont);
TpPecaBaralho * busca (TpPecaBaralho *pont, int cod);
TpPecaBaralho * insertCarta (TpPecaBaralho *pont);
TpPecaBaralho * search(TpPecaBaralho* carta , int i);
TpPecaBaralho * CopiaMonte(TpPecaBaralho* monte, TpPecaBaralho* teste);


int valorcarta(int n);
int * lottery (int max);
int contacartas(TpPecaBaralho* pont);
int geth();
int TesteEscopa(TpPecaBaralho* teste);
int potencia(int n, int e);
int *gera_vetor(int qtdcartas, int combina );
int verificaOuro(TpPecaBaralho* monte);
int verificaBelo(TpPecaBaralho* monte);
int verifica7(TpPecaBaralho* monte);

void print_menu (TpPecaBaralho *pont);
void linha();
void exibirCartas(TpPecaBaralho* Play, TpPecaBaralho* pc, TpPecaBaralho* mesa);
void menuplayer();
void desenvolvedores();
void menu_principal();
void Conta_Pontos(int escopasplay, int escopasPC, TpPecaBaralho* montePlay, TpPecaBaralho* montePC);
