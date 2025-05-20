//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char data;
  struct node *next;
};

struct node *create_node(char data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void push(struct node **head, char data) {
  struct node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

int pop(struct node **head) {
  if (*head == NULL) {
    return -1;
  }
  struct node *temp = *head;
  *head = (*head)->next;
  free(temp);
  return 0;
}

int is_palindrome(char *str) {
  struct node *head = NULL;
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    push(&head, str[i]);
  }
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != pop(&head)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char str[] = "madam";
  if (is_palindrome(str)) {
    printf("%s is a palindrome\n", str);
  } else {
    printf("%s is not a palindrome\n", str);
  }
  return 0;
}