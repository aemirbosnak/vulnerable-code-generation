//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the structure for the resume fields
struct Applicant{
    char name[50];
    char address[50];
    char email[50];
    char phone[20];
    char education[100];
    char skillset[200];
    char experience[200];
};

//Function to parse the resume and extract the fields
void parse_resume(char resume_template[]){
    struct Applicant applicant;
    char *token;

    //Extract the name field
    token = strtok(resume_template, "\n");
    strcpy(applicant.name, token);

    //Extract the address field
    token = strtok(NULL, "\n");
    strcpy(applicant.address, token);

    //Extract the email field
    token = strtok(NULL, "\n");
    strcpy(applicant.email, token);

    //Extract the phone number field
    token = strtok(NULL, "\n");
    strcpy(applicant.phone, token);

    //Extract the education field
    token = strtok(NULL, "\n");
    strcpy(applicant.education, token);

    //Extract the skillset field
    token = strtok(NULL, "\n");
    strcpy(applicant.skillset, token);

    //Extract the experience field
    token = strtok(NULL, "\n");
    strcpy(applicant.experience, token);

    //Print the extracted fields
    printf("Name: %s\n", applicant.name);
    printf("Address: %s\n", applicant.address);
    printf("Email: %s\n", applicant.email);
    printf("Phone: %s\n", applicant.phone);
    printf("Education: %s\n", applicant.education);
    printf("Skillset: %s\n", applicant.skillset);
    printf("Experience: %s\n", applicant.experience);
}

int main(){
    char resume_template[500];

    //Read the resume file
    FILE *file = fopen("resume.txt", "r");
    if(file == NULL){
        printf("Error: Failed to open the resume file!\n");
        exit(0);
    }
    fgets(resume_template, 500, file);
    fclose(file);

    parse_resume(resume_template);

    return 0;
}