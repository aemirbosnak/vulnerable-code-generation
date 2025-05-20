//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum buffer size for reading the text file
#define MAX_BUFFER_SIZE 10000

// Define the maximum number of resumes to be parsed
#define MAX_RESUMES 100

// Define the maximum length of a resume field
#define MAX_FIELD_LENGTH 100

// Define the fields of a resume
typedef struct Resume {
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
    char education[MAX_FIELD_LENGTH];
    char experience[MAX_FIELD_LENGTH];
} Resume;

// Declare the functions used in the program
int load_resumes(Resume resumes[]);
void parse_resume(char *resume_text, Resume *resume);
void print_resumes(Resume resumes[], int num_resumes);

int main() {
    // Declare an array of resumes to store the parsed data
    Resume resumes[MAX_RESUMES];
    // Load the resumes from a text file
    int num_resumes = load_resumes(resumes);
    // Print the parsed resumes to the console
    print_resumes(resumes, num_resumes);
    return 0;
}

int load_resumes(Resume resumes[]) {
    // Open the text file containing the resumes
    FILE *file = fopen("resumes.txt", "r");

    // Define the buffer to read lines of text from the file
    char buffer[MAX_BUFFER_SIZE];
    // Define the index for the array of resumes
    int resume_index = 0;

    // Loop through the file until the end is reached or the maximum number of resumes is parsed
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL && resume_index < MAX_RESUMES) {
        // Parse the resume text into a Resume struct
        parse_resume(buffer, &resumes[resume_index]);
        // Increment the index for the array of resumes
        resume_index++;
    }

    // Close the file
    fclose(file);

    // Return the number of resumes loaded
    return resume_index;
}

void parse_resume(char *resume_text, Resume *resume) {
    // Define a pointer for each field of the resume
    char *name_ptr = NULL;
    char *email_ptr = NULL;
    char *phone_ptr = NULL;
    char *education_ptr = NULL;
    char *experience_ptr = NULL;

    // Tokenize the resume text using "\n" as the delimiter
    char *token = strtok(resume_text, "\n");

    // Loop through the tokens until the end is reached
    while (token != NULL) {
        // Check if the token contains the name field
        if (strstr(token, "Name: ") == token) {
            // Set the pointer for the name field to the string after the "Name: " prefix
            name_ptr = token + strlen("Name: ");
        }
        // Check if the token contains the email field
        else if (strstr(token, "Email: ") == token) {
            // Set the pointer for the email field to the string after the "Email: " prefix
            email_ptr = token + strlen("Email: ");
        }
        // Check if the token contains the phone field
        else if (strstr(token, "Phone: ") == token) {
            // Set the pointer for the phone field to the string after the "Phone: " prefix
            phone_ptr = token + strlen("Phone: ");
        }
        // Check if the token contains the education field
        else if (strstr(token, "Education: ") == token) {
            // Set the pointer for the education field to the string after the "Education: " prefix
            education_ptr = token + strlen("Education: ");
        }
        // Check if the token contains the experience field
        else if (strstr(token, "Experience: ") == token) {
            // Set the pointer for the experience field to the string after the "Experience: " prefix
            experience_ptr = token + strlen("Experience: ");
        }
        // Move to the next token
        token = strtok(NULL, "\n");
    }

    // Copy the string for each field into the corresponding field of the Resume struct
    strcpy(resume->name, name_ptr);
    strcpy(resume->email, email_ptr);
    strcpy(resume->phone, phone_ptr);
    strcpy(resume->education, education_ptr);
    strcpy(resume->experience, experience_ptr);
}

void print_resumes(Resume resumes[], int num_resumes) {
    // Print the header for the table of resumes
    printf("%-20s %-25s %-15s %-20s %-20s\n", "Name", "Email", "Phone", "Education", "Experience");

    // Loop through the array of resumes and print each one in a row of the table
    for (int i = 0; i < num_resumes; i++) {
        printf("%-20s %-25s %-15s %-20s %-20s\n", resumes[i].name, resumes[i].email, resumes[i].phone, resumes[i].education, resumes[i].experience);
    }
}