//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store details of an applicant
typedef struct applicant {
    char name[50];
    char email[50];
    char skills[100];
    char education[50];
    char experience[100];
    int years_of_experience;
} Applicant;

// Function to parse a resume and fill in the details of an applicant
void parseResume(char* resumeText, Applicant* applicant) {
    char* token;
    char* rest = resumeText;
    
    // Get name
    token = strtok_r(rest, "\n", &rest);
    strcpy(applicant->name, token);
    
    // Get email
    token = strtok_r(rest, "\n", &rest);
    strcpy(applicant->email, token);
    
    // Get skills
    token = strtok_r(rest, "\n", &rest);
    strcpy(applicant->skills, token);
    
    // Get education
    token = strtok_r(rest, "\n", &rest);
    strcpy(applicant->education, token);
    
    // Get experience
    token = strtok_r(rest, "\n", &rest);
    strcpy(applicant->experience, token);
    
    // Get years of experience
    sscanf(applicant->experience, "%d", &applicant->years_of_experience);
}

int main() {
    Applicant applicant;
    char resumeText[500] = "John Doe\njohndoe@email.com\nC++, Java\nMasters in Computer Science\n2 years of experience";
    
    parseResume(resumeText, &applicant);
    
    printf("Name: %s\nEmail: %s\nSkills: %s\nEducation: %s\nExperience: %s\nYears of experience: %d\n", 
           applicant.name, applicant.email, applicant.skills, applicant.education, applicant.experience, applicant.years_of_experience);
    
    return 0;
}