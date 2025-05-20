//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for a resume
typedef struct Resume {
    char name[50];
    int age;
    char email[50];
    char skills[100];
} Resume;

// define a function to parse resumes from input file
Resume* parseResumes(char* filename, int* count) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    // allocate memory for resumes based on number of lines in file
    int lines = 0;
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    Resume* resumes = malloc(sizeof(Resume) * lines);
    *count = lines;

    // parse each line in file and create resume struct
    rewind(fp);
    char line[150];
    int i = 0;
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ",");
        strcpy(resumes[i].name, token);

        token = strtok(NULL, ",");
        resumes[i].age = atoi(token);

        token = strtok(NULL, ",");
        strcpy(resumes[i].email, token);

        token = strtok(NULL, ",");
        strcpy(resumes[i].skills, token);

        i++;
    }

    fclose(fp);
    return resumes;
}

// main function to test resume parsing
int main() {
    int count;
    Resume* resumes = parseResumes("resumes.txt", &count);

    printf("Number of resumes: %d\n\n", count);

    for (int i = 0; i < count; i++) {
        printf("Resume #%d\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Age: %d\n", resumes[i].age);
        printf("Email: %s\n", resumes[i].email);
        printf("Skills: %s\n", resumes[i].skills);
        printf("\n");
    }

    free(resumes);
    return 0;
}