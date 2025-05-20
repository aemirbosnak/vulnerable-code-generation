//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char skills[500];
    char education[100];
    char experience[1000];
} Resume;

// function to parse resume data and fill Resume struct
Resume ParseResumeData(char* data) {
    Resume resume;
    memset(&resume, 0, sizeof(resume));

    // parse name
    char* nameStart = strstr(data, "Name:");
    if(nameStart) {
        char* nameEnd = strstr(nameStart + 5, "\n");
        if(nameEnd) {
            strncpy(resume.name, nameStart + 5, nameEnd - (nameStart + 5));
        }
    }

    // parse email
    char* emailStart = strstr(data, "Email:");
    if(emailStart) {
        char* emailEnd = strstr(emailStart + 6, "\n");
        if(emailEnd) {
            strncpy(resume.email, emailStart + 6, emailEnd - (emailStart + 6));
        }
    }

    // parse phone
    char* phoneStart = strstr(data, "Phone:");
    if(phoneStart) {
        char* phoneEnd = strstr(phoneStart + 6, "\n");
        if(phoneEnd) {
            strncpy(resume.phone, phoneStart + 6, phoneEnd - (phoneStart + 6));
        }
    }

    // parse address
    char* addressStart = strstr(data, "Address:");
    if(addressStart) {
        char* addressEnd = strstr(addressStart + 8, "\n");
        if(addressEnd) {
            strncpy(resume.address, addressStart + 8, addressEnd - (addressStart + 8));
        }
    }

    // parse skills
    char* skillsStart = strstr(data, "Skills:");
    if(skillsStart) {
        char* skillsEnd = strstr(skillsStart + 7, "\n");
        if(skillsEnd) {
            strncpy(resume.skills, skillsStart + 7, skillsEnd - (skillsStart + 7));
        }
    }

    // parse education
    char* educationStart = strstr(data, "Education:");
    if(educationStart) {
        char* educationEnd = strstr(educationStart + 10, "\n");
        if(educationEnd) {
            strncpy(resume.education, educationStart + 10, educationEnd - (educationStart + 10));
        }
    }

    // parse experience
    char* experienceStart = strstr(data, "Experience:");
    if(experienceStart) {
        char* experienceEnd = strstr(experienceStart + 11, "\n");
        if(experienceEnd) {
            strncpy(resume.experience, experienceStart + 11, experienceEnd - (experienceStart + 11));
        }
    }

    return resume;
}

int main() {
    // read resume text file into memory
    FILE* file = fopen("resume.txt", "r");
    if(!file) {
        printf("Failed to read resume file\n");
        return -1;
    }
    char* data = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&data, &len, file)) != -1) {
        // remove newline characters from line
        char* cursorPos = strchr(data, '\n');
        if(cursorPos) {
            *cursorPos = '\0';
        }

        // parse resume data
        Resume resume = ParseResumeData(data);

        // process resume data however you like...
    }

    // cleanup
    free(data);
    fclose(file);

    return 0;
}