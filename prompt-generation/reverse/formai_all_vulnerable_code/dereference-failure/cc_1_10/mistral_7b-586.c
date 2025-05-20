//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    char education[100][10];
    int num_education;
} Resume;

void parse_line(char line[], Resume *resume) {
    char *token;

    token = strtok(line, ":");
    strcpy(resume->name, token);

    token = strtok(NULL, ":");
    strcpy(resume->phone, token);

    token = strtok(NULL, ":");
    strcpy(resume->email, token);

    if (strcmp(token, "Education") == 0) {
        resume->num_education++;
        strcpy(resume->education[resume->num_education - 1], "");

        token = strtok(NULL, ":");
        strcat(resume->education[resume->num_education - 1], token);

        token = strtok(NULL, ":");
        strcat(resume->education[resume->num_education - 1], " ");

        strcat(resume->education[resume->num_education - 1], token);

        token = strtok(NULL, ":");
        strcat(resume->education[resume->num_education - 1], " ");

        strcat(resume->education[resume->num_education - 1], token);

        token = strtok(NULL, "\n");
    }
}

int main() {
    FILE *file;
    char line[100];
    Resume resume;

    file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        parse_line(line, &resume);
        printf("\nName: %s\n", resume.name);
        printf("Phone: %s\n", resume.phone);
        printf("Email: %s\n", resume.email);
        printf("Education:\n");

        for (int i = 0; i < resume.num_education; i++) {
            printf("- %s\n", resume.education[i]);
        }

        memset(&resume, 0, sizeof(Resume));
    }

    fclose(file);

    return 0;
}