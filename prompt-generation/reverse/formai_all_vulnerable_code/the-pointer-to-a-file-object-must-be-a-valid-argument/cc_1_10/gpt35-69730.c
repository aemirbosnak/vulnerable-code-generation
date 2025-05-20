//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 1000

// Email structure
typedef struct {
    char* from;
    char* to;
    char* subject;
    char* body;
} Email;

// Node for Linked List
typedef struct email_node {
    Email email;
    struct email_node* next;
} EmailNode;

// Head of Linked List
EmailNode* head = NULL;

// Add new email to Linked List
void add_email(Email email) {
    EmailNode* new_node = (EmailNode*)malloc(sizeof(EmailNode));
    new_node->email = email;
    new_node->next = head;
    head = new_node;
}

// Display all emails in Linked List
void display_emails() {
    EmailNode* current = head;
    while(current != NULL) {
        printf("From: %s\n", current->email.from);
        printf("To: %s\n", current->email.to);
        printf("Subject: %s\n", current->email.subject);
        printf("Body: %s\n", current->email.body);
        current = current->next;
    }
}

// Write emails to file
void write_emails(char* filename) {
    FILE* fp = fopen(filename, "w");
    EmailNode* current = head;
    while(current != NULL) {
        fprintf(fp, "%s\n", current->email.from);
        fprintf(fp, "%s\n", current->email.to);
        fprintf(fp, "%s\n", current->email.subject);
        fprintf(fp, "%s\n", current->email.body);
        current = current->next;
    }
    fclose(fp);
}

// Read emails from file
void read_emails(char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[100];
    char* from;
    char* to;
    char* subject;
    char* body;
    while(fgets(line, sizeof(line), fp) != NULL) {
        from = (char*)malloc(sizeof(char) * strlen(line));
        strcpy(from, line);
        fgets(line, sizeof(line), fp);
        to = (char*)malloc(sizeof(char) * strlen(line));
        strcpy(to, line);
        fgets(line, sizeof(line), fp);
        subject = (char*)malloc(sizeof(char) * strlen(line));
        strcpy(subject, line);
        fgets(line, sizeof(line), fp);
        body = (char*)malloc(sizeof(char) * strlen(line));
        strcpy(body, line);
        Email email = {from, to, subject, body};
        add_email(email);
    }
    fclose(fp);
}

int main() {
    int choice;
    char from[100], to[100], subject[100], body[1000], filename[100];
    do {
        printf("\n1. Compose Email\n2. View Emails\n3. Save Emails\n4. Load Emails\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter From: ");
                scanf("%s", from);
                printf("Enter To: ");
                scanf("%s", to);
                printf("Enter Subject: ");
                scanf("%s", subject);
                printf("Enter Body: ");
                scanf("%s", body);
                Email email = {from, to, subject, body};
                add_email(email);
                break;
            case 2:
                display_emails();
                break;
            case 3:
                printf("Enter filename to save emails: ");
                scanf("%s", filename);
                write_emails(filename);
                break;
            case 4:
                printf("Enter filename to load emails from: ");
                scanf("%s", filename);
                read_emails(filename);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);
    return 0;
}