//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD 64

typedef struct {
    char name[MAX_WORD];
    char address[MAX_WORD];
    char phone[MAX_WORD];
    char email[MAX_WORD];
} contact;

void parse_line(char *line, contact *contact) {
    char *token = strtok(line, ",");
    while (token!= NULL) {
        if (strlen(token) > MAX_WORD - 1) {
            printf("Error: Field too long.\n");
            exit(1);
        }
        strcpy(contact->name, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Missing fields.\n");
            exit(1);
        }
        strcpy(contact->address, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Missing fields.\n");
            exit(1);
        }
        strcpy(contact->phone, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Missing fields.\n");
            exit(1);
        }
        strcpy(contact->email, token);
        token = strtok(NULL, ",");
        if (token!= NULL) {
            printf("Error: Too many fields.\n");
            exit(1);
        }
    }
}

void print_contact(contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Address: %s\n", contact->address);
    printf("Phone: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
    printf("\n");
}

int main() {
    FILE *fp;
    char line[MAX_LINE];
    contact contact;

    if ((fp = fopen("contacts.txt", "r")) == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        parse_line(line, &contact);
        print_contact(&contact);
    }

    fclose(fp);
    return 0;
}