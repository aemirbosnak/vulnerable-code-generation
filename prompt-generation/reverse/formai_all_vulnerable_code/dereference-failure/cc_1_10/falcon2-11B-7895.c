//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

// Function to parse a resume
void parseResume(char* resume, char* output) {
    regex_t regex;
    regmatch_t match[100];
    int err;

    // Initialize the regular expression pattern
    char* pattern = "([a-zA-Z0-9\s\-\.]+)";
    regcomp(&regex, pattern, REG_EXTENDED);

    // Scan the resume for each match of the pattern
    err = regcomp(&regex, pattern, REG_EXTENDED);
    if (err!= 0) {
        printf("Error: %s\n", regerror(err, &regex, 0, NULL));
        return;
    }

    err = regexec(&regex, resume, 100, match, 0);
    if (err == 0) {
        int count = 0;
        char* line = (char*)malloc(sizeof(char) * 100);
        char* token = (char*)malloc(sizeof(char) * 100);

        for (int i = 0; i < 100; i++) {
            if (match[i].rm_so!= -1) {
                strcpy(line, resume + match[i].rm_so);
                line[match[i].rm_eo] = '\0';
                token = strtok(line, " ");
                while (token!= NULL) {
                    strcpy(output, token);
                    output[strlen(token)] = '\0';
                    token = strtok(NULL, " ");
                    count++;
                }
            }
        }

        free(line);
        free(token);
    }
    else {
        printf("Error: %s\n", regerror(err, &regex, 0, NULL));
    }

    regfree(&regex);
}

int main() {
    char resume[100] = "Name: John Doe\n\
Phone: 123-456-7890\n\
Email: johndoe@example.com\n\
Experience:\n\
1. Company X, Software Engineer (2015-2018)\n\
2. Company Y, Product Manager (2018-2020)\n\
Education:\n\
Bachelor of Science in Computer Science (2011-2015)\n\
Skills:\n\
C, Java, Python, SQL, Git";
    char output[100];
    parseResume(resume, output);
    printf("%s\n", output);
    return 0;
}