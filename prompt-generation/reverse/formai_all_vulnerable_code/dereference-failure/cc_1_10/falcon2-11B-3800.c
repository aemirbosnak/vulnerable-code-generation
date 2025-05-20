//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Job {
    char* name;
    char* company;
    char* location;
    char* skills;
};

struct Person {
    char* name;
    int age;
    char* email;
};

struct Resume {
    struct Job job1;
    struct Job job2;
    struct Person person;
};

void parse_resume(struct Resume* resume, FILE* file) {
    char line[1000];
    char* token;
    int i;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " \t\n");
        if (!strcmp(token, "JOB1")) {
            resume->job1.name = strdup(strtok(NULL, " \t\n"));
            resume->job1.company = strdup(strtok(NULL, " \t\n"));
            resume->job1.location = strdup(strtok(NULL, " \t\n"));
            resume->job1.skills = strdup(strtok(NULL, " \t\n"));
        } else if (!strcmp(token, "JOB2")) {
            resume->job2.name = strdup(strtok(NULL, " \t\n"));
            resume->job2.company = strdup(strtok(NULL, " \t\n"));
            resume->job2.location = strdup(strtok(NULL, " \t\n"));
            resume->job2.skills = strdup(strtok(NULL, " \t\n"));
        } else if (!strcmp(token, "PERSON")) {
            resume->person.name = strdup(strtok(NULL, " \t\n"));
            resume->person.age = atoi(strtok(NULL, " \t\n"));
            resume->person.email = strdup(strtok(NULL, " \t\n"));
        }
    }
}

int main() {
    struct Resume* resume = (struct Resume*)malloc(sizeof(struct Resume));
    FILE* file = fopen("resume.txt", "r");

    parse_resume(resume, file);

    printf("Job 1: %s\n", resume->job1.name);
    printf("Company: %s\n", resume->job1.company);
    printf("Location: %s\n", resume->job1.location);
    printf("Skills: %s\n\n", resume->job1.skills);

    printf("Job 2: %s\n", resume->job2.name);
    printf("Company: %s\n", resume->job2.company);
    printf("Location: %s\n", resume->job2.location);
    printf("Skills: %s\n\n", resume->job2.skills);

    printf("Name: %s\n", resume->person.name);
    printf("Age: %d\n", resume->person.age);
    printf("Email: %s\n", resume->person.email);

    free(resume->job1.name);
    free(resume->job1.company);
    free(resume->job1.location);
    free(resume->job1.skills);
    free(resume->job2.name);
    free(resume->job2.company);
    free(resume->job2.location);
    free(resume->job2.skills);
    free(resume->person.name);
    free(resume->person.email);
    free(resume);

    return 0;
}