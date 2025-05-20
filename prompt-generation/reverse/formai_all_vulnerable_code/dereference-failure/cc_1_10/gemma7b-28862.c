//Gemma-7B DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10
#define MAX_MSG_LENGTH 255

typedef struct Message {
  char sender[MAX_MSG_LENGTH];
  char message[MAX_MSG_LENGTH];
  struct Message* next;
} Message;

Message* createMessage(char* sender, char* message) {
  Message* newMessage = (Message*)malloc(sizeof(Message));
  strcpy(newMessage->sender, sender);
  strcpy(newMessage->message, message);
  newMessage->next = NULL;
  return newMessage;
}

void addMessage(Message* head, Message* newMessage) {
  if (head == NULL) {
    head = newMessage;
  } else {
    head->next = newMessage;
  }
}

void printMessages(Message* head) {
  Message* currentMessage = head;
  while (currentMessage) {
    printf("From: %s\n", currentMessage->sender);
    printf("Message: %s\n", currentMessage->message);
    printf("\n");
    currentMessage = currentMessage->next;
  }
}

int main() {
  Message* head = NULL;

  // Simulate a multiplayer game where users send messages to each other
  char sender[MAX_MSG_LENGTH];
  char message[MAX_MSG_LENGTH];

  printf("Enter your name: ");
  scanf("%s", sender);

  printf("Enter your message: ");
  scanf("%s", message);

  addMessage(head, createMessage(sender, message));

  printMessages(head);

  return 0;
}