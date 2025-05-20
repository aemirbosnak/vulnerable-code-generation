//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100

struct keyword {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
};

struct keyword keywords[] = {
    {"name", "John Doe"},
    {"age", "30"},
    {"email", "john.doe@gmail.com"},
    {"phone", "555-555-5555"},
    {"address", "123 Main St"},
    {"education", "Bachelor's Degree in Computer Science"},
    {"experience", "5 years in software development"}
};

int num_keywords = sizeof(keywords) / sizeof(struct keyword);

struct keyword *find_keyword(char *name) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strcmp(keywords[i].name, name) == 0) {
            return &keywords[i];
        }
    }
    return NULL;
}

void parse_line(char *line, struct keyword *keyword) {
    char *value;
    value = strchr(line, ':');
    if (value!= NULL) {
        value++;
        strncpy(keyword->value, value, MAX_VALUE_LEN);
    } else {
        strncpy(keyword->value, "", MAX_VALUE_LEN);
    }
}

void print_keywords(FILE *output, struct keyword *keywords) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        fprintf(output, "%s: %s\n", keywords[i].name, keywords[i].value);
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char line[MAX_LINE];
    struct keyword *keyword;
    input = fopen("resume.txt", "r");
    output = fopen("parsed_resume.txt", "w");
    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fgets(line, MAX_LINE, input)!= NULL) {
        keyword = find_keyword(line);
        if (keyword!= NULL) {
            parse_line(line, keyword);
            fprintf(output, "%s\n", keyword->value);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}