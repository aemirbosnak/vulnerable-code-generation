//FormAI DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>

// defining the structure for a node of the linked list
struct LinkedListNode {
  int data;
  struct LinkedListNode* next;
};

// function to add data to the linked list
struct LinkedListNode* addNode(struct LinkedListNode* head, int data) {
  struct LinkedListNode* newNode = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  return head;
}

// function to print the linked list
void printLinkedList(struct LinkedListNode* head) {
  struct LinkedListNode* current = head;
  printf("Your linked list is: ");
  while(current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}

// function to find the size of the linked list
int size(struct LinkedListNode* head) {
  int size = 0;
  while (head != NULL) {
    size++;
    head = head->next;
  }
  return size;
}

// function to remove a node from the linked list at a given index
struct LinkedListNode* removeNode(struct LinkedListNode* head, int index) {
  int i = 0;
  struct LinkedListNode* current = head, *prevNode = NULL;
  while (current != NULL && i != index) {
    prevNode = current;
    current = current->next;
    i++;
  }
  if (current == NULL) {
    printf("Index %d out of range for your linked list.\n", index);
    return head;
  }
  if (prevNode == NULL) {
    head = head->next;
  } else {
    prevNode->next = current->next;
  }
  free(current);
  return head;
}

// function to reverse the linked list
struct LinkedListNode* reverse(struct LinkedListNode* head) {
  struct LinkedListNode *prevNode = NULL, *currentNode = head, *nextNode = NULL;
  while (currentNode != NULL) {
    nextNode = currentNode->next;
    currentNode->next = prevNode;
    prevNode = currentNode;
    currentNode = nextNode;
  }
  head = prevNode;
  return head;
}

int main() {
  struct LinkedListNode* head = NULL;
  printf("Welcome to the MIND-BENDING Linked List Program!\n\n");
  printf("How many numbers would you like to add to your linked list?\n");
  int num, data;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    printf("Enter number %d to add to your linked list: ", i+1);
    scanf("%d", &data);
    head = addNode(head, data);
  }
  printLinkedList(head);
  printf("\n\nThe size of your linked list is: %d\n", size(head));
  if (size(head) > 0) {
    printf("Enter the index of the node you would like to remove: ");
    int index;
    scanf("%d", &index);
    head = removeNode(head, index);
    printLinkedList(head);
  }
  printf("\n\nNow we will reverse your linked list!\n");
  head = reverse(head);
  printLinkedList(head);
  return 0;
}