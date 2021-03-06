#include <stdlib.h>
#include <stdio.h>

#include "./ArvoreAVL.h"

int contador = 0;

Arvore *criar()
{
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;

  return arvore;
}

int vazia(Arvore *arvore)
{
  return arvore->raiz == NULL;
}

No *adicionarNo(No *no, int valor)
{
  contador++;

  if (valor > no->valor)
  {
    if (no->direita == NULL)
    {
      // printf("Adicionando %d\n", valor);
      No *novo = malloc(sizeof(No));
      novo->valor = valor;
      novo->pai = no;

      no->direita = novo;

      return novo;
    }
    else
    {
      return adicionarNo(no->direita, valor);
    }
  }
  else
  {
    if (no->esquerda == NULL)
    {
      // printf("Adicionando %d\n", valor);
      No *novo = malloc(sizeof(No));
      novo->valor = valor;
      novo->pai = no;

      no->esquerda = novo;

      return novo;
    }
    else
    {
      return adicionarNo(no->esquerda, valor);
    }
  }
}

No *adicionar(Arvore *arvore, int valor)
{
  if (arvore->raiz == NULL)
  {
    // printf("Adicionando %d\n", valor);
    No *novo = malloc(sizeof(No));
    novo->valor = valor;

    arvore->raiz = novo;

    return novo;
  }
  else
  {
    No *no = adicionarNo(arvore->raiz, valor);
    balanceamento(arvore, no);

    return no;
  }
}

void remover(Arvore *arvore, No *no)
{
  if (no->esquerda != NULL)
  {
    remover(arvore, no->esquerda);
  }

  if (no->direita != NULL)
  {
    remover(arvore, no->direita);
  }

  if (no->pai == NULL)
  {
    arvore->raiz = NULL;
  }
  else
  {
    if (no->pai->esquerda == no)
    {
      no->pai->esquerda = NULL;
    }
    else
    {
      no->pai->direita = NULL;
    }
  }

  free(no);
}

No *localizar(No *no, int valor)
{
  if (no->valor == valor)
  {
    return no;
  }
  else
  {
    if (valor < no->valor)
    {
      if (no->esquerda != NULL)
      {
        return localizar(no->esquerda, valor);
      }
    }
    else
    {
      if (no->direita != NULL)
      {
        return localizar(no->direita, valor);
      }
    }
  }

  return NULL;
}

void percorrerProfundidadeInOrder(No *no, void (*callback)(int))
{
  if (no != NULL)
  {
    percorrerProfundidadeInOrder(no->esquerda, callback);
    callback(no->valor);
    percorrerProfundidadeInOrder(no->direita, callback);
  }
}

void percorrerProfundidadePreOrder(No *no, void (*callback)(int))
{
  if (no != NULL)
  {
    callback(no->valor);
    percorrerProfundidadePreOrder(no->esquerda, callback);
    percorrerProfundidadePreOrder(no->direita, callback);
  }
}

void percorrerProfundidadePosOrder(No *no, void(callback)(int))
{
  if (no != NULL)
  {
    percorrerProfundidadePosOrder(no->esquerda, callback);
    percorrerProfundidadePosOrder(no->direita, callback);
    callback(no->valor);
  }
}

void balanceamento(Arvore *arvore, No *no)
{
  contador++;

  while (no != NULL)
  {
    // printf("Foi while\n");
    int fator = fb(no);
    // printf("Foi fb\n");

    if (fator > 1)
    { //??rvore mais pesada para esquerda
      //rota????o para a direita
      if (fb(no->esquerda) > 0)
      {
        // printf("RSD(%d)\n", no->valor);
        rsd(arvore, no); //rota????o simples a direita, pois o FB do filho tem sinal igual
      }
      else
      {
        // printf("RDD(%d)\n", no->valor);
        rdd(arvore, no); //rota????o dupla a direita, pois o FB do filho tem sinal diferente
      }
    }
    else if (fator < -1)
    { //??rvore mais pesada para a direita
      //rota????o para a esquerda
      if (fb(no->direita) < 0)
      {
        // printf("RSE(%d)\n", no->valor);
        rse(arvore, no); //rota????o simples a esquerda, pois o FB do filho tem sinal igual
      }
      else
      {
        // printf("RDE(%d)\n", no->valor);
        rde(arvore, no); //rota????o dupla a esquerda, pois o FB do filho tem sinal diferente
      }
    }

    no = no->pai;
  }
}

int altura(No *no)
{
  contador++;

  int esquerda = 0, direita = 0;

  if (no->esquerda != NULL)
  {
    esquerda = altura(no->esquerda) + 1;
  }

  if (no->direita != NULL)
  {
    direita = altura(no->direita) + 1;
  }

  return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(No *no)
{
  contador++;

  int esquerda = 0, direita = 0;

  if (no->esquerda != NULL)
  {
    esquerda = altura(no->esquerda) + 1;
  }

  if (no->direita != NULL)
  {
    direita = altura(no->direita) + 1;
  }

  return esquerda - direita;
}

No *rse(Arvore *arvore, No *no)
{
  contador++;

  No *pai = no->pai;
  No *direita = no->direita;

  no->direita = direita->esquerda;
  no->pai = direita;

  direita->esquerda = no;
  direita->pai = pai;

  if (pai == NULL)
  {
    arvore->raiz = direita;
  }
  else
  {
    if (pai->esquerda == no)
    {
      pai->esquerda = direita;
    }
    else
    {
      pai->direita = direita;
    }
  }

  return direita;
}

No *rsd(Arvore *arvore, No *no)
{
  contador++;

  No *pai = no->pai;
  No *esquerda = no->esquerda;

  no->esquerda = esquerda->direita;
  no->pai = esquerda;

  esquerda->direita = no;
  esquerda->pai = pai;

  if (pai == NULL)
  {
    arvore->raiz = esquerda;
  }
  else
  {
    if (pai->esquerda == no)
    {
      pai->esquerda = esquerda;
    }
    else
    {
      pai->direita = esquerda;
    }
  }

  return esquerda;
}

No *rde(Arvore *arvore, No *no)
{
  contador++;

  no->direita = rsd(arvore, no->direita);
  // printf("Foi rde\n");
  return rse(arvore, no);
}

No *rdd(Arvore *arvore, No *no)
{
  contador++;

  no->esquerda = rse(arvore, no->esquerda);
  return rsd(arvore, no);
}

void freeNo(No *no)
{
  if (no->direita != NULL)
  {
    freeNo(no->direita);
  }
  else
  {
    free(no->direita);
  }

  if (no->esquerda != NULL)
  {
    freeNo(no->esquerda);
  }
  else
  {
    free(no->esquerda);
  }
}

void freeArvore(Arvore *arvore)
{
  if (arvore->raiz != NULL)
  {
    freeNo(arvore->raiz);
    // freeNo(arvore->raiz->esquerda);

    free(arvore->raiz);
    free(arvore);
  }
}

int getNumeroOperacoes()
{
  return contador;
}