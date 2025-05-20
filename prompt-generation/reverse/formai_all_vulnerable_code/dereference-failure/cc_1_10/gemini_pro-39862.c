//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: irregular
//    .________________________________._
//    |\                                   \|
//    | \--------------------------------- / |
//    | |{=============[ THE BOSS ]========}| |
//    | |                                   | |
//    | /_________________________________\| |
//    |/              .:::.                 \|/
//    |              |\___/|                |
//    |              | \ / |                |
//    |              |_\_/_|                |
//    |      _.-=""""       """"=-._       |
//    |    .'          [RESUME]         '.    |
//    |   /       .                   .       \   |
//    |  /                  C                  \  |
//    |  \_______..._________..._______/  |
//    |                                   |
//    |                                   |
//    |___________________________________|
//                                            /\
//                                           /  \
//                                          /    \
//                                         /      \
//                                        /        \
//                                       /          \
//                                      /____________\

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

// Define the function to parse a resume
resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the resume struct
    resume *resume = malloc(sizeof(resume));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    // Parse the resume
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Parse the name
        if (strstr(line, "Name:")) {
            resume->name = strdup(strtok(line, ":"));
        }

        // Parse the email
        if (strstr(line, "Email:")) {
            resume->email = strdup(strtok(line, ":"));
        }

        // Parse the phone
        if (strstr(line, "Phone:")) {
            resume->phone = strdup(strtok(line, ":"));
        }

        // Parse the address
        if (strstr(line, "Address:")) {
            resume->address = strdup(strtok(line, ":"));
        }

        // Parse the skills
        if (strstr(line, "Skills:")) {
            resume->skills = strdup(strtok(line, ":"));
        }

        // Parse the experience
        if (strstr(line, "Experience:")) {
            resume->experience = strdup(strtok(line, ":"));
        }

        // Parse the education
        if (strstr(line, "Education:")) {
            resume->education = strdup(strtok(line, ":"));
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Define the function to print a resume
void print_resume(resume *resume) {
    // Print the resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Parse the resume file
    resume *resume = parse_resume(argv[1]);

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume struct
    free(resume);

    return 0;
}