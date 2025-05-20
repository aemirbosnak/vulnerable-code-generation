//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone_number[20];
    char address[100];
    char education[100];
    char experience[100];
    char skills[100];
};

void parse_resume(struct Resume* res) {
    char* buffer = (char*)malloc(255 * sizeof(char));
    FILE* file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Failed to open resume file.\n");
        exit(EXIT_FAILURE);
    }

    // Read name
    fgets(buffer, 255, file);
    strcpy(res->name, buffer);

    // Read email
    fgets(buffer, 255, file);
    strcpy(res->email, buffer);

    // Read phone number
    fgets(buffer, 255, file);
    strcpy(res->phone_number, buffer);

    // Read address
    fgets(buffer, 255, file);
    strcpy(res->address, buffer);

    // Read education
    fgets(buffer, 255, file);
    strcpy(res->education, buffer);

    // Read experience
    fgets(buffer, 255, file);
    strcpy(res->experience, buffer);

    // Read skills
    fgets(buffer, 255, file);
    strcpy(res->skills, buffer);

    fclose(file);
    free(buffer);
}

int main() {
    struct Resume res;
    parse_resume(&res);

    printf("Name: %s", res.name);
    printf("Email: %s", res.email);
    printf("Phone Number: %s", res.phone_number);
    printf("Address: %s", res.address);
    printf("Education: %s", res.education);
    printf("Experience: %s", res.experience);
    printf("Skills: %s", res.skills);

    return 0;
}