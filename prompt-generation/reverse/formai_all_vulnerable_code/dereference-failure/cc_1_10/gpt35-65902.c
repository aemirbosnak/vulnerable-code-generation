//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// data structure for a resume
typedef struct {
    char *name;
    char *email;
    char *education;
    char *skills;
} Resume;

// function to parse a resume string and return a Resume struct
Resume parseResume(char *resumeStr) {
    Resume resume;
    
    // get the name
    char *nameStart = strstr(resumeStr, "Name:");
    char *nameEnd = strstr(nameStart, "\n");
    size_t nameLen = nameEnd - nameStart - 5;  // exclude "Name:" and "\n"
    resume.name = strndup(nameStart + 5, nameLen);
    
    // get the email
    char *emailStart = strstr(resumeStr, "Email:");
    char *emailEnd = strstr(emailStart, "\n");
    size_t emailLen = emailEnd - emailStart - 6;  // exclude "Email:" and "\n"
    resume.email = strndup(emailStart + 6, emailLen);
    
    // get the education
    char *eduStart = strstr(resumeStr, "Education:");
    char *eduEnd = strstr(eduStart, "\n\n");
    size_t eduLen = eduEnd - eduStart - 10;  // exclude "Education:" and "\n\n"
    resume.education = strndup(eduStart + 10, eduLen);
    
    // get the skills
    char *skillsStart = strstr(resumeStr, "Skills:");
    char *skillsEnd = strstr(skillsStart, "\n\n");
    size_t skillsLen = skillsEnd - skillsStart - 7;  // exclude "Skills:" and "\n\n"
    resume.skills = strndup(skillsStart + 7, skillsLen);
    
    return resume;
}

int main() {
    char *resumeStr = "Name: John Doe\nEmail: john.doe@example.com\n\nEducation: B.S. Computer Science, University of XYZ\n\nSkills: C++, Python, SQL";
    
    Resume resume = parseResume(resumeStr);
    printf("Name: %s\nEmail: %s\nEducation: %s\nSkills: %s\n", resume.name, resume.email, resume.education, resume.skills);
    
    free(resume.name);
    free(resume.email);
    free(resume.education);
    free(resume.skills);
    
    return 0;
}