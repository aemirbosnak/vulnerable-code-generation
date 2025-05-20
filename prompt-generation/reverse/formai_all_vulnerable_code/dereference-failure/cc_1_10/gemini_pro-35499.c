//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I am not sorry for this code.

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
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    struct resume *resume = malloc(sizeof(struct resume));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        if (strstr(line, "Name:") != NULL) {
            resume->name = strdup(line + 6);
        } else if (strstr(line, "Email:") != NULL) {
            resume->email = strdup(line + 7);
        } else if (strstr(line, "Phone:") != NULL) {
            resume->phone = strdup(line + 7);
        } else if (strstr(line, "Address:") != NULL) {
            resume->address = strdup(line + 9);
        } else if (strstr(line, "Skills:") != NULL) {
            resume->skills = strdup(line + 8);
        } else if (strstr(line, "Experience:") != NULL) {
            resume->experience = strdup(line + 12);
        } else if (strstr(line, "Education:") != NULL) {
            resume->education = strdup(line + 11);
        }
    }

    fclose(file);

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

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        fprintf(stderr, "Error: could not parse resume\n");
        return 1;
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

    return 0;
}