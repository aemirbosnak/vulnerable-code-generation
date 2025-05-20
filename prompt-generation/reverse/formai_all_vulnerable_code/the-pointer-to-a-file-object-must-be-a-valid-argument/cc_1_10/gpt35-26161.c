//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a C structure for Resume
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[50][100];
    char experience[50][100];
};

// Function to parse Resume
struct Resume parseResume(char* filename) {
    struct Resume resume;
    FILE* fp = fopen(filename, "r");
    char line[100];

    // Read each line of file and store in respective fields of structure
    while (fgets(line, 100, fp) != NULL) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", resume.name);
        }
        else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", resume.email);
        }
        else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", resume.phone);
        }
        else if (strstr(line, "Education:")) {
            sscanf(line, "Education: %[^\n]", resume.education[0]);
            int i = 1;
            while (fgets(line, 100, fp) != NULL && strstr(line, "-")) {
                sscanf(line, "- %[^\n]", resume.education[i++]);
            }
        }
        else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", resume.experience[0]);
            int i = 1;
            while (fgets(line, 100, fp) != NULL && strstr(line, "-")) {
                sscanf(line, "- %[^\n]", resume.experience[i++]);
            }
        }
    }

    fclose(fp);
    return resume;
}

// Function to print Resume
void printResume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);

    int i = 0;
    printf("Education:\n");
    while (strcmp(resume.education[i], "") != 0) {
        printf("- %s\n", resume.education[i++]);
    }

    i = 0;
    printf("Experience:\n");
    while (strcmp(resume.experience[i], "") != 0) {
        printf("- %s\n", resume.experience[i++]);
    }
}

// Driver function
int main() {
    struct Resume resume = parseResume("resume.txt");
    printResume(resume);
    return 0;
}