//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    struct Resume *next;
} Resume;

void parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    Resume *head = NULL;
    Resume *curr = NULL;

    char line[255];
    while (fgets(line, 255, fp) != NULL) {
        char *name = strchr(line, ':');
        char *value = strchr(line, ':') + 1;

        if (name && value) {
            if (curr == NULL) {
                head = curr = malloc(sizeof(Resume));
            } else {
                curr = curr->next = malloc(sizeof(Resume));
                curr = curr->next;
            }

            curr->name = strdup(name);
            curr->email = strdup(value);
            curr->phone = NULL;
            curr->address = NULL;
            curr->summary = NULL;
        }
    }

    fclose(fp);
    curr = head;
    while (curr) {
        printf("%s: %s\n", curr->name, curr->email);
        curr = curr->next;
    }
}

int main() {
    parse_resume("resume.txt");
    return 0;
}