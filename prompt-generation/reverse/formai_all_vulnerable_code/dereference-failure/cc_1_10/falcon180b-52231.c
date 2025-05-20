//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structure for a resume
typedef struct {
    char name[50];
    char email[100];
    char phone[20];
    char address[200];
    char education[200];
    char experience[200];
} resume;

// Function to parse a line of text and return a token
char* get_token(char* line) {
    char* token = (char*) malloc(sizeof(char)*100);
    char* temp = line;
    int i = 0;

    // Skip leading spaces
    while (isspace(*temp)) {
        temp++;
    }

    // Copy token
    while (!isspace(*temp) && i < 99) {
        token[i++] = *temp;
        temp++;
    }
    token[i] = '\0';

    return token;
}

// Function to parse a resume from a text file
void parse_resume(FILE* file, resume* r) {
    char line[200];
    int section = 0;

    // Read first line for name
    fgets(line, sizeof(line), file);
    strcpy(r->name, get_token(line));

    // Loop through remaining lines for other sections
    while (fgets(line, sizeof(line), file)) {
        char* token = get_token(line);
        if (strcmp(token, "Email:") == 0) {
            strcpy(r->email, get_token(line));
        } else if (strcmp(token, "Phone:") == 0) {
            strcpy(r->phone, get_token(line));
        } else if (strcmp(token, "Address:") == 0) {
            strcpy(r->address, get_token(line));
        } else if (strcmp(token, "Education:") == 0) {
            strcpy(r->education, get_token(line));
        } else if (strcmp(token, "Experience:") == 0) {
            strcpy(r->experience, get_token(line));
        }
    }
}

// Function to print a resume
void print_resume(resume* r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

// Main function to read a text file and parse the resume
int main() {
    FILE* file;
    resume r;

    // Open the text file
    file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Parse the resume
    parse_resume(file, &r);

    // Print the resume
    print_resume(&r);

    // Close the file
    fclose(file);

    return 0;
}