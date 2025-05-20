//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void read_contacts_from_file(mailing_list *list, FILE *file) {
    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        if (name == NULL || email == NULL) {
            printf("Invalid line format: %s\n", line);
            continue;
        }
        strncpy(list->contacts[list->num_contacts].name, name, MAX_NAME_LENGTH);
        strncpy(list->contacts[list->num_contacts].email, email, MAX_EMAIL_LENGTH);
        list->num_contacts++;
    }
}

void send_email(char *to, char *subject, char *message) {
    printf("Sending email to %s with subject '%s' and message:\n%s\n", to, subject, message);
}

int main() {
    mailing_list list;
    list.num_contacts = 0;
    list.contacts = malloc(sizeof(contact) * 100);

    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error opening contacts file.\n");
        return 1;
    }

    read_contacts_from_file(&list, file);
    fclose(file);

    printf("Number of contacts: %d\n", list.num_contacts);

    for (int i = 0; i < list.num_contacts; i++) {
        send_email(list.contacts[i].email, "Hello from the mailing list", "This is a test message.");
    }

    free(list.contacts);
    return 0;
}