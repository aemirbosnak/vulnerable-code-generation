//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char **skills;
    char *education;
    char *experience;
} Resume;

typedef struct Node {
    Resume *data;
    struct Node *next;
} Node;

Node* createNode(Resume *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(Node **head, Resume *data) {
    Node *newNode = createNode(data);
    Node **last = head;
    while (*last != NULL) {
        last = &((*last)->next);
    }
    *last = newNode;
}

void printSkills(char **skills) {
    printf("Skills: ");
    for (int i = 0; i < sizeof(*skills); i++) {
        printf("%s, ", *(skills + i));
    }
    printf("\n");
}

void printResume(Resume *resume) {
    printf("\nName: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printSkills(resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

void printList(Node *head) {
    while (head != NULL) {
        printResume(head->data);
        head = head->next;
    }
}

void freeResume(Resume *resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume);
}

void freeList(Node **head) {
    while (*head != NULL) {
        Node *nextNode = (*head)->next;
        freeResume((*head)->data);
        free(*head);
        *head = nextNode;
    }
}

#define DELIMITER ";"
#define MAX_LENGTH 1000

void parseFile(char *filename, Node **head) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file)) {
        // Remove newline at end of line
        line[strcspn(line, "\n")] = '\0';

        char *name, *email, *phone, *address, *education, *experience;
        char **skills = (char**) malloc(10 * sizeof(char*));

        // Parse line and set variables
        name = strtok(line, DELIMITER);
        email = strtok(NULL, DELIMITER);
        phone = strtok(NULL, DELIMITER);
        address = strtok(NULL, DELIMITER);
        char *skillsString = strtok(NULL, DELIMITER);
        education = strtok(NULL, DELIMITER);
        experience = strtok(NULL, DELIMITER);

        // Parse skills string
        int i = 0;
        char *skill = strtok(skillsString, ",");
        while (skill != NULL) {
            *(skills + i) = skill;
            skill = strtok(NULL, ",");
            i++;
        }

        // Create resume and insert into linked list
        Resume *resume = (Resume*) malloc(sizeof(Resume));
        resume->name = strdup(name);
        resume->email = strdup(email);
        resume->phone = strdup(phone);
        resume->address = strdup(address);
        resume->skills = skills;
        resume->education = strdup(education);
        resume->experience = strdup(experience);
        insert(head, resume);
    }

    fclose(file);
}

int main() {
    Node *head = NULL;
    parseFile("resumes.txt", &head);
    printList(head);
    freeList(&head);
    return 0;
}