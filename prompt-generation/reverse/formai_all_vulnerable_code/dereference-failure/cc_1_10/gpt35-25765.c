//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume{
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char skills[500];
};

// Function to parse resume file and populate the structure
void parse_resume_file(char *filename, struct resume *res){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if(strncmp(line, "Name:", 5) == 0){
            strcpy(res->name, line+6);
            count++;
        }
        if(strncmp(line, "Email:", 6) == 0){
            strcpy(res->email, line+7);
            count++;
        }
        if(strncmp(line, "Phone:", 6) == 0){
            strcpy(res->phone, line+7);
            count++;
        }
        if(strncmp(line, "Education:", 10) == 0){
            strcpy(res->education, line+11);
            count++;
        }
        if(strncmp(line, "Skills:", 7) == 0){
            strcpy(res->skills, line+8);
            count++;
        }
    }

    if(count != 5){
        printf("Error parsing resume file!\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    if (line)
        free(line);
}

// Function to print the contents of the structure
void print_resume_data(struct resume *res){
    printf("Name: %s", res->name);
    printf("Email: %s", res->email);
    printf("Phone: %s", res->phone);
    printf("Education: %s", res->education);
    printf("Skills: %s", res->skills);
}

int main(int argc, char *argv[]){
    struct resume res;

    if(argc < 2){
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    parse_resume_file(argv[1], &res);

    print_resume_data(&res);

    return 0;
}