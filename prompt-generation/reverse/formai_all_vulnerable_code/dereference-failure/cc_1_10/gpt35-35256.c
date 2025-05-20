//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[12];
    char education[100];
    char work_experience[200];
};

int main() {
    int num_resumes;
    printf("Enter number of resumes: ");
    scanf("%d", &num_resumes);
    getchar();  // consume newline

    struct Resume *resumes = malloc(num_resumes * sizeof(struct Resume));

    printf("Enter resumes:\n");
    for (int i = 0; i < num_resumes; i++) {
        printf("---Resume %d---\n", i + 1);
        printf("Name: ");
        fgets(resumes[i].name, 50, stdin);
        printf("Email: ");
        fgets(resumes[i].email, 50, stdin);
        printf("Phone: ");
        fgets(resumes[i].phone, 12, stdin);
        printf("Education: ");
        fgets(resumes[i].education, 100, stdin);
        printf("Work Experience: ");
        fgets(resumes[i].work_experience, 200, stdin);
    }

    printf("Enter keyword to search for: ");
    char keyword[50];
    fgets(keyword, 50, stdin);
    strtok(keyword, "\n");  // remove newline from keyword

    printf("\nResults:\n");
    for (int i = 0; i < num_resumes; i++) {
        if (strstr(resumes[i].name, keyword) || strstr(resumes[i].email, keyword)
                || strstr(resumes[i].phone, keyword) || strstr(resumes[i].education, keyword)
                || strstr(resumes[i].work_experience, keyword)) {
            printf("---Resume %d---\n", i + 1);
            printf("Name: %s", resumes[i].name);
            printf("Email: %s", resumes[i].email);
            printf("Phone: %s", resumes[i].phone);
            printf("Education: %s", resumes[i].education);
            printf("Work Experience: %s", resumes[i].work_experience);
        }
    }

    free(resumes);
    return 0;
}