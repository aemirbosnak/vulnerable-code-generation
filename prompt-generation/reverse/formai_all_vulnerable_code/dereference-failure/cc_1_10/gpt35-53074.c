//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing the information parsed from resumes
typedef struct {
    char* name;
    char* email;
    char* phone_number;
    char** education;
    char** experience;
} Resume;

// Define a function for parsing resumes
Resume* parse_resume(char* resume_text) {
    // Allocate memory for the resume structure
    Resume* resume = malloc(sizeof(Resume));

    // Parse the name
    char* name_start = strstr(resume_text, "Name:");
    if (name_start == NULL) {
        printf("Error: Unable to parse name\n");
        return NULL;
    }
    name_start += strlen("Name:");
    char* name_end = strstr(name_start, "\n");
    resume->name = strndup(name_start, name_end - name_start);
    
    // Parse the email
    char* email_start = strstr(resume_text, "Email:");
    if (email_start == NULL) {
        printf("Error: Unable to parse email\n");
        return NULL;
    }
    email_start += strlen("Email:");
    char* email_end = strstr(email_start, "\n");
    resume->email = strndup(email_start, email_end - email_start);
    
    // Parse the phone number
    char* phone_start = strstr(resume_text, "Phone:");
    if (phone_start == NULL) {
        printf("Error: Unable to parse phone number\n");
        return NULL;
    }
    phone_start += strlen("Phone:");
    char* phone_end = strstr(phone_start, "\n");
    resume->phone_number = strndup(phone_start, phone_end - phone_start);

    // Parse the education
    char** education_start = NULL;
    char** education_end = NULL;
    char* education_header = strstr(resume_text, "Education:");
    if (education_header != NULL) {
        // Find the start and end of the education section
        education_header += strlen("Education:");
        education_start = &education_header;
        while (*education_start != NULL) {
            education_end = education_start + 1;
            if (strstr(*education_end, ":") != NULL) {
                break;
            }
        }
        // Parse the education section
        int education_count = education_end - education_start;
        resume->education = malloc((education_count + 1) * sizeof(char*));
        for (int i = 0; i < education_count; i++) {
            char* education_line = education_start[i];
            char* education_end = strstr(education_line, "\n");
            resume->education[i] = strndup(education_line, education_end - education_line);
        }
        resume->education[education_count] = NULL;
    } else {
        // No education section was found
        resume->education = NULL;
    }

    // Parse the experience
    char** experience_start = NULL;
    char** experience_end = NULL;
    char* experience_header = strstr(resume_text, "Experience:");
    if (experience_header != NULL) {
        // Find the start and end of the experience section
        experience_header += strlen("Experience:");
        experience_start = &experience_header;
        while (*experience_start != NULL) {
            experience_end = experience_start + 1;
            if (strstr(*experience_end, ":") != NULL) {
                break;
            }
        }
        // Parse the experience section
        int experience_count = experience_end - experience_start;
        resume->experience = malloc((experience_count + 1) * sizeof(char*));
        for (int i = 0; i < experience_count; i++) {
            char* experience_line = experience_start[i];
            char* experience_end = strstr(experience_line, "\n");
            resume->experience[i] = strndup(experience_line, experience_end - experience_line);
        }
        resume->experience[experience_count] = NULL;
    } else {
        // No experience section was found
        resume->experience = NULL;
    }
    
    return resume;
}

int main(void) {
    // Example usage of the resume parsing function
    char* resume_text = "Name: John Doe\nEmail: johndoe@example.com\nPhone: 555-555-5555\nEducation:\nB.S. in Computer Science, University of Example, 2010-2014\nExperience:\nSoftware Engineer, Example Company, 2014-2017\nSenior Software Engineer, Example Company, 2017-present\n";
    Resume* resume = parse_resume(resume_text);
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone Number: %s\n", resume->phone_number);
    printf("Education:\n");
    char** education = resume->education;
    while (*education != NULL) {
        printf("- %s\n", *education);
        education++;
    }
    printf("Experience:\n");
    char** experience = resume->experience;
    while (*experience != NULL) {
        printf("- %s\n", *experience);
        experience++;
    }
    return 0;
}