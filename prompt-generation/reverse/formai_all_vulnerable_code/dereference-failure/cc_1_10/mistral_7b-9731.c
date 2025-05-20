//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char company[50];
    char phone[20];
    char email[50];
} Contact;

void parse_line(char *line, Contact *contact) {
    char *token;
    int field = 0;

    token = strtok(line, ":");
    strcpy(contact->name, token);

    token = strtok(NULL, ":");
    token[strlen(token) - 1] = '\0';
    field++;

    if (strcmp(token, "Company") == 0) {
        token = strtok(NULL, ":");
        strcpy(contact->company, token);
        field++;
    }

    if (strcmp(contact->name, "Phone") == 0) {
        token = strtok(NULL, ":");
        strcpy(contact->phone, token);
        field++;
    }

    if (strcmp(contact->name, "Email") == 0) {
        token = strtok(NULL, ":");
        strcpy(contact->email, token);
        field++;
    }

    if (field != 4) {
        printf("Invalid line: %s\n", line);
        exit(1);
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[100];
    Contact contacts[100];
    int i = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        Contact contact;
        parse_line(line, &contact);
        contacts[i++] = contact;
    }

    fclose(fp);

    printf("Contacts:\n");
    for (int j = 0; j < i; j++) {
        printf("\nName: %s\nCompany: %s\nPhone: %s\nEmail: %s",
            contacts[j].name, contacts[j].company, contacts[j].phone, contacts[j].email);
    }

    return 0;
}