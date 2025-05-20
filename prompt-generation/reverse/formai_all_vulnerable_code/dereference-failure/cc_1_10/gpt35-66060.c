//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing information from resume
typedef struct {
    char* name;
    char* email;
    char* education;
    char* experience;
} ResumeInfo;

// Function for parsing resume and storing information in ResumeInfo struct
ResumeInfo* parse_resume(char* resume) {
    ResumeInfo* info = (ResumeInfo*) malloc(sizeof(ResumeInfo));
    
    char* name_start = strstr(resume, "Name:");
    if (name_start != NULL) {
        name_start += strlen("Name:");
        char* name_end = strstr(name_start, "\n");
        if (name_end != NULL) {
            *name_end = '\0';
            info->name = (char*) malloc(strlen(name_start) + 1);
            strcpy(info->name, name_start);
        }
    }
    
    char* email_start = strstr(resume, "Email:");
    if (email_start != NULL) {
        email_start += strlen("Email:");
        char* email_end = strstr(email_start, "\n");
        if (email_end != NULL) {
            *email_end = '\0';
            info->email = (char*) malloc(strlen(email_start) + 1);
            strcpy(info->email, email_start);
        }
    }
    
    char* edu_start = strstr(resume, "Education:");
    if (edu_start != NULL) {
        edu_start += strlen("Education:");
        char* edu_end = strstr(edu_start, "\n\n");
        if (edu_end != NULL) {
            *edu_end = '\0';
            info->education = (char*) malloc(strlen(edu_start) + 1);
            strcpy(info->education, edu_start);
        }
    }
    
    char* exp_start = strstr(resume, "Experience:");
    if (exp_start != NULL) {
        exp_start += strlen("Experience:");
        char* exp_end = strstr(exp_start, "\n\n");
        if (exp_end != NULL) {
            *exp_end = '\0';
            info->experience = (char*) malloc(strlen(exp_start) + 1);
            strcpy(info->experience, exp_start);
        }
    }
    
    return info;
}

int main() {
    char resume[] = "Name: John Doe\nEmail: john.doe@mail.com\nEducation: Bachelor's degree in Computer Science from XYZ University\nExperience: 3 years of experience as a software engineer at ABC Inc.";
    
    ResumeInfo* info = parse_resume(resume);
    
    printf("Name: %s\n", info->name);
    printf("Email: %s\n", info->email);
    printf("Education: %s\n", info->education);
    printf("Experience: %s\n", info->experience);
    
    free(info->name);
    free(info->email);
    free(info->education);
    free(info->experience);
    free(info);
    
    return 0;
}