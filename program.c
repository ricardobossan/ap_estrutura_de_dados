#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

  char nome[20];

  float nota;

  int turma;

  struct Aluno *ant;

  struct Aluno *prx;

} Aluno;

// Inicializa a lista
Aluno *initLista() { return NULL; }

// TODO: Método de inserir no início da lista
// TODO: Método de inserir no final da lista
// TODO: Método de excluir do meio da lista
// TODO: Método de imprimir a lista
// TODO: Método Main(), para implementar o `Roteiro de teste`
