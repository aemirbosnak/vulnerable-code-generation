//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[100];
    char phone[20];
    char skills[500];
    char experience[500];
    char education[200];
};

void parseResume(char* fileName, struct Resume *resume) {
    FILE* fp = fopen(fileName, "r");
    char buffer[1000];

    // read name
    fgets(buffer, sizeof(buffer), fp);
    strcpy(resume->name, buffer);

    // read email
    fgets(buffer, sizeof(buffer), fp);
    strcpy(resume->email, buffer);

    // read phone
    fgets(buffer, sizeof(buffer), fp);
    strcpy(resume->phone, buffer);

    // read skills
    fgets(buffer, sizeof(buffer), fp);
    strcpy(resume->skills, buffer);

    // read experience
    fgets(buffer, sizeof(buffer), fp);
    strcpy(resume->experience, buffer);

    // read education
    fgets(buffer, sizeof(buffer), fp);
    strcpy(resume->education, buffer);

    fclose(fp);
}

void printResume(struct Resume *resume) {
    printf("Name: %s", resume->name);
    printf("Email: %s", resume->email);
    printf("Phone: %s", resume->phone);
    printf("Skills: %s", resume->skills);
    printf("Experience: %s", resume->experience);
    printf("Education: %s", resume->education);
}

int main() {
    struct Resume resume;
    char fileName[20];

    printf("Enter file name: ");
    scanf("%s", fileName);

    parseResume(fileName, &resume);
    printResume(&resume);

    return 0;
}