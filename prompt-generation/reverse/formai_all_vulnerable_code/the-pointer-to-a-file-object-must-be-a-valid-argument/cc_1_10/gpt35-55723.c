//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define struct for storing resume information
struct Resume {
    char name[100];
    char email[100];
    char phone[15];
    char education[100];
    char experience[500];
};

//function prototype
void parseResume(char* filename);

int main() {
    char* filename = "resume.txt";
    parseResume(filename);
    return 0;
}

void parseResume(char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[100];
    struct Resume resume;
    while (fgets(line, sizeof(line), fp) != NULL) {
        //retrieve name
        if (strstr(line, "Name:")) {
            char* token = strtok(line, ":");
            strcpy(resume.name, strtok(NULL, "\n"));
        }
        //retrieve email
        if (strstr(line, "Email:")) {
            char* token = strtok(line, ":");
            strcpy(resume.email, strtok(NULL, "\n"));
        }
        //retrieve phone number
        if (strstr(line, "Phone:")) {
            char* token = strtok(line, ":");
            strcpy(resume.phone, strtok(NULL, "\n"));
        }
        //retrieve education
        if (strstr(line, "Education:")) {
            char* token = strtok(line, ":");
            strcpy(resume.education, strtok(NULL, "\n"));
        }
        //retrieve experience
        if (strstr(line, "Experience:")) {
            char* token = strtok(line, ":");
            strcpy(resume.experience, strtok(NULL, "\n"));
        }
    }
    //close file
    fclose(fp);
    //print retrieved resume information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}