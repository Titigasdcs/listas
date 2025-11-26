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
    struct no *fim;
} listaC;

void create(listaC *q);
int isEmpty(listaC q);
int insert(listaC *q, int d);
int remover(listaC *q, int d);
void imprime(listaC q);

void create(listaC *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int isEmpty(listaC q) {
    return (q.inicio == NULL) ? TRUE : FALSE;
}

int insert(listaC *q, int d) {
    struct no *aux = (struct no *) malloc(sizeof(struct no));
    if (aux == NULL) return FALSE;

    aux->dado = d;

    if (q->inicio == NULL) {
        q->inicio = aux;
        q->fim = aux;
        aux->prox = aux; 
        return TRUE;
    }

    aux->prox = q->inicio;
    q->fim->prox = aux;
    q->fim = aux;

    return TRUE;
}

void imprime(listaC q) {
    struct no *aux;

    if (!isEmpty(q)) {
        aux = q.inicio;

        printf("\n");

        if (aux != q.fim) {
            do {
                printf("%d -> %d   ", aux->dado, aux->prox->dado);
                aux = aux->prox;
            } while (aux != q.inicio);
        }
        else {
            printf("%d -> NULL  ", aux->dado);
        }

        printf("\n");
    }
}

int remover(listaC *q, int d) {
    struct no *aux, *atual, *anterior;

    if (isEmpty(*q)) return FALSE;

    if (d == q->inicio->dado) {
        aux = q->inicio;

        if (q->inicio == q->fim) {
            q->inicio = NULL;
            q->fim = NULL;
        } else {
            q->inicio = q->inicio->prox;
            q->fim->prox = q->inicio;  
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

        if (atual == q->fim) {
            q->fim = anterior;
        }

        free(aux);
        return TRUE;
    }

    return FALSE; 
}

int main() {
    listaC L;

    create(&L);

    insert(&L, 12);
    insert(&L, 320);
    insert(&L, 413);

    imprime(L);

    remover(&L, 320);

    imprime(L);

    return 0;
}
