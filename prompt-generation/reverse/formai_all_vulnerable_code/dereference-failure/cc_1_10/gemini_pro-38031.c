//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: visionary
// A Visionary Tale of Linked List Operations

#include <stdio.h>
#include <stdlib.h>

// Elixir of Node
typedef struct Node {
  int payload;       // Treasure within
  struct Node *after; // Path to the next realm
} Node;

// The Eternal List
typedef struct LinkedList {
  Node *head;        // Sentinel of the first realm
  Node *tail;        // Guardian of the final realm
  int length;        // Threads that weave the realms
} LinkedList;

// The Genesis: Creating an Empty Linked List
LinkedList *CreateLinkedList() {
  LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}

// The Tapestry: Adding a Node at the End
Node *AddNodeAtEnd(LinkedList *list, int payload) {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->payload = payload;
  newNode->after = NULL;
  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->after = newNode;
    list->tail = newNode;
  }
  list->length++;
  return newNode;
}

// The Anchor: Adding a Node at the Beginning
Node *AddNodeAtBeginning(LinkedList *list, int payload) {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->payload = payload;
  newNode->after = NULL;
  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->after = list->head;
    list->head = newNode;
  }
  list->length++;
  return newNode;
}

// The Sentinel: Deleting a Node from the Beginning
int DeleteNodeFromBeginning(LinkedList *list) {
  if (list->head == NULL) {
    printf("The list is empty, nothing to delete.\n");
    return -1;
  } else if (list->length == 1) {
    int payload = list->head->payload;
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return payload;
  } else {
    int payload = list->head->payload;
    Node *newHead = list->head->after;
    free(list->head);
    list->head = newHead;
    list->length--;
    return payload;
  }
}

// The Guardian: Deleting a Node from the End
int DeleteNodeFromEnd(LinkedList *list) {
  if (list->head == NULL) {
    printf("The list is empty, nothing to delete.\n");
    return -1;
  } else if (list->length == 1) {
    int payload = list->head->payload;
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return payload;
  } else {
    Node *nodeBeforeTail = list->head;
    while (nodeBeforeTail->after != list->tail) {
      nodeBeforeTail = nodeBeforeTail->after;
    }
    int payload = list->tail->payload;
    free(list->tail);
    list->tail = nodeBeforeTail;
    list->tail->after = NULL;
    list->length--;
    return payload;
  }
}

// The Seeker: Finding a Node by Payload
Node *FindNodeByPayload(LinkedList *list, int payload) {
  Node *currentNode = list->head;
  while (currentNode != NULL) {
    if (currentNode->payload == payload) {
      return currentNode;
    }
    currentNode = currentNode->after;
  }
  return NULL;
}

// The Messenger: Printing the List
void PrintLinkedList(LinkedList *list) {
  Node *currentNode = list->head;
  printf("The List: ");
  while (currentNode != NULL) {
    printf("%d ", currentNode->payload);
    currentNode = currentNode->after;
  }
  printf("\n");
}

// The Odyssey: The Grand Adventure
int main() {
  LinkedList *list = CreateLinkedList();

  AddNodeAtEnd(list, 1);
  AddNodeAtEnd(list, 2);
  AddNodeAtEnd(list, 3);
  AddNodeAtBeginning(list, 0);
  PrintLinkedList(list);

  Node *foundNode = FindNodeByPayload(list, 2);
  if (foundNode != NULL) {
    printf("Found node with payload 2: %d\n", foundNode->payload);
  } else {
    printf("Node with payload 2 not found.\n");
  }

  DeleteNodeFromBeginning(list);
  DeleteNodeFromEnd(list);
  PrintLinkedList(list);

  return 0;
}