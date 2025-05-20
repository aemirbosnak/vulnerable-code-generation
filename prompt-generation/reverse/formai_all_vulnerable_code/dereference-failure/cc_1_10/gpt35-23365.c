//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void detect_intrusion(char *input_file_path, char *output_file_path) {
    FILE *input_file, *output_file;
    char buffer[BUFFER_SIZE];
    char *suspicious_keywords[] = {"rm", "cat", "su", "sudo", "dd", "wget"};
    int i, line_number = 1, flag = 0;

    input_file = fopen(input_file_path, "r");
    output_file = fopen(output_file_path, "w");

    if(!input_file) {
        printf("Error opening input file!");
        exit(EXIT_FAILURE);
    }

    if(!output_file) {
        printf("Error opening output file!");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, BUFFER_SIZE, input_file)) {
        for(i = 0; i < sizeof(suspicious_keywords)/sizeof(suspicious_keywords[0]); i++) {
            if(strstr(buffer, suspicious_keywords[i])) {
                fprintf(output_file, "Suspicious keyword '%s' found on line %d: %s", suspicious_keywords[i], line_number, buffer);
                flag = 1;
                break;
            }
        }

        line_number++;
    }

    if(flag) {
        printf("Intrusion detected and logged in %s", output_file_path);
    } else {
        printf("No intrusion detected.");
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char *input_file_path = "script.sh";
    char *output_file_path = "intrusion.log";

    detect_intrusion(input_file_path, output_file_path);

    return 0;
}