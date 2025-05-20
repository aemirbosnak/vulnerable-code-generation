//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: irregular
//-- C Resume Parsing System --//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Format: "name:value;"
#define FIELD_DELIM ";"

// Format: "keyword"
#define KEYWORD_DELIM ","

// Structure to store the resume data
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Function to parse a resume
Resume *parse_resume(char *resume_text) {
    Resume *resume = malloc(sizeof(Resume));

    // Split the resume text into fields
    char *fields[7];
    char *field = strtok(resume_text, FIELD_DELIM);
    int i = 0;
    while (field != NULL) {
        fields[i++] = field;
        field = strtok(NULL, FIELD_DELIM);
    }

    // Parse the fields
    for (i = 0; i < 7; i++) {
        char *keyword = strtok(fields[i], KEYWORD_DELIM);
        char *value = strtok(NULL, KEYWORD_DELIM);

        if (strcmp(keyword, "name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(keyword, "email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(keyword, "phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(keyword, "address") == 0) {
            resume->address = strdup(value);
        } else if (strcmp(keyword, "skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(keyword, "experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(keyword, "education") == 0) {
            resume->education = strdup(value);
        }
    }

    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main() {
    // Read the resume from a file
    char *resume_text = NULL;
    FILE *fp = fopen("resume.txt", "r");
    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        long fsize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        resume_text = malloc(fsize + 1);
        fread(resume_text, 1, fsize, fp);
        fclose(fp);
    }

    // Parse the resume
    Resume *resume = parse_resume(resume_text);

    // Print the resume
    print_resume(resume);

    // Free the memory
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return 0;
}