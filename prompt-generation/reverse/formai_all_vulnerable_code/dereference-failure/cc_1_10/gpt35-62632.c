//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for holding resume data
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *education;
    char *work_experience;
} ResumeData;

// Function declaration for parsing resume
ResumeData* parseResume(char *resume);

int main() {
    char *resume = "John Smith\njohn.smith@email.com\n123-456-7890\nEducation: BS Computer Science, University of California, Los Angeles\nWork Experience: Software Engineer, Google Inc.";
    
    ResumeData *resumeData = parseResume(resume);
    
    printf("Name: %s\n", resumeData->name);
    printf("Email: %s\n", resumeData->email);
    printf("Phone: %s\n", resumeData->phone);
    printf("Education: %s\n", resumeData->education);
    printf("Work Experience: %s\n", resumeData->work_experience);
    
    free(resumeData);
    
    return 0;
}

ResumeData* parseResume(char *resume) {
    ResumeData *resumeData = (ResumeData*) malloc(sizeof(ResumeData));
    int charsRead = 0;
    
    resumeData->name = strtok(resume, "\n");
    charsRead += strlen(resumeData->name) + 1;
    
    resumeData->email = strtok(resume + charsRead, "\n");
    charsRead += strlen(resumeData->email) + 1;
    
    resumeData->phone = strtok(resume + charsRead, "\n");
    charsRead += strlen(resumeData->phone) + 1;
    
    // Look for the "Education:" substring and grab everything after it
    char *educationStart = strstr(resume + charsRead, "Education:");
    if (educationStart != NULL) {
        charsRead += (int)(educationStart - (resume + charsRead));
        resumeData->education = strtok(educationStart, "\n");
        charsRead += strlen(resumeData->education) + 1;
    } else {
        resumeData->education = "";
    }
    
    // Look for the "Work Experience:" substring and grab everything after it
    char *workExperienceStart = strstr(resume + charsRead, "Work Experience:");
    if (workExperienceStart != NULL) {
        charsRead += (int)(workExperienceStart - (resume + charsRead));
        resumeData->work_experience = strtok(workExperienceStart, "\n");
        charsRead += strlen(resumeData->work_experience) + 1;
    } else {
        resumeData->work_experience = "";
    }
    
    return resumeData;
}