//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    int num_skills;
    KeyValuePair skills[MAX_TOKENS];
} Person;

void add_skill(Person *person, char *skill) {
    if (person->num_skills >= MAX_TOKENS) {
        printf("Error: Too many skills.\n");
        return;
    }
    strcpy(person->skills[person->num_skills].key, skill);
    person->skills[person->num_skills].value = "";
    person->num_skills++;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    Person person = {0};

    file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, "\n");
        if (token == NULL)
            continue;
        if (strcasecmp(token, "Name:") == 0) {
            token = strtok(NULL, " ");
            strcpy(person.name, token);
        } else if (strcasecmp(token, "Email:") == 0) {
            token = strtok(NULL, " ");
            strcpy(person.email, token);
        } else if (strcasecmp(token, "Phone:") == 0) {
            token = strtok(NULL, " ");
            strcpy(person.phone, token);
        } else if (strcasecmp(token, "Address:") == 0) {
            token = strtok(NULL, " ");
            strcpy(person.address, token);
        } else if (strcasecmp(token, "Skills:") == 0) {
            token = strtok(NULL, " ");
            while (token!= NULL) {
                add_skill(&person, token);
                token = strtok(NULL, ", ");
            }
        }
    }

    fclose(file);

    printf("Name: %s\n", person.name);
    printf("Email: %s\n", person.email);
    printf("Phone: %s\n", person.phone);
    printf("Address: %s\n", person.address);
    printf("Skills:\n");
    for (int i = 0; i < person.num_skills; i++) {
        printf("%s: %s\n", person.skills[i].key, person.skills[i].value);
    }

    return 0;
}