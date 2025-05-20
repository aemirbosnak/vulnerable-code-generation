//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Resume {
    char name[100];
    char title[100];
    char email[100];
    char phone[20];
    char address[100];
    char skills[1000];
    char education[1000];
    char experience[1000];
};

bool parseResume(FILE *fp, struct Resume *resume) {
    char line[1000];
    char *token;
    int i = 0;
    
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " \t");
        
        if (token[0] == '\0') {
            continue;
        }
        
        switch (i) {
            case 0:
                strcpy(resume->name, token);
                break;
            case 1:
                strcpy(resume->title, token);
                break;
            case 2:
                strcpy(resume->email, token);
                break;
            case 3:
                strcpy(resume->phone, token);
                break;
            case 4:
                strcpy(resume->address, token);
                break;
            case 5:
                strcpy(resume->skills, token);
                break;
            case 6:
                strcpy(resume->education, token);
                break;
            case 7:
                strcpy(resume->experience, token);
                break;
            default:
                break;
        }
        
        i++;
    }
    
    return true;
}

int main() {
    FILE *fp;
    struct Resume resume;
    
    fp = fopen("resume.txt", "r");
    
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    
    parseResume(fp, &resume);
    
    printf("Name: %s\n", resume.name);
    printf("Title: %s\n", resume.title);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    
    fclose(fp);
    
    return 0;
}