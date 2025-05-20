//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to trim leading/trailing whitespace from a string
char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
        *end = '\0';
    }
    while (isspace(*str)) {
        str++;
    }
    return str;
}

// Function to parse a line of text as a name/value pair
void parse_line(char* line, char** name, char** value) {
    *name = strtok(line, ":");
    *value = strtok(NULL, ":");
}

// Function to print the contents of a resume
void print_resume(char* name, int age, char* education, char* experience) {
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);
}

// Function to parse a resume from a text file
void parse_resume_file(FILE* fp, void (*print_func)(char*, int, char*, char*)) {
    char line[MAX_LINE_LENGTH];
    char* name = NULL;
    char* value = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        parse_line(line, &name, &value);

        if (strcmp(name, "name") == 0) {
            print_func(value, 0, "", "");
        } else if (strcmp(name, "age") == 0) {
            print_func("", atoi(value), "", "");
        } else if (strcmp(name, "education") == 0) {
            print_func("", 0, value, "");
        } else if (strcmp(name, "experience") == 0) {
            print_func("", 0, "", value);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    void (*print_func)(char*, int, char*, char*) = &print_resume;
    parse_resume_file(fp, print_func);

    fclose(fp);
    return 0;
}