//FormAI DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 80
#define MAX_EMAIL_BODY_LENGTH 2000

typedef struct {
  char sender[40];
  char recipient[40];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_EMAIL_BODY_LENGTH];
} email;

char emailsFile[] = "emails.txt"; // file to store emails
email inbox[MAX_EMAILS]; // array to hold emails

int count_emails() {
  int count = 0;
  FILE *file;

  file = fopen(emailsFile, "r");

  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      count++;
    }
  }

  fclose(file);

  return count;
}

void save_email(email newEmail) {
  FILE *file;

  file = fopen(emailsFile, "a");

  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  fprintf(file, "%s;%s;%s;%s\n", newEmail.sender, newEmail.recipient, newEmail.subject, newEmail.body);

  fclose(file);
}

void load_emails() {
  FILE *file;

  file = fopen(emailsFile, "r");

  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  char line[200];
  int i = 0;
  while (fgets(line, sizeof(line), file)) {
    char *token = strtok(line, ";");
    strcpy(inbox[i].sender, token);

    token = strtok(NULL, ";");
    strcpy(inbox[i].recipient, token);

    token = strtok(NULL, ";");
    strcpy(inbox[i].subject, token);

    token = strtok(NULL, ";");
    strcpy(inbox[i].body, token);

    i++;
  }

  fclose(file);
}

void print_emails() {
  printf("Inbox:\n");

  for (int i = 0; i < count_emails(); i++) {
    printf("%d. From: %s\nTo: %s\nSubject: %s\n%s\n",
    i+1, inbox[i].sender, inbox[i].recipient, inbox[i].subject, inbox[i].body);
  }
}

void compose_email() {
  email newEmail;

  printf("To: ");
  scanf("%s", newEmail.recipient);

  printf("Subject: ");
  getchar(); // consume newline character left by previous scanf
  fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
  newEmail.subject[strcspn(newEmail.subject, "\n")] = '\0'; // remove newline character

  printf("Body:\n");
  fgets(newEmail.body, MAX_EMAIL_BODY_LENGTH, stdin);
  newEmail.body[strcspn(newEmail.body, "\n")] = '\0'; // remove newline character

  printf("Sending email...\n");

  strcpy(newEmail.sender, "me@myemail.com");
  save_email(newEmail);
}

int main() {
  load_emails();

  while (1) {
    printf("\nCommands:\n");
    printf("-c: Compose email\n-i: Inbox\n-e: Exit\n");
    printf("Enter command: ");

    char command[2];
    scanf("%s", command);

    if (strcmp(command, "-c") == 0) {
      compose_email();
    } else if (strcmp(command, "-i") == 0) {
      print_emails();
    } else if (strcmp(command, "-e") == 0) {
      printf("Exiting...\n");
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}