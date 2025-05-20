//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
/* C Resume Parsing System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_COMPANY_LEN 100
#define MAX_JOB_TITLE_LEN 100
#define MAX_EDUCATION_LEN 100
#define MAX_SKILLS_LEN 100

// Define structures for resume data
typedef struct {
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    char job_title[MAX_JOB_TITLE_LEN];
    char education[MAX_EDUCATION_LEN];
    char skills[MAX_SKILLS_LEN];
} Resume;

// Function to parse a line of the resume
void parse_line(Resume *r, char *line) {
    char *key = strtok(line, ":");
    char *value = strtok(NULL, ":");

    if (strcmp(key, "name") == 0) {
        strncpy(r->name, value, MAX_NAME_LEN);
    } else if (strcmp(key, "company") == 0) {
        strncpy(r->company, value, MAX_COMPANY_LEN);
    } else if (strcmp(key, "job_title") == 0) {
        strncpy(r->job_title, value, MAX_JOB_TITLE_LEN);
    } else if (strcmp(key, "education") == 0) {
        strncpy(r->education, value, MAX_EDUCATION_LEN);
    } else if (strcmp(key, "skills") == 0) {
        strncpy(r->skills, value, MAX_SKILLS_LEN);
    }
}

// Function to print a resume
void print_resume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Company: %s\n", r.company);
    printf("Job Title: %s\n", r.job_title);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
}

// Main function to parse a resume file and print the results
int main(int argc, char *argv[]) {
    FILE *fp;
    Resume r = {0};

    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(r.name, MAX_NAME_LEN, fp)!= NULL) {
        parse_line(&r, r.name);
    }

    printf("Resume:\n");
    print_resume(r);

    fclose(fp);
    return 0;
}