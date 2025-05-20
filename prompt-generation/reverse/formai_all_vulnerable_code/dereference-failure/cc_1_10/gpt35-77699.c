//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// This function generates a random email address
char* generate_email() {
  char* email = malloc(sizeof(char) * 30);
  strcpy(email, "");
  strcat(email, "somename");
  char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
  for (int i=0; i<8; i++) {
    email[strlen(email)] = alphabet[rand() % 26];
  }
  strcat(email, "@someemail.com");
  return email;
}

// This function prints the email menu and prompts the user to choose an option
int print_menu() {
  int choice;
  printf("\nEmail Client\n");
  printf("1. Compose\n");
  printf("2. Inbox\n");
  printf("3. Sent\n");
  printf("4. Generate email address\n");
  printf("5. Exit\n");
  printf("Enter choice: ");
  scanf("%d", &choice);
  return choice;
}

// This function prompts the user to compose an email
void compose_email(char* email_address) {
  char subject[50];
  char body[500];
  printf("To: %s\n", email_address);
  printf("Subject: ");
  scanf(" %[^\n]s", subject);
  printf("Body: ");
  scanf(" %[^\n]s", body);
  printf("\nEmail sent!\n");
}

// This function prints the inbox
void print_inbox() {
  printf("Inbox\n\n");
  printf("From: alice@someemail.com\n");
  printf("Subject: Hello\n");
  printf("Body: How are you?\n\n");
  printf("From: bob@someemail.com\n");
  printf("Subject: Meeting\n");
  printf("Body: Let's schedule a meeting for next week.\n\n");
}

// This function prints the sent emails
void print_sent() {
  printf("Sent\n\n");
  printf("To: alice@someemail.com\n");
  printf("Subject: Hello\n");
  printf("Body: I am doing well, thank you.\n\n");
}

// Main function
int main() {

  char* email_address = generate_email(); // generate a random email address
  int choice = -1;

  while (choice != 5) {
    choice = print_menu();
    switch(choice) {
      case 1:
        compose_email(email_address);
        break;
      case 2:
        print_inbox();
        break;
      case 3:
        print_sent();
        break;
      case 4:
        free(email_address);
        email_address = generate_email();
        printf("\nNew email address generated: %s\n", email_address);
        break;
      case 5:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice.\n");
    }
  }

  return 0;
}