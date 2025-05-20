//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold resume information
typedef struct {
    char name[50];
    int age;
    char gender[10];
    char address[100];
    char phone[20];
    char email[50];
    char skills[50][50];
    int num_skills;
} Resume;

// Function to parse the resume string and populate the struct
void parseResume(char *resume, Resume *res) {
    // Initialize struct to default values
    strcpy(res->name, "John Doe");
    res->age = 25;
    strcpy(res->gender, "Male");
    strcpy(res->address, "123 Main St.");
    strcpy(res->phone, "555-555-5555");
    strcpy(res->email, "john.doe@example.com");
    strcpy(res->skills, "");
    res->num_skills = 0;

    // Split the resume into lines and parse each line
    char *line = strtok(resume, "\n");
    while (line!= NULL) {
        // Check if the line contains relevant information
        if (strstr(line, "Name:") || strstr(line, "Phone:") || strstr(line, "Email:") || strstr(line, "Skills:") || strstr(line, "Address:") || strstr(line, "Age:")) {
            // Extract relevant information from the line
            char *key = strtok(line, ":");
            char *value = strtok(NULL, ":");

            // Check if the key is "Skills"
            if (strcmp(key, "Skills") == 0) {
                // Split the value into an array of strings
                char *skill = strtok(value, ",");
                while (skill!= NULL) {
                    strcat(res->skills, skill);
                    strcat(res->skills, ",");
                    skill = strtok(NULL, ",");
                }
            }
            // Store the key-value pair in the struct
            strcpy(res->name, key);
            strcat(res->name, value);
            strcat(res->name, "\n");
            res->age = atoi(value);
            strcpy(res->gender, key);
            strcat(res->gender, value);
            strcpy(res->address, key);
            strcat(res->address, value);
            strcpy(res->phone, key);
            strcat(res->phone, value);
            strcpy(res->email, key);
            strcat(res->email, value);
        }
        // Get the next line
        line = strtok(NULL, "\n");
    }

    // Count the number of skills
    int i = 0;
    while (res->skills[i]!= '\0') {
        i++;
    }
    res->num_skills = i;
}

int main() {
    // Read the resume from a file
    FILE *fp = fopen("resume.txt", "r");
    char resume[1000];
    fgets(resume, sizeof(resume), fp);
    fclose(fp);

    // Parse the resume
    Resume res;
    parseResume(resume, &res);

    // Print the parsed information
    printf("Name: %s\n", res.name);
    printf("Age: %d\n", res.age);
    printf("Gender: %s\n", res.gender);
    printf("Address: %s\n", res.address);
    printf("Phone: %s\n", res.phone);
    printf("Email: %s\n", res.email);
    printf("Skills: ");
    for (int i = 0; i < res.num_skills; i++) {
        printf("%s, ", res.skills[i]);
    }
    printf("\n");

    return 0;
}