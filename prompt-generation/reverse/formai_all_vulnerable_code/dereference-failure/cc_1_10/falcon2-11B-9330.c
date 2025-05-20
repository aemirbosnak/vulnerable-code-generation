//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Struct for storing an email message
typedef struct {
  char sender[100];
  char recipient[100];
  char subject[100];
  char body[1000];
  char timestamp[100];
} email_t;

// Function to read an email message from the user
email_t* read_email() {
  email_t* email = (email_t*)malloc(sizeof(email_t));

  // Prompt the user to enter the sender's email address
  printf("Enter the sender's email address:\n");
  fgets(email->sender, sizeof(email->sender), stdin);

  // Remove newline character from the input
  email->sender[strcspn(email->sender, "\n")] = '\0';

  // Prompt the user to enter the recipient's email address
  printf("Enter the recipient's email address:\n");
  fgets(email->recipient, sizeof(email->recipient), stdin);

  // Remove newline character from the input
  email->recipient[strcspn(email->recipient, "\n")] = '\0';

  // Prompt the user to enter the subject of the email
  printf("Enter the subject of the email:\n");
  fgets(email->subject, sizeof(email->subject), stdin);

  // Remove newline character from the input
  email->subject[strcspn(email->subject, "\n")] = '\0';

  // Prompt the user to enter the body of the email
  printf("Enter the body of the email:\n");
  fgets(email->body, sizeof(email->body), stdin);

  // Remove newline character from the input
  email->body[strcspn(email->body, "\n")] = '\0';

  // Get the current timestamp
  time_t now = time(NULL);
  strftime(email->timestamp, sizeof(email->timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

  return email;
}

// Function to send the email
void send_email(email_t* email) {
  char command[100];
  strcpy(command, "echo \"");
  strcat(command, email->sender);
  strcat(command, " <");
  strcat(command, email->body);
  strcat(command, ">");
  strcat(command, email->recipient);
  strcat(command, "\"");
  system(command);
  printf("Email sent successfully!\n");
}

int main() {
  email_t* email = read_email();
  send_email(email);
  return 0;
}