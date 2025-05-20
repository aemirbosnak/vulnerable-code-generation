//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fclose(fp);
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strstr(line, "Name:")) {
            resume->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            resume->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            resume->phone = strdup(line + 7);
        } else if (strstr(line, "Address:")) {
            resume->address = strdup(line + 9);
        } else if (strstr(line, "Skills:")) {
            resume->skills = strdup(line + 8);
        } else if (strstr(line, "Experience:")) {
            resume->experience = strdup(line + 12);
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        printf("Error parsing resume\n");
        return 1;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume);

    return 0;
}