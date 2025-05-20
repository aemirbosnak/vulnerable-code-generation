//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *education;
    char *work_experience;
};

struct resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[1024];
    struct resume *resume = malloc(sizeof(struct resume));
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            resume->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            resume->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            resume->phone = strdup(line + 7);
        } else if (strstr(line, "Address:")) {
            resume->address = strdup(line + 9);
        } else if (strstr(line, "Skills:")) {
            resume->skills = strdup(line + 8);
        } else if (strstr(line, "Education:")) {
            resume->education = strdup(line + 11);
        } else if (strstr(line, "Work Experience:")) {
            resume->work_experience = strdup(line + 16);
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(struct resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_experience);
}

int main() {
    struct resume *resume = parse_resume("resume.txt");
    print_resume(resume);
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->education);
    free(resume->work_experience);
    free(resume);

    return 0;
}