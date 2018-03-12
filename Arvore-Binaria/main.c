typedef struct NO* ArvBin;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NO {
    int valor;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof (ArvBin));
    if (raiz != NULL) {

        *raiz = NULL;
    }
    return raiz;
}

struct NO* criarFolha(int valor) {
    struct NO* folha = (struct NO*) malloc(sizeof (struct NO));
    if (folha == NULL) {
        return 0;
    }
    folha->valor = valor;
    folha->dir = NULL;
    folha->esq = NULL;
    return folha;
}

bool arvoreIsEmpty(ArvBin const *raiz);

bool valorDuplicado(int valor, const struct NO *atual);

void insere_ArvBin(ArvBin* raiz, int valor) {
    if (raiz == NULL) {
        return;
    }
    struct NO* novo = criarFolha(valor);

    if (arvoreIsEmpty(raiz)) {
        *raiz = novo;
    } else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (valorDuplicado(valor, atual)) {
                free(novo);
                return;
            }
            if (valor > atual->valor) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
        if (valor > ant->valor) {
            ant->dir = novo;
        } else {
            ant->esq = novo;
        }
    }
}

bool valorDuplicado(int valor, const struct NO *atual) { return valor == atual->valor; }

bool arvoreIsEmpty(ArvBin const *raiz) { return *raiz == NULL; }

int main(int argc, char** argv) {
    int v;
    ArvBin* raiz = cria_ArvBin();
    do {
        printf("Digite um valor: ");
        scanf("%d", &v);
        if (v > 0) {
            insere_ArvBin(raiz, v);
        }
    } while (v != 0);

    return (EXIT_SUCCESS);
}