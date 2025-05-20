//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_INPUT_LENGTH 10000

// Define struct to hold information about each separate project or job
typedef struct {
    char name[MAX_STRING_LENGTH];
    char position[MAX_STRING_LENGTH];
    char start_date[MAX_STRING_LENGTH];
    char end_date[MAX_STRING_LENGTH];
    char description[MAX_STRING_LENGTH];
} Job;

// Define struct to hold all information about a candidate
typedef struct {
    char name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char phone_number[MAX_STRING_LENGTH];
    char summary[MAX_STRING_LENGTH];
    Job jobs[MAX_STRING_LENGTH];
} Candidate;

// Declare function to parse candidate information from input string
void parse_candidate(char* input_string, Candidate* candidate);

int main() 
{
    // Declare input string and read input from user
    char input[MAX_INPUT_LENGTH];
    printf("Enter your resume:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Declare candidate struct and parse input string
    Candidate candidate;
    parse_candidate(input, &candidate);

    // Print out parsed candidate information
    printf("---Candidate Information---\n");
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone Number: %s\n", candidate.phone_number);
    printf("Summary: %s\n", candidate.summary);
    printf("Jobs:\n");
    for (int i = 0; i < MAX_STRING_LENGTH && candidate.jobs[i].name[0] != '\0'; i++) {
        printf("---%s---\n", candidate.jobs[i].name);
        printf("Position: %s\n", candidate.jobs[i].position);
        printf("Start Date: %s\n", candidate.jobs[i].start_date);
        printf("End Date: %s\n", candidate.jobs[i].end_date);
        printf("Description: %s\n", candidate.jobs[i].description);
    }

    return 0;
}

void parse_candidate(char* input_string, Candidate* candidate) {
    // Use strtok to split input on newlines
    char* token = strtok(input_string, "\n");

    // Parse first line as candidate name
    strcpy(candidate->name, token);

    // Parse second line as candidate email
    token = strtok(NULL, "\n");
    strcpy(candidate->email, token);

    // Parse third line as candidate phone number
    token = strtok(NULL, "\n");
    strcpy(candidate->phone_number, token);

    // Parse fourth line as candidate summary
    token = strtok(NULL, "\n");
    strcpy(candidate->summary, token);

    // Parse each subsequent block of input as separate jobs
    int job_index = 0;
    while (token != NULL) {
        token = strtok(NULL, "\n");
        if (token != NULL && strlen(token) > 0) {
            Job job;
            strcpy(job.name, token);
            token = strtok(NULL, "\n");
            strcpy(job.position, token);
            token = strtok(NULL, "\n");
            strcpy(job.start_date, token);
            token = strtok(NULL, "\n");
            strcpy(job.end_date, token);
            token = strtok(NULL, "\n");
            strcpy(job.description, token);
            candidate->jobs[job_index++] = job;
        }
    }
}