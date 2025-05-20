//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
char *resume_path;
char *file_name;
char *user_name;
char *user_email;
char *job_title;
char *company_name;
char *start_date;
char *end_date;
char *summary;
char *education;
char *skills;

// Function to parse the resume
void parse_resume() {
    // Open the resume file
    FILE *fp = fopen(resume_path, "r");
    
    // Read the file line by line
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        // Check for the start of a new section
        if (strstr(line, "----")) {
            // Check for the section type
            if (strstr(line, "NAME")) {
                // Parse the name section
                sscanf(line, "%s", user_name);
            }
            else if (strstr(line, "EMAIL")) {
                // Parse the email section
                sscanf(line, "%s", user_email);
            }
            else if (strstr(line, "TITLE")) {
                // Parse the title section
                sscanf(line, "%s", job_title);
            }
            else if (strstr(line, "COMPANY")) {
                // Parse the company section
                sscanf(line, "%s", company_name);
            }
            else if (strstr(line, "START_DATE")) {
                // Parse the start date section
                sscanf(line, "%s", start_date);
            }
            else if (strstr(line, "END_DATE")) {
                // Parse the end date section
                sscanf(line, "%s", end_date);
            }
            else if (strstr(line, "SUMMARY")) {
                // Parse the summary section
                sscanf(line, "%s", summary);
            }
            else if (strstr(line, "EDUCATION")) {
                // Parse the education section
                sscanf(line, "%s", education);
            }
            else if (strstr(line, "SKILLS")) {
                // Parse the skills section
                sscanf(line, "%s", skills);
            }
        }
    }
    
    // Close the resume file
    fclose(fp);
}

// Function to generate a resume
void generate_resume() {
    // Open the resume file
    FILE *fp = fopen(resume_path, "w");
    
    // Write the name section
    fprintf(fp, "---- NAME ----\n");
    fprintf(fp, "%s\n\n", user_name);
    
    // Write the email section
    fprintf(fp, "---- EMAIL ----\n");
    fprintf(fp, "%s\n\n", user_email);
    
    // Write the title section
    fprintf(fp, "---- TITLE ----\n");
    fprintf(fp, "%s\n\n", job_title);
    
    // Write the company section
    fprintf(fp, "---- COMPANY ----\n");
    fprintf(fp, "%s\n\n", company_name);
    
    // Write the start date section
    fprintf(fp, "---- START DATE ----\n");
    fprintf(fp, "%s\n\n", start_date);
    
    // Write the end date section
    fprintf(fp, "---- END DATE ----\n");
    fprintf(fp, "%s\n\n", end_date);
    
    // Write the summary section
    fprintf(fp, "---- SUMMARY ----\n");
    fprintf(fp, "%s\n\n", summary);
    
    // Write the education section
    fprintf(fp, "---- EDUCATION ----\n");
    fprintf(fp, "%s\n\n", education);
    
    // Write the skills section
    fprintf(fp, "---- SKILLS ----\n");
    fprintf(fp, "%s\n\n", skills);
    
    // Close the resume file
    fclose(fp);
}

// Function to distribute the work
void distribute_work() {
    // Generate a unique ID for the user
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char user_id[10];
    sprintf(user_id, "%04d%02d%02d%02d%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min);
    
    // Open the resume file
    FILE *fp = fopen(resume_path, "w");
    
    // Write the user ID
    fprintf(fp, "---- USER ID ----\n");
    fprintf(fp, "%s\n\n", user_id);
    
    // Generate the resume
    generate_resume();
    
    // Close the resume file
    fclose(fp);
}

// Main function
int main() {
    // Set the resume path
    resume_path = "resume.txt";
    
    // Parse the resume
    parse_resume();
    
    // Distribute the work
    distribute_work();
    
    return 0;
}