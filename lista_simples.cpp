#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

struct no {
    int dado;
    struct no *prox;
};

typedef struct {
    struct no *inicio;
} lista;

void create(lista *q) {
    q->inicio = NULL;
}

int isEmpty(lista q) {
    return q.inicio == NULL ? TRUE : FALSE;
}

void insert(lista *q, int d) {
struct no *aux = (struct no*) malloc(sizeof(struct no));

    if (aux != NULL) {
        aux->dado = d;
        aux->prox = NULL;
        struct no *anterior = NULL;
        struct no *atual = q->inicio;

        while (atual != NULL && d > atual->dado) {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) {
            aux->prox = q->inicio;
            q->inicio = aux;
        } else {
            anterior->prox = aux;
            aux->prox = atual;
        }
    }
}

void imprime(lista q) {
    struct no *aux = q.inicio;
    if (!isEmpty(q)) {
        while (aux != NULL) {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int remover(lista *q, int d) {
    if (q->inicio == NULL) return FALSE;

    struct no *aux, *atual, *anterior;

    if (d == q->inicio->dado) {
        aux = q->inicio;
        q->inicio = q->inicio->prox;
        free(aux);
        return TRUE;
    } else {
        anterior = q->inicio;
        atual = q->inicio->prox;
        while (atual != NULL && atual->dado != d) {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual != NULL) {
            aux = atual;
            anterior->prox = atual->prox;
            free(aux);
            return TRUE;
        }
    }
    return FALSE;
}

int main(void) {
    lista L;
    create(&L);

    insert(&L, 12);
    insert(&L, 320);
    insert(&L, 197);
    insert(&L, 26);

    imprime(L);
    remover(&L, 320);
    imprime(L);

    return 0;
}