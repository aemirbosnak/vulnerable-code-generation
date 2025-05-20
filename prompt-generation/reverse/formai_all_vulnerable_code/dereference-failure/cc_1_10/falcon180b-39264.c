//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *name;
    char *email;
    char *phone;
} Contact;

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) == -1) {
        fprintf(stderr, "Error reading line\n");
        exit(EXIT_FAILURE);
    }

    if (line[read - 1] == '\n') {
        line[--read] = '\0';
    }

    return line;
}

Contact *parse_contact(char *line) {
    Contact *contact = malloc(sizeof(Contact));
    char *name = NULL;
    char *email = NULL;
    char *phone = NULL;
    char *token;

    token = strtok(line, ",");
    name = strdup(token);

    token = strtok(NULL, ",");
    email = strdup(token);

    token = strtok(NULL, ",");
    phone = strdup(token);

    contact->name = name;
    contact->email = email;
    contact->phone = phone;

    return contact;
}

void print_contact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone: %s\n\n", contact->phone);
}

void free_contact(Contact *contact) {
    free(contact->name);
    free(contact->email);
    free(contact->phone);
    free(contact);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    Contact *contact;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return 1;
    }

    while ((contact = parse_contact(read_line(fp)))!= NULL) {
        print_contact(contact);
        free_contact(contact);
    }

    fclose(fp);

    return 0;
}