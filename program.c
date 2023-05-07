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

// Insere Aluno no início da lista
void inicioLista(Aluno **lista, int turma, char nome[], float nota) {

  Aluno *primeiro = (Aluno *)malloc(sizeof(Aluno));

  primeiro->turma = turma;
  strcpy(primeiro->nome, nome);
  primeiro->nota = nota;
  primeiro->prx = *lista;
  primeiro->ant = NULL;

  // Checa se a lista não está vazia. Se não está, atribui o novo primeiro nodo
  // ao início da lista.
  if (*lista != NULL) {
    (*lista) = primeiro;
  }

  *lista = primeiro;
}

// TODO: Insere Aluno no final da lista
// TODO: Exclui do meio da lista
// TODO: Imprime a lista
// TODO: Método Main(), para implementar o `Roteiro de teste`
int main() {
  Aluno *lista = initList();

  inicioLista(&lista, 1, "Fabio", 9.0);
  inicioLista(&lista, 1, "Pedro", 8.0);

  printf("Primeiro:\n");
  printf("%s", strcat(lista->nome, "\n"));
  printf("Segundo:\n");
  printf("%s", strcat(lista->prx->nome, "\n"));
  return 1;
}
