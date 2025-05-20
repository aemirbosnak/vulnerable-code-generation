//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Resume structure
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[10]; // Max 10 skills
    int num_skills;
} resume;

// Function to create a new resume
resume *new_resume() {
    resume *res = (resume *)malloc(sizeof(resume));
    res->name = NULL;
    res->email = NULL;
    res->phone = NULL;
    res->address = NULL;
    res->num_skills = 0;
    return res;
}

// Function to free a resume
void free_resume(resume *res) {
    if (res) {
        if (res->name) free(res->name);
        if (res->email) free(res->email);
        if (res->phone) free(res->phone);
        if (res->address) free(res->address);
        for (int i = 0; i < res->num_skills; i++) {
            if (res->skills[i]) free(res->skills[i]);
        }
        free(res);
    }
}

// Function to parse a line of text and extract the relevant information
void parse_line(char *line, resume *res) {
    char *key, *value;

    // Split the line into key and value
    key = strtok(line, ":");
    value = strtok(NULL, "\n");

    // Check the key and update the resume accordingly
    if (!strcmp(key, "Name")) {
        res->name = (char *)malloc(strlen(value) + 1);
        strcpy(res->name, value);
    } else if (!strcmp(key, "Email")) {
        res->email = (char *)malloc(strlen(value) + 1);
        strcpy(res->email, value);
    } else if (!strcmp(key, "Phone")) {
        res->phone = (char *)malloc(strlen(value) + 1);
        strcpy(res->phone, value);
    } else if (!strcmp(key, "Address")) {
        res->address = (char *)malloc(strlen(value) + 1);
        strcpy(res->address, value);
    } else if (!strcmp(key, "Skills")) {
        char *skill;

        // Split the skills into individual skills
        skill = strtok(value, ",");
        while (skill) {
            res->skills[res->num_skills] = (char *)malloc(strlen(skill) + 1);
            strcpy(res->skills[res->num_skills], skill);
            res->num_skills++;
            skill = strtok(NULL, ",");
        }
    }
}

// Function to print a resume
void print_resume(resume *res) {
    printf("Name: %s\n", res->name);
    printf("Email: %s\n", res->email);
    printf("Phone: %s\n", res->phone);
    printf("Address: %s\n", res->address);
    printf("Skills: ");
    for (int i = 0; i < res->num_skills; i++) {
        printf("%s, ", res->skills[i]);
    }
    printf("\n");
}

// Main function
int main() {
    FILE *fp;
    char line[1024];
    resume *res;

    // Open the resume file
    fp = fopen("resume.txt", "r");
    if (!fp) {
        printf("Error opening resume file\n");
        return 1;
    }

    // Create a new resume
    res = new_resume();

    // Parse the resume file line by line
    while (fgets(line, sizeof(line), fp)) {
        parse_line(line, res);
    }

    // Close the resume file
    fclose(fp);

    // Print the resume
    print_resume(res);

    // Free the resume
    free_resume(res);

    return 0;
}