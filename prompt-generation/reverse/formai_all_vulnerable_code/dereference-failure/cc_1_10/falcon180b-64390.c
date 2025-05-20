//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_WORD_LENGTH];
    char address[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
} Contact;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    Contact contacts[100];
    int num_contacts = 0;

    if (argc!= 2) {
        printf("Incorrect number of arguments.\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, &delimiter);
        if (token == NULL) {
            continue;
        }
        strcpy(contacts[num_contacts].name, token);
        token = strtok(NULL, &delimiter);
        if (token == NULL) {
            continue;
        }
        strcpy(contacts[num_contacts].address, token);
        token = strtok(NULL, &delimiter);
        if (token == NULL) {
            continue;
        }
        strcpy(contacts[num_contacts].phone, token);
        token = strtok(NULL, &delimiter);
        if (token == NULL) {
            continue;
        }
        strcpy(contacts[num_contacts].email, token);
        num_contacts++;
    }

    fclose(file);

    printf("Number of contacts: %d\n", num_contacts);

    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Address: %s\n", contacts[i].address);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("\n");
    }

    return 0;
}