//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *city;
    char *state;
    char *zip;
} Applicant;

void printApplicant(Applicant a) {
    printf("Name: %s\n", a.name);
    printf("Email: %s\n", a.email);
    printf("Phone: %s\n", a.phone);
    printf("City: %s\n", a.city);
    printf("State: %s\n", a.state);
    printf("Zip Code: %s\n", a.zip);
}

int main() {
    char resume[1000] = "John Smith\njohn.smith@email.com\n(123) 456-7890\nSan Francisco\nCA\n94109";
    Applicant a;
    char *ptr;

    ptr = strtok(resume, "\n");
    a.name = (char*)malloc(strlen(ptr)+1);
    strcpy(a.name, ptr);

    ptr = strtok(NULL, "\n");
    a.email = (char*)malloc(strlen(ptr)+1);
    strcpy(a.email, ptr);

    ptr = strtok(NULL, "\n");
    a.phone = (char*)malloc(strlen(ptr)+1);
    strcpy(a.phone, ptr);

    ptr = strtok(NULL, "\n");
    a.city = (char*)malloc(strlen(ptr)+1);
    strcpy(a.city, ptr);

    ptr = strtok(NULL, "\n");
    a.state = (char*)malloc(strlen(ptr)+1);
    strcpy(a.state, ptr);

    ptr = strtok(NULL, "\n");
    a.zip = (char*)malloc(strlen(ptr)+1);
    strcpy(a.zip, ptr);

    printApplicant(a);

    free(a.name);
    free(a.email);
    free(a.phone);
    free(a.city);
    free(a.state);
    free(a.zip);

    return 0;
}