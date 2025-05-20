//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

int parse_resume(FILE *fp, resume *r) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name:")) {
            r->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            r->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            r->phone = strdup(line + 7);
        } else if (strstr(line, "Address:")) {
            r->address = strdup(line + 9);
        } else if (strstr(line, "Skills:")) {
            r->skills = strdup(line + 8);
        } else if (strstr(line, "Experience:")) {
            r->experience = strdup(line + 12);
        } else if (strstr(line, "Education:")) {
            r->education = strdup(line + 11);
        }
    }

    free(line);
    return 0;
}

void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    resume r;
    if (parse_resume(fp, &r) != 0) {
        fprintf(stderr, "parse_resume failed\n");
        return 1;
    }

    print_resume(&r);

    fclose(fp);
    return 0;
}