//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct resume{
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char skills[500];
    char experience[1000];
};

int main(){

    printf("\n********* C Resume Parsing System **********\n\n");

    struct resume candidate;

    printf("Enter candidate's full name:\n");
    fgets(candidate.name, 50, stdin);

    printf("\nEnter candidate's email address:\n");
    fgets(candidate.email, 50, stdin);

    printf("\nEnter candidate's phone number:\n");
    fgets(candidate.phone, 20, stdin);

    printf("\nEnter candidate's current address:\n");
    fgets(candidate.address, 100, stdin);

    printf("\nEnter candidate's skills(separated by commas):\n");
    fgets(candidate.skills, 500, stdin);

    printf("\nEnter candidate's experience:\n");
    fgets(candidate.experience, 1000, stdin);

    //Now we will extract the required information from the resume

    char *token;
    char *remainder = candidate.experience;
    char job_desc[1000];
    char company[100];
    char duration[10];
    char job_title[100];

    printf("\n********* Resume Parsing Results *********\n\n");

    printf("Candidate name: %s\n", candidate.name);
    printf("Candidate email: %s\n", candidate.email);
    printf("Candidate phone number:%s\n", candidate.phone);
    printf("Candidate address: %s\n", candidate.address);
    printf("Candidate skills:\n");

    //Extracting skills
    token = strtok(candidate.skills, ",");
    while(token != NULL){
        printf("\t-%s\n", token);
        token = strtok(NULL, ",");
    }

    //Extracting work experience
    while((token = strtok_r(remainder, ",", &remainder))){
        strcpy(job_desc, token);
        token = strtok_r(remainder, ",", &remainder);
        strcpy(company, token);
        token = strtok_r(remainder, ",", &remainder);
        strcpy(duration, token);
        token = strtok_r(remainder, ",", &remainder);
        strcpy(job_title, token);

        printf("\nJob Description: %s\n", job_desc);
        printf("\nCompany: %s\n", company);
        printf("\nDuration: %s\n", duration);
        printf("\nJob Title: %s\n", job_title);
    }

    return 0;
}