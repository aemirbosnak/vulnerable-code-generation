//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELDS 20

// Define the structure for each field in the resume
typedef struct {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} Field;

// Define the structure for the resume
typedef struct {
    int num_fields;
    Field fields[MAX_FIELDS];
} Resume;

// Function to read a line of text from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to split a line of text into fields
int split_line(char* line, Field* fields) {
    int num_fields = 0;
    char* start = line;
    while (num_fields < MAX_FIELDS && start!= NULL) {
        char* end = strchr(start, ':');
        if (end!= NULL) {
            strncpy(fields[num_fields].name, start, end - start);
            fields[num_fields].value[0] = '\0';
            strncat(fields[num_fields].value, end + 1, MAX_LINE_LENGTH - (end + 1 - fields[num_fields].name));
            num_fields++;
            start = end + 1;
        } else {
            break;
        }
    }
    return num_fields;
}

// Function to parse a resume from a file
Resume* parse_resume(FILE* file) {
    Resume* resume = malloc(sizeof(Resume));
    resume->num_fields = 0;
    char* line = read_line(file);
    while (line!= NULL) {
        int num_fields = split_line(line, resume->fields);
        resume->num_fields += num_fields;
        line = read_line(file);
    }
    return resume;
}

// Function to print a resume
void print_resume(Resume* resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

// Main function to run the program
int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    Resume* resume = parse_resume(file);
    fclose(file);
    print_resume(resume);
    free(resume);
    return 0;
}