//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Define structure of a resume */
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char objective[200];
    char education[200];
    char experience[200];
    char skills[200];
};


/* Define function to parse a resume and return a Resume structure */
struct Resume parse_resume(char* filename) {
    struct Resume resume;
    char* line = NULL;
    size_t len = 0;

    FILE* fp = fopen(filename, "r"); // Open file
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (getline(&line, &len, fp) != -1) {
        // Parse name
        if (strstr(line, "Name: ")) {
            char* name = line + strlen("Name: ");
            strncpy(resume.name, name, strlen(name)-1);
            resume.name[strlen(name)-1] = '\0';

        // Parse email
        } else if (strstr(line, "Email: ")) {
            char* email = line + strlen("Email: ");
            strncpy(resume.email, email, strlen(email)-1);
            resume.email[strlen(email)-1] = '\0';

        // Parse phone
        } else if (strstr(line, "Phone: ")) {
            char* phone = line + strlen("Phone: ");
            strncpy(resume.phone, phone, strlen(phone)-1);
            resume.phone[strlen(phone)-1] = '\0';

        // Parse address
        } else if (strstr(line, "Address: ")) {
            char* address = line + strlen("Address: ");
            strncpy(resume.address, address, strlen(address)-1);
            resume.address[strlen(address)-1] = '\0';

        // Parse objective
        } else if (strstr(line, "Objective: ")) {
            char* objective = line + strlen("Objective: ");
            strncpy(resume.objective, objective, strlen(objective)-1);
            resume.objective[strlen(objective)-1] = '\0';

        // Parse education
        } else if (strstr(line, "Education: ")) {
            char* education = line + strlen("Education: ");
            strncpy(resume.education, education, strlen(education)-1);
            resume.education[strlen(education)-1] = '\0';

        // Parse experience
        } else if (strstr(line, "Experience: ")) {
            char* experience = line + strlen("Experience: ");
            strncpy(resume.experience, experience, strlen(experience)-1);
            resume.experience[strlen(experience)-1] = '\0';

        // Parse skills
        } else if (strstr(line, "Skills: ")) {
            char* skills = line + strlen("Skills: ");
            strncpy(resume.skills, skills, strlen(skills)-1);
            resume.skills[strlen(skills)-1] = '\0';
        }
    }

    fclose(fp); // Close file
    if (line) free(line); // Free getline buffer
    return resume;
}


/* Define function to print a Resume structure */
void print_resume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Objective: %s\n", resume.objective);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);
}


/* Define main function */
int main() {
    struct Resume resume = parse_resume("resume.txt");
    print_resume(resume);
    return 0;
}