//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to store all the details 
struct resume {
    char name[50];
    char email[50];
    char address[100];
    char mobile[15];
    char education[150];
    char experience[200];
    char skills[200];
};

// A function to parse the resume
struct resume resume_parser(char file_name[]) {
    // Open the resume file
    FILE *file = fopen(file_name, "r");

    // A struct to store the resume details
    struct resume my_resume;

    // Variable to store the line being read
    char line[150];

    // Loop through the file
    while (fgets(line, sizeof(line), file)) {

        // Check if the line contains the name 
        if (strstr(line, "Name")) {
            sscanf(line, "%*s %50[^\n]", my_resume.name);
        }

        // Check if the line contains the email 
        if (strstr(line, "Email")) {
            sscanf(line, "%*s %50[^\n]", my_resume.email);
        }

        // Check if the line contains the address 
        if (strstr(line, "Address")) {
            sscanf(line, "%*s %100[^\n]", my_resume.address);
        }

        // Check if the line contains the mobile number 
        if (strstr(line, "Mobile")) {
            sscanf(line, "%*s %15[^\n]", my_resume.mobile);
        }

        // Check if the line contains the education 
        if (strstr(line, "Education")) {
            sscanf(line, "%*s %150[^\n]", my_resume.education);
        }

        // Check if the line contains the experience 
        if (strstr(line, "Experience")) {
            sscanf(line, "%*s %200[^\n]", my_resume.experience);
        }

        // Check if the line contains the skills 
        if (strstr(line, "Skills")) {
            sscanf(line, "%*s %200[^\n]", my_resume.skills);
        }
    }

    // Close the file
    fclose(file);

    // Return the struct with the details
    return my_resume;
}

int main() {
    // Parse the resume with the function created above
    struct resume my_resume = resume_parser("my_resume.txt");

    // Print the parsed details
    printf("Name: %s\nEmail: %s\nAddress: %s\nMobile: %s\nEducation: %s\nExperience: %s\nSkills: %s", my_resume.name, my_resume.email, my_resume.address, my_resume.mobile, my_resume.education, my_resume.experience, my_resume.skills);

    return 0;
}