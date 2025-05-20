//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to store resume information
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[100];
};

//function to read resume from file
struct Resume readResumeFromFile(char *fileName) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct Resume resume;
    int lineNum = 0;
    
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.");
        exit(EXIT_FAILURE);
    }
    
    while ((read = getline(&line, &len, file)) != -1) {
        lineNum++;
        switch(lineNum) {
            case 1:
                strcpy(resume.name, line);
                break;
            case 2:
                strcpy(resume.email, line);
                break;
            case 3:
                strcpy(resume.phone, line);
                break;
            case 4:
                strcpy(resume.education, line);
                break;
            case 5:
                strcpy(resume.experience, line);
                break;
            default:
                break;
        }
    }
    
    fclose(file);
    if (line)
        free(line);
    
    return resume;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./resume_parser resume.txt");
        exit(EXIT_FAILURE);
    }
    
    struct Resume resume = readResumeFromFile(argv[1]);
    
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);
    
    return 0;
}