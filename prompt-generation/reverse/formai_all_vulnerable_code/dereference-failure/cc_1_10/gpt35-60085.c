//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_RESUME_FIELDS 10

typedef struct {
    int id;
    char *name;
    char *email;
    char *phone;
    char *address;
    char *work_experience;
    char *skills;
} Resume;

int num_resumes = 0;
Resume* resumes[MAX_RESUME_FIELDS];

void parse_line(char *line, Resume *resume) {
    char *key = strtok(line, ":");
    char *value = strtok(NULL, "\n");
    if (strcmp(key, "ID") == 0) {
        resume->id = atoi(value);
    } else if (strcmp(key, "Name") == 0) {
        resume->name = strdup(value);
    } else if (strcmp(key, "Email") == 0) {
        resume->email = strdup(value);
    } else if (strcmp(key, "Phone") == 0) {
        resume->phone = strdup(value);
    } else if (strcmp(key, "Address") == 0) {
        resume->address = strdup(value);
    } else if (strcmp(key, "Work Experience") == 0) {
        resume->work_experience = strdup(value);
    } else if (strcmp(key, "Skills") == 0) {
        resume->skills = strdup(value);
    }
}

void load_resumes(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Cannot open file");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (line[0] == '#') {
            num_resumes++;
            resumes[num_resumes-1] = calloc(1, sizeof(Resume));
        } else {
            parse_line(line, resumes[num_resumes-1]);
        }
    }

    fclose(fp);
}

void print_resume(Resume *resume) {
    printf("ID: %d\n", resume->id);
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Work Experience: %s\n", resume->work_experience);
    printf("Skills: %s\n", resume->skills);
}

void print_resumes() {
    for (int i = 0; i < num_resumes; i++) {
        printf("\nResume %d:\n", i+1);
        print_resume(resumes[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./resumeparser <filename>\n");
        return 1;
    }

    load_resumes(argv[1]);
    print_resumes();

    for (int i = 0; i < num_resumes; i++) {
        free(resumes[i]->name);
        free(resumes[i]->email);
        free(resumes[i]->phone);
        free(resumes[i]->address);
        free(resumes[i]->work_experience);
        free(resumes[i]->skills);
        free(resumes[i]);
    }

    return 0;
}