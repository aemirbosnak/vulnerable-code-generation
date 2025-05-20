//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LEN 1024
#define MAX_KEYWORDS 10

// Define structure for keyword matching
typedef struct {
    char* keyword;
    int count;
} Keyword;

// Define function to read in resume text
char* readResume() {
    char* resume = malloc(MAX_RESUME_LEN * sizeof(char));
    printf("Please input your resume:\n");
    fgets(resume, MAX_RESUME_LEN, stdin);
    return resume;
}

// Define function to tokenize resume text
char** tokenizeResume(char* resume) {
    char** tokens = malloc(MAX_RESUME_LEN * sizeof(char*));
    char* delim = " ,.-\n";
    char* token = strtok(resume, delim);
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }
    return tokens;
}

// Define function to match keywords in resume tokens
Keyword* matchKeywords(char** tokens, char** keywords, int numKeywords) {
    Keyword* matches = malloc(numKeywords * sizeof(Keyword));
    for (int i = 0; i < numKeywords; i++) {
        matches[i].keyword = keywords[i];
        matches[i].count = 0;
    }

    for (int i = 0; tokens[i] != NULL; i++) {
        for (int j = 0; j < numKeywords; j++) {
            if (strcmp(tokens[i], keywords[j]) == 0) {
                matches[j].count++;
            }
        }
    }
    return matches;
}

// Define function to print keyword matches
void printKeywordMatches(Keyword* matches, int numKeywords) {
    printf("\nResults:\n");
    printf("------------------------\n");
    for (int i = 0; i < numKeywords; i++) {
        printf("%s: %d\n", matches[i].keyword, matches[i].count);
    }
}

// Define main function to parse resume for keywords and output count
int main() {
    // Define keywords to match
    char* keywords[MAX_KEYWORDS] = {"Java", "C++", "Python", "Microsoft", "Agile", "Scrum", "Data Analysis", "Teamwork", "Problem-solving", "Communication"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    // Read in resume and tokenize
    char* resume = readResume();
    char** tokens = tokenizeResume(resume);

    // Match keywords and output results
    Keyword* matches = matchKeywords(tokens, keywords, numKeywords);
    printKeywordMatches(matches, numKeywords);

    // Free memory
    for (int i = 0; i < numKeywords; i++) {
        free(matches[i].keyword);
    }
    free(matches);
    free(resume);
    free(tokens);

    return 0;
}