//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume information
struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[100];
    char education[50];
    char experience[100];
};

// Function to parse resume and return a Resume struct
struct Resume parseResume(char resumeContent[]) {
    struct Resume resume;

    // Extract name
    int i = 0;
    while (resumeContent[i] != '\n') {
        resume.name[i] = resumeContent[i];
        i++;
    }
    resume.name[i] = '\0';

    // Extract email
    i++;
    int j = 0;
    while (resumeContent[i] != '\n') {
        resume.email[j] = resumeContent[i];
        i++;
        j++;
    }
    resume.email[j] = '\0';

    // Extract phone
    i++;
    j = 0;
    while (resumeContent[i] != '\n') {
        resume.phone[j] = resumeContent[i];
        i++;
        j++;
    }
    resume.phone[j] = '\0';

    // Extract skills
    i++;
    j = 0;
    while (resumeContent[i] != '\n') {
        resume.skills[j] = resumeContent[i];
        i++;
        j++;
    }
    resume.skills[j] = '\0';

    // Extract education
    i++;
    j = 0;
    while (resumeContent[i] != '\n') {
        resume.education[j] = resumeContent[i];
        i++;
        j++;
    }
    resume.education[j] = '\0';

    // Extract experience
    i++;
    j = 0;
    while (resumeContent[i] != '\n') {
        resume.experience[j] = resumeContent[i];
        i++;
        j++;
    }
    resume.experience[j] = '\0';

    return resume;
}

int main() {
    char resumeContent[] = "John Doe\njohndoe@example.com\n123-456-7890\nC++, Java, Python\nBachelor's Degree in Computer Science\nSoftware Engineer at ABC Company";

    struct Resume resume = parseResume(resumeContent);

    // Print parsed information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}