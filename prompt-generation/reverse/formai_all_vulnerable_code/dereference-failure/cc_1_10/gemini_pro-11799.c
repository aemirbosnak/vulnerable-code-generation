//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
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

void parse_resume(char *filename, struct resume *r) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, f)) != -1) {
        if (strstr(line, "Name:")) {
            r->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            r->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            r->phone = strdup(line + 7);
        } else if (strstr(line, "Skills:")) {
            r->skills = strdup(line + 8);
        } else if (strstr(line, "Experience:")) {
            r->experience = strdup(line + 12);
        } else if (strstr(line, "Education:")) {
            r->education = strdup(line + 11);
        }
    }

    fclose(f);
}

void print_resume(struct resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct resume r;
    parse_resume(argv[1], &r);
    print_resume(&r);

    return EXIT_SUCCESS;
}