//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone_number;
    char *education;
    char *experience;
    int clubs;
} Resume;

char *parse_resume(char *filename);
int detect_clubs(char *experience);

int main() {
    char *filename = "resume.txt";
    char *resume_contents = parse_resume(filename);

    Resume *my_resume = (Resume*) malloc(sizeof(Resume));

    char *line;
    char *key = "name: ";
    line = strstr(resume_contents, key);
    line = line + strlen(key);
    int length = strcspn(line, "\n");
    my_resume->name = (char*) malloc(length+1);
    strncpy(my_resume->name, line, length);

    key = "email: ";
    line = strstr(resume_contents, key);
    line = line + strlen(key);
    length = strcspn(line, "\n");
    my_resume->email = (char*) malloc(length+1);
    strncpy(my_resume->email, line, length);
    
    key = "phone number: ";
    line = strstr(resume_contents, key);
    line = line + strlen(key);
    length = strcspn(line, "\n");
    my_resume->phone_number = (char*) malloc(length+1);
    strncpy(my_resume->phone_number, line, length);

    key = "education: ";
    line = strstr(resume_contents, key);
    line = line + strlen(key);
    length = strcspn(line, "\n");
    my_resume->education = (char*) malloc(length+1);
    strncpy(my_resume->education, line, length);

    key = "experience: ";
    line = strstr(resume_contents, key);
    line = line + strlen(key);
    length = strcspn(line, "\n");
    my_resume->experience = (char*) malloc(length+1);
    strncpy(my_resume->experience, line, length);

    my_resume->clubs = detect_clubs(my_resume->experience);

    printf("Name: %s\nEmail: %s\nPhone Number: %s\nEducation: %s\nExperience: %s\nClubs: %d\n",
        my_resume->name, my_resume->email, my_resume->phone_number, my_resume->education, my_resume->experience, my_resume->clubs);

    free(my_resume->name);
    free(my_resume->email);
    free(my_resume->phone_number);
    free(my_resume->education);
    free(my_resume->experience);
    free(my_resume);
}

char *parse_resume(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *contents = (char*) malloc(1);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        contents = (char*) realloc(contents, strlen(contents) + strlen(line) + 1);
        strcat(contents, line);
    }

    if (line) {
        free(line);
    }

    fclose(fp);

    return contents;
}

int detect_clubs(char *experience) {
    int num_clubs = 0;

    char *ptr = strstr(experience, "club");
    while (ptr != NULL) {
        num_clubs++;
        ptr = strstr(ptr + 1, "club");
    }

    return num_clubs;
}