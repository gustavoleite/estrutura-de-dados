#include <stdio.h>
#include <stdlib.h>

//define uma nova struct (primitivo de classe)
struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

//defino um novo tipo chamado ArvBin que é do tipo NO
typedef struct NO* ArvBin;

//declaro um ponteiro global do tipo ArvBin
ArvBin* raiz;

//aloca espaco para uma nova variavel do tipo ArvBin
ArvBin* cria_ArvBin() {
    ArvBin* arvBin = (ArvBin*) malloc(sizeof (ArvBin));
    if (arvBin != NULL) {
        *arvBin = NULL;
    }
    return arvBin;
};


int main(void) {
    raiz = cria_ArvBin();

}