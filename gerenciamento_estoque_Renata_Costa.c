//Projeto Gerenciamento Estoque de Estrutura de Dados - Prof. Veronica Quandt
//Estudante: Renata Costa
//Data entrega: 03/04/2020

#include <stdio.h>
#include <string.h>
#include "ESTOQUE.h"

void exit();

int main()
{
    int opcao, nr_lojas, nr_produtos;
    int abastecimento[QNT], estoque[LIN][COL];
    TProduto produtos[QNT];

    do
    {
        printf("Informe o numero de lojas e produtos: \n");
        scanf("%d %d", &nr_lojas, &nr_produtos);
    } while (nr_lojas <=0||nr_lojas >10||nr_produtos <=0 ||nr_produtos >10);
    getchar();

    cadastrar_produto(produtos, &nr_produtos);
    ler_estoque(estoque, &nr_lojas, &nr_produtos);
    ler_abastecimento(abastecimento, &nr_produtos);

    //imprime_produtos(produtos, &nr_produtos);
    
    do
    {
        exibe_menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case ABASTECIMENTO:
            abastecer(abastecimento, estoque, &nr_produtos, &nr_lojas);
            imprime_estoque(estoque, &nr_lojas, &nr_produtos);
            break;
        case PESQUISA:
            if(pesquisar(produtos, estoque, &nr_lojas, &nr_produtos)==0)
            {
                printf("Produto nao encontrado\n");
            }
            break;
        case SAIR:
            exit();
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }while(opcao != SAIR);


    return 0;

}