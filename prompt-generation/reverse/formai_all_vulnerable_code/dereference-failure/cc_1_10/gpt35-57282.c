//FormAI DATASET v1.0 Category: Email Client ; Style: thoughtful
// START OF CODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000

typedef struct email {
    char *subject;
    char *sender;
    char *recipient;
    char *message;
} Email;

Email *emails[MAX_EMAILS];  // Pointer array for emails
int count = 0;  // Number of emails

void printMenu();
int getEmailCount();
void sendEmail();
void receiveEmail();
void viewInbox();
void viewEmail(int index);
void deleteEmail(int index);
char *readString();
void cleanup();

int main() {
    int choice = -1;
    
    while (choice != 0) {
        printMenu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                sendEmail();
                break;
            case 2:
                receiveEmail();
                break;
            case 3:
                viewInbox();
                break;
            case 0:
                cleanup();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}

void printMenu() {
    printf("\n1. Send email\n");
    printf("2. Receive email\n");
    printf("3. View inbox\n");
    printf("0. Quit\n");
}

int getEmailCount() {
    int count = 0;
    
    for (int i = 0; i < MAX_EMAILS; i++) {
        if (emails[i] != NULL) {
            count++;
        }
    }
    
    return count;
}

void sendEmail() {
    char *subject;
    char *sender;
    char *recipient;
    char *message;
    
    subject = readString("Enter subject: ");
    sender = readString("Enter your email address: ");
    recipient = readString("Enter recipient email address: ");
    message = readString("Enter message: ");
    
    Email *newEmail = (Email *) malloc(sizeof(Email));
    newEmail->subject = subject;
    newEmail->sender = sender;
    newEmail->recipient = recipient;
    newEmail->message = message;
    
    emails[count] = newEmail;
    count++;
    
    printf("Email sent.\n");
}

void receiveEmail() {
    char *subject = "Hello from John";
    char *sender = "john@doe.com";
    char *recipient = "you@yourdomain.com";
    char *message = "This is a test email to show that the receiveEmail function is working properly.";
    
    Email *newEmail = (Email *) malloc(sizeof(Email));
    newEmail->subject = subject;
    newEmail->sender = sender;
    newEmail->recipient = recipient;
    newEmail->message = message;
    
    emails[count] = newEmail;
    count++;
}

void viewInbox() {
    int numEmails = getEmailCount();
    
    if (numEmails == 0) {
        printf("Inbox is empty.\n");
        return;
    }
    
    printf("Inbox:\n");
    
    for (int i = 0; i < numEmails; i++) {
        Email *email = emails[i];
        printf("%d. %s\n", i+1, email->subject);
    }
    
    int choice = -1;
    printf("Enter email number to view (0 to cancel): ");
    scanf("%d", &choice);
    
    if (choice != 0) {
        viewEmail(choice-1);
    }
}

void viewEmail(int index) {
    Email *email = emails[index];
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Message: %s\n", email->message);
    
    int choice = -1;
    printf("Enter 1 to delete, 0 to cancel: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        deleteEmail(index);
    }
}

void deleteEmail(int index) {
    free(emails[index]->subject);
    free(emails[index]->sender);
    free(emails[index]->recipient);
    free(emails[index]->message);
    free(emails[index]);
    emails[index] = NULL;
    
    printf("Email deleted.\n");
}

// Read a string from the user with a prompt
char *readString(char *prompt) {
    char buffer[512];
    printf("%s", prompt);
    scanf(" %[^\n]", buffer);
    
    char *str = (char *) malloc(strlen(buffer) + 1);  // Allocate memory for string
    strcpy(str, buffer);  // Copy string to allocated memory
    return str;
}

void cleanup() {
    for (int i = 0; i < MAX_EMAILS; i++) {
        if (emails[i] != NULL) {
            free(emails[i]->subject);
            free(emails[i]->sender);
            free(emails[i]->recipient);
            free(emails[i]->message);
            free(emails[i]);
        }
    }
    
    printf("Exiting.\n");
}

// END OF CODE