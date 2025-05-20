//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char name[MAX_LINE_SIZE];
    char address[MAX_LINE_SIZE];
    char phone_number[MAX_LINE_SIZE];
    char email[MAX_LINE_SIZE];
} contact;

contact parse_line(char *line) {
    contact result = {0};
    char *token = strtok(line, ",");

    while (token!= NULL) {
        if (strlen(token) >= MAX_LINE_SIZE) {
            printf("Error: field too long\n");
            exit(1);
        }

        strcpy(result.name, token);
        token = strtok(NULL, ",");
    }

    return result;
}

void write_to_file(FILE *file, contact *contact) {
    fprintf(file, "Name: %s\n", contact->name);
    fprintf(file, "Address: %s\n", contact->address);
    fprintf(file, "Phone Number: %s\n", contact->phone_number);
    fprintf(file, "Email: %s\n\n", contact->email);
}

int main() {
    FILE *input_file = fopen("contacts.csv", "r");

    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    FILE *output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        contact contact = parse_line(line);
        write_to_file(output_file, &contact);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}