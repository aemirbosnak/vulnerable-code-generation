//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
//The Case of the Missing Resumes
#include <stdio.h>
#include <string.h>

//define the structure for resume
struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
};

//function to parse the resume
void parseResume(char* filename, struct resume *res) {
    FILE *fptr;
    char str[200];
    char *token;

    //open the file
    fptr = fopen(filename, "r");

    //read the file line by line
    while (fgets(str, 200, fptr) != NULL) {
        //get name
        if (strstr(str, "Name:")) {
            token = strtok(str, ":");
            token = strtok(NULL, ":");
            strcpy(res->name, token);
        }
        //get email
        if (strstr(str, "Email:")) {
            token = strtok(str, ":");
            token = strtok(NULL, ":");
            strcpy(res->email, token);
        }
        //get phone number
        if (strstr(str, "Phone:")) {
            token = strtok(str, ":");
            token = strtok(NULL, ":");
            strcpy(res->phone, token);
        }
        //get skills
        if (strstr(str, "Skills:")) {
            token = strtok(str, ":");
            token = strtok(NULL, ":");
            strcpy(res->skills, token);
        }
    }

    //close the file
    fclose(fptr);
}

int main() {
    struct resume r;

    //declare the case
    printf("The Case of the Missing Resumes\n\n");
    printf("It was a dark and stormy night when we received a call from a local company. Their resumes for a job opening had gone missing! We were on the case.\n\n");

    //parse the resume
    parseResume("resume.txt", &r);

    //display the results
    printf("We found the following information:\n");
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);

    //conclude the case
    printf("\nWe were able to locate the missing resumes and return them to the company. Another case solved by Sherlock Holmes and Dr. Watson!\n");

    return 0;
}