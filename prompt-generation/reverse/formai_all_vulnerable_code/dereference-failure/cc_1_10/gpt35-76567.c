//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char education[200];
    char experience[200];
};

struct resume* create_resume(char* name, char* email, char* education, char* experience);
void parse_resume(struct resume* r);
void print_resume(struct resume* r);

int main() {
    char name[50], email[50], education[200], experience[200];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your education: ");
    scanf(" %[^\n]s", education);
    printf("Enter your experience: ");
    scanf(" %[^\n]s", experience);

    struct resume* my_resume = create_resume(name, email, education, experience);
    parse_resume(my_resume);
    print_resume(my_resume);
    free(my_resume);
    return 0;
}

struct resume* create_resume(char* name, char* email, char* education, char* experience) {
    struct resume *r = malloc(sizeof(struct resume));
    strcpy(r->name, name);
    strcpy(r->email, email);
    strcpy(r->education, education);
    strcpy(r->experience, experience);
    return r;
}

void parse_resume(struct resume* r) {
    // implementation of resume parsing system goes here
    // for example, parsing education details
    char* pch = strstr(r->education, "degree");
    if (pch != NULL) {
        printf("Degree: %s\n", pch);
    }
}

void print_resume(struct resume* r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}