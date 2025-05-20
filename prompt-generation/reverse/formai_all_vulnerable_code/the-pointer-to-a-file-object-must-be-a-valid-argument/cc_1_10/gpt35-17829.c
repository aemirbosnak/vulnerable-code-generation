//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

typedef struct Resume {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char address[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Resume;

void parseResume(const char* filename, Resume* resume) {
    FILE* file = fopen(filename, "r");
    char line[MAX_LENGTH];
    int section = 0;
    while (fgets(line, MAX_LENGTH, file)) {
        if (strstr(line, "Name:")) {
            strcpy(resume->name, line + strlen("Name:"));
            section = 1;
        } else if (strstr(line, "Email:")) {
            strcpy(resume->email, line + strlen("Email:"));
            section = 2;
        } else if (strstr(line, "Phone:")) {
            strcpy(resume->phone, line + strlen("Phone:"));
            section = 3;
        } else if (strstr(line, "Address:")) {
            strcpy(resume->address, line + strlen("Address:"));
            section = 4;
        } else if (strstr(line, "Education:")) {
            strcpy(resume->education, line + strlen("Education:"));
            section = 5;
        } else if (strstr(line, "Experience:")) {
            strcpy(resume->experience, line + strlen("Experience:"));
            section = 6;
        } else if (section > 0) {
            if (section == 5 || section == 6) {
                strcat(section == 5 ? resume->education : resume->experience, line);
            } else {
                break;
            }
        }
    }
    fclose(file);
}

int main(int argc, char** argv) {
    Resume resume;
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s [RESUME_FILE]\n", argv[0]);
        return 1;
    }
    parseResume(argv[1], &resume);
    printf("Name: %sEmail: %sPhone: %sAddress: %sEducation: %sExperience: %s",
           resume.name, resume.email, resume.phone, resume.address,
           resume.education, resume.experience);
    return 0;
}