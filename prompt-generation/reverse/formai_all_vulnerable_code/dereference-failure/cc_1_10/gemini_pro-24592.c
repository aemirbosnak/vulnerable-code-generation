//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our queue, a vessel of wonder
typedef struct EnchantmentQueue {
  char *name;
  struct EnchantmentQueue *next;
} EQNode;

// The enigmatic queue keeper
EQNode *queueHead = NULL;
EQNode *queueTail = NULL;

// We welcome a new enchantment to our queue
void enqueue(char *enchantment) {
  EQNode *newNode = malloc(sizeof(EQNode));
  newNode->name = strdup(enchantment);
  newNode->next = NULL;
  if (queueTail == NULL) {
    queueHead = queueTail = newNode;
  } else {
    queueTail->next = newNode;
    queueTail = newNode;
  }
  printf("Enchanting! '%s' has joined the queue.\n", enchantment);
}

// We bid farewell to an enchantment from our queue
char *dequeue() {
  if (queueHead == NULL) {
    return NULL;
  }
  char *enchantment = queueHead->name;
  EQNode *temp = queueHead;
  queueHead = queueHead->next;
  if (queueHead == NULL) {
    queueTail = NULL;
  }
  free(temp);
  printf("Farewell, enchantment! '%s' has left the queue.\n", enchantment);
  return enchantment;
}

// We glimpse the enchantment at the queue's head
char *peek() {
  if (queueHead == NULL) {
    return NULL;
  }
  return queueHead->name;
}

// We unravel the secrets of our whimsical queue
void printQueue() {
  EQNode *curr = queueHead;
  printf("[ ");
  while (curr != NULL) {
    printf("'%s' ", curr->name);
    curr = curr->next;
  }
  printf("]\n");
}

// Our grand enchantment begins
int main() {
  // The enchantments we shall cast upon our queue
  char *enchantments[] = {
    "Swiftness of the Wind",
    "Strength of the Bear",
    "Wisdom of the Owl",
    "Healing Touch",
    "Protection of the Stag"
  };

  // We gather our enchantments into the queue
  for (int i = 0; i < 5; i++) {
    enqueue(enchantments[i]);
  }

  // We peek into the queue's secrets
  printf("Behold the enchantment at the queue's head: '%s'\n", peek());

  // We dequeue an enchantment, setting it free
  char *freedEnchantment = dequeue();

  // We print our enchanted queue
  printf("Our Enchanted Queue:\n");
  printQueue();

  // We welcome a new enchantment to our queue
  enqueue("Flight of the Eagle");

  // We dequeue another enchantment, giving it life
  char *anotherFreedEnchantment = dequeue();

  // We print our enchanted queue once more
  printf("Our Enchanted Queue:\n");
  printQueue();

  // We bid farewell to our enchanting companions
  free(freedEnchantment);
  free(anotherFreedEnchantment);

  return 0;
}