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

  if (tmp->prx != NULL)
    tmp->prx->ant = tmp->ant;

  free(tmp);
}

// Imprime a lista de Alunos
void imprimeLista(Aluno *lista) {
  Aluno *tmp = lista;
  while (tmp != NULL) {
    printf("Nome: %s, Turma: %d, Nota: %.2f\n", tmp->nome, tmp->turma,
           tmp->nota);
    tmp = tmp->prx;
  }
}
// TODO: Método Main(), para implementar o `Roteiro de teste`
int main() {
  Aluno *lista = initList();

  finalLista(&lista, 1, "Fabio", 7.0);
  finalLista(&lista, 1, "João", 8.0);
  finalLista(&lista, 1, "Ronaldo", 6.0);
  finalLista(&lista, 1, "Pedro", 8.0);
  finalLista(&lista, 1, "Maria", 10.0);
  finalLista(&lista, 1, "Felipe", 9.0);
  finalLista(&lista, 2, "Alice", 10.0);
  excluiDaLista(&lista, 3);
  excluiDaLista(&lista, 1);

  imprimeLista(lista);

  free(lista);

  return 1;
}
