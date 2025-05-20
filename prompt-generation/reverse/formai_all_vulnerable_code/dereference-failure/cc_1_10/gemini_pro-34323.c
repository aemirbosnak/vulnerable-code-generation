//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for storing resume data
struct Name {
    char first[20];
    char last[20];
};

struct Education {
    char degree[20];
    char school[20];
    int start_year;
    int end_year;
};

struct Experience {
    char title[20];
    char company[20];
    int start_month;
    int start_year;
    int end_month;
    int end_year;
};

struct Skill {
    char name[20];
    int level;
};

struct Resume {
    struct Name name;
    struct Education education[5];
    struct Experience experience[5];
    struct Skill skill[5];
};

// Function to parse a resume file
struct Resume* parse_resume(char* filename) {
    // Open the resume file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening resume file: %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume struct
    struct Resume* resume = malloc(sizeof(struct Resume));
    if (resume == NULL) {
        printf("Error allocating memory for resume struct\n");
        fclose(fp);
        return NULL;
    }

    // Parse the resume file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the name
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name: %s %s", resume->name.first, resume->name.last);
        }

        // Parse the education
        else if (strncmp(line, "Education:", 10) == 0) {
            int i = 0;
            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "\n", 1) == 0) {
                    break;
                }
                sscanf(line, "%s %s %d %d", resume->education[i].degree, resume->education[i].school, &resume->education[i].start_year, &resume->education[i].end_year);
                i++;
            }
        }

        // Parse the experience
        else if (strncmp(line, "Experience:", 10) == 0) {
            int i = 0;
            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "\n", 1) == 0) {
                    break;
                }
                sscanf(line, "%s %s %d %d %d %d", resume->experience[i].title, resume->experience[i].company, &resume->experience[i].start_month, &resume->experience[i].start_year, &resume->experience[i].end_month, &resume->experience[i].end_year);
                i++;
            }
        }

        // Parse the skills
        else if (strncmp(line, "Skills:", 7) == 0) {
            int i = 0;
            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "\n", 1) == 0) {
                    break;
                }
                sscanf(line, "%s %d", resume->skill[i].name, &resume->skill[i].level);
                i++;
            }
        }
    }

    // Close the resume file
    fclose(fp);

    // Return the resume struct
    return resume;
}

// Function to print the resume
void print_resume(struct Resume* resume) {
    // Print the name
    printf("Name: %s %s\n", resume->name.first, resume->name.last);

    // Print the education
    printf("Education:\n");
    for (int i = 0; i < 5; i++) {
        if (resume->education[i].degree[0] != '\0') {
            printf(" - %s, %s, %d-%d\n", resume->education[i].degree, resume->education[i].school, resume->education[i].start_year, resume->education[i].end_year);
        }
    }

    // Print the experience
    printf("Experience:\n");
    for (int i = 0; i < 5; i++) {
        if (resume->experience[i].title[0] != '\0') {
            printf(" - %s, %s, %s-%s\n", resume->experience[i].title, resume->experience[i].company, resume->experience[i].start_month, resume->experience[i].start_year);
        }
    }

    // Print the skills
    printf("Skills:\n");
    for (int i = 0; i < 5; i++) {
        if (resume->skill[i].name[0] != '\0') {
            printf(" - %s, Level: %d\n", resume->skill[i].name, resume->skill[i].level);
        }
    }
}

// Main function
int main() {
    // Parse the resume file
    struct Resume* resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume struct
    free(resume);

    // Return 0 to indicate successful execution
    return 0;
}