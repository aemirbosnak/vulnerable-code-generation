//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[100];
    char email[100];
    char phone[15];
    char address[100];
    char education[100];
    char skills[100];
} Resume;

char* read_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    char *buffer = malloc(BUFFER_SIZE * sizeof(char));
    if (!buffer) {
        printf("Cannot allocate memory\n");
        fclose(file);
        exit(1);
    }

    size_t n = fread(buffer, sizeof(char), BUFFER_SIZE - 1, file);
    if (ferror(file)) {
        printf("Error reading file %s\n", filename);
        free(buffer);
        fclose(file);
        exit(1);
    }

    buffer[n] = '\0';
    fclose(file);

    return buffer;
}

Resume* parse_resume(const char* resume_string) {
    Resume *resume = malloc(sizeof(Resume));
    if (!resume) {
        printf("Cannot allocate memory\n");
        exit(1);
    }

    char *token, *rest = strdup(resume_string);
    int i = 0;
    while ((token = strtok_r(rest, "\n", &rest))) {
        if (i == 0) {
            strcpy(resume->name, token);
        } else if (i == 1) {
            strcpy(resume->email, token);
        } else if (i == 2) {
            strcpy(resume->phone, token);
        } else if (i == 3) {
            strcpy(resume->address, token);
        } else if (i == 4) {
            strcpy(resume->education, token);
        } else if (i == 5) {
            strcpy(resume->skills, token);
        }
        i++;
    }

    free(rest);
    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
}

int main() {
    char *resume_string = read_file("resume.txt");
    Resume *resume = parse_resume(resume_string);
    print_resume(resume);
    free(resume_string);
    free(resume);
    return 0;
}