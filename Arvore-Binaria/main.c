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

void handleOption(int *v, ArvBin const *raiz);

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

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if (atual->esq == NULL) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL) {
        no1 = no2;
        no2 = no2->dir;
    }
    if (no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

void remove_ArvBin(ArvBin *raiz, int valor) {
    if (raiz == NULL) {
        return;
    }
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while (atual != NULL) {
        if (valor == atual->valor) {
            if (atual == *raiz) {
                *raiz = remove_atual(atual);
            } else {
                if (ant->dir == atual) {
                    ant->dir = remove_atual(atual);
                } else {
                    ant->esq = remove_atual(atual);
                }
            }
            return;
        }
        ant = atual;
        if (valor > atual->valor) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
}

void handleOption(int *v, ArvBin const *raiz) {
    switch ((*v)) {
        case 1:
            printf("\n\nDigite o valor que deseja remover: ");
            scanf("%d", v);
            if ((*v) > 0) {
                remove_ArvBin(raiz, (*v));
            }
            break;
    }
}

int main(int argc, char** argv) {
    int v;
    ArvBin* raiz = cria_ArvBin();
    do {
        printf("Digite um valor ou pressione 0 para sair: ");
        scanf("%d", &v);
        if (v > 0) {
            insere_ArvBin(raiz, v);
        }
    } while (v != 0);

    do {
        printf("\nEscolha uma opcao: " );
        printf("\n1 - Excluir");
        printf("\n2 - Exibir em ordem");
        printf("\n3 - Exibir pre ordem");
        printf("\n4 - Exibir pos ordem");
        printf("\n5 - Exibir toda lista");
        printf("\n0 - Sair");
        scanf("%d", &v);
        handleOption(&v, raiz);
    } while (v != 0);


    return (EXIT_SUCCESS);
}