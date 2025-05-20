//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char title[50];
    char company[50];
    int years_experience;
    char skills[100][20];
} Resume;

void parse_resume(char* line) {
    Resume* current_resume = malloc(sizeof(Resume));
    char field[20], value[100];
    char* token;

    strcpy(current_resume->name, "Sir Unknown of Nowhere");
    strcpy(current_resume->title, "Knight Errant");
    strcpy(current_resume->company, "King's Court");
    current_resume->years_experience = 0;

    token = strtok(line, ": ");
    strcpy(field, token);

    while (token != NULL) {
        token = strtok(NULL, ": ");
        strcpy(value, token);

        if (strcmp(field, "Name") == 0) {
            strcpy(current_resume->name, value);
        } else if (strcmp(field, "Title") == 0) {
            strcpy(current_resume->title, value);
        } else if (strcmp(field, "Company") == 0) {
            strcpy(current_resume->company, value);
        } else if (strcmp(field, "Experience") == 0) {
            current_resume->years_experience = atoi(value);
        } else if (strcmp(field, "Skills") == 0) {
            int i = 0;
            token = strtok(value, ",");

            while (token != NULL) {
                strcpy(current_resume->skills[i], token);
                i++;
                token = strtok(NULL, ",");
            }
        }

        token = strtok(NULL, ": ");
        strcpy(field, token);
    }

    printf("Name: %s\n", current_resume->name);
    printf("Title: %s\n", current_resume->title);
    printf("Company: %s\n", current_resume->company);
    printf("Years of Experience: %d\n", current_resume->years_experience);
    printf("Skills:\n");

    for (int i = 0; i < 10; i++) {
        printf("- %s\n", current_resume->skills[i]);
    }

    free(current_resume);
}

int main() {
    char line[200] = "Name: Sir Lancelot of Camelot, Title: Knight, Company: King Arthur's Court, Experience: 10, Skills: Swordfighting, Chivalry, Horseback Riding, Diplomacy, Archery, Languages: French, Latin, Old English";

    parse_resume(line);

    return 0;
}