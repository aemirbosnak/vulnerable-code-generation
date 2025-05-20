//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define maximum size to store resume content
#define MAX_RESUME_SIZE 100000

// Define structure for resume information
typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* skills[MAX_RESUME_SIZE];
    int num_skills;
    char* experience[MAX_RESUME_SIZE];
    int num_experiences;
    char* education[MAX_RESUME_SIZE];
    int num_education;
} ResumeInfo;

// Define function to parse resume content and store information in respective fields
void parse_resume_content(char* content, ResumeInfo* info) {
    char* token;

    // Get name
    if ((token = strstr(content, "Name:")) != NULL) {
        info->name = strtok(token + strlen("Name:"), "\n");
    }

    // Get email
    if ((token = strstr(content, "Email:")) != NULL) {
        info->email = strtok(token + strlen("Email:"), "\n");
    }

    // Get phone number
    if ((token = strstr(content, "Phone:")) != NULL) {
        info->phone = strtok(token + strlen("Phone:"), "\n");
    }

    // Get address
    if ((token = strstr(content, "Address:")) != NULL) {
        info->address = strtok(token + strlen("Address:"), "\n");
    }

    // Get skills
    if ((token = strstr(content, "Skills:")) != NULL) {
        token += strlen("Skills:");
        while ((token = strtok(token, "\n")) != NULL && info->num_skills < MAX_RESUME_SIZE) {
            info->skills[info->num_skills++] = token;
            token = NULL;
        }
    }

    // Get experience
    if ((token = strstr(content, "Experience:")) != NULL) {
        token += strlen("Experience:");
        while ((token = strtok(token, "\n")) != NULL && info->num_experiences < MAX_RESUME_SIZE) {
            info->experience[info->num_experiences++] = token;
            token = NULL;
        }
    }

    // Get education
    if ((token = strstr(content, "Education:")) != NULL) {
        token += strlen("Education:");
        while ((token = strtok(token, "\n")) != NULL && info->num_education < MAX_RESUME_SIZE) {
            info->education[info->num_education++] = token;
            token = NULL;
        }
    }
}

// Main function
int main() {
    // Initialize variables
    char* content = (char*)malloc(MAX_RESUME_SIZE * sizeof(char));
    ResumeInfo info;
    info.num_skills = 0;
    info.num_experiences = 0;
    info.num_education = 0;

    // Sample resume content
    strcpy(content, "Name: John Doe\nEmail: john.doe@gmail.com\nPhone: 123-456-7890\nAddress: 123 Main St\nSkills:\n- C\n- Java\n- Python\nExperience:\n- Software Engineer at Google\n- Internship at Microsoft\nEducation:\n- Bachelor's Degree in Computer Science from UCLA\n");

    // Parse resume content and store information in resume info structure
    parse_resume_content(content, &info);

    // Print resume information
    printf("Name: %s\n", info.name);
    printf("Email: %s\n", info.email);
    printf("Phone: %s\n", info.phone);
    printf("Address: %s\n", info.address);
    printf("Skills:\n");
    for (int i = 0; i < info.num_skills; i++) {
        printf("- %s\n", info.skills[i]);
    }
    printf("Experience:\n");
    for (int i = 0; i < info.num_experiences; i++) {
        printf("- %s\n", info.experience[i]);
    }
    printf("Education:\n");
    for (int i = 0; i < info.num_education; i++) {
        printf("- %s\n", info.education[i]);
    }

    // Free dynamically allocated memory
    free(content);

    return 0;
}