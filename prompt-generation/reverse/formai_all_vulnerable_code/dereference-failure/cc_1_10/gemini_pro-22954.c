//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *education;
    char *experience;
    char *awards;
    char *references;
} resume_t;

// Function to parse a resume from a file
resume_t *parse_resume(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the resume
    resume_t *resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *temp;
	bool p = false;
	
    // Read the file line by line
    while ((read = getline(&line, &len, file)) != -1) {
        temp = strndup(line, read);
		if (strncmp(line, "Name", 4) == 0) {
			resume->name = strdup(temp);
		} else if (strncmp(line, "Email", 5) == 0) {
			resume->email = strdup(temp);
		} else if (strncmp(line, "Phone", 5) == 0) {
			resume->phone = strdup(temp);
		} else if (strncmp(line, "Address", 7) == 0) {
			resume->address = strdup(temp);
		} else if (strncmp(line, "Skills", 6) == 0) {
			resume->skills = strdup(temp);
		} else if (strncmp(line, "Education", 9) == 0) {
			resume->education = strdup(temp);
		} else if (strncmp(line, "Experience", 10) == 0) {
			resume->experience = strdup(temp);
		} else if (strncmp(line, "Awards", 6) == 0) {
			resume->awards = strdup(temp);
		} else if (strncmp(line, "References", 10) == 0) {
			resume->references = strdup(temp);
		}
		free(temp);
    }
	
    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(resume_t *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Awards: %s\n", resume->awards);
    printf("References: %s\n", resume->references);
}

// Main function
int main() {
    // Parse the resume
    resume_t *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the resume
    free(resume);

    return 0;
}