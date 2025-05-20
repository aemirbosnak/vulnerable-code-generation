//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define struct for Resume details
struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[100];
    char experience[100];
};

int main() {

    struct resume applicant;

    // Get user input for resume details
    printf("Enter your Name: ");
    fgets(applicant.name, sizeof(applicant.name), stdin);
    printf("Enter your Email: ");
    fgets(applicant.email, sizeof(applicant.email), stdin);
    printf("Enter your Phone number: ");
    fgets(applicant.phone, sizeof(applicant.phone), stdin);
    printf("Enter your Skills: ");
    fgets(applicant.skills, sizeof(applicant.skills), stdin);
    printf("Enter your Experience: ");
    fgets(applicant.experience, sizeof(applicant.experience), stdin);

    // Create File pointer and open file to write
    FILE *fp;
    fp = fopen("ResumeDetails.txt", "w+");
    if(fp == NULL) {
        printf("Cannot open file");
        exit(1);
    }

    // Write resume details into file
    fprintf(fp, "Name: %sEmail: %sPhone: %sSkills: %sExperience: %s", 
            applicant.name, applicant.email, applicant.phone, applicant.skills, applicant.experience);

    // Close file pointer
    fclose(fp);

    // Open file to read the details
    fp = fopen("ResumeDetails.txt", "r");
    char buffer[500];

    // Read the details and parse the information
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {

        printf("Extracted Data:\n");
        printf("------------------\n");

        // Parse Name
        char *name = strstr(buffer, "Name: ");
        if(name != NULL) {
            printf("Name: %s", name+6);
        }

        // Parse Email
        char *email = strstr(buffer, "Email: ");
        if(email != NULL) {
            printf("Email: %s", email+7);
        }

        // Parse Phone
        char *phone = strstr(buffer, "Phone: ");
        if(phone != NULL) {
            printf("Phone: %s", phone+7);
        }

        // Parse Skills
        char *skills = strstr(buffer, "Skills: ");
        if(skills != NULL) {
            printf("Skills: %s", skills+8);
        }

        // Parse Experience
        char *exp = strstr(buffer, "Experience: ");
        if(exp != NULL) {
            printf("Experience: %s", exp+12);
        }

        printf("------------------\n");
    }

    // Close file pointer
    fclose(fp);

    return 0;
}