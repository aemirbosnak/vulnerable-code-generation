//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
    char objective[500];
    char education[500];
    char experience[1000];
};

int main() {
    char resume[5000];
    struct candidate candidate_info;
    
    printf("Please enter the candidate's resume:\n");
    fgets(resume, 5000, stdin);
    
    // Parse name from resume
    char *name_start = strstr(resume, "Name:");
    char *name_end = strstr(name_start, "\n");
    strncpy(candidate_info.name, name_start + 5, name_end - name_start - 5);
    candidate_info.name[name_end - name_start - 5] = '\0';
    
    // Parse email from resume
    char *email_start = strstr(resume, "Email:");
    char *email_end = strstr(email_start, "\n");
    strncpy(candidate_info.email, email_start + 6, email_end - email_start - 6);
    candidate_info.email[email_end - email_start - 6] = '\0';
    
    // Parse phone from resume
    char *phone_start = strstr(resume, "Phone:");
    char *phone_end = strstr(phone_start, "\n");
    strncpy(candidate_info.phone, phone_start + 6, phone_end - phone_start - 6);
    candidate_info.phone[phone_end - phone_start - 6] = '\0';
    
    // Parse address from resume
    char *address_start = strstr(resume, "Address:");
    char *address_end = strstr(address_start, "\n");
    strncpy(candidate_info.address, address_start + 8, address_end - address_start - 8);
    candidate_info.address[address_end - address_start - 8] = '\0';
    
    // Parse objective from resume
    char *objective_start = strstr(resume, "Objective:");
    char *objective_end = strstr(objective_start, "\n");
    strncpy(candidate_info.objective, objective_start + 10, objective_end - objective_start - 10);
    candidate_info.objective[objective_end - objective_start - 10] = '\0';
    
    // Parse education from resume
    char *education_start = strstr(resume, "Education:");
    char *education_end = strstr(education_start, "Experience:");
    strncpy(candidate_info.education, education_start + 10, education_end - education_start - 10);
    candidate_info.education[education_end - education_start - 10] = '\0';
    
    // Parse experience from resume
    char *experience_start = education_end;
    char *experience_end = strstr(resume, "\nReferences:");
    strncpy(candidate_info.experience, experience_start + 11, experience_end - experience_start - 11);
    candidate_info.experience[experience_end - experience_start - 11] = '\0';
    
    // Print parsed information
    printf("Name: %s\n", candidate_info.name);
    printf("Email: %s\n", candidate_info.email);
    printf("Phone: %s\n", candidate_info.phone);
    printf("Address: %s\n", candidate_info.address);
    printf("Objective: %s\n", candidate_info.objective);
    printf("Education: %s\n", candidate_info.education);
    printf("Experience: %s\n", candidate_info.experience);
    
    return 0;
}