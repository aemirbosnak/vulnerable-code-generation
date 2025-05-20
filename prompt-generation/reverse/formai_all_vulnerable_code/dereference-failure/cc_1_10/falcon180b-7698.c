//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Email;

int main() {
    FILE *contacts_file = fopen("contacts.txt", "r");
    FILE *emails_file = fopen("emails.txt", "w");

    if (contacts_file == NULL || emails_file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Contact contacts[1000];
    int num_contacts = 0;

    while (fscanf(contacts_file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    fclose(contacts_file);

    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter subject: ");
    fgets(subject, MAX_SUBJECT_LENGTH, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    Email email = {subject, message};

    for (int i = 0; i < num_contacts; i++) {
        fprintf(emails_file, "To: %s\nSubject: %s\n\n%s\n", contacts[i].email, email.subject, email.message);
    }

    fclose(emails_file);

    printf("Emails have been sent successfully!\n");

    return 0;
}