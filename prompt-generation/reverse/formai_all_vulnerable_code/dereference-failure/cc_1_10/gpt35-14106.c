//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold parsed resume information
struct Resume {
    char* name;
    char* email;
    char* phone;
    char* education;
    char* experience;
};

// function to parse resume string and fill out Resume structure
void parseResume(char* resumeString, struct Resume* resume) {
    // split resume string into lines
    char* line = strtok(resumeString, "\n");

    // loop through each line and parse relevant information
    while(line != NULL) {
        // check for name
        if(strstr(line, "Name: ") != NULL) {
            // allocate space for name and copy value
            resume->name = (char*) malloc(strlen(line) + 1);
            strcpy(resume->name, line + 6);
        }
        // check for email
        else if(strstr(line, "Email: ") != NULL) {
            // allocate space for email and copy value
            resume->email = (char*) malloc(strlen(line) + 1);
            strcpy(resume->email, line + 7);
        }
        // check for phone number
        else if(strstr(line, "Phone: ") != NULL) {
            // allocate space for phone number and copy value
            resume->phone = (char*) malloc(strlen(line) + 1);
            strcpy(resume->phone, line + 7);
        }
        // check for education
        else if(strstr(line, "Education: ") != NULL) {
            // allocate space for education and copy value
            resume->education = (char*) malloc(strlen(line) + 1);
            strcpy(resume->education, line + 11);
        }
        // check for experience
        else if(strstr(line, "Experience: ") != NULL) {
            // allocate space for experience and copy value
            resume->experience = (char*) malloc(strlen(line) + 1);
            strcpy(resume->experience, line + 12);
        }

        // get next line
        line = strtok(NULL, "\n");
    }
}

int main() {
    // example resume string
    char* resumeString = "Name: John Doe\nEmail: john.doe@email.com\nPhone: 555-555-5555\nEducation: Bachelor of Science in Computer Science\nExperience: Software Engineer at XYZ Company";

    // create resume structure
    struct Resume resume = {NULL, NULL, NULL, NULL, NULL};

    // parse resume string and fill out structure
    parseResume(resumeString, &resume);

    // print out parsed information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    // free allocated memory
    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.education);
    free(resume.experience);

    return 0;
}