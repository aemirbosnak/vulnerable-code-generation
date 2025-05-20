//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char* name;
    char* education;
    int experience;
    char* skills[3];
} Resume;

Resume* parse_resume(char* resume) {
    Resume* r = malloc(sizeof(Resume));
    char* token;
    int i = 0;

    token = strtok(resume, "\n");

    while (token != NULL) {
        if (i == 0) {
            r->name = malloc(strlen(token) + 1);
            strcpy(r->name, token);
        }
        else if (i == 1) {
            r->education = malloc(strlen(token) + 1);
            strcpy(r->education, token);
        }
        else if (i == 2) {
            r->experience = atoi(token);
        }
        else if (i == 3) {
            char* skill = malloc(strlen(token) + 1);
            strcpy(skill, token);
            r->skills[0] = skill;
        }
        else if (i == 4) {
            char* skill = malloc(strlen(token) + 1);
            strcpy(skill, token);
            r->skills[1] = skill;
        }
        else if (i == 5) {
            char* skill = malloc(strlen(token) + 1);
            strcpy(skill, token);
            r->skills[2] = skill;
        }
        else {
            printf("Invalid resume format.\n");
            free(r);
            return NULL;
        }

        token = strtok(NULL, "\n");
        i++;
    }

    if (i != 6) {
        printf("Invalid resume format.\n");
        free(r);
        return NULL;
    }

    return r;
}

int main() {
    char* resume_str = "John Smith\nB.S. in Computer Science\n3\nC++\nJava\nPython";

    Resume* r = parse_resume(resume_str);

    printf("Name: %s\n", r->name);
    printf("Education: %s\n", r->education);
    printf("Experience: %d years\n", r->experience);
    printf("Skills: %s, %s, %s\n", r->skills[0], r->skills[1], r->skills[2]);

    free(r->name);
    free(r->education);
    free(r->skills[0]);
    free(r->skills[1]);
    free(r->skills[2]);
    free(r);
}