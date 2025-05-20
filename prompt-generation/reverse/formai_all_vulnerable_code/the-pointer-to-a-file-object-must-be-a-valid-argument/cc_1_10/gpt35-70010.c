//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

struct resume {
    char name[MAX_BUFFER_SIZE];
    char email[MAX_BUFFER_SIZE];
    char phone[MAX_BUFFER_SIZE];
    char education[MAX_BUFFER_SIZE];
    char experience[MAX_BUFFER_SIZE];
    char skills[MAX_BUFFER_SIZE];
};

typedef struct resume Resume;

// Function to parse the resume and store it in the structure
void parse_resume(char* filename, Resume* resume) {
    FILE* fp;
    char buffer[MAX_BUFFER_SIZE];

    fp = fopen(filename, "r");

    while(fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        if(strstr(buffer, "Name: ")) {
            strcpy(resume->name, buffer + 6);
            resume->name[strcspn(resume->name, "\n\r")] = 0;
        }
        else if(strstr(buffer, "Email: ")) {
            strcpy(resume->email, buffer + 7);
            resume->email[strcspn(resume->email, "\n\r")] = 0;
        }
        else if(strstr(buffer, "Phone: ")) {
            strcpy(resume->phone, buffer + 7);
            resume->phone[strcspn(resume->phone, "\n\r")] = 0;
        }
        else if(strstr(buffer, "Education: ")) {
            strcpy(resume->education, buffer + 11);
            resume->education[strcspn(resume->education, "\n\r")] = 0;
        }
        else if(strstr(buffer, "Experience: ")) {
            strcpy(resume->experience, buffer + 12);
            resume->experience[strcspn(resume->experience, "\n\r")] = 0;
        }
        else if(strstr(buffer, "Skills: ")) {
            strcpy(resume->skills, buffer + 8);
            resume->skills[strcspn(resume->skills, "\n\r")] = 0;
        }
    }

    fclose(fp);
}

int main() {
    Resume resume;
    char filename[MAX_BUFFER_SIZE];

    printf("Enter the filename of the resume to be parsed: ");
    fgets(filename, MAX_BUFFER_SIZE, stdin);
    filename[strcspn(filename, "\n\r")] = 0;

    parse_resume(filename, &resume);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}