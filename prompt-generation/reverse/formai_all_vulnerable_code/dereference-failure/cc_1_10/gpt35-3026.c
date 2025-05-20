//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_RESUME_LEN 10000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_SKILLS_COUNT 10

/* Structure to hold parsed data of Resume */ 

struct Resume {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char skills[MAX_SKILLS_COUNT][MAX_NAME_LEN];
    int skills_count;
};

/* Function to parse Resume and return a struct */

struct Resume parseResume(char* resume_text) {
    struct Resume parsed_resume;
    parsed_resume.skills_count = 0;
    
    // Parsing name
    char* ptr_to_name_start = strstr(resume_text, "Name:");
    char* ptr_to_name_end = strstr(ptr_to_name_start, "\n");
    strncpy(parsed_resume.name, ptr_to_name_start + strlen("Name:"), ptr_to_name_end - ptr_to_name_start - strlen("Name:"));
    parsed_resume.name[ptr_to_name_end - ptr_to_name_start - strlen("Name:")] = '\0';
    
    // Parsing email
    char* ptr_to_email_start = strstr(resume_text, "Email:");
    char* ptr_to_email_end = strstr(ptr_to_email_start, "\n");
    strncpy(parsed_resume.email, ptr_to_email_start + strlen("Email:"), ptr_to_email_end - ptr_to_email_start - strlen("Email:"));
    parsed_resume.email[ptr_to_email_end - ptr_to_email_start - strlen("Email:")] = '\0';
    
    // Parsing skills
    char* ptr_to_skills_start = strstr(resume_text, "Skills:");
    char* ptr_to_skills_end = strstr(ptr_to_skills_start, "\n\n");
    char* ptr_to_skill_begin = ptr_to_skills_start + strlen("Skills:");
    char* ptr_to_skill_end = strstr(ptr_to_skill_begin, ",");
    while(ptr_to_skill_end != NULL && ptr_to_skill_end <= ptr_to_skills_end) {
        strncpy(parsed_resume.skills[parsed_resume.skills_count], ptr_to_skill_begin, ptr_to_skill_end - ptr_to_skill_begin);
        parsed_resume.skills[parsed_resume.skills_count][ptr_to_skill_end - ptr_to_skill_begin] = '\0';
        parsed_resume.skills_count++;
        ptr_to_skill_begin = ptr_to_skill_end + 1;
        ptr_to_skill_end = strstr(ptr_to_skill_begin, ",");
    }
    if(ptr_to_skill_begin <= ptr_to_skills_end) {
        strncpy(parsed_resume.skills[parsed_resume.skills_count], ptr_to_skill_begin, ptr_to_skills_end - ptr_to_skill_begin);
        parsed_resume.skills[parsed_resume.skills_count][ptr_to_skills_end - ptr_to_skill_begin] = '\0';
        parsed_resume.skills_count++;        
    }
    return parsed_resume;
}

/* Driver Code to test the Resume parsing  */

int main() {
    char resume_text[MAX_RESUME_LEN];
    printf("Enter the Resume text (Max len : %d): ", MAX_RESUME_LEN);
    fgets(resume_text, sizeof(resume_text), stdin);
    
    struct Resume parsed_resume = parseResume(resume_text);
    printf("Parsed Resume : \n");
    printf("Name : %s\n", parsed_resume.name);
    printf("Email : %s\n", parsed_resume.email);
    printf("Skills : ");
    for(int i=0; i<parsed_resume.skills_count; i++) {
        printf("%s ", parsed_resume.skills[i]);
    }
    printf("\n");
    return 0;
}