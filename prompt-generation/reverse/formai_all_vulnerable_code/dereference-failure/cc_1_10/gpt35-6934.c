//FormAI DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

struct EmailNode {
  char email[MAX_EMAIL_LENGTH];
  struct EmailNode* next;
};

typedef struct EmailNode EmailNode;

EmailNode* createNode(char *email) {
  EmailNode* node = (EmailNode*) malloc(sizeof(EmailNode));
  strcpy(node->email, email);
  node->next = NULL;

  return node;
}

void addEmailToList(char *email, EmailNode **list) {
  EmailNode* node = createNode(email);

  if (*list == NULL) {
    *list = node;
  } else {
    EmailNode* curr = *list;
    while (curr->next != NULL) {
      curr = curr->next;
    }

    curr->next = node;
  }
}

void printEmailList(EmailNode* list) {
  EmailNode* curr = list;
  while (curr != NULL) {
    printf("%s\n", curr->email);
    curr = curr->next;
  }
}

void deleteEmailList(EmailNode* list) {
  EmailNode* curr = list;

  while (curr != NULL) {
    EmailNode* temp = curr;
    curr = curr->next;
    free(temp);
  }
}

int main() {
  EmailNode *list = NULL;
  int numEmails = 0;
  char input[MAX_EMAIL_LENGTH];

  printf("Enter email addresses to add to the mailing list (max %d):\n", MAX_EMAILS);

  while (numEmails < MAX_EMAILS) {
    printf("Email %d: ", numEmails + 1);
    fgets(input, MAX_EMAIL_LENGTH, stdin);

    if (strcmp(input, "exit\n") == 0) {
      break;
    }

    if (strlen(input) > 0 && input[strlen(input)-1] == '\n') {
      input[strlen(input)-1] = '\0';
    }

    addEmailToList(input, &list);
    numEmails++;
  }

  printf("\nMailing list:\n");
  printEmailList(list);

  deleteEmailList(list);

  return 0;
}