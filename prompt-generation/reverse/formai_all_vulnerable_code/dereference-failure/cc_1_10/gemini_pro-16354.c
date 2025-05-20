//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
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
    struct resume *r = malloc(sizeof(struct resume));
    FILE *f = fopen(filename, "r");
    if (!f) {
        return NULL;
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
    return r;
}

void print_resume(struct resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct resume *r = parse_resume(argv[1]);
    if (!r) {
        printf("Error parsing resume\n");
        return 1;
    }

    print_resume(r);

    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);

    return 0;
}