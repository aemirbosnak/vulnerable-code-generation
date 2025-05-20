//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 50
#define MAX_SKILLS 20
#define MAX_EXPERIENCES 20

typedef struct {
    char first_name[20];
    char last_name[20];
    char email[50];
    char phone[20];
    char address[100];
    char summary[200];
    char skills[MAX_SKILLS][50];
    char experiences[MAX_EXPERIENCES][200];
    int num_skills;
    int num_experiences;
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

void parse_resume(char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    char line[200];
    int i = 0;

    while (fgets(line, 200, file)) {
        //Parse first name
        if (strstr(line, "First Name:")) {
            sscanf(line, "First Name: %s", resume->first_name);
        }
        //Parse last name
        else if (strstr(line, "Last Name:")) {
            sscanf(line, "Last Name: %s", resume->last_name);
        }
        //Parse email
        else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %s", resume->email);
        }
        //Parse phone number
        else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %s", resume->phone);
        }
        //Parse address
        else if (strstr(line, "Address:")) {
            sscanf(line, "Address: %[^\n]", resume->address);
        }
        //Parse summary
        else if (strstr(line, "Summary:")) {
            sscanf(line, "Summary: %[^\n]", resume->summary);
        }
        //Parse skills
        else if (strstr(line, "Skills:")) {
            char *skill = strtok(line, ",");
            while (skill != NULL) {
                strcpy(resume->skills[i], skill);
                i++;
                skill = strtok(NULL, ",");
            }
            resume->num_skills = i;
            i = 0;
        }
        //Parse experiences
        else if (strstr(line, "Experience:")) {
            char *experience = strtok(line, ",");
            while (experience != NULL) {
                strcpy(resume->experiences[i], experience);
                i++;
                experience = strtok(NULL, ",");
            }
            resume->num_experiences = i;
            i = 0;
        }
    }

    fclose(file);
}

void add_resume() {
    Resume resume;
    char filename[50];

    printf("Enter the name of the file containing the resume: ");
    scanf("%s", filename);

    parse_resume(filename, &resume);

    resumes[num_resumes] = resume;
    num_resumes++;

    printf("Resume added successfully!\n\n");
}

void print_resume(Resume *resume) {
    printf("Name: %s %s\n", resume->first_name, resume->last_name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Summary: %s\n", resume->summary);
    printf("Skills: ");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("%s", resume->skills[i]);
        if (i != resume->num_skills - 1) {
            printf(", ");
        }
    }
    printf("\nExperiences:\n");
    for (int i = 0; i < resume->num_experiences; i++) {
        printf("%s\n", resume->experiences[i]);
    }
    printf("\n");
}

void view_all_resumes() {
    if (num_resumes == 0) {
        printf("No resumes available.\n\n");
        return;
    }

    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i + 1);
        print_resume(&resumes[i]);
    }
}

void search_resume() {
    char keyword[50];
    int matches = 0;

    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_resumes; i++) {
        if (strstr(resumes[i].summary, keyword)) {
            printf("Match found in Resume %d:\n", i + 1);
            print_resume(&resumes[i]);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add new resume\n");
        printf("2. View all resumes\n");
        printf("3. Search for resumes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_resume();
                break;
            case 2:
                view_all_resumes();
                break;
            case 3:
                search_resume();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}