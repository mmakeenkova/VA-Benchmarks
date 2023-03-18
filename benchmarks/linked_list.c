#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int data; 
    struct listNode *next; 
} node; 

int main(int argc, char** argv) {
  list_test(100); 
  return 0; 
}

node * List_createNode(int value) {
  node * nodePointer = (node *) malloc(sizeof(node));

  if(nodePointer == NULL)
    return NULL;

  nodePointer->next = NULL;

  nodePointer->data = value;
  return nodePointer;
}

void List_destory(node * list) {
  node *curr;
  while((curr = list) != NULL) {
    list = list->next; 
    free(curr); 
    //printf("node removed \n");
  }
}

void list_test(int n) {
  int num_allocs = 100;
  for(int k=0; k<num_allocs; k++) {
    int iter = n; 
    node *last = List_createNode(1); 
    node * first = last;
    for(int i=0; i<iter; i++) {
      node *new = List_createNode(0); 
      last->next = new; 
      last = new; 
      //printf("node added \n");
    }
    List_destory(first); 
    //printf("completed \n");
  }
}
