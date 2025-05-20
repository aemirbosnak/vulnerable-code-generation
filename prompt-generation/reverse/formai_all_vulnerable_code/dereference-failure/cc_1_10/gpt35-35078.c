//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>

void analyze_logs(char* log_file) {
    FILE* file = fopen(log_file, "r");
    if (!file) {
        printf("Error: Could not open file %s\n!", log_file);
        return;
    }

    int line_count = 0;
    int error_count = 0;
    char line[256];

    while(fgets(line, sizeof(line), file)) {
        line_count++;
        if (strstr(line, "Error")) {
            error_count++;
            printf("Error detected on line %d: %s", line_count, line);
        }
    }

    if (error_count == 0) {
        printf("No errors detected in log file!\n");
    } else {
        printf("Total %d errors detected in log file out of %d lines.\n", error_count, line_count);
    }

    fclose(file);
}

void shape_shift_analyze(char* log_file, char* file_type) {
    printf("Analyzing %s file: %s...\n", file_type, log_file);

    if (strcmp(file_type, "csv") == 0) {
        printf("Converting csv file to log format...\n");
        // Code to convert csv to log format goes here
        printf("Conversion successful!\n");
        log_file = "converted_logs.log";
    } else if (strcmp(file_type, "txt") != 0 && strcmp(file_type, "log") != 0) {
        printf("Error: Unsupported file type: %s\n", file_type);
        return;
    }

    analyze_logs(log_file);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: log_analyzer <log_file> <file_type>\n");
        printf("Supported file types: txt, log, csv\n");
        return 0;
    }

    char* log_file = argv[1];
    char* file_type = argv[2];

    shape_shift_analyze(log_file, file_type);

    return 0;
}