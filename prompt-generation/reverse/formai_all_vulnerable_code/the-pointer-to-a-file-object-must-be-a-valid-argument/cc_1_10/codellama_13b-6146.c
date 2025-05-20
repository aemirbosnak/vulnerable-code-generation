//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: brave
/*
 * C Resume Parsing System
 *
 * Developed by John Doe
 *
 * Usage: ./resume_parser <resume_file>
 *
 * This program parses a resume file and extracts relevant information such as name,
 * contact information, education, work experience, skills, and achievements.
 *
 * The program is designed to be efficient and fast, using a simple but effective
 * algorithm to extract the relevant information.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_SKILL_LEN 20
#define MAX_EXP_LEN 50

// Structure to store information about a resume
struct Resume {
    char name[MAX_NAME_LEN];
    char contact[MAX_NAME_LEN];
    char education[MAX_NAME_LEN];
    char work_exp[MAX_EXP_LEN];
    char skills[MAX_SKILL_LEN];
    char achievements[MAX_EXP_LEN];
};

// Function to parse the resume file and extract information
void parse_resume(struct Resume *resume, char *file_name) {
    FILE *fp;
    char line[MAX_EXP_LEN];
    char *token;

    // Open the resume file
    fp = fopen(file_name, "r");

    // Read each line of the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Check if the line contains the name
        if (strstr(line, "Name:") != NULL) {
            // Extract the name from the line
            token = strtok(line, ":");
            strcpy(resume->name, token);
        }

        // Check if the line contains the contact information
        if (strstr(line, "Contact:") != NULL) {
            // Extract the contact information from the line
            token = strtok(line, ":");
            strcpy(resume->contact, token);
        }

        // Check if the line contains the education
        if (strstr(line, "Education:") != NULL) {
            // Extract the education from the line
            token = strtok(line, ":");
            strcpy(resume->education, token);
        }

        // Check if the line contains the work experience
        if (strstr(line, "Work Experience:") != NULL) {
            // Extract the work experience from the line
            token = strtok(line, ":");
            strcpy(resume->work_exp, token);
        }

        // Check if the line contains the skills
        if (strstr(line, "Skills:") != NULL) {
            // Extract the skills from the line
            token = strtok(line, ":");
            strcpy(resume->skills, token);
        }

        // Check if the line contains the achievements
        if (strstr(line, "Achievements:") != NULL) {
            // Extract the achievements from the line
            token = strtok(line, ":");
            strcpy(resume->achievements, token);
        }
    }

    // Close the file
    fclose(fp);
}

// Function to display the resume information
void display_resume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Contact: %s\n", resume->contact);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_exp);
    printf("Skills: %s\n", resume->skills);
    printf("Achievements: %s\n", resume->achievements);
}

// Main function
int main(int argc, char *argv[]) {
    // Create a resume structure
    struct Resume resume;

    // Check if the resume file is provided as an argument
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    // Parse the resume file
    parse_resume(&resume, argv[1]);

    // Display the resume information
    display_resume(&resume);

    return 0;
}