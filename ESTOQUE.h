#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

#define SAIR 3 
#define PESQUISA 2
#define ABASTECIMENTO 1

#define QNT 10 
#define LIN 10
#define COL 10
#define TAM 100

typedef struct Produto
{
    int id;
    char nome[TAM];
    float preco;
}TProduto; 

void cadastrar_produto(TProduto produtos[QNT], int *nr_produtos);
void ler_estoque(int estoque[LIN][COL], int *nr_lojas, int *nr_produtos);
void ler_abastecimento(int abastecimento[QNT], int *nr_produtos);
void exibe_menu();
void imprime_estoque(int estoque[LIN][COL], int *nr_lojas, int *nr_produtos);
void abastecer(int abastecimento[QNT], int estoque[LIN][COL], int *nr_produtos, int *nr_lojas);
int pesquisar(TProduto produtos[QNT], int estoque[LIN][COL], int* nr_lojas, int *nr_produtos);
void imprime_produtos(TProduto produtos[QNT], int *nr_produtos);

#endif