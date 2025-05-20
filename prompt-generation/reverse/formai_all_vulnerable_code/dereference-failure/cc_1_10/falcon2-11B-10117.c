//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
    char education[100];
    char skills[100];
    char experience[100];
} Resume;

Resume* parse_resume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Resume* resume = (Resume*)malloc(sizeof(Resume));
    if (resume == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* data = strtok(line, "\n");
        while (data!= NULL) {
            if (strcmp(data, "Name:") == 0) {
                strcpy(resume->name, strtok(NULL, "\n"));
            } else if (strcmp(data, "Phone:") == 0) {
                strcpy(resume->phone, strtok(NULL, "\n"));
            } else if (strcmp(data, "Email:") == 0) {
                strcpy(resume->email, strtok(NULL, "\n"));
            } else if (strcmp(data, "Address:") == 0) {
                strcpy(resume->address, strtok(NULL, "\n"));
            } else if (strcmp(data, "Education:") == 0) {
                strcpy(resume->education, strtok(NULL, "\n"));
            } else if (strcmp(data, "Skills:") == 0) {
                strcpy(resume->skills, strtok(NULL, "\n"));
            } else if (strcmp(data, "Experience:") == 0) {
                strcpy(resume->experience, strtok(NULL, "\n"));
            } else {
                printf("Invalid data: %s\n", data);
            }
            data = strtok(NULL, "\n");
        }
    }
    fclose(file);

    return resume;
}

int main() {
    Resume* resume = parse_resume("resume.txt");
    if (resume == NULL) {
        printf("Error parsing resume\n");
        return 1;
    }

    printf("Name: %s\n", resume->name);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);

    free(resume);
    return 0;
}