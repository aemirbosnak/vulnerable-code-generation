//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_WORD 100

typedef struct {
    char name[MAX_WORD];
    char email[MAX_WORD];
    int phone_num;
} contact;

int main() {
    FILE *fp;
    char line[MAX_LINE];
    char *token;
    contact person;
    int count = 0;

    // open the file for reading
    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // read each line of the file
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        // clear the token buffer
        memset(token, 0, MAX_WORD);

        // tokenize the line
        token = strtok(line, " ");

        // extract the name from the token
        strcpy(person.name, token);

        // clear the token buffer
        memset(token, 0, MAX_WORD);

        // tokenize the line
        token = strtok(NULL, " ");

        // extract the email from the token
        strcpy(person.email, token);

        // clear the token buffer
        memset(token, 0, MAX_WORD);

        // tokenize the line
        token = strtok(NULL, " ");

        // extract the phone number from the token
        person.phone_num = atoi(token);

        // print the extracted information
        printf("Name: %s\nEmail: %s\nPhone Number: %d\n", person.name, person.email, person.phone_num);

        // increment the contact count
        count++;
    }

    // close the file
    fclose(fp);

    // print the total number of contacts
    printf("Total Contacts: %d\n", count);

    return 0;
}