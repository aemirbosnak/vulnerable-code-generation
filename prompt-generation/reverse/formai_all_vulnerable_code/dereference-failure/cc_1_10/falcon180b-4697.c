//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

// Data structure to hold parsed resume data
typedef struct {
    char name[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
    char phone[MAX_LINE_LENGTH];
    char address[MAX_LINE_LENGTH];
    char education[MAX_LINE_LENGTH];
    char experience[MAX_LINE_LENGTH];
} Resume;

// Function to tokenize a line of text
void tokenize(char* line, char** tokens, int max_tokens) {
    int i = 0;
    char* token = strtok(line, " ");
    while (token!= NULL && i < max_tokens) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
}

// Function to parse a resume line by line
Resume* parse_resume(FILE* fp) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    memset(resume, 0, sizeof(Resume));

    char line[MAX_LINE_LENGTH];
    char* tokens[MAX_TOKENS];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            tokenize(line, tokens, MAX_TOKENS);
            strcpy(resume->name, tokens[1]);
        } else if (strncmp(line, "Email:", 6) == 0) {
            tokenize(line, tokens, MAX_TOKENS);
            strcpy(resume->email, tokens[1]);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            tokenize(line, tokens, MAX_TOKENS);
            strcpy(resume->phone, tokens[1]);
        } else if (strncmp(line, "Address:", 8) == 0) {
            tokenize(line, tokens, MAX_TOKENS);
            strcpy(resume->address, tokens[1]);
        } else if (strncmp(line, "Education:", 9) == 0) {
            tokenize(line, tokens, MAX_TOKENS);
            strcpy(resume->education, tokens[1]);
        } else if (strncmp(line, "Experience:", 9) == 0) {
            tokenize(line, tokens, MAX_TOKENS);
            strcpy(resume->experience, tokens[1]);
        }
    }

    return resume;
}

// Function to print resume data
void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Main function to read and parse a resume file
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    Resume* resume = parse_resume(fp);
    if (resume == NULL) {
        printf("Invalid resume format\n");
        return 1;
    }

    print_resume(resume);

    free(resume);
    fclose(fp);

    return 0;
}