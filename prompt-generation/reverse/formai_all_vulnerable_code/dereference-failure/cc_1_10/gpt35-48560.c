//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char skills[100];
    char experience[500];
};

void parseResume(char *resumeFile);

int main() {
    char file[] = "resume.txt";
    parseResume(file);

    return 0;
}

void parseResume(char *resumeFile) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct Resume r;

    fp = fopen(resumeFile, "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        exit(0);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name")) {
            strcpy(r.name, line + 5); // skip "Name:"
            r.name[strlen(r.name) - 1] = '\0'; // remove newline character
        }

        if (strstr(line, "Email")) {
            strcpy(r.email, line + 6); // skip "Email:"
            r.email[strlen(r.email) - 1] = '\0';
        }

        if (strstr(line, "Phone")) {
            strcpy(r.phone, line + 6); // skip "Phone:"
            r.phone[strlen(r.phone) - 1] = '\0';
        }

        if (strstr(line, "Education")) {
            strcpy(r.education, line + 10); // skip "Education:"
            r.education[strlen(r.education) - 1] = '\0';
        }

        if (strstr(line, "Skills")) {
            strcpy(r.skills, line + 7); // skip "Skills:"
            r.skills[strlen(r.skills) - 1] = '\0';
        }

        if (strstr(line, "Experience")) {
            strcpy(r.experience, line + 11); // skip "Experience:"
            r.experience[strlen(r.experience) - 1] = '\0';
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    // print out parsed resume
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
}