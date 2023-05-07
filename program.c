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

// TODO: Insere Aluno ao final da lista
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

// TODO: Exclui Aluno do meio da lista
// TODO: Imprime a lista de Alunos
// TODO: Método Main(), para implementar o `Roteiro de teste`
int main() {
  Aluno *lista = initList();

  inicioLista(&lista, 1, "Fabio", 9.0);
  inicioLista(&lista, 1, "Pedro", 8.0);
  finalLista(&lista, 2, "Alice", 10.0);

  Aluno *tmp = lista;
  while (tmp != NULL) {
    printf("Nome: %s, Turma: %d, Nota: %.2f\n", tmp->nome, tmp->turma,
           tmp->nota);
    tmp = tmp->prx;
  }

  return 1;
}
