#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no {
    int dado;
    struct no *prox;
    struct no *ant;
};

typedef struct {
    struct no *inicio;
    struct no *fim;
} listaDE;

void create(listaDE *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int isEmpty(listaDE q) {
    return (q.inicio == NULL) ? TRUE : FALSE;
}

int insert(listaDE *q, int d) {
    struct no *aux = (struct no *) malloc(sizeof(struct no));
    if (aux == NULL) return FALSE;

    aux->dado = d;
    aux->prox = NULL;
    aux->ant = q->fim;

    if (q->inicio == NULL) {
        // Lista vazia
        q->inicio = aux;
    } else {
        q->fim->prox = aux;
    }
    q->fim = aux;

    return TRUE;
}

void imprime(listaDE q, char modo) {
    struct no *aux;

    if (isEmpty(q)) return;

    if (modo == 'i') {
        aux = q.inicio;
        while (aux != NULL) {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
    } else {
        aux = q.fim;
        while (aux != NULL) {
            printf("%d ", aux->dado);
            aux = aux->ant;
        }
    }
    printf("\n");
}

int remover(listaDE *q, int d) {
    if (isEmpty(*q)) return FALSE;

    struct no *aux;
    struct no *atual = q->inicio;

    while (atual != NULL && atual->dado != d) {
        atual = atual->prox;
    }

    if (atual == NULL) return FALSE; 

    aux = atual;

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        q->inicio = atual->prox;
    }

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    } else {
        q->fim = atual->ant;
    }

    free(aux);
    return TRUE;
}

int main() {
    listaDE L;

    create(&L);

    insert(&L, 12);
    insert(&L, 320);
    insert(&L, 197);
    insert(&L, 26);

    printf("Lista do início ao fim: ");
    imprime(L, 'i');

    remover(&L, 320);

    printf("Após remover 320: ");
    imprime(L, 'i');

    printf("Lista do fim ao início: ");
    imprime(L, 'f');

    return 0;
}
