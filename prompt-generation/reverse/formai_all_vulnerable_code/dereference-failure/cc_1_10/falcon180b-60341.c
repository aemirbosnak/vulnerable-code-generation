//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAILS_PER_PERSON 5
#define SUBJECT_LEN 100
#define BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char emails[MAX_EMAILS_PER_PERSON][100];
    int num_emails;
} Person;

void add_email(Person *person) {
    if (person->num_emails >= MAX_EMAILS_PER_PERSON) {
        printf("Error: Cannot add more than %d emails per person.\n", MAX_EMAILS_PER_PERSON);
        return;
    }

    char email[100];
    printf("Enter email address: ");
    scanf("%s", email);

    strcpy(person->emails[person->num_emails], email);
    person->num_emails++;
}

void send_email(Person *person) {
    char subject[SUBJECT_LEN];
    char body[BODY_LEN];

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter body:\n");
    fgets(body, BODY_LEN, stdin);

    for (int i = 0; i < person->num_emails; i++) {
        printf("Sending email to %s...\n", person->emails[i]);
    }
}

int main() {
    Person person;

    printf("Enter your name:\n");
    scanf("%s", person.name);

    while (1) {
        printf("\n1. Add email\n2. Send email\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(&person);
                break;
            case 2:
                send_email(&person);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}