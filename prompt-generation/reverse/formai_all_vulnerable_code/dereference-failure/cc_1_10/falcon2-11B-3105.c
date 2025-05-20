//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char degree[100];
    char university[100];
    char major[100];
    char date_start[10];
    char date_end[10];
    char description[500];
} Resume;

Resume* readResume(FILE* file) {
    Resume* resume = malloc(sizeof(Resume));
    char buffer[1000];

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "Name:", 5) == 0) {
            fgets(resume->name, sizeof(resume->name), file);
        } else if (strncmp(buffer, "Education:", 8) == 0) {
            fgets(resume->degree, sizeof(resume->degree), file);
            fgets(resume->university, sizeof(resume->university), file);
            fgets(resume->major, sizeof(resume->major), file);
        } else if (strncmp(buffer, "Work Experience:", 14) == 0) {
            fgets(resume->date_start, sizeof(resume->date_start), file);
            fgets(resume->date_end, sizeof(resume->date_end), file);
            fgets(resume->description, sizeof(resume->description), file);
        }
    }

    return resume;
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Resume* resume = readResume(file);
    if (resume == NULL) {
        printf("Error parsing resume\n");
        return 1;
    }

    printf("Name: %s\n", resume->name);
    printf("Education: %s\n", resume->degree);
    printf("University: %s\n", resume->university);
    printf("Major: %s\n", resume->major);
    printf("Date Start: %s\n", resume->date_start);
    printf("Date End: %s\n", resume->date_end);
    printf("Description: %s\n", resume->description);

    free(resume);
    fclose(file);

    return 0;
}