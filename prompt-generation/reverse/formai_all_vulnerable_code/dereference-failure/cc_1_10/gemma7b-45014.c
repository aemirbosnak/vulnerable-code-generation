//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
} Resume;

int main() {
    char resume_data[] = "John Doe\njohn.doe@gmail.com\n123 Main St.\nAnytown, CA 12345\n\nJane Doe\njane.doe@gmail.com\n456 Oak Ave.\nNew York, NY 67890";

    Resume *resumes = (Resume *)malloc(sizeof(Resume) * 2);

    int num_resumes = 0;

    char *line = strtok(resume_data, "\n");

    while (line) {
        if (num_resumes == 0) {
            strcpy(resumes[num_resumes].name, line);
        } else if (num_resumes == 1) {
            strcpy(resumes[num_resumes].email, line);
        } else if (num_resumes == 2) {
            strcpy(resumes[num_resumes].phone, line);
        } else if (num_resumes == 3) {
            strcpy(resumes[num_resumes].address, line);
        }

        num_resumes++;

        line = strtok(NULL, "\n");
    }

    for (int i = 0; i < num_resumes; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Address: %s\n", resumes[i].address);
        printf("\n");
    }

    free(resumes);

    return 0;
}