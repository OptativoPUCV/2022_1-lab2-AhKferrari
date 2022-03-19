#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * nueva = (List *)malloc(sizeof(List));
  nueva->head = NULL;
  nueva->current = NULL;
  nueva->tail = NULL;
  return nueva;
} 

void * firstList(List * list) {
  list->current = list->head;
  if(list->head == NULL) return NULL;
  return list->head->data;
}

void * nextList(List * list) {
  if(!list->current || !list->current->next) return NULL;
  list->current = list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  list->current = list->tail;
  if(list->tail == NULL) return NULL;
  return list->tail->data;
}

void * prevList(List * list) {
  if(!list->current || !list->current->prev) return NULL;
  list->current = list->current->prev;
  return list->current->data;  
  }
//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

void pushFront(List * list, void * data) {
  Node * nodo = createNode ((void*) data);

  nodo->next = list->head;
  list->head = nodo;
  }

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}