//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *log_file_path;
    int threshold;
    char *exclude_string;
    char *output_file_path;
} Config;

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

void log(LogLevel level, char *message) {
    switch(level) {
        case INFO:
            printf("[INFO] %s\n", message);
            break;
        case WARNING:
            printf("[WARNING] %s\n", message);
            break;
        case ERROR:
            printf("[ERROR] %s\n", message);
            break;
        default:
            break;
    }
}

void process_log_file(Config *config) {
    FILE *log_file = fopen(config->log_file_path, "r");
    FILE *output_file = fopen(config->output_file_path, "w");

    if(!log_file) {
        log(ERROR, "Could not open log file.");
        exit(1);
    }

    if(!output_file) {
        log(ERROR, "Could not create output file.");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int line_num = 0;

    while(fgets(line, MAX_LINE_SIZE, log_file) != NULL) {
        line_num++;

        // Check if line contains exclude string
        if(strstr(line, config->exclude_string) != NULL) {
            log(INFO, "Exclude string found in line.");
            continue;
        }

        // Check if line contains ERROR keyword
        if(config->threshold >= ERROR && strstr(line, "ERROR") != NULL) {
            fprintf(output_file, "[ERROR] Line %d: %s", line_num, line);
            continue;
        }

        // Check if line contains WARNING keyword
        if(config->threshold >= WARNING && strstr(line, "WARNING") != NULL) {
            fprintf(output_file, "[WARNING] Line %d: %s", line_num, line);
            continue;
        }

        // Check if line contains INFO keyword
        if(config->threshold >= INFO && strstr(line, "INFO") != NULL) {
            fprintf(output_file, "[INFO] Line %d: %s", line_num, line);
            continue;
        }
    }

    fclose(log_file);
    fclose(output_file);

    log(INFO, "Log analysis complete.");
}

int main(int argc, char *argv[]) {
    Config config;

    // Default config values
    config.log_file_path = "./app.log";
    config.threshold = ERROR;
    config.exclude_string = "";
    config.output_file_path = "./output.log";

    // Override config values with command line arguments
    if(argc > 1) {
        config.log_file_path = argv[1];
    }
    if(argc > 2) {
        config.threshold = atoi(argv[2]);
    }
    if(argc > 3) {
        config.exclude_string = argv[3];
    }
    if(argc > 4) {
        config.output_file_path = argv[4];
    }

    log(INFO, "Starting log analysis...");

    process_log_file(&config);

    return 0;
}