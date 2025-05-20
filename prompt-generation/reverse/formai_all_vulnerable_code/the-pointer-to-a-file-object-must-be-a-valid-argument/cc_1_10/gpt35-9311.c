//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 1000

typedef struct {
    char name[50];
    char email[50];
    char skills[100];
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

void parse_resume_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[255];
    char *token;
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        Resume resume;
        token = strtok(line, ",");
        strcpy(resume.name, token);
        token = strtok(NULL, ",");
        strcpy(resume.email, token);
        token = strtok(NULL, "\n");
        strcpy(resume.skills, token);
        resumes[i] = resume;
        i++;
    }
    num_resumes = i;

    fclose(file);
}

void print_resume(Resume resume) {
    printf("Name: %s\nEmail: %s\nSkills: %s\n", resume.name, resume.email, resume.skills);
}

void search_resumes(char *term) {
    int i = 0;
    for (i = 0; i < num_resumes; i++) {
        if (strstr(resumes[i].skills, term)) {
            printf("Match found:\n");
            print_resume(resumes[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <resume_file> <search_term>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *search_term = argv[2];

    parse_resume_file(filename);
    search_resumes(search_term);

    return 0;
}