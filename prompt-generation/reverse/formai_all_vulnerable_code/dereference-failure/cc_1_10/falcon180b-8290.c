//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int main() {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    int num_contacts = 0;
    Contact *contacts = NULL;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");

        if (name == NULL || email == NULL) {
            printf("Error: Invalid contact information.\n");
            fclose(file);
            return 1;
        }

        num_contacts++;
        contacts = realloc(contacts, sizeof(Contact) * num_contacts);

        strncpy(contacts[num_contacts - 1].name, name, MAX_NAME_LEN);
        strncpy(contacts[num_contacts - 1].email, email, MAX_EMAIL_LEN);
    }

    fclose(file);

    printf("Number of contacts: %d\n", num_contacts);

    for (int i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }

    return 0;
}