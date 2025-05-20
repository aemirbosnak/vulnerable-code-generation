//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char skills[200];
    char work_experience[1000];
};

void print_resume_details(struct resume res) {
    printf("Name: %s\n", res.name);
    printf("Email: %s\n", res.email);
    printf("Phone: %s\n", res.phone);
    printf("Address: %s\n", res.address);
    printf("Skills: %s\n", res.skills);
    printf("Work Experience: %s\n", res.work_experience);
}

void parse_resume(char *file_name) {
    FILE *fp;
    char *line_buffer = NULL;
    size_t line_buffer_size = 0;
    ssize_t line_size;
    struct resume res;
    memset(&res, 0, sizeof(res));

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    while ((line_size = getline(&line_buffer, &line_buffer_size, fp)) != -1) {
        if (strstr(line_buffer, "Name: ") != NULL) {
            strcpy(res.name, line_buffer + 6);
        } else if (strstr(line_buffer, "Email: ") != NULL) {
            strcpy(res.email, line_buffer + 7);
        } else if (strstr(line_buffer, "Phone: ") != NULL) {
            strcpy(res.phone, line_buffer + 7);
        } else if (strstr(line_buffer, "Address: ") != NULL) {
            strcpy(res.address, line_buffer + 9);
        } else if (strstr(line_buffer, "Skills: ") != NULL) {
            strcpy(res.skills, line_buffer + 8);
        } else if (strstr(line_buffer, "Work Experience: ") != NULL) {
            char *eow = strstr(line_buffer, "Work Experience: ") + 18;
            char *newline = strstr(eow, "\n");
            strncpy(res.work_experience, eow, newline - eow);
        }
    }

    print_resume_details(res);

    fclose(fp);
}

int main() {
    parse_resume("sample_resume.txt");
    return 0;
}