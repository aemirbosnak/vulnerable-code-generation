//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_C_NET_LINKS 10

typedef struct CNetNode {
  char name[255];
  struct CNetNode* next;
  struct CNetNode* links[MAX_C_NET_LINKS];
} CNetNode;

CNetNode* CNetNode_Create(char* name) {
  CNetNode* node = (CNetNode*)malloc(sizeof(CNetNode));
  strcpy(node->name, name);
  node->next = NULL;
  for (int i = 0; i < MAX_C_NET_LINKS; i++) {
    node->links[i] = NULL;
  }
  return node;
}

void CNetNode_AddLink(CNetNode* node, CNetNode* other) {
  for (int i = 0; i < MAX_C_NET_LINKS; i++) {
    if (node->links[i] == NULL) {
      node->links[i] = other;
      return;
    }
  }
  printf("Error: No more links available.\n");
}

int main() {
  CNetNode* head = CNetNode_Create("A");
  CNetNode* second = CNetNode_Create("B");
  CNetNode_AddLink(head, second);

  CNetNode* third = CNetNode_Create("C");
  CNetNode_AddLink(second, third);

  CNetNode* fourth = CNetNode_Create("D");
  CNetNode_AddLink(third, fourth);

  CNetNode* fifth = CNetNode_Create("E");
  CNetNode_AddLink(fourth, fifth);

  printf("Network topology:\n");
  CNetNode* current = head;
  while (current) {
    printf("%s ", current->name);
    CNetNode* link = current->links;
    while (link) {
      printf("-> %s ", link->name);
      link = link->next;
    }
    printf("\n");
    current = current->next;
  }

  return 0;
}