//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *first_name;
    char *last_name;
    char *email;
    char *phone_number;
    char *education;
    char *experience;
} Resume;

int main() {
    Resume *resume = malloc(sizeof(Resume));
    char buffer[1000];
    FILE *file;
    file = fopen("resume.txt", "r");

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "First Name")) {
            resume->first_name = strdup(strtok(buffer, ":"));
        }

        if (strstr(buffer, "Last Name")) {
            resume->last_name = strdup(strtok(buffer, ":"));
        }

        if (strstr(buffer, "Email")) {
            resume->email = strdup(strtok(buffer, ":"));
        }

        if (strstr(buffer, "Phone Number")) {
            resume->phone_number = strdup(strtok(buffer, ":"));
        }

        if (strstr(buffer, "Education")) {
            resume->education = strdup(strtok(buffer, ":"));
        }

        if (strstr(buffer, "Experience")) {
            resume->experience = strdup(strtok(buffer, ":"));
        }
    }

    fclose(file);

    printf("First Name: %s\n", resume->first_name);
    printf("Last Name: %s\n", resume->last_name);
    printf("Email: %s\n", resume->email);
    printf("Phone Number: %s\n", resume->phone_number);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);

    free(resume->first_name);
    free(resume->last_name);
    free(resume->email);
    free(resume->phone_number);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return 0;
}