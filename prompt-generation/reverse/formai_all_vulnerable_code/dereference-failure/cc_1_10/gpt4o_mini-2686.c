//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "system.log"
#define SUSPICIOUS_PATTERNS 5

const char *patterns[SUSPICIOUS_PATTERNS] = {
    "failed password",
    "invalid user",
    "ssh",
    "root access",
    "suspicious login"
};

void check_for_intrusions(const char *line) {
    for(int i = 0; i < SUSPICIOUS_PATTERNS; i++) {
        if (strstr(line, patterns[i]) != NULL) {
            printf("Intrusion detected: %s\n", patterns[i]);
            return;
        }
    }
}

void monitor_log_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(fp, 0, SEEK_END); // Move to end of file
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET); // Move back to start of file
    
    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation failure");
        fclose(fp);
        return;
    }
    
    while (1) {
        size_t bytes_read = fread(buffer, 1, file_size, fp);
        buffer[bytes_read] = '\0'; // Null-terminate the string
        
        char *line = strtok(buffer, "\n");
        while (line != NULL) {
            check_for_intrusions(line);
            line = strtok(NULL, "\n");
        }

        fflush(fp); // Flush the stream
        sleep(10); // Pause for a while before checking again
        
        fseek(fp, 0, SEEK_END);
        long new_file_size = ftell(fp);
        if (new_file_size < file_size) {
            // Log file rotated or cleared, reset to start
            fseek(fp, 0, SEEK_SET);
            file_size = 0;
        } else {
            file_size = new_file_size;
        }
    }

    free(buffer);
    fclose(fp);
}

int main() {
    printf("Starting Intrusion Detection System...\n");
    monitor_log_file(LOG_FILE);
    
    return 0;
}