//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract the name from the resume
void extractName(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char name[100];
    fgets(name, sizeof(name), fp);
    fclose(fp);

    printf("Name: %s\n", name);
}

// Function to extract the education from the resume
void extractEducation(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char education[100];
    fgets(education, sizeof(education), fp);
    fclose(fp);

    printf("Education: %s\n", education);
}

// Function to extract the experience from the resume
void extractExperience(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char experience[100];
    fgets(experience, sizeof(experience), fp);
    fclose(fp);

    printf("Experience: %s\n", experience);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char filename[100];
    strcpy(filename, argv[1]);

    extractName(filename);
    extractEducation(filename);
    extractExperience(filename);

    return 0;
}