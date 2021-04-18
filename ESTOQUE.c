#include <stdio.h>
#include <string.h>
#include "ESTOQUE.h"

/*typedef struct Produto
{
    int id;
    char nome[TAM];
    float preco;
}TProduto;*/ 

void cadastrar_produto(TProduto produtos[QNT], int *nr_produtos)
{
    int i;

    printf("\nInforme os produtos:\n");
    for(i=0; i<*nr_produtos; i++)
    {
        printf("Nome: ");
        fgets(produtos[i].nome, TAM-1, stdin);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("\n");
        getchar();
    }
}

void ler_estoque(int estoque[LIN][COL], int *nr_lojas, int *nr_produtos)
{
    int i, j;

    printf("Informe o estoque:\n");
    for (i=0; i<*nr_lojas; i++)
    {
        for(j=0; j<*nr_produtos; j++)
        {
            scanf("%d", &estoque[i][j]);
        }
    }
    getchar();
}

void ler_abastecimento(int abastecimento[QNT], int *nr_produtos)
{
    int i;

    printf("\nInforme o vetor de abastecimento\n");
    for(i=0; i < *nr_produtos; i++)
    {
        scanf("%d", &abastecimento[i]);        
    }
    getchar();
}

void exibe_menu()
{
    printf("\n------\n");
    printf("Selecione uma opcao:\n");
    printf("(%d) Abastecer estoque\n", ABASTECIMENTO);
    printf("(%d) Pesquisar produto\n", PESQUISA);
    printf("(%d) Sair\n", SAIR);
    printf("------\n");
}

void imprime_estoque(int estoque[LIN][COL], int *nr_lojas, int *nr_produtos)
{
    int i, j;

    printf("\nEstoque atualizado:\n");
    for (i=0; i< *nr_lojas; i++)
    {
        for(j=0; j< *nr_produtos; j++)
        {
            printf("%d ", estoque[i][j]);
        }
        printf("\n");
    }
}

void abastecer(int abastecimento[QNT], int estoque[LIN][COL], int *nr_produtos, int *nr_lojas)
{
   int i,j, menor = 0;

   //determinar a menor qnt
   for (i=0; i < *nr_lojas; i++)
   {
       for(j=0; j < *nr_produtos; j++)
       {
           if(estoque[i][menor] > estoque[i][j])
           {
               menor =j;
           }
       }
       //somar abastecimento
       estoque[i][menor] += abastecimento[menor];
   }  
   
}

int pesquisar(TProduto produtos[QNT], int estoque[LIN][COL], int* nr_lojas, int *nr_produtos)
{
    int i, j;
    char busca[TAM];

    printf("\nBusca:");
    fgets(busca, TAM-1, stdin);

    for(i=0; i< *nr_produtos; i++)
    {
        if(strcmp(produtos[i].nome, busca)==0)
        {
            printf("ID: %d\n", i);
            printf("Nome: %s", produtos[i].nome);
            printf("Preco: %.2f\n", produtos[i].preco); 
            for(j=0; j< *nr_lojas; j++)
            {
                printf("Loja %d: %d unidades\n", j, estoque[j][i]);
            }
            return 1;
        }
    }
    return 0;
}

void imprime_produtos(TProduto produtos[QNT], int *nr_produtos)
{
    int i; 

    printf("\nProdutos:\n");
    for(i=0; i< *nr_produtos; i++)
    {
        printf("ID: %d\n", i);
        printf("Nome: %s", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("\n");
    }
}