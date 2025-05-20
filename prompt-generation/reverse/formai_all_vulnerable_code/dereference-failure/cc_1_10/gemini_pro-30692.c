//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[1024];
    resume *res = malloc(sizeof(resume));
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "Name:")) {
            res->name = strdup(strchr(buffer, ':') + 1);
        } else if (strstr(buffer, "Email:")) {
            res->email = strdup(strchr(buffer, ':') + 1);
        } else if (strstr(buffer, "Phone:")) {
            res->phone = strdup(strchr(buffer, ':') + 1);
        } else if (strstr(buffer, "Skills:")) {
            res->skills = strdup(strchr(buffer, ':') + 1);
        } else if (strstr(buffer, "Experience:")) {
            res->experience = strdup(strchr(buffer, ':') + 1);
        } else if (strstr(buffer, "Education:")) {
            res->education = strdup(strchr(buffer, ':') + 1);
        }
    }

    fclose(fp);
    return res;
}

void print_resume(resume *res) {
    printf("Name: %s", res->name);
    printf("Email: %s", res->email);
    printf("Phone: %s", res->phone);
    printf("Skills: %s", res->skills);
    printf("Experience: %s", res->experience);
    printf("Education: %s", res->education);
}

int main() {
    resume *res = parse_resume("resume.txt");
    print_resume(res);
    free(res);
    return 0;
}