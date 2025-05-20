//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *name;
    char *email;
    char *phone;
    int years_experience;
} Resume;

Resume parse_resume(char *text) {
    Resume resume = {0};
    char *token;
    int i = 0;

    while ((token = strtok(text, " \n\t\r"))!= NULL) {
        if (i >= MAX_WORDS) {
            break;
        }
        if (strlen(token) >= MAX_WORD_LENGTH) {
            printf("Warning: truncating long word '%s'\n", token);
            token[MAX_WORD_LENGTH - 1] = '\0';
        }
        switch (i) {
            case 0:
                resume.name = strdup(token);
                break;
            case 1:
                resume.email = strdup(token);
                break;
            case 2:
                resume.phone = strdup(token);
                break;
            default:
                printf("Warning: ignoring extra word '%s'\n", token);
                break;
        }
        i++;
    }
    resume.years_experience = -1;
    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Years of experience: %d\n", resume.years_experience);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char *text = NULL;
    size_t size = 0;
    ssize_t read;

    while ((read = getline(&text, &size, fp))!= -1) {
        if (text[read - 1] == '\n') {
            text[read - 1] = '\0';
        }
        Resume resume = parse_resume(text);
        print_resume(resume);
        free(text);
        text = NULL;
        size = 0;
    }

    if (text!= NULL) {
        free(text);
    }

    fclose(fp);
    return 0;
}