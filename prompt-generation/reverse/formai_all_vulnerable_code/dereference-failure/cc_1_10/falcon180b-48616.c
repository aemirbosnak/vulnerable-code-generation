//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

//Struct to store the resume data
typedef struct resume {
    char name[MAX_WORD_LENGTH];
    char address[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char education[MAX_WORD_LENGTH];
    char work_experience[MAX_WORD_LENGTH];
} Resume;

//Function to split a string into words
void split(char* str, char* words[], int max_words) {
    int i = 0;
    char* token;
    token = strtok(str, " ");
    while (token!= NULL && i < max_words) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }
}

//Function to parse the resume data
void parse_resume(char* input, Resume* resume) {
    char name_words[MAX_WORD_LENGTH];
    char address_words[MAX_WORD_LENGTH];
    char phone_words[MAX_WORD_LENGTH];
    char email_words[MAX_WORD_LENGTH];
    char education_words[MAX_WORD_LENGTH];
    char work_experience_words[MAX_WORD_LENGTH];

    //Split the input string into words
    char* words[6];
    split(input, words, 6);

    //Copy the words to the appropriate fields
    strcpy(resume->name, words[0]);
    strcpy(resume->address, words[1]);
    strcpy(resume->phone, words[2]);
    strcpy(resume->email, words[3]);
    strcpy(resume->education, words[4]);
    strcpy(resume->work_experience, words[5]);
}

//Function to display the resume data
void display_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Address: %s\n", resume->address);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_experience);
}

//Main function
int main() {
    char input[MAX_WORD_LENGTH];
    Resume resume;

    //Prompt the user to enter their resume data
    printf("Enter your resume data (Name Address Phone Email Education Work Experience):\n");
    scanf("%s", input);

    //Parse the resume data
    parse_resume(input, &resume);

    //Display the parsed resume data
    display_resume(&resume);

    return 0;
}