//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing resume information
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char skills[200];
};

// Function to parse the resume
struct Resume parseResume(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    struct Resume resume;

    // Open the file
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Oops, unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Wow, parsing resume...\n");

    // Read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name: ") != NULL) {
            strcpy(resume.name, line + 6);
        } else if (strstr(line, "E-mail: ") != NULL) {
            strcpy(resume.email, line + 8);
        } else if (strstr(line, "Phone: ") != NULL) {
            strcpy(resume.phone, line + 7);
        } else if (strstr(line, "Education: ") != NULL) {
            strcpy(resume.education, line + 11);
        } else if (strstr(line, "Skills: ") != NULL) {
            strcpy(resume.skills, line + 8);
        }
    }

    printf("Awesome, resume parsed successfully!\n");

    // Close the file
    fclose(fp);
    if (line)
        free(line);

    return resume;
}

int main() {
    struct Resume myResume;

    // Parse the resume and store the information
    myResume = parseResume("myresume.txt");

    // Print the information
    printf("Name: %s", myResume.name);
    printf("E-mail: %s", myResume.email);
    printf("Phone: %s", myResume.phone);
    printf("Education: %s", myResume.education);
    printf("Skills: %s", myResume.skills);

    return 0;
}