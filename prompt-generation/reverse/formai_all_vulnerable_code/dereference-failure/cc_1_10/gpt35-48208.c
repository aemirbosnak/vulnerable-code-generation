//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold resume information */
typedef struct {
    char *name;
    char *education;
    char *skills;
} Resume;

/* Define a function to parse the resume */
Resume parseResume(char *resumeText) {
    Resume resume;

    /* Parse the name */
    char *nameStart = strstr(resumeText, "Name");
    if (nameStart == NULL) {
        perror("Error: Name not found in resume.");
        exit(1);
    }
    char *nameEnd = strstr(nameStart, "\n");
    size_t nameLength = nameEnd-nameStart-4; /* 4 is the length of "Name" plus the space */
    resume.name = calloc(nameLength+1, sizeof(char));
    strncpy(resume.name, nameStart+5, nameLength);

    /* Parse the education */
    char *educationStart = strstr(resumeText, "Education");
    if (educationStart == NULL) {
        perror("Error: Education not found in resume.");
        exit(1);
    }
    char *educationEnd = strstr(educationStart, "\n\n");
    size_t educationLength = educationEnd-educationStart-10; /* 10 is the length of "Education" plus the two spaces */
    resume.education = calloc(educationLength+1, sizeof(char));
    strncpy(resume.education, educationStart+11, educationLength);

    /* Parse the skills */
    char *skillsStart = strstr(resumeText, "Skills");
    if (skillsStart == NULL) {
        perror("Error: Skills not found in resume.");
        exit(1);
    }
    char *skillsEnd = strstr(skillsStart, "\n\n");
    size_t skillsLength = skillsEnd-skillsStart-7; /* 7 is the length of "Skills" plus the two spaces */
    resume.skills = calloc(skillsLength+1, sizeof(char));
    strncpy(resume.skills, skillsStart+8, skillsLength);

    return resume;
}

int main() {
    /* Sample resume text */
    char *resumeText = "Name: John Doe\n"
                       "Education: B.S. Computer Science, University of California, Berkeley\n\n"
                       "Skills: C++, Java, Python, HTML, CSS, JavaScript\n\n";

    /* Parse the resume */
    Resume resume = parseResume(resumeText);

    /* Print the resume */
    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    /* Free the memory */
    free(resume.name);
    free(resume.education);
    free(resume.skills);

    return 0;
}