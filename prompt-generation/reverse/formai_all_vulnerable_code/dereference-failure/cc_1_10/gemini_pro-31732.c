//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct _Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    char *skills;
    char *education;
    char *work;
} Resume;

typedef struct _Node {
    Resume *resume;
    struct _Node *next;
} Node;

Node *root = NULL;

int add_resume(Resume *resume) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        return -1;
    }

    new_node->resume = resume;
    new_node->next = NULL;

    if (!root) {
        root = new_node;
    } else {
        Node *current = root;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    return 0;
}

int print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n\n", resume->address);

    printf("Summary\n");
    printf("-------\n");
    printf("%s\n\n", resume->summary);

    printf("Skills\n");
    printf("------\n");
    printf("%s\n\n", resume->skills);

    printf("Education\n");
    printf("---------\n");
    printf("%s\n\n", resume->education);

    printf("Work\n");
    printf("----\n");
    printf("%s\n", resume->work);

    return 0;
}

int parse_resume(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    Resume *resume = (Resume *)malloc(sizeof(Resume));
    if (!resume) {
        fclose(fp);
        return -1;
    }

    memset(resume, 0, sizeof(Resume));

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "Address:", 8) == 0) {
            resume->address = strdup(line + 8);
        } else if (strncmp(line, "Summary:", 8) == 0) {
            resume->summary = strdup(line + 8);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "Education:", 10) == 0) {
            resume->education = strdup(line + 10);
        } else if (strncmp(line, "Work:", 5) == 0) {
            resume->work = strdup(line + 5);
        }
    }

    fclose(fp);

    if (add_resume(resume) == -1) {
        free(resume->name);
        free(resume->email);
        free(resume->phone);
        free(resume->address);
        free(resume->summary);
        free(resume->skills);
        free(resume->education);
        free(resume->work);
        free(resume);

        return -1;
    }

    return 0;
}

int main() {
    if (parse_resume("resume.txt") == -1) {
        printf("Error parsing resume\n");
        return 1;
    }

    Node *current = root;
    while (current) {
        print_resume(current->resume);
        current = current->next;
    }

    return 0;
}