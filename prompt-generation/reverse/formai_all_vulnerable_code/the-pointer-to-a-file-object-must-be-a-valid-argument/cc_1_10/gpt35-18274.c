//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold resume information
typedef struct resume {
    char name[50];
    char title[50];
    char email[50];
    char phone[20];
} Resume;

// Define a function to parse resume
void parseResume(char *filename) {
    FILE *fp;
    char line[100];
    Resume r;
    int i = 0;

    // Open the resume file
    fp = fopen(filename, "r");

    // Read each line of the resume file
    while (fgets(line, 100, fp) != NULL) {
        // Parse the line to get the name
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %s", r.name);
        }
        // Parse the line to get the title
        else if (strstr(line, "Title:")) {
            sscanf(line, "Title: %s", r.title);
        }
        // Parse the line to get the email
        else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %s", r.email);
        }
        // Parse the line to get the phone number
        else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %s", r.phone);
        }
        i++;
    }

    // Print the parsed information
    printf("Name: %s\n", r.name);
    printf("Title: %s\n", r.title);
    printf("Email: %s\n", r.email);
    printf("Phone Number: %s\n", r.phone);

    // Close the file
    fclose(fp);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Parse the resume file
    if (argc == 2) {
        parseResume(argv[1]);
    }
    else {
        printf("Please provide a resume file.\n");
    }

    return 0;
}