//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILE_SIZE 1024

typedef struct Resume {
    char *name;
    char *email;
    char *phone_number;
    char *address;
    char *skills;
} Resume;

typedef struct Thread_Params {
    char *file_path;
    Resume *resume;
} Thread_Params;

void parse_resume_file(Thread_Params *params) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(params->file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name:")) {
            params->resume->name = line + 6;
        } else if (strstr(line, "Email:")) {
            params->resume->email = line + 7;
        } else if (strstr(line, "Phone Number:")) {
            params->resume->phone_number = line + 14;
        } else if (strstr(line, "Address:")) {
            params->resume->address = line + 9;
        } else if (strstr(line, "Skills:")) {
            params->resume->skills = line + 8;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main() {
    pthread_t threads[3];
    Thread_Params params[3];
    Resume resumes[3];

    params[0].file_path = "resume1.txt";
    params[0].resume = &resumes[0];
    pthread_create(&threads[0], NULL, (void*)parse_resume_file, (void*)&params[0]);

    params[1].file_path = "resume2.txt";
    params[1].resume = &resumes[1];
    pthread_create(&threads[1], NULL, (void*)parse_resume_file, (void*)&params[1]);

    params[2].file_path = "resume3.txt";
    params[2].resume = &resumes[2];
    pthread_create(&threads[2], NULL, (void*)parse_resume_file, (void*)&params[2]);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
        printf("Resume %d\n", i+1);
        printf("Name: %s", resumes[i].name);
        printf("Email: %s", resumes[i].email);
        printf("Phone Number: %s", resumes[i].phone_number);
        printf("Address: %s", resumes[i].address);
        printf("Skills: %s\n", resumes[i].skills);
    }

    return 0;
}