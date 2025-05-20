//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void printMaze(Node* head)
{
  while(head)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->data = 1;
  head->next = malloc(sizeof(Node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 3;

  printMaze(head);

  // Find the route from 1 to 3
  Node* current = head;
  while(current)
  {
    if(current->data == 1)
    {
      current = current->next;
      while(current)
      {
        if(current->data == 3)
        {
          printf("The route from 1 to 3 is: ");
          printMaze(current);
          break;
        }
        current = current->next;
      }
    }
    current = current->next;
  }

  return 0;
}