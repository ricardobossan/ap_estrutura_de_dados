#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno Aluno; // Declaração adiantada

struct Aluno {

  char nome[20];

  float nota;

  int turma;

  Aluno *ant;

  Aluno *prx;
};

// Inicializa a lista
Aluno *initList() { return NULL; }

// Insere Aluno ao início da lista
void inicioLista(Aluno **lista, int turma, char nome[], float nota) {

  Aluno *primeiro = (Aluno *)malloc(sizeof(Aluno));

  primeiro->turma = turma;
  strcpy(primeiro->nome, nome);
  primeiro->nota = nota;

  primeiro->ant = NULL;
  primeiro->prx = *lista;

  // Checa se a lista não está vazia. Se não está, atribui o novo primeiro nodo
  // ao início da lista.
  if (*lista != NULL) {
    (*lista) = primeiro;
  }

  *lista = primeiro;
}

// Insere Aluno ao final da lista
void finalLista(Aluno **lista, int turma, char nome[], float nota) {

  Aluno *ultimo = (Aluno *)malloc(sizeof(Aluno));

  ultimo->turma = turma;
  strcpy(ultimo->nome, nome);
  ultimo->nota = nota;

  ultimo->ant = NULL;
  ultimo->prx = NULL;

  if (*lista == NULL) {
    *lista = ultimo;
  } else {
    Aluno *tmp = *lista;

    while (tmp->prx != NULL) {
      tmp = tmp->prx;
    }

    tmp->prx = ultimo;
    ultimo->ant = tmp;
  }
}

void insereNaLista(Aluno **lista, int i, int turma, char nome[], float nota) {
  if (*lista == NULL) {
    return;
  }

  if (i <= 1) {
    return;
  }

  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

  aluno->turma = turma;
  strcpy(aluno->nome, nome);
  aluno->nota = nota;

  aluno->ant = NULL;
  aluno->prx = NULL;

  if (i == 2) {
    aluno->prx = (*lista)->prx;
    if ((*lista)->prx != NULL) {
      (*lista)->prx->ant = aluno;
    }
    (*lista)->prx = aluno;
    aluno->ant = (*lista);
  } else {
    Aluno *tmp = *lista;

    int j = 1;
    while (tmp != NULL && j < i-1 ) {
      tmp = tmp->prx;
      j++;
    }

    if (tmp == NULL) {
      free(aluno);
      return;
    }

    aluno->ant = tmp;
    aluno->prx = tmp->prx;
    if (tmp->prx != NULL) {
      tmp->prx->ant = aluno;
    }
    tmp->prx = aluno;
  }
}

// Exclui Aluno do meio da lista
void excluiDaLista(Aluno **lista, int i) {
  if (*lista == NULL)
    return;

  if (i <= 0)
    return;

  // Define o nodo da lista a ser excluído;
  Aluno *tmp = *lista;
  int j = 1;
  while (tmp != NULL && j < i) {
    tmp = tmp->prx;
    j++;
  }

  // Se o índice de exclusão não for o primeiro da lista,
  if (tmp->ant != NULL)
    // Altera o próximo do item anterior para o próximo do que será excluído
    tmp->ant->prx = tmp->prx;
  // Mas se for o primeiro,
  else
    // Define como primeiro da lista o próximo
    *lista = tmp->prx;

  if (tmp->prx != NULL) {
    tmp->prx->ant = tmp->ant;
  }
}

// Imprime a lista de Alunos
void imprimeLista(Aluno **lista) {
  printf("\nInício da lista\n\n");
  Aluno *tmp = *lista;
  while (tmp != NULL) {
    printf("Nome: %s, Nota: %.2f, Turma: %d\n", tmp->nome, tmp->nota,
           tmp->turma);
    tmp = tmp->prx;
  }
  printf("\nFim da lista\n");
}

// Método Main(), para implementar o `Roteiro de teste`
int main() {
  Aluno *lista = initList();

  inicioLista(&lista, 1, "João", 7.0);
  finalLista(&lista, 1, "Maria", 8.0);
  finalLista(&lista, 1, "Paula", 6.0);
  insereNaLista(&lista, 3, 1, "Carlos", 8.0);

  imprimeLista(&lista);

  excluiDaLista(&lista, 2);
  excluiDaLista(&lista, 3);

  imprimeLista(&lista);
  return 1;
}
