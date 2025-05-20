//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 10240

typedef struct {
    char *subject;
    char *body;
} Email;

Email *read_email(FILE *file) {
    Email *email = malloc(sizeof(Email));
    char line[MAX_LINE_LENGTH];
    email->subject = NULL;
    email->body = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == 'S' && line[1] == 'u' && line[2] == 'b' && line[3] == 'j' && line[4] == 'e' && line[5] == 'c' && line[6] == 't') {
            char *subject = strtok(line + 7, ":");
            email->subject = strdup(subject);
        } else if (line[0] == 'B' && line[1] == 'o' && line[2] == 'd' && line[3] == 'y') {
            char *body = strtok(line + 5, ":");
            email->body = strdup(body);
        }
    }

    return email;
}

void print_email(Email *email) {
    if (email == NULL) {
        printf("No email found.\n");
        return;
    }

    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
}

void free_email(Email *email) {
    if (email == NULL) {
        return;
    }

    free(email->subject);
    free(email->body);
    free(email);
}

int main() {
    FILE *file = fopen("email.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Email *email = read_email(file);
    print_email(email);
    free_email(email);

    fclose(file);
    return 0;
}