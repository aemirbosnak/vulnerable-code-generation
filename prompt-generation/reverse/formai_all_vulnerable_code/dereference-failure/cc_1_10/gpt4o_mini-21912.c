//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum sizes for fields
#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 15
#define MAX_SKILLS_LEN 300
#define MAX_LINE_LEN 512
#define MAX_RESUMES 100

// Struct to hold candidate information
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
    char skills[MAX_SKILLS_LEN];
} Resume;

// Function prototypes
void parseResume(const char* filename, Resume* resumes, int* resumeCount);
void printResumes(const Resume* resumes, int resumeCount);
void trimWhitespace(char* str);

int main() {
    Resume resumes[MAX_RESUMES];
    int resumeCount = 0;

    const char* filename = "resumes.txt"; // Name of the file containing resumes
    parseResume(filename, resumes, &resumeCount); // Parse resumes from file
    printResumes(resumes, resumeCount); // Print parsed resumes

    return 0;
}

// Function to parse resumes from a given file
void parseResume(const char* filename, Resume* resumes, int* resumeCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LEN];
    Resume currentResume;
    int resumeIndex = -1;

    while (fgets(line, sizeof(line), file)) {
        trimWhitespace(line);

        // Identify the start of a new resume
        if (strcmp(line, "NEW RESUME") == 0) {
            resumeIndex++;
            if (resumeIndex >= MAX_RESUMES) {
                fprintf(stderr, "Maximum number of resumes reached\n");
                break;
            }
            memset(&currentResume, 0, sizeof(currentResume)); // Clear current resume data
            continue;
        }

        // Parse fields based on the content of the line
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", currentResume.name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", currentResume.email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", currentResume.phone);
        } else if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %[^\n]", currentResume.skills);
        } 
        // Store the resume when we reach the end of input
        if (feof(file)) {
            resumes[resumeIndex] = currentResume;
            (*resumeCount)++;
        }
    }

    fclose(file);
}

// Function to print the resumes
void printResumes(const Resume* resumes, int resumeCount) {
    for (int i = 0; i < resumeCount; i++) {
        printf("Resume %d:\n", i + 1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Skills: %s\n", resumes[i].skills);
        printf("------------------------\n");
    }
}

// Function to trim leading and trailing whitespace
void trimWhitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate
    *(end + 1) = '\0';
}