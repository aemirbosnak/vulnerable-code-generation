//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse a resume line by line
void parseResume(FILE* file) {
    // Create a structure to hold resume data
    struct Resume {
        char name[50];
        char address[100];
        char phone[20];
        char email[50];
        char skills[100][50];
        int numSkills;
    };

    // Allocate memory for resume structure
    struct Resume* resume = (struct Resume*)malloc(sizeof(struct Resume));

    // Read each line of the resume file
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Remove whitespace and newline characters
        strncpy(resume->name, line, sizeof(resume->name));
        strncpy(resume->address, line + sizeof(resume->name), sizeof(resume->address));
        strncpy(resume->phone, line + sizeof(resume->name) + sizeof(resume->address), sizeof(resume->phone));
        strncpy(resume->email, line + sizeof(resume->name) + sizeof(resume->address) + sizeof(resume->phone), sizeof(resume->email));

        // Split the skills section into individual skills
        char* skill;
        char* nextSkill;
        char* currentSkill = strtok(line + sizeof(resume->name) + sizeof(resume->address) + sizeof(resume->phone) + sizeof(resume->email), ", \t\n");
        resume->numSkills = 0;
        while (currentSkill!= NULL) {
            strncpy(resume->skills[resume->numSkills], currentSkill, sizeof(resume->skills[resume->numSkills]));
            resume->numSkills++;
            nextSkill = strchr(currentSkill, ',');
            if (nextSkill!= NULL) {
                *nextSkill = '\0';
                skill = nextSkill + 1;
                while (*skill!= '\0') {
                    currentSkill = skill;
                    skill = strchr(skill, ',');
                    if (skill!= NULL) {
                        *skill = '\0';
                        resume->numSkills++;
                        strncpy(resume->skills[resume->numSkills], currentSkill, sizeof(resume->skills[resume->numSkills]));
                    }
                }
            }
            currentSkill = nextSkill;
        }
    }

    // Free allocated memory
    free(resume);
}

// Main function
int main() {
    // Open the resume file
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Parse the resume line by line
    parseResume(file);

    // Close the resume file
    fclose(file);

    return 0;
}