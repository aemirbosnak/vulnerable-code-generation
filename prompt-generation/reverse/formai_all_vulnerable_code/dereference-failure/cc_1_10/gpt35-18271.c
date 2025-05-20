//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESUME_SIZE 10000
#define MAX_SKILLS 100

// Structures
typedef struct {
    char name[50];
    int experienceMonths;
    bool isCertified;
} Skill;

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char skills[MAX_SKILLS][50];
    int numSkills;
} Resume;

// Functions
void parseResume(char* resumeText, Resume* resume) {
    // Extract name
    char* nameStart = strstr(resumeText, "Name: ") + strlen("Name: ");
    char* nameEnd = strstr(nameStart, "\n");
    strncpy(resume->name, nameStart, nameEnd - nameStart);
    resume->name[nameEnd - nameStart] = '\0';

    // Extract email address
    char* emailStart = strstr(resumeText, "Email: ") + strlen("Email: ");
    char* emailEnd = strstr(emailStart, "\n");
    strncpy(resume->email, emailStart, emailEnd - emailStart);
    resume->email[emailEnd - emailStart] = '\0';

    // Extract phone number
    char* phoneStart = strstr(resumeText, "Phone: ") + strlen("Phone: ");
    char* phoneEnd = strstr(phoneStart, "\n");
    strncpy(resume->phone, phoneStart, phoneEnd - phoneStart);
    resume->phone[phoneEnd - phoneStart] = '\0';

    // Extract skills
    char* skillsStart = strstr(resumeText, "Skills: ") + strlen("Skills: ");
    char* skillStart = skillsStart;
    char* skillEnd = NULL;
    int numSkills = 0;

    while ((skillEnd = strstr(skillStart, ",")) != NULL || (skillEnd = strstr(skillStart, "\n")) != NULL) {
        strncpy(resume->skills[numSkills], skillStart, skillEnd - skillStart);
        resume->skills[numSkills][skillEnd - skillStart] = '\0';
        numSkills++;
        skillStart = skillEnd + 1;
    }

    resume->numSkills = numSkills;
}

void addSkill(Resume* resume, char* skillName, int experienceMonths, bool isCertified) {
    Skill skill;
    strncpy(skill.name, skillName, sizeof(skill.name));
    skill.name[sizeof(skill.name) - 1] = '\0';
    skill.experienceMonths = experienceMonths;
    skill.isCertified = isCertified;

    int i = resume->numSkills;
    while (i > 0 && strcmp(skillName, resume->skills[i - 1]) < 0) {
        strcpy(resume->skills[i], resume->skills[i - 1]);
        i--;
    }

    strcpy(resume->skills[i], skillName);
    resume->numSkills++;
}

void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);

    printf("Skills:\n");
    for (int i = 0; i < resume->numSkills; i++) {
        printf("\t%s\n", resume->skills[i]);
    }
}

int main() {
    char* resumeText = (char*) malloc(MAX_RESUME_SIZE * sizeof(char));
    strcpy(resumeText, "Name: John Smith\nEmail: john.smith@gmail.com\nPhone: (123) 456-7890\nSkills: C++, Java, Python\n");

    Resume resume;
    parseResume(resumeText, &resume);
    printResume(&resume);

    addSkill(&resume, "HTML", 12, true);
    addSkill(&resume, "CSS", 4, false);
    addSkill(&resume, "JavaScript", 8, false);

    printf("\nUpdated skills:\n");
    printResume(&resume);

    free(resumeText);

    return 0;
}