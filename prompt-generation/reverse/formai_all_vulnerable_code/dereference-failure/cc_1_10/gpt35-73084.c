//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RESUME_SIZE 5000
#define MAX_KEYWORDS 50

char* parse_keywords[MAX_KEYWORDS];
int keyword_count = 0;

/* Function to read the resume from a file */
char* read_resume(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    char* resume = (char*) malloc(sizeof(char) * MAX_RESUME_SIZE);
    int index = 0;
    char c = fgetc(fp);
    while(c != EOF && index < MAX_RESUME_SIZE) {
        resume[index++] = c;
        c = fgetc(fp);
    }
    resume[index] = '\0';
    fclose(fp);
    return resume;
}

/* Function to parse the keywords from a file */
void parse_keywords_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    char buffer[100];
    while(fgets(buffer, 100, fp) != NULL && keyword_count < MAX_KEYWORDS) {
        buffer[strcspn(buffer, "\n")] = '\0';
        parse_keywords[keyword_count] = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(parse_keywords[keyword_count++], buffer);
    }
    fclose(fp);
}

/* Function to check if a given keyword is present in the resume */
int is_keyword_present(char* resume, char* keyword) {
    if(resume == NULL || keyword == NULL) {
        return 0;
    }
    char* token;
    token = strtok(resume, " .,\n");
    while(token != NULL) {
        if(strcmp(token, keyword) == 0) {
            return 1;
        }
        token = strtok(NULL, " .,\n");
    }
    return 0;
}

int main() {
    /* Read the resume and parse the keywords from files */
    char* resume = read_resume("resume.txt");
    parse_keywords_file("keywords.txt");
    
    /* Check for the presence of keywords in the resume */
    int i;
    for(i = 0; i < keyword_count; i++) {
        if(is_keyword_present(resume, parse_keywords[i])) {
            printf("Found keyword: %s\n", parse_keywords[i]);
        }
    }
    
    /* Free the allocated memory */
    free(resume);
    for(i = 0; i < keyword_count; i++) {
        free(parse_keywords[i]);
    }
    
    return 0;
}