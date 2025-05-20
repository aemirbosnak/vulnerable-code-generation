//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputFile[] = "resume.txt";
    char outputFile[] = "parsed_resume.txt";

    FILE *inputFilePtr, *outputFilePtr;
    inputFilePtr = fopen(inputFile, "r");
    outputFilePtr = fopen(outputFile, "w");

    if (inputFilePtr == NULL || outputFilePtr == NULL) {
        fprintf(stderr, "Error opening files\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), inputFilePtr)!= NULL) {
        char *name;
        char *education;
        char *experience;
        char *skills;
        char *contact;

        name = strtok(line, " \t");
        education = strtok(NULL, " \t");
        experience = strtok(NULL, " \t");
        skills = strtok(NULL, " \t");
        contact = strtok(NULL, " \t");

        if (name!= NULL) {
            fprintf(outputFilePtr, "Name: %s\n", name);
        }
        if (education!= NULL) {
            fprintf(outputFilePtr, "Education: %s\n", education);
        }
        if (experience!= NULL) {
            fprintf(outputFilePtr, "Experience: %s\n", experience);
        }
        if (skills!= NULL) {
            fprintf(outputFilePtr, "Skills: %s\n", skills);
        }
        if (contact!= NULL) {
            fprintf(outputFilePtr, "Contact: %s\n", contact);
        }
    }

    fclose(inputFilePtr);
    fclose(outputFilePtr);

    printf("Resume parsed successfully\n");

    return 0;
}