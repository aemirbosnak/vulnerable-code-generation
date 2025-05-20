//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *education;
    char *experience;
};

struct resume *parse_resume(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char buffer[1024];
    struct resume *resume = malloc(sizeof(struct resume));

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strncmp(buffer, "Name: ", 6) == 0) {
            resume->name = strdup(buffer + 6);
        } else if (strncmp(buffer, "Email: ", 7) == 0) {
            resume->email = strdup(buffer + 7);
        } else if (strncmp(buffer, "Phone: ", 7) == 0) {
            resume->phone = strdup(buffer + 7);
        } else if (strncmp(buffer, "Skills: ", 8) == 0) {
            resume->skills = strdup(buffer + 8);
        } else if (strncmp(buffer, "Education: ", 11) == 0) {
            resume->education = strdup(buffer + 11);
        } else if (strncmp(buffer, "Experience: ", 12) == 0) {
            resume->experience = strdup(buffer + 12);
        }
    }

    fclose(file);

    return resume;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct resume *resume = parse_resume(argv[1]);

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return EXIT_SUCCESS;
}