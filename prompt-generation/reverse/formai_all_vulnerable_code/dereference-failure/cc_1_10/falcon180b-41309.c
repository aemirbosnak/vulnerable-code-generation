//Falcon-180B DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char *header;
    int header_size;
    int body_size;
    char *body;
    int i;
    int num_tokens;
    token_t tokens[MAX_TOKENS];

    // Open the input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    // Read the first line of the file to get the header
    fgets(line, MAX_LINE_LENGTH, input_file);
    header = strdup(line);
    header_size = strlen(header);

    // Read the rest of the file to get the body
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        body_size += strlen(line);
    }
    body = (char *) malloc(body_size + 1);
    rewind(input_file);
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        strcat(body, line);
    }

    // Parse the header to get the email information
    num_tokens = parse_header(header, tokens);
    if (num_tokens < 2) {
        printf("Error: Invalid email header.\n");
        exit(1);
    }

    // Print the email information
    printf("From: %s\n", tokens[0].value);
    printf("To: %s\n", tokens[1].value);

    // Print the body of the email
    printf("\n%s\n", body);

    // Free memory
    free(header);
    free(body);
    for (i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    return 0;
}

int parse_header(char *header, token_t tokens[]) {
    char *token;
    char *value;
    int num_tokens;
    int i;

    // Initialize the token array
    num_tokens = 0;
    for (i = 0; i < MAX_TOKENS; i++) {
        tokens[i].name = NULL;
        tokens[i].value = NULL;
    }

    // Parse the header
    token = strtok(header, ": ");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens in email header.\n");
            exit(1);
        }
        value = strtok(NULL, ": ");
        if (value == NULL) {
            printf("Error: Invalid email header.\n");
            exit(1);
        }
        tokens[num_tokens].name = strdup(token);
        tokens[num_tokens].value = strdup(value);
        num_tokens++;
        token = strtok(NULL, ": ");
    }

    // Make sure we have at least two tokens
    if (num_tokens < 2) {
        printf("Error: Invalid email header.\n");
        exit(1);
    }

    return num_tokens;
}