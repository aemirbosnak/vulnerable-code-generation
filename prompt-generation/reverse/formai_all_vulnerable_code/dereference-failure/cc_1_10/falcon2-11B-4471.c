//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char title[100];
    char company[100];
    char skills[100];
    char education[100];
} Resume;

Resume* parse_resume(char* resume) {
    Resume* r = (Resume*) malloc(sizeof(Resume));
    int i = 0;
    char* word = strtok(resume, " ");
    while (word!= NULL) {
        switch (i) {
            case 0:
                strcpy(r->name, word);
                break;
            case 1:
                strcpy(r->title, word);
                break;
            case 2:
                strcpy(r->company, word);
                break;
            case 3:
                strcpy(r->skills, word);
                break;
            case 4:
                strcpy(r->education, word);
                break;
            default:
                break;
        }
        word = strtok(NULL, " ");
        i++;
    }
    return r;
}

int main() {
    char* resume = "John Smith\tSoftware Engineer\tABC Corp\tC++, Java\tBachelor's Degree in Computer Science";
    Resume* r = parse_resume(resume);
    printf("Name: %s\n", r->name);
    printf("Title: %s\n", r->title);
    printf("Company: %s\n", r->company);
    printf("Skills: %s\n", r->skills);
    printf("Education: %s\n", r->education);
    free(r);
    return 0;
}