//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Resume {
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    struct Resume *next;
} Resume;

void parseLine(char *line, Resume *resume) {
    char key[20];
    char value[100];
    int len = 0;
    int i = 0;

    while (isspace(*line)) line++;

    if (*line == ':') {
        strncpy(key, line, 19);
        key[19] = '\0';
        line += strlen(key) + 1;

        while (*line && !isspace(*line)) {
            value[i++] = *line++;
        }

        value[i] = '\0';

        switch (strcmp(key, "Name")) {
            case 0: strcpy(resume->name, value); break;
            case 1: strcpy(resume->phone, value); break;
            case 2: strcpy(resume->email, value); break;
            case 3: strcpy(resume->address, value); break;
            default:;
        }

        len += strlen(key) + strlen(value) + 2;
    } else if (len < 100) {
        strncat(resume->address, line, 100 - strlen(resume->address) - len);
    }
}

int main() {
    char line[256];
    Resume *resume = NULL;
    int done = 0;

    while (!done) {
        printf("Enter resume data (q to quit):\n");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "q") == 0) {
            done = 1;
            continue;
        }

        Resume *newResume = (Resume *)calloc(1, sizeof(Resume));
        parseLine(line, newResume);

        if (resume == NULL) {
            resume = newResume;
        } else {
            Resume *current = resume;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newResume;
        }

        printf("Successfully parsed: %s\n", line);
    }

    Resume *current = resume;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone: %s\n", current->phone);
        printf("Email: %s\n", current->email);
        printf("Address: %s\n", current->address);
        current = current->next;
    }

    while (resume != NULL) {
        Resume *temp = resume;
        resume = resume->next;
        free(temp);
    }

    return 0;
}