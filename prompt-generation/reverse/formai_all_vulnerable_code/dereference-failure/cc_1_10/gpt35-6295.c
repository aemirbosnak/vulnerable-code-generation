//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for resume sections
typedef struct {
    char *name;
    char *content;
} ResumeSection;

// Define struct for resume
typedef struct {
    ResumeSection *sections;
    int numSections;
} Resume;

// Define function for parsing resume
Resume parseResume(char *resumeText) {
    Resume resume;
    resume.numSections = 0;

    // Create section for header
    ResumeSection header;
    header.name = "Header";
    char *headerEnd = strstr(resumeText, "\n\n");
    if (headerEnd != NULL) {
        int headerLen = headerEnd - resumeText;
        header.content = malloc((headerLen + 1) * sizeof(char));
        strncpy(header.content, resumeText, headerLen);
        header.content[headerLen] = '\0';
        resume.numSections++;
    }
    else {
        header.content = ""; // if no header is found
    }

    // Create section for education
    ResumeSection education;
    education.name = "Education";
    char *educationStart = strstr(resumeText, "Education");
    if (educationStart != NULL) {
        char *educationEnd = strstr(educationStart, "\n\n");
        if (educationEnd != NULL) {
            int educationLen = educationEnd - educationStart;
            education.content = malloc((educationLen + 1) * sizeof(char));
            strncpy(education.content, educationStart, educationLen);
            education.content[educationLen] = '\0';
            resume.numSections++;
        }
        else {
            education.content = ""; // if no education section is found
        }
    }
    else {
        education.content = ""; // if no education section is found
    }

    // Create section for work experience
    ResumeSection workExperience;
    workExperience.name = "Work Experience";
    char *workStart = strstr(resumeText, "Work Experience");
    if (workStart != NULL) {
        char *workEnd = strstr(workStart, "\n\n");
        if (workEnd != NULL) {
            int workLen = workEnd - workStart;
            workExperience.content = malloc((workLen + 1) * sizeof(char));
            strncpy(workExperience.content, workStart, workLen);
            workExperience.content[workLen] = '\0';
            resume.numSections++;
        }
        else {
            workExperience.content = ""; // if no work experience section is found
        }
    }
    else {
        workExperience.content = ""; // if no work experience section is found
    }

    // Create section for skills
    ResumeSection skills;
    skills.name = "Skills";
    char *skillsStart = strstr(resumeText, "Skills");
    if (skillsStart != NULL) {
        char *skillsEnd = strstr(skillsStart, "\n\n");
        if (skillsEnd != NULL) {
            int skillsLen = skillsEnd - skillsStart;
            skills.content = malloc((skillsLen + 1) * sizeof(char));
            strncpy(skills.content, skillsStart, skillsLen);
            skills.content[skillsLen] = '\0';
            resume.numSections++;
        }
        else {
            skills.content = ""; // if no skills section is found
        }
    }
    else {
        skills.content = ""; // if no skills section is found
    }

    // Add sections to resume
    resume.sections = malloc(resume.numSections * sizeof(ResumeSection));
    int i = 0;
    if (strcmp(header.content, "") != 0) {
        resume.sections[i] = header;
        i++;
    }
    if (strcmp(education.content, "") != 0) {
        resume.sections[i] = education;
        i++;
    }
    if (strcmp(workExperience.content, "") != 0) {
        resume.sections[i] = workExperience;
        i++;
    }
    if (strcmp(skills.content, "") != 0) {
        resume.sections[i] = skills;
    }

    return resume;
}

int main() {
    char *resumeText = "John Doe\n123 Main St\nAnytown, USA\n555-555-5555\njohn.doe@email.com\n\n\
                        Education\nBachelor of Science in Computer Science\nAny University\nGraduated May 2020\n\n\
                        Work Experience\nSoftware Engineer\nSome Company\nMay 2020 - Present\n\
                        - Developed software that improved efficiency by 20%\n- Collaborated with team to implement new features\n\
                        Intern\nAnother Company\nMay 2019 - August 2019\n- Assisted in development of mobile application\n\
                        Skills\nProgramming Languages: C, C++, Java, Python\nFrameworks: React, Angular";

    Resume parsedResume = parseResume(resumeText);

    // Print sections of resume
    for (int i = 0; i < parsedResume.numSections; i++) {
        printf("%s:\n%s\n\n", parsedResume.sections[i].name, parsedResume.sections[i].content);
    }

    // Free allocated memory
    for (int i = 0; i < parsedResume.numSections; i++) {
        free(parsedResume.sections[i].content);
    }
    free(parsedResume.sections);

    return 0;
}