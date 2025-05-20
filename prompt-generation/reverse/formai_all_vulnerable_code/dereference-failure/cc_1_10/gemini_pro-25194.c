//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *education;
    char *experience;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name:") != NULL) {
            resume->name = strdup(line + 5);
        } else if (strstr(line, "Email:") != NULL) {
            resume->email = strdup(line + 6);
        } else if (strstr(line, "Phone:") != NULL) {
            resume->phone = strdup(line + 6);
        } else if (strstr(line, "Skills:") != NULL) {
            resume->skills = strdup(line + 7);
        } else if (strstr(line, "Education:") != NULL) {
            resume->education = strdup(line + 10);
        } else if (strstr(line, "Experience:") != NULL) {
            resume->experience = strdup(line + 11);
        }
    }

    fclose(fp);
    free(line);

    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return EXIT_SUCCESS;
}