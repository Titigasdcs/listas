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
} listaCDE;

void create(listaCDE *q);
int isEmpty(listaCDE q);
int insert(listaCDE *q, int d);
int remover(listaCDE *q, int d);
void imprime(listaCDE q, char modo);

void create(listaCDE *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int isEmpty(listaCDE q) {
    return (q.inicio == NULL) ? TRUE : FALSE;
}

int insert(listaCDE *q, int d) {
    struct no *aux = (struct no*) malloc(sizeof(struct no));
    if (aux == NULL) return FALSE;

    aux->dado = d;

    if (q->inicio == NULL) {
        q->inicio = aux;
        q->fim = aux;
        aux->prox = aux;
        aux->ant = aux;
        return TRUE;
    }

    aux->prox = q->inicio;
    aux->ant = q->fim;
    q->fim->prox = aux;
    q->inicio->ant = aux;
    q->fim = aux;

    return TRUE;
}

void imprime(listaCDE q, char modo) {
    struct no *aux;

    if (isEmpty(q)) return;

    if (modo == 'i') {
        aux = q.inicio;

        if (aux != q.fim) {
            do {
                printf("%d -> %d  ", aux->dado, aux->prox->dado);
                aux = aux->prox;
            } while (aux != q.inicio);
        } else {
            printf("%d", aux->dado);
        }
    }

    else if (modo == 'f') {
        aux = q.fim;

        if (aux != q.inicio) {
            do {
                printf("%d -> %d  ", aux->dado, aux->ant->dado);
                aux = aux->ant;
            } while (aux != q.fim);
        } else {
            printf("%d", aux->dado);
        }
    }

    printf("\n");
}

int remover(listaCDE *q, int d) {
    struct no *aux, *atual, *anterior;

    if (isEmpty(*q)) return FALSE;

    if (d == q->inicio->dado) {
        aux = q->inicio;

        if (q->inicio == q->fim) {
            q->inicio = NULL;
            q->fim = NULL;
        } else {
            q->inicio = aux->prox;
            q->fim->prox = q->inicio;
            q->inicio->ant = q->fim;
        }

        free(aux);
        return TRUE;
    }

    anterior = q->inicio;
    atual = q->inicio->prox;

    while (atual != q->inicio && atual->dado != d) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != q->inicio) {
        aux = atual;
        anterior->prox = atual->prox;
        atual->prox->ant = atual->ant;

        if (atual == q->fim) {
            q->fim = anterior;
        }

        free(aux);
        return TRUE;
    }

    return FALSE;
}

int main() {
    listaCDE f;

    create(&f);

    insert(&f, 12);
    insert(&f, 320);
    insert(&f, 413);

    imprime(f, 'i'); 

    remover(&f, 320);

    imprime(f, 'f'); 

    return 0;
}
