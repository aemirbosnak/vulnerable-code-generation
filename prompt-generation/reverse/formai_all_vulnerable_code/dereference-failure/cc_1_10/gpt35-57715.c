//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 1000

struct resume {
    char name[50];
    char email[50];
    char phone_number[20];
    char skills[100];
    char education[50];
};

// Function to load resumes from file
int load_resumes(FILE *file, struct resume resumes[]) {
    int count = 0;
    char line[256];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        // Split line into fields
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        char *phone_number = strtok(NULL, ",");
        char *skills = strtok(NULL, ",");
        char *education = strtok(NULL, ",");
        
        // Create resume
        struct resume r;
        strcpy(r.name, name);
        strcpy(r.email, email);
        strcpy(r.phone_number, phone_number);
        strcpy(r.skills, skills);
        strcpy(r.education, education);
        
        // Add resume to array
        resumes[count] = r;
        count++;
    }
    
    return count;
}

// Function to search for resumes by skill
void search_resumes(struct resume resumes[], int count, char *skill) {
    printf("Searching resumes for skill: %s\n", skill);
    
    for (int i = 0; i < count; i++) {
        char *tok = strtok(resumes[i].skills, ",");
        
        while (tok != NULL) {
            if (strcmp(tok, skill) == 0) {
                printf("%s - %s - %s\n", resumes[i].name, resumes[i].phone_number, resumes[i].email);
                break;
            }
            tok = strtok(NULL, ",");
        }
    }
}

int main() {
    // Open resumes file
    FILE *file = fopen("resumes.txt", "r");
    
    if (file == NULL) {
        printf("Error opening resumes file.\n");
        return 1;
    }
    
    // Load resumes into array
    struct resume resumes[MAX_RESUMES];
    int count = load_resumes(file, resumes);
    
    // Close file
    fclose(file);
    
    // Search for resumes by skill
    char skill[50];
    printf("Enter skill to search for: ");
    scanf("%s", skill);
    search_resumes(resumes, count, skill);
    
    return 0;
}