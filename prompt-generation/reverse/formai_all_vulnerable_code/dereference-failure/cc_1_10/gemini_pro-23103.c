//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
};

struct resume *parse_resume(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    struct resume *resume = malloc(sizeof(struct resume));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        if (strncmp(line, "name:", 5) == 0) {
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "email:", 6) == 0) {
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "phone:", 6) == 0) {
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "skills:", 7) == 0) {
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "experience:", 10) == 0) {
            resume->experience = strdup(line + 10);
        } else if (strncmp(line, "education:", 10) == 0) {
            resume->education = strdup(line + 10);
        }
    }

    free(line);
    fclose(file);

    return resume;
}

void print_resume(struct resume *resume) {
    printf("name: %s\n", resume->name);
    printf("email: %s\n", resume->email);
    printf("phone: %s\n", resume->phone);
    printf("skills: %s\n", resume->skills);
    printf("experience: %s\n", resume->experience);
    printf("education: %s\n", resume->education);
}

int main() {
    struct resume *resume = parse_resume("resume.txt");
    if (resume == NULL) {
        printf("Error parsing resume.\n");
        return 1;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return 0;
}