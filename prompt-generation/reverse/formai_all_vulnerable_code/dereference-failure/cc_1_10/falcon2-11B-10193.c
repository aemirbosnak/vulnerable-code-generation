//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000

void extract_metadata(char* file_name, char* author, char* email, char* date) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", file_name);
        return;
    }

    char line[MAX_LINE_LEN];
    char* tokens[5];
    char* token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " \t\n\r");
        if (strcmp(token, "/*") == 0) {
            char* comment = strtok(NULL, "*/");
            if (strcmp(comment, "*/") == 0) {
                continue;
            }

            for (int i = 0; i < 5; i++) {
                tokens[i] = strtok(comment, " \t\n\r");
            }

            if (strcmp(tokens[0], "Author:") == 0) {
                strncpy(author, tokens[1], sizeof(author));
                author[sizeof(author) - 1] = '\0';
            } else if (strcmp(tokens[0], "Email:") == 0) {
                strncpy(email, tokens[1], sizeof(email));
                email[sizeof(email) - 1] = '\0';
            } else if (strcmp(tokens[0], "Date:") == 0) {
                strncpy(date, tokens[1], sizeof(date));
                date[sizeof(date) - 1] = '\0';
            }
        }
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char* file_name = argv[1];
    char* author = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    char* email = (char*) malloc(sizeof(char) * MAX_LINE_LEN);
    char* date = (char*) malloc(sizeof(char) * MAX_LINE_LEN);

    extract_metadata(file_name, author, email, date);

    printf("Author: %s\n", author);
    printf("Email: %s\n", email);
    printf("Date: %s\n", date);

    free(author);
    free(email);
    free(date);

    return 0;
}