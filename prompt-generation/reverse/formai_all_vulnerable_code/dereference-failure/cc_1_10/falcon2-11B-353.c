//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to parse resume
void parse_resume(char* resume) {
    char* current_line = strtok(resume, "\n");
    char* current_word = strtok(NULL, " ");

    while (current_line!= NULL) {
        if (strcmp(current_word, "Name") == 0) {
            printf("Name: %s\n", current_word);
            current_word = strtok(NULL, " ");
        }
        else if (strcmp(current_word, "Email") == 0) {
            printf("Email: %s\n", current_word);
            current_word = strtok(NULL, " ");
        }
        else if (strcmp(current_word, "Phone") == 0) {
            printf("Phone: %s\n", current_word);
            current_word = strtok(NULL, " ");
        }
        else if (strcmp(current_word, "Address") == 0) {
            printf("Address: %s\n", current_word);
            current_word = strtok(NULL, " ");
        }
        else if (strcmp(current_word, "Skills") == 0) {
            printf("Skills: %s\n", current_word);
            current_word = strtok(NULL, " ");
        }

        current_line = strtok(NULL, "\n");
    }
}

// Function to read resume from file
void read_resume_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    char resume[10000];

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fgets(resume, 10000, file);
    fclose(file);

    parse_resume(resume);
}

// Function to print usage
void print_usage() {
    printf("Usage:./resume_parser <resume_file>\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    read_resume_from_file(argv[1]);

    return 0;
}