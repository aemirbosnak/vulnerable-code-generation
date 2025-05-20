//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

struct person {
    char name[MAX_LINE_LENGTH];
    char address[MAX_LINE_LENGTH];
    char phone[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
};

struct person parse_line(char *line) {
    struct person person = {0};
    char *token;
    int i = 0;

    // Extract name
    token = strtok(line, ",");
    strncpy(person.name, token, MAX_LINE_LENGTH);
    i++;

    // Extract address
    token = strtok(NULL, ",");
    strncpy(person.address, token, MAX_LINE_LENGTH);
    i++;

    // Extract phone number
    token = strtok(NULL, ",");
    strncpy(person.phone, token, MAX_LINE_LENGTH);
    i++;

    // Extract email address
    token = strtok(NULL, ",");
    strncpy(person.email, token, MAX_LINE_LENGTH);

    return person;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    struct person person;

    file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        person = parse_line(line);
        printf("Name: %s\n", person.name);
        printf("Address: %s\n", person.address);
        printf("Phone: %s\n", person.phone);
        printf("Email: %s\n\n", person.email);
    }

    fclose(file);

    return 0;
}