#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{
    char nome[50];
    struct No* esquerda;
    struct No* direita;
} No;

//cria dinamicamente uma sala (nó da árvore) com nome e os filhos inicializados como NULL
No* criarSala(const char* nome) {
    No* sala = (No*)malloc(sizeof(No));
    if (sala == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(sala->nome, nome);
    sala->esquerda = NULL;
    sala->direita = NULL;
    return sala;
}

//permite explorar as salas navegando na arvore
void explorarSalas(No* atual) {
    char opcao;
    // armazena o caminho percorrido pelo jogador
    char historico[100][50]; 
    int qtd = 0;
    
    while(atual != NULL) {
        printf("\nVoce esta em: %s\n", atual->nome);
        strcpy(historico[qtd], atual->nome);
        qtd++;

        if(atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este comodo nao possui mais caminhos.\n");
            break;
        }

        printf("\n---------- OPCOES ----------\n");

        if(atual->esquerda != NULL) {
            printf("e. ir para a esquerda\n");
        }
        if(atual->direita != NULL) {
            printf("d. ir para a direita\n");
        }
        printf("s. sair\n");

        printf("Escolha: ");
        scanf(" %c", &opcao);

        switch (opcao)
        {
            case 'e':
                if(atual->esquerda != NULL) {
                    atual = atual->esquerda;
                } else {
                    printf("Nao existe sala a esquerda!\n");
                }
                break;
            case 'd':
                if(atual->direita != NULL) {
                    atual = atual->direita;
                } else {
                    printf("Nao existe sala a direita!\n");
                }
                break;
            case 's':
                printf("Saindo da mansao...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente\n");
        }
    }
    //mostra o caminho que foi percorrido pelo jogador
    printf("\nCaminho percorrido: \n");
    for(int i = 0; i < qtd; i++) {
        printf("%s", historico[i]);
        if(i < qtd - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    No* hall = criarSala("Hall de entrada"); //raiz da arvore
    No* salaTv = criarSala("Sala de estar"); //hall->direita
    No* salaJantar = criarSala("Sala de jantar"); //hall->esquerda
    No* cozinha = criarSala("Cozinha"); //salaJantar->esquerda
    No* quarto = criarSala("Quarto"); //salaTv->esquerda
    No* banheiro = criarSala("Banheiro"); //salaTv->direita
    No* jardim = criarSala("Jardim"); //salaJantar->direita
    No* suite = criarSala("Banheiro da Suite"); //quarto->esquerda

    hall->esquerda = salaJantar;
    hall->esquerda->esquerda = cozinha;
    hall->esquerda->direita = jardim;
    hall->direita = salaTv;
    hall->direita->esquerda = quarto;
    hall->direita->esquerda->esquerda = suite;
    hall->direita->direita = banheiro;
    
    explorarSalas(hall);

    printf("\n");

    return 0;
}

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().
