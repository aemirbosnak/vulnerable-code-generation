//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {
  char* value;
  struct node* next;
};

typedef struct node Node;
typedef struct {
  Node* head;
  int size;
} LinkedList;

void addToList(LinkedList* list, char* value) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  if(list->size == 0) {
    list->head = new_node;
  } else {
    Node* current = list->head;
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  list->size++;
}

int isInList(LinkedList* list, char* value) {
  Node* current = list->head;
  while(current != NULL) {
    if(strcmp(current->value, value) == 0) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void printList(LinkedList* list) {
  Node* current = list->head;
  printf("\n[");
  while(current != NULL) {
    printf("%s", current->value);
    if(current->next != NULL) {
      printf(",");
    }
    current = current->next;
  }
  printf("]\n");
}

int main() {
  LinkedList* ip_list = (LinkedList*)malloc(sizeof(LinkedList));
  ip_list->head = NULL;
  ip_list->size = 0;

  char* ip;
  int i, j;
  srand(time(NULL));
  for(i = 0; i < 1000; i++) {
    ip = (char*)malloc(16);
    sprintf(ip, "%d.%d.%d.%d", rand() % 255, rand() % 255, rand() % 255, rand() % 255);
    if(!isInList(ip_list, ip)) {
      addToList(ip_list, ip);
      printf("New IP: %s\n", ip);
    } else {
      printf("Found duplicate: %s\n", ip);
    }
  }

  printf("\nFinal IP List:");
  printList(ip_list);

  return 0;
}