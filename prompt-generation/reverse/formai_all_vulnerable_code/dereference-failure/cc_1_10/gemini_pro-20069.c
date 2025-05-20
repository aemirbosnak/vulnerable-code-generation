//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 256
#define MAX_KEYWORDS 10

// Resume token types
enum token_type {
    NAME,
    EMAIL,
    PHONE,
    SKILLS,
    EXPERIENCE,
    EDUCATION,
    PROJECTS,
    AWARDS,
    CERTIFICATIONS,
    OTHER
};

// Resume tokens
struct token {
    enum token_type type;
    char *value;
};

// Resume keywords
char *keywords[MAX_KEYWORDS] = {
    "name",
    "email",
    "phone",
    "skills",
    "experience",
    "education",
    "projects",
    "awards",
    "certifications",
    "other"
};

// Function to tokenize a resume
int tokenize_resume(char *resume, struct token tokens[]) {
    int num_tokens = 0;
    char *token_start = resume;
    char *token_end = NULL;

    while (*resume != '\0' && num_tokens < MAX_TOKENS) {
        // Skip whitespace
        while (*resume != '\0' && isspace(*resume))
            resume++;

        // Check if we have reached the end of the resume
        if (*resume == '\0')
            break;

        // Find the end of the token
        token_end = resume + 1;
        while (*token_end != '\0' && !isspace(*token_end))
            token_end++;

        // Allocate memory for the token
        tokens[num_tokens].value = malloc(token_end - token_start + 1);
        if (tokens[num_tokens].value == NULL) {
            fprintf(stderr, "Error: Could not allocate memory for token %d\n", num_tokens);
            return -1;
        }

        // Copy the token value
        strncpy(tokens[num_tokens].value, token_start, token_end - token_start);
        tokens[num_tokens].value[token_end - token_start] = '\0';

        // Determine the token type
        tokens[num_tokens].type = OTHER;
        for (int i = 0; i < MAX_KEYWORDS; i++) {
            if (strcmp(tokens[num_tokens].value, keywords[i]) == 0) {
                tokens[num_tokens].type = i;
                break;
            }
        }

        // Increment the number of tokens
        num_tokens++;

        // Advance the resume pointer
        resume = token_end;
    }

    return num_tokens;
}

// Function to print the resume tokens
void print_tokens(struct token tokens[], int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %s (%d)\n", i, tokens[i].value, tokens[i].type);
    }
}

// Function to free the resume tokens
void free_tokens(struct token tokens[], int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].value);
    }
}

int main() {
    // Allocate memory for the resume
    char *resume = malloc(1024);
    if (resume == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for resume\n");
        return -1;
    }

    // Get the resume from the user
    printf("Enter your resume: ");
    fgets(resume, 1024, stdin);

    // Tokenize the resume
    struct token tokens[MAX_TOKENS];
    int num_tokens = tokenize_resume(resume, tokens);
    if (num_tokens == -1) {
        return -1;
    }

    // Print the resume tokens
    print_tokens(tokens, num_tokens);

    // Free the resume tokens
    free_tokens(tokens, num_tokens);

    // Free the resume
    free(resume);

    return 0;
}