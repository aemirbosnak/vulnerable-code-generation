//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

// struct to hold resume information
struct Resume {
    char name[MAX];
    char email[MAX];
    char company[MAX];
    char job_title[MAX];
    char education[MAX];
};

// function to parse resume information
void parse_resume(char *filename, struct Resume *resume) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");  // open file for reading

    // read file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        // check for name
        if (strstr(line, "Name:")) {
            char *name = strtok(line, " ");  // get name from line
            strcpy(resume->name, strtok(NULL, "\n"));  // remove newline character
        }
        // check for email
        if (strstr(line, "Email:")) {
            char *email = strtok(line, " ");  // get email from line
            strcpy(resume->email, strtok(NULL, "\n"));  // remove newline character
        }
        // check for company
        if (strstr(line, "Company:")) {
            char *company = strtok(line, " ");  // get company from line
            strcpy(resume->company, strtok(NULL, "\n"));  // remove newline character
        }
        // check for job title
        if (strstr(line, "Job Title:")) {
            char *job_title = strtok(line, " ");  // get job title from line
            strcpy(resume->job_title, strtok(NULL, "\n"));  // remove newline character
        }
        // check for education
        if (strstr(line, "Education:")) {
            char *education = strtok(line, " ");  // get education from line
            strcpy(resume->education, strtok(NULL, "\n"));  // remove newline character
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main() {
    struct Resume resume;
    char *filename = "resume.txt";  // name of file to parse

    parse_resume(filename, &resume);  // parse resume information

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Company: %s\n", resume.company);
    printf("Job Title: %s\n", resume.job_title);
    printf("Education: %s\n", resume.education);

    return 0;
}