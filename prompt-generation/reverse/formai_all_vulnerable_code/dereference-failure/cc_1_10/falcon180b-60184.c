//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

// Function to tokenize the input string
void tokenize(char *input, char **tokens) {
    int i = 0;
    char *token;

    // Allocate memory for the tokens
    tokens[0] = (char *)malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(tokens[0], input);

    // Tokenize the input string
    token = strtok(tokens[0], " ");
    while (token!= NULL) {
        tokens[i] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, " ");
    }
}

// Function to print the parsed resume
void print_resume(char **tokens) {
    int i;

    // Print the personal information
    printf("Name: %s\n", tokens[0]);
    printf("Email: %s\n", tokens[1]);
    printf("Phone: %s\n", tokens[2]);

    // Print the education details
    printf("\nEducation:\n");
    for (i = 3; i < 6; i++) {
        printf("- %s\n", tokens[i]);
    }

    // Print the work experience details
    printf("\nWork Experience:\n");
    for (i = 6; i < 9; i++) {
        printf("- %s\n", tokens[i]);
    }

    // Print the skills
    printf("\nSkills:\n");
    for (i = 9; i < 12; i++) {
        printf("- %s\n", tokens[i]);
    }
}

// Main function to parse the resume
int main() {
    char input[MAX_WORDS];
    char *tokens[12];

    // Read the input resume
    printf("Enter the resume:\n");
    fgets(input, MAX_WORDS, stdin);

    // Tokenize the input string
    tokenize(input, tokens);

    // Print the parsed resume
    print_resume(tokens);

    return 0;
}