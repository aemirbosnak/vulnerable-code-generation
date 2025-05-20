//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

resume *parse_resume(char *filename) {
    resume *r = malloc(sizeof(resume));

    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, f)) != -1) {
        if (strstr(line, "Name:")) {
            r->name = strdup(strtok(line, ":"));
        } else if (strstr(line, "Email:")) {
            r->email = strdup(strtok(line, ":"));
        } else if (strstr(line, "Phone:")) {
            r->phone = strdup(strtok(line, ":"));
        } else if (strstr(line, "Address:")) {
            r->address = strdup(strtok(line, ":"));
        } else if (strstr(line, "Skills:")) {
            r->skills = strdup(strtok(line, ":"));
        } else if (strstr(line, "Experience:")) {
            r->experience = strdup(strtok(line, ":"));
        } else if (strstr(line, "Education:")) {
            r->education = strdup(strtok(line, ":"));
        }
    }

    fclose(f);
    free(line);

    return r;
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

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    resume *r = parse_resume(argv[1]);
    if (!r) {
        fprintf(stderr, "Error parsing resume\n");
        return 1;
    }

    print_resume(r);

    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->address);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);

    return 0;
}