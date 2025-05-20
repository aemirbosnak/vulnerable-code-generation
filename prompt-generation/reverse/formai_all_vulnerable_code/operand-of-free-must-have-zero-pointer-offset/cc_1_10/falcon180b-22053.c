//Falcon-180B DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *get_email_address(char *line) {
    char *email_address = line;
    while (*line!= '\0' && *line!= '@') {
        line++;
    }
    if (*line == '\0') {
        return NULL;
    }
    *line = '\0';
    email_address = strdup(line + 1);
    return email_address;
}

char *get_subject(char *line) {
    char *subject = line;
    while (*line!= '\0' && *line!= ':') {
        line++;
    }
    if (*line == '\0') {
        return NULL;
    }
    *line = '\0';
    subject = line + 1;
    while (*subject!= '\0' && isspace(*subject)) {
        subject++;
    }
    return subject;
}

int main() {
    FILE *input_file = fopen("email.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove newline character

        char *email_address = get_email_address(line);
        if (email_address == NULL) {
            printf("Invalid email address: %s\n", line);
            continue;
        }

        char *subject = get_subject(line);
        if (subject == NULL) {
            printf("Invalid subject: %s\n", line);
            continue;
        }

        printf("Email address: %s\n", email_address);
        printf("Subject: %s\n", subject);
        printf("\n");

        free(email_address);
        free(subject);
    }

    fclose(input_file);
    return 0;
}