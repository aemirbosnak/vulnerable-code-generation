//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 256
#define MAX_SKILLS 50

void extractInfo(const char *line, const char *pattern, char *buffer) {
    regex_t regex;
    regmatch_t matches[2]; // To hold the start and end of the match

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    // Execute regex
    if (regexec(&regex, line, 2, matches, 0) == 0) {
        // If we match, copy the match to buffer
        strncpy(buffer, line + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
        buffer[matches[0].rm_eo - matches[0].rm_so] = '\0'; // Null terminate the string
    }

    regfree(&regex);
}

void parseResume(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];

    // Variables to store extracted information
    char name[MAX_LINE_LENGTH] = "", email[MAX_LINE_LENGTH] = "", phone[MAX_LINE_LENGTH] = "", skills[MAX_SKILLS][MAX_LINE_LENGTH];
    int skillCount = 0;

    const char *namePattern = "Name: (.*)";
    const char *emailPattern = "Email: ([^ ]+)";
    const char *phonePattern = "Phone: ([0-9\\-\\+ ]+)";
    const char *skillsPattern = "Skills: (.*)";

    while (fgets(line, sizeof(line), file)) {
        // Extract the name
        extractInfo(line, namePattern, name);
        // Extract the email
        extractInfo(line, emailPattern, email);
        // Extract the phone number
        extractInfo(line, phonePattern, phone);
        // Extract the skills
        if (strstr(line, "Skills: ")) {
            char *token = strtok(line + 8, ", ");
            while (token != NULL && skillCount < MAX_SKILLS) {
                strcpy(skills[skillCount++], token);
                token = strtok(NULL, ", ");
            }
        }
    }

    fclose(file);

    // Print extracted information
    printf("Extracted Resume Information:\n");
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Skills:\n");
    
    for (int i = 0; i < skillCount; i++) {
        printf(" - %s\n", skills[i]);
    }
}

int main() {
    const char *filename = "resume.txt"; // Ensure you have this text file in the same directory
    parseResume(filename);
    return 0;
}