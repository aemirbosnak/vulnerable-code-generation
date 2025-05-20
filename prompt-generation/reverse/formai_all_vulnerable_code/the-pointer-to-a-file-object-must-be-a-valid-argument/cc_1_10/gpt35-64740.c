//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 512
#define MAX_NUM_RESUMES 100

// A struct to hold information extracted from a resume
typedef struct {
    char name[50];
    char email[50];
    char mobile[15];
    char skills[200];
    int years_exp;
} Resume;

// A function to parse a single resume and populate a Resume object
void parse_resume(char *resume_text, Resume *resume) {
    char *line;
    char *keyword;
    char *value;
    line = strtok(resume_text, "\n");
    while (line != NULL) {
        // Extract the keyword and value from the line
        keyword = strtok(line, ":");
        value = strtok(NULL, "");
        // Strip leading/trailing whitespace from the value
        char *trim_value = malloc(strlen(value) + 1);
        strcpy(trim_value, value);
        char *start = trim_value;
        while (*start == ' ') start++;
        char *end = start + strlen(start) - 1;
        while (*end == ' ') end--;
        *(end+1) = '\0';
        // Set the appropriate field in the Resume object based on the keyword
        if (strcmp(keyword, "Name") == 0) {
            strcpy(resume->name, trim_value);
        } else if (strcmp(keyword, "Email") == 0) {
            strcpy(resume->email, trim_value);
        } else if (strcmp(keyword, "Mobile") == 0) {
            strcpy(resume->mobile, trim_value);
        } else if (strcmp(keyword, "Skills") == 0) {
            strcpy(resume->skills, trim_value);
        } else if (strcmp(keyword, "Years of Experience") == 0) {
            resume->years_exp = atoi(trim_value);
        }
        // Move to the next line
        line = strtok(NULL, "\n");
    }
}

int main() {
    // Read resumes from file
    FILE *fp = fopen("resumes.txt", "r");
    char line[MAX_LINE_LEN];
    char resume_text[MAX_NUM_RESUMES * MAX_LINE_LEN];
    Resume resumes[MAX_NUM_RESUMES];
    int num_resumes = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        // Concatenate each line into one string per resume
        strcat(resume_text, line);
        if (strcmp(line, "\n") == 0) {
            // Parse the completed resume and add to the resumes array
            parse_resume(resume_text, &resumes[num_resumes]);
            num_resumes++;
            // Clear the resume_text buffer for the next resume
            memset(resume_text, 0, sizeof(resume_text));
        }
    }
    fclose(fp);

    // Print out the extracted information for each resume
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Mobile: %s\n", resumes[i].mobile);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Years of Experience: %d\n\n", resumes[i].years_exp);
    }

    return 0;
}