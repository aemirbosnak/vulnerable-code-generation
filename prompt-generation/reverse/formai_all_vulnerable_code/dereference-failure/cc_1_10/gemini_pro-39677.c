//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
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
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct resume *resume = malloc(sizeof(struct resume));

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name:")) {
            resume->name = malloc(strlen(line) + 1);
            strcpy(resume->name, line + 6);
        } else if (strstr(line, "Email:")) {
            resume->email = malloc(strlen(line) + 1);
            strcpy(resume->email, line + 7);
        } else if (strstr(line, "Phone:")) {
            resume->phone = malloc(strlen(line) + 1);
            strcpy(resume->phone, line + 7);
        } else if (strstr(line, "Address:")) {
            resume->address = malloc(strlen(line) + 1);
            strcpy(resume->address, line + 9);
        } else if (strstr(line, "Skills:")) {
            resume->skills = malloc(strlen(line) + 1);
            strcpy(resume->skills, line + 7);
        } else if (strstr(line, "Experience:")) {
            resume->experience = malloc(strlen(line) + 1);
            strcpy(resume->experience, line + 11);
        } else if (strstr(line, "Education:")) {
            resume->education = malloc(strlen(line) + 1);
            strcpy(resume->education, line + 10);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

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
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
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