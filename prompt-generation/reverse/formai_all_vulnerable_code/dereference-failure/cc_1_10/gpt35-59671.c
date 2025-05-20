//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 10000

/* Struct definition for a resume */
typedef struct {
    char name[50];
    char email[50];
    char phone_number[20];
    char degree[50];
    char institution[50];
    char skills[100];
} Resume;

/* Function to parse a resume and extract relevant information */
void parseResume(char *resumeText, Resume *resume) {
    /* Extract name */
    char *nameStart = strstr(resumeText, "Name:");
    char *nameEnd = strstr(nameStart, "\n");
    strncpy(resume->name, nameStart + 6, nameEnd - nameStart - 6);
    resume->name[nameEnd - nameStart - 6] = '\0';
    
    /* Extract email */
    char *emailStart = strstr(resumeText, "Email:");
    char *emailEnd = strstr(emailStart, "\n");
    strncpy(resume->email, emailStart + 7, emailEnd - emailStart - 7);
    resume->email[emailEnd - emailStart - 7] = '\0';
    
    /* Extract phone number */
    char *phoneStart = strstr(resumeText, "Phone:");
    char *phoneEnd = strstr(phoneStart, "\n");
    strncpy(resume->phone_number, phoneStart + 7, phoneEnd - phoneStart - 7);
    resume->phone_number[phoneEnd - phoneStart - 7] = '\0';
    
    /* Extract degree */
    char *degreeStart = strstr(resumeText, "Degree:");
    char *degreeEnd = strstr(degreeStart, "\n");
    strncpy(resume->degree, degreeStart + 8, degreeEnd - degreeStart - 8);
    resume->degree[degreeEnd - degreeStart - 8] = '\0';
    
    /* Extract institution */
    char *instStart = strstr(resumeText, "Institution:");
    char *instEnd = strstr(instStart, "\n");
    strncpy(resume->institution, instStart + 12, instEnd - instStart - 12);
    resume->institution[instEnd - instStart - 12] = '\0';
    
    /* Extract skills */
    char *skillsStart = strstr(resumeText, "Skills:");
    char *skillsEnd = strstr(skillsStart, "\n");
    strncpy(resume->skills, skillsStart + 7, skillsEnd - skillsStart - 7);
    resume->skills[skillsEnd - skillsStart - 7] = '\0';
}

int main() {
    char resumeText[MAX_RESUME_LENGTH];
    Resume resume;
    
    /* Prompt user to enter resume text */
    printf("Enter your resume text:\n");
    fgets(resumeText, MAX_RESUME_LENGTH, stdin);
    
    /* Parse the resume */
    parseResume(resumeText, &resume);
    
    /* Print out the parsed resume information */
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone number: %s\n", resume.phone_number);
    printf("Degree: %s\n", resume.degree);
    printf("Institution: %s\n", resume.institution);
    printf("Skills: %s\n", resume.skills);
    
    return 0;
}