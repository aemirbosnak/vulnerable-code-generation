//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_KEYWORDS 10
#define MAX_STRING_LENGTH 1000

typedef struct {
    char *resume_text;
    int num_keywords;
    char *keywords[MAX_KEYWORDS];
} Resume;

Resume *resumes[MAX_RESUMES];
int num_resumes;

void read_keyword_input(char *input, Resume *resume) {
    int num_keywords = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        resume->keywords[num_keywords] = malloc(strlen(token) + 1);
        strcpy(resume->keywords[num_keywords], token);
        num_keywords++;
        token = strtok(NULL, " ");
    }
    resume->num_keywords = num_keywords;
}

void read_resume_input(char *input) {
    Resume *resume = malloc(sizeof(Resume));
    resume->resume_text = malloc(strlen(input) + 1);
    strcpy(resume->resume_text, input);
    char *keywords_input = strtok(NULL, "\n");
    read_keyword_input(keywords_input, resume);
    resumes[num_resumes] = resume;
    num_resumes++;
}

void parse_resume(Resume *resume) {
    char *token = strtok(resume->resume_text, " .");
    while (token != NULL) {
        for (int i = 0; i < resume->num_keywords; i++) {
            if (strcmp(token, resume->keywords[i]) == 0) {
                printf("Resume matches with keyword: %s\n", resume->keywords[i]);
            }
        }
        token = strtok(NULL, " .");
    }
}

int main() {
    printf("Enter each resume followed by keywords separated by a space, and press enter to submit. Enter a blank line to end input.\n");
    char input[MAX_STRING_LENGTH];
    fgets(input, MAX_STRING_LENGTH, stdin);
    while (strcmp(input, "\n") != 0) {
        read_resume_input(input);
        fgets(input, MAX_STRING_LENGTH, stdin);
    }
    for (int i = 0; i < num_resumes; i++) {
        parse_resume(resumes[i]);
    }
    return 0;
}