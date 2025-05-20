//FormAI DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while(end > str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

int main() {
    FILE* log_file = fopen("example_log_file.log", "r");
    if(log_file == NULL) {
        printf("Error opening log file!\n");
        return 1;
    }

    char line[MAX_LINE_LEN];
    int line_count = 0;
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;

    printf("\n\nGrateful greetings, dear developer! I am your trusty log analysis program.\n\n");

    while(fgets(line, MAX_LINE_LEN, log_file)) {
        line_count++;
        trim(line);

        if(strstr(line, "ERROR")) {
            error_count++;
            printf("Line %d: Error: %s\n", line_count, line);
        }
        else if(strstr(line, "WARNING")) {
            warning_count++;
            printf("Line %d: Warning: %s\n", line_count, line);
        }
        else if(strstr(line, "INFO")) {
            info_count++;
            printf("Line %d: Info: %s\n", line_count, line);
        }
    }

    printf("\n\nAnalysis complete! Here's what I found:\n\n");
    printf("Total number of lines in log file: %d\n", line_count);
    printf("Number of errors: %d\n", error_count);
    printf("Number of warnings: %d\n", warning_count);
    printf("Number of info messages: %d\n", info_count);

    printf("\n\nI hope this analysis has been helpful! Have a wonderful day, dear developer!\n\n");

    fclose(log_file);
    return 0;
}