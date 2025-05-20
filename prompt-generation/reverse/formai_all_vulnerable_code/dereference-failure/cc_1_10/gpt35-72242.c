//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function to welcome user
void welcomeMessage() {
  printf("Welcome to Genius Email Client!\n\n");
}

//Function to display menu options
int displayMenu() {
  int choice;
  printf("\nPlease select an option:\n");
  printf("1. Compose email\n");
  printf("2. View inbox\n");
  printf("3. View sent emails\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

//Email structure
struct email {
  char sender[100];
  char recipient[100];
  char subject[200];
  char message[500];
  char timestamp[50];
};

//Function to get current timestamp
char* getCurrentTimestamp() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *s = asctime(tm);
  s[strlen(s) - 1] = '\0'; //Removing the newline character
  return s;
}

//Function to compose email
void composeEmail() {
  struct email e;
  printf("\nPlease enter the following details:\n");
  printf("From: ");
  scanf("%s", e.sender);
  printf("To: ");
  scanf("%s", e.recipient);
  printf("Subject: ");
  scanf(" %[^\n]s", e.subject); //To allow spaces in subject
  printf("Message: ");
  scanf(" %[^\n]s", e.message); //To allow spaces in message
  strcpy(e.timestamp, getCurrentTimestamp());

  //Writing the email to file
  FILE *fp;
  fp = fopen("sent_emails.txt", "a");
  if(fp == NULL) {
    printf("Error opening file!\n");
    return;
  }
  fwrite(&e, sizeof(e), 1, fp);
  fclose(fp);

  printf("\nEmail sent successfully!\n\n");
}

//Function to view inbox
void viewInbox() {
  struct email e;
  FILE *fp;
  fp = fopen("inbox.txt", "r");
  if(fp == NULL) {
    printf("Inbox is empty!\n\n");
    return;
  }
  printf("\n=== INBOX ===\n\n");
  while(fread(&e, sizeof(e), 1, fp)) {
    printf("From: %s\n", e.sender);
    printf("Subject: %s\n", e.subject);
    printf("Message: %s\n", e.message);
    printf("Timestamp: %s\n\n", e.timestamp);
  }
  fclose(fp);
}

//Function to view sent emails
void viewSentEmails() {
  struct email e;
  FILE *fp;
  fp = fopen("sent_emails.txt", "r");
  if(fp == NULL) {
    printf("You haven't sent any email!\n\n");
    return;
  }
  printf("\n=== SENT EMAILS ===\n\n");
  while(fread(&e, sizeof(e), 1, fp)) {
    printf("To: %s\n", e.recipient);
    printf("Subject: %s\n", e.subject);
    printf("Message: %s\n", e.message);
    printf("Timestamp: %s\n\n", e.timestamp);
  }
  fclose(fp);
}

//Main function
int main() {
  welcomeMessage();
  int choice;

  do {
    choice = displayMenu();
    switch(choice) {
        case 1:
            composeEmail();
            break;
        case 2:
            viewInbox();
            break;
        case 3:
            viewSentEmails();
            break;
        case 4:
            printf("\nThank you for using Genius Email Client!\n\n");
            break;
        default:
            printf("\nInvalid choice, please try again!\n\n");
            break;
    }
  } while(choice != 4);

  return 0;
}