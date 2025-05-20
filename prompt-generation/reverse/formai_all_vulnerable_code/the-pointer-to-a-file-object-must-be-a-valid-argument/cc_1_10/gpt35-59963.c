//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Resume {
   char name[50];
   char email[50];
   char phone[20];
   char education[100];
   char experience[500];
};

void parseResume(char* resumePath, struct Resume* resume) {
    FILE *fp = fopen(resumePath,"r"); // Opening the resume file in read mode
    char line[150];
    int count = 1;

    while(fgets(line, 150, fp)) { // Reading the file line by line
        if(count == 1) {
            strcpy(resume->name, line);
        }
        else if(count == 2) {
            strcpy(resume->email, line);
        }
        else if(count == 3) {
            strcpy(resume->phone, line);
        }
        else if(count == 4) {
            strcpy(resume->education, line);
        }
        else if(count == 5) {
            strcpy(resume->experience, line);
        }
        count++;
    }

    fclose(fp); // Closing the file
}

void displayResume(struct Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

int main() {
    struct Resume resume;
    char* resumePath = "sample.txt";
    parseResume(resumePath, &resume);
    displayResume(&resume);
    return 0;
}