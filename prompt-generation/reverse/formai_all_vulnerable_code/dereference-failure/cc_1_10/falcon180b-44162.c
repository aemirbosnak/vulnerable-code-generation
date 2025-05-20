//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 100
#define MAX_SECTIONS 10

struct section {
    char name[MAX_TOKEN_LEN];
    char data[MAX_TOKEN_LEN];
};

void tokenize(char* str, char* tokens[], int max_tokens) {
    int i = 0;
    char* token;
    token = strtok(str, " ");
    while (token!= NULL && i < max_tokens) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
}

void parse_section(char* line, struct section* section) {
    char* name;
    char* data;
    name = strtok(line, ":");
    data = strtok(NULL, ":");
    strcpy(section->name, name);
    strcpy(section->data, data);
}

int main() {
    FILE* fp;
    char line[MAX_TOKEN_LEN];
    char* tokens[MAX_TOKEN_LEN];
    struct section sections[MAX_SECTIONS];
    int num_sections = 0;
    int i;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        tokenize(line, tokens, MAX_TOKEN_LEN);
        if (strcmp(tokens[0], "Name") == 0) {
            strcpy(sections[num_sections].name, tokens[1]);
            strcpy(sections[num_sections].data, "");
            num_sections++;
        } else if (strcmp(tokens[0], "Education") == 0) {
            parse_section(line, &sections[num_sections]);
            num_sections++;
        } else if (strcmp(tokens[0], "Experience") == 0) {
            parse_section(line, &sections[num_sections]);
            num_sections++;
        }
    }

    fclose(fp);

    for (i = 0; i < num_sections; i++) {
        printf("Section Name: %s\n", sections[i].name);
        printf("Section Data: %s\n", sections[i].data);
        printf("\n");
    }

    return 0;
}