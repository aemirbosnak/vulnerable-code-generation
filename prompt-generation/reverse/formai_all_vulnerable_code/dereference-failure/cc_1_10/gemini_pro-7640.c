//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Resume Data Structure
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[5];
    char *experience[5];
    char *education[5];
} resume_t;

// Resume Parsing Function
resume_t *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening resume file: %s\n", filename);
        return NULL;
    }

    // Create a new resume
    resume_t *resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        fprintf(stderr, "Error allocating memory for resume\n");
        fclose(file);
        return NULL;
    }

    // Initialize the resume fields
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    for (int i = 0; i < 5; i++) {
        resume->skills[i] = NULL;
        resume->experience[i] = NULL;
        resume->education[i] = NULL;
    }

    // Parse the resume file
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Find the section header
        if (strstr(line, "Name:") != NULL) {
            // Parse the name
            char *name = strchr(line, ':') + 1;
            resume->name = strdup(name);
        } else if (strstr(line, "Email:") != NULL) {
            // Parse the email
            char *email = strchr(line, ':') + 1;
            resume->email = strdup(email);
        } else if (strstr(line, "Phone:") != NULL) {
            // Parse the phone number
            char *phone = strchr(line, ':') + 1;
            resume->phone = strdup(phone);
        } else if (strstr(line, "Address:") != NULL) {
            // Parse the address
            char *address = strchr(line, ':') + 1;
            resume->address = strdup(address);
        } else if (strstr(line, "Skills:") != NULL) {
            // Parse the skills
            char *skills = strchr(line, ':') + 1;
            char *skill;
            int i = 0;
            while ((skill = strtok(skills, ",")) != NULL) {
                resume->skills[i] = strdup(skill);
                i++;
            }
        } else if (strstr(line, "Experience:") != NULL) {
            // Parse the experience
            char *experience = strchr(line, ':') + 1;
            char *job;
            int i = 0;
            while ((job = strtok(experience, ",")) != NULL) {
                resume->experience[i] = strdup(job);
                i++;
            }
        } else if (strstr(line, "Education:") != NULL) {
            // Parse the education
            char *education = strchr(line, ':') + 1;
            char *degree;
            int i = 0;
            while ((degree = strtok(education, ",")) != NULL) {
                resume->education[i] = strdup(degree);
                i++;
            }
        }
    }

    // Close the resume file
    fclose(file);

    // return the parsed resume
    return resume;
}

// Print the resume
void print_resume(resume_t *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills:\n");
    for (int i = 0; i < 5; i++) {
        if (resume->skills[i] != NULL) {
            printf(" - %s\n", resume->skills[i]);
        }
    }
    printf("Experience:\n");
    for (int i = 0; i < 5; i++) {
        if (resume->experience[i] != NULL) {
            printf(" - %s\n", resume->experience[i]);
        }
    }
    printf("Education:\n");
    for (int i = 0; i < 5; i++) {
        if (resume->education[i] != NULL) {
            printf(" - %s\n", resume->education[i]);
        }
    }
}

// Free the resume
void free_resume(resume_t *resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    for (int i = 0; i < 5; i++) {
        free(resume->skills[i]);
        free(resume->experience[i]);
        free(resume->education[i]);
    }
    free(resume);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    resume_t *resume = parse_resume(argv[1]);

    // Print the resume
    print_resume(resume);

    // Free the resume
    free_resume(resume);

    return 0;
}