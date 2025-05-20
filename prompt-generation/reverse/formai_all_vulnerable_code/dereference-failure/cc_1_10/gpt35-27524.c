//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    char email[50];
    int age;
    char education[100];
    char skills[200];
    char experience[300];
};

int main() {
    int num_of_candidates = 0;
    struct Candidate candidates[50];
    
    // Open the resume file
    FILE *fp = fopen("resumes.txt", "r");
    if(fp == NULL) {
        printf("Error: Cannot open resumes file!\n");
        return 1;
    }
    
    // Parse each candidate's resume
    char line[200];
    while(fgets(line, sizeof(line), fp) != NULL) {
        struct Candidate candidate;
        
        // Extract candidate's name
        char *name = strtok(line, ",");
        strcpy(candidate.name, name);
        
        // Extract candidate's email
        char *email = strtok(NULL, ",");
        strcpy(candidate.email, email);
        
        // Extract candidate's age
        char *age_str = strtok(NULL, ",");
        candidate.age = atoi(age_str);
        
        // Extract candidate's education
        char *education = strtok(NULL, ",");
        strcpy(candidate.education, education);
        
        // Extract candidate's skills
        char *skills = strtok(NULL, ",");
        strcpy(candidate.skills, skills);
        
        // Extract candidate's experience
        char *experience = strtok(NULL, "\n");
        strcpy(candidate.experience, experience);
        
        // Add candidate to the list
        candidates[num_of_candidates] = candidate;
        num_of_candidates++;
    }
    
    // Close the resume file
    fclose(fp);
    
    // Print all the candidate information
    for(int i = 0; i < num_of_candidates; i++) {
        struct Candidate candidate = candidates[i];
        printf("Candidate %d:\n", i+1);
        printf("\tName: %s\n", candidate.name);
        printf("\tEmail: %s\n", candidate.email);
        printf("\tAge: %d\n", candidate.age);
        printf("\tEducation: %s\n", candidate.education);
        printf("\tSkills: %s\n", candidate.skills);
        printf("\tExperience: %s\n", candidate.experience);
    }
    
    return 0;
}