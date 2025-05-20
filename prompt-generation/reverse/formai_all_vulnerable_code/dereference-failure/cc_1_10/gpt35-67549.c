//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_SKILLS 20
#define MAX_SKILL_LENGTH 30

enum JobTitle {SOFTWARE_ENGINEER, DATA_SCIENTIST, PRODUCT_MANAGER};

typedef struct Skill {
    char name[MAX_SKILL_LENGTH];
    struct Skill* next;
} Skill;

typedef struct Resume {
    char name[100];
    enum JobTitle title;
    Skill* skills[MAX_SKILLS];
} Resume;

void add_skill(Resume* resume, char* skill) {
    Skill* new_skill = malloc(sizeof(Skill));
    strncpy(new_skill->name, skill, MAX_SKILL_LENGTH);
    new_skill->next = NULL;

    int i = 0;
    while(resume->skills[i] != NULL) {
        i++;
    }

    resume->skills[i] = new_skill;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Job Title: %d\n", resume->title);

    int i = 0;
    while(resume->skills[i] != NULL) {
        printf("Skill %d: %s\n", i+1, resume->skills[i]->name);
        i++;
    }
}

bool contains_skill(Resume* resume, char* skill) {
    int i = 0;
    while(resume->skills[i] != NULL) {
        if (strncmp(resume->skills[i]->name, skill, MAX_SKILL_LENGTH) == 0) {
            return true;
        }
        i++;
    }

    return false;
}

int main() {
    Resume resumes[MAX_RESUMES];
    int num_resumes = 0;

    //Parsing resumes from PDF files
    //...

    //Add skills to resumes
    add_skill(&resumes[0], "Java");
    add_skill(&resumes[0], "Python");
    add_skill(&resumes[0], "C++");

    add_skill(&resumes[1], "Python");
    add_skill(&resumes[1], "Machine Learning");

    add_skill(&resumes[2], "Agile Methodology");
    add_skill(&resumes[2], "Product Management");

    //Print resumes that have a specific skill
    char skill_to_search[MAX_SKILL_LENGTH] = "Python";

    printf("Resumes with skill '%s':\n", skill_to_search);
    for (int i = 0; i < num_resumes; i++) {
        if (contains_skill(&resumes[i], skill_to_search)) {
            print_resume(&resumes[i]);
        }
    }

    return 0;
}