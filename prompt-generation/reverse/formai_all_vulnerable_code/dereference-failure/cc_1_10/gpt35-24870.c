//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *address;
    char *skills;
    char *experience;
} Resume;

static const char *RESUME_FILE = "resume.txt";

void print_resume(Resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
}

Resume *parse_resume(char *str) {
    Resume *r = (Resume *) malloc(sizeof(Resume));

    char *line;
    while ((line = strsep(&str, "\n"))) {
        char *val = strchr(line, ':');
        if (!val) continue;
        *val = '\0'; // replace ':' with null terminator
        val++; // move to start of value

        if (strcmp(line, "Name") == 0) {
            r->name = val;
        } else if (strcmp(line, "Email") == 0) {
            r->email = val;
        } else if (strcmp(line, "Address") == 0) {
            r->address = val;
        } else if (strcmp(line, "Skills") == 0) {
            r->skills = val;
        } else if (strcmp(line, "Experience") == 0) {
            r->experience = val;
        }
    }

    return r;
}

int main(void) {
    FILE *fp = fopen(RESUME_FILE, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", RESUME_FILE);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *str = (char *) malloc(sizeof(char));
    str[0] = '\0';

    while ((read = getline(&line, &len, fp)) != -1) {
        strcat(str, line);
    }

    Resume *r = parse_resume(str);
    print_resume(r);

    free(line);
    free(str);
    fclose(fp);
    return 0;
}