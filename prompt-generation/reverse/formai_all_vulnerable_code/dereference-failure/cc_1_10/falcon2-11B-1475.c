//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char name[100];
    char address[200];
    char phone[20];
    char email[100];
    char skills[100];
    char position[100];
    char company[100];
} Resume;

Resume* parseResumeLine(char line[], Resume* resume) {
    int i;
    for (i = 0; i < 100; i++) {
        resume->name[i] = line[i];
    }
    for (i = 0; i < 200; i++) {
        resume->address[i] = line[i];
    }
    for (i = 0; i < 20; i++) {
        resume->phone[i] = line[i];
    }
    for (i = 0; i < 100; i++) {
        resume->email[i] = line[i];
    }
    for (i = 0; i < 100; i++) {
        resume->skills[i] = line[i];
    }
    for (i = 0; i < 100; i++) {
        resume->position[i] = line[i];
    }
    for (i = 0; i < 100; i++) {
        resume->company[i] = line[i];
    }
    return resume;
}

void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Address: %s\n", resume->address);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
    printf("Skills: %s\n", resume->skills);
    printf("Position: %s\n", resume->position);
    printf("Company: %s\n", resume->company);
}

int main() {
    Resume* resume = malloc(sizeof(Resume));
    char line[100];
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        Resume* temp = parseResumeLine(line, resume);
        if (temp!= NULL) {
            free(temp);
        }
    }
    printResume(resume);
    return 0;
}