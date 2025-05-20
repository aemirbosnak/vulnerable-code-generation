//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name; // Applicant's name
    char *email; // Applicant's email
    char *phone; // Applicant's phone number
    char *resume_text; // Applicant's resume text
    char *education; // Applicant's education information
    char *experience; // Applicant's work experience information
} Resume;

// Function to read the resume text from a file
char *read_resume_text(char *filename) {
    FILE *fp;
    char *buffer;
    long file_size;

    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    buffer = (char *) malloc(sizeof(char) * file_size + 1);

    if(buffer == NULL) {
        printf("Error: Unable to allocate memory for file %s\n", filename);
        exit(1);
    }

    fread(buffer, 1, file_size, fp);
    buffer[file_size] = '\0';

    fclose(fp);

    return buffer;
}

// Function to parse the resume text into individual sections
void parse_resume_text(Resume *resume) {
    char *token;
    char *line;

    line = strtok(resume->resume_text, "\n");

    while(line != NULL) {
        if(strcmp(line, "Education") == 0) {
            token = strtok(NULL, "\n");
            resume->education = (char *) malloc(sizeof(char) * strlen(token) + 1);
            strcpy(resume->education, token);
        }
        else if(strcmp(line, "Experience") == 0) {
            token = strtok(NULL, "\n");
            resume->experience = (char *) malloc(sizeof(char) * strlen(token) + 1);
            strcpy(resume->experience, token);
        }

        line = strtok(NULL, "\n");
    }
}

int main() {
    Resume *resume = (Resume *) malloc(sizeof(Resume));

    resume->name = "John Doe";
    resume->email = "johndoe@gmail.com";
    resume->phone = "555-555-5555";
    resume->resume_text = read_resume_text("resume.txt");

    parse_resume_text(resume);

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);

    free(resume->resume_text);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return 0;
}