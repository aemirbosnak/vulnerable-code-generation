//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *linkedin;
    char *skills;
    char *education;
    char *experience;
} resume;

resume *parse_resume(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char line[1024];
    resume *res = malloc(sizeof(resume));

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:")) {
            res->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            res->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            res->phone = strdup(line + 7);
        } else if (strstr(line, "LinkedIn:")) {
            res->linkedin = strdup(line + 10);
        } else if (strstr(line, "Skills:")) {
            res->skills = strdup(line + 8);
        } else if (strstr(line, "Education:")) {
            res->education = strdup(line + 11);
        } else if (strstr(line, "Experience:")) {
            res->experience = strdup(line + 12);
        }
    }

    fclose(file);

    return res;
}

void print_resume(resume *res) {
    printf("Name: %s\n", res->name);
    printf("Email: %s\n", res->email);
    printf("Phone: %s\n", res->phone);
    printf("LinkedIn: %s\n", res->linkedin);
    printf("Skills: %s\n", res->skills);
    printf("Education: %s\n", res->education);
    printf("Experience: %s\n", res->experience);
}

int main() {
    resume *res = parse_resume("resume.txt");
    print_resume(res);

    free(res->name);
    free(res->email);
    free(res->phone);
    free(res->linkedin);
    free(res->skills);
    free(res->education);
    free(res->experience);
    free(res);

    return 0;
}