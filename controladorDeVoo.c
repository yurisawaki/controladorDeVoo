#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//quest�o 1
//ALUNO: Breno Yuri Saraiva Sawaki
typedef struct Aviao {
    char nome[50];
    int identificador;
    struct Aviao* proximo;
} Aviao;


typedef struct {
    Aviao* inicio;
    Aviao* fim;
    int tamanho;
} FilaDecolagem;

void inicializarFila(FilaDecolagem* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void adicionarAviao(FilaDecolagem* fila, char* nome, int identificador) {
    Aviao* novoAviao = (Aviao*)malloc(sizeof(Aviao));
    strcpy(novoAviao->nome, nome);
    novoAviao->identificador = identificador;
    novoAviao->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novoAviao;
    } else {
        fila->fim->proximo = novoAviao;
    }
    fila->fim = novoAviao;
    fila->tamanho++;
}

int listarNumeroAvioes(FilaDecolagem* fila) {
    return fila->tamanho;
}


void autorizarDecolagem(FilaDecolagem* fila) {
    if (fila->inicio == NULL) {
        printf("Nenhum avi�o na fila de decolagem.\n");
        return;
    }

    Aviao* aviaoDecolando = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    printf("Avi�o %s (ID: %d) autorizado para decolagem.\n", aviaoDecolando->nome, aviaoDecolando->identificador);
    free(aviaoDecolando);
    fila->tamanho--;
}


void listarAvioes(FilaDecolagem* fila) {
    Aviao* atual = fila->inicio;
    while (atual != NULL) {
        printf("Avi�o %s (ID: %d)\n", atual->nome, atual->identificador);
        atual = atual->proximo;
    }
}

void listarPrimeiroAviao(FilaDecolagem* fila) {
    if (fila->inicio == NULL) {
        printf("Nenhum avi�o na fila de decolagem.\n");
        return;
    }
    printf("Primeiro avi�o na fila: %s (ID: %d)\n", fila->inicio->nome, fila->inicio->identificador);
}

int main() {
    FilaDecolagem fila;
    inicializarFila(&fila);

    adicionarAviao(&fila, "Avi�o 1", 12839001);
    adicionarAviao(&fila, "Avi�o 2", 10192832);
    adicionarAviao(&fila, "Avi�o 3", 12938903);

    printf("N�mero de avi�es na fila: %d\n", listarNumeroAvioes(&fila));
    listarAvioes(&fila);
    listarPrimeiroAviao(&fila);

    autorizarDecolagem(&fila);
    printf("N�mero de avi�es na fila: %d\n", listarNumeroAvioes(&fila));
    listarAvioes(&fila);
    listarPrimeiroAviao(&fila);

    return 0;
}
