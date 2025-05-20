//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 100

typedef struct {
    char name[100];
    char email[100];
    char phone[100];
    char address[100];
    char summary[100];
    char experience[100];
    char education[100];
    char skills[100];
} Resume;

void parse_resume(FILE *fp, Resume *resume) {
    char line[MAX_LINE_LEN];
    char *token;
    int line_num = 0;

    while (fgets(line, MAX_LINE_LEN, fp)) {
        line_num++;
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "Name:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->name, token);
            }
        } else if (strcmp(token, "Email:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->email, token);
            }
        } else if (strcmp(token, "Phone:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->phone, token);
            }
        } else if (strcmp(token, "Address:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->address, token);
            }
        } else if (strcmp(token, "Summary:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->summary, token);
            }
        } else if (strcmp(token, "Experience:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->experience, token);
            }
        } else if (strcmp(token, "Education:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->education, token);
            }
        } else if (strcmp(token, "Skills:") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(resume->skills, token);
            }
        }
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    Resume resume;
    parse_resume(fp, &resume);
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Summary: %s\n", resume.summary);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);
    return 0;
}