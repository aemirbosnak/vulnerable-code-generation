//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
};

struct resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    struct resume *resume = malloc(sizeof(struct resume));
    if (resume == NULL) {
        fclose(fp);
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "Address:", 8) == 0) {
            resume->address = strdup(line + 8);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            resume->experience = strdup(line + 11);
        } else if (strncmp(line, "Education:", 10) == 0) {
            resume->education = strdup(line + 10);
        }
    }

    free(line);
    fclose(fp);

    return resume;
}

void print_resume(struct resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        fprintf(stderr, "Error parsing resume\n");
        return EXIT_FAILURE;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return EXIT_SUCCESS;
}