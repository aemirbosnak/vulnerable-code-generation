//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 512
#define MAX_EMAILS 10

typedef struct {
    char *name;
    char *email;
    time_t sent;
} email_t;

void init_email(email_t *emails, int max_emails) {
    int i;
    for (i = 0; i < max_emails; i++) {
        emails[i].name = malloc(MAX_LENGTH);
        emails[i].email = malloc(MAX_LENGTH);
        emails[i].sent = time(NULL);
    }
}

void add_email(email_t *emails, char *name, char *email) {
    int i;
    for (i = 0; i < MAX_EMAILS; i++) {
        if (strcmp(emails[i].name, name) != 0) {
            break;
        }
    }
    if (i == MAX_EMAILS) {
        printf("Error: too many emails\n");
        return;
    }
    strcpy(emails[i].name, name);
    strcpy(emails[i].email, email);
    emails[i].sent = time(NULL);
}

void print_emails(email_t *emails, int max_emails) {
    int i;
    for (i = 0; i < max_emails; i++) {
        printf("%s <%s> sent at %s\n", emails[i].name, emails[i].email, ctime(&emails[i].sent));
    }
}

int main() {
    email_t emails[MAX_EMAILS];
    int max_emails = 0;

    // Add some emails
    add_email(emails, "John Doe", "johndoe@example.com");
    add_email(emails, "Jane Doe", "janedoe@example.com");
    add_email(emails, "Bob Smith", "bobsmith@example.com");

    // Print the emails
    print_emails(emails, max_emails);

    // Wait for input
    printf("Press enter to continue...");
    getchar();

    // Delete an email
    int delete_index = get_delete_index();
    if (delete_index >= 0) {
        max_emails--;
        for (int i = delete_index; i < max_emails; i++) {
            memcpy(&emails[i], &emails[i + 1], sizeof(email_t));
        }
        free(emails[max_emails].name);
        free(emails[max_emails].email);
    }

    // Print the updated list of emails
    print_emails(emails, max_emails);

    return 0;
}

int get_delete_index() {
    int delete_index = -1;
    char input[MAX_LENGTH];
    printf("Enter an email index to delete (0-%d): ", MAX_EMAILS - 1);
    fgets(input, MAX_LENGTH, stdin);
    delete_index = atoi(input);
    return delete_index;
}