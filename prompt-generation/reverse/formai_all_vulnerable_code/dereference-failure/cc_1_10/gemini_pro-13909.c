//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of each log line
#define MAX_LOG_LINE_SIZE 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 1000

// Define the structure of a log line
typedef struct log_line {
    char *line;
    size_t size;
} log_line;

// Define the structure of the log analyzer
typedef struct log_analyzer {
    log_line *lines;
    size_t num_lines;
} log_analyzer;

// Function to create a new log analyzer
log_analyzer *log_analyzer_new() {
    log_analyzer *analyzer = malloc(sizeof(log_analyzer));
    if (analyzer == NULL) {
        return NULL;
    }

    analyzer->lines = malloc(sizeof(log_line) * MAX_LOG_LINES);
    if (analyzer->lines == NULL) {
        free(analyzer);
        return NULL;
    }

    analyzer->num_lines = 0;

    return analyzer;
}

// Function to free the memory allocated by a log analyzer
void log_analyzer_free(log_analyzer *analyzer) {
    for (size_t i = 0; i < analyzer->num_lines; i++) {
        free(analyzer->lines[i].line);
    }

    free(analyzer->lines);
    free(analyzer);
}

// Function to add a log line to the log analyzer
int log_analyzer_add_line(log_analyzer *analyzer, char *line, size_t size) {
    if (analyzer->num_lines >= MAX_LOG_LINES) {
        return -1;
    }

    analyzer->lines[analyzer->num_lines].line = malloc(size + 1);
    if (analyzer->lines[analyzer->num_lines].line == NULL) {
        return -1;
    }

    memcpy(analyzer->lines[analyzer->num_lines].line, line, size);
    analyzer->lines[analyzer->num_lines].line[size] = '\0';
    analyzer->lines[analyzer->num_lines].size = size;

    analyzer->num_lines++;

    return 0;
}

// Function to print the log analyzer to a file
int log_analyzer_print(log_analyzer *analyzer, FILE *file) {
    for (size_t i = 0; i < analyzer->num_lines; i++) {
        fprintf(file, "%s\n", analyzer->lines[i].line);
    }

    return 0;
}

// Function to analyze the log analyzer and print the results to a file
int log_analyzer_analyze(log_analyzer *analyzer, FILE *file) {
    // Count the number of occurrences of each unique IP address
    char *unique_ips[MAX_LOG_LINES];
    int ip_counts[MAX_LOG_LINES];
    int num_unique_ips = 0;

    for (size_t i = 0; i < analyzer->num_lines; i++) {
        char *ip_address = strtok(analyzer->lines[i].line, " ");

        int found = 0;
        for (int j = 0; j < num_unique_ips; j++) {
            if (strcmp(ip_address, unique_ips[j]) == 0) {
                ip_counts[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            unique_ips[num_unique_ips] = ip_address;
            ip_counts[num_unique_ips] = 1;
            num_unique_ips++;
        }
    }

    // Sort the unique IP addresses by the number of occurrences
    for (int i = 0; i < num_unique_ips - 1; i++) {
        for (int j = 0; j < num_unique_ips - i - 1; j++) {
            if (ip_counts[j] < ip_counts[j + 1]) {
                char *temp_ip = unique_ips[j];
                int temp_count = ip_counts[j];

                unique_ips[j] = unique_ips[j + 1];
                ip_counts[j] = ip_counts[j + 1];

                unique_ips[j + 1] = temp_ip;
                ip_counts[j + 1] = temp_count;
            }
        }
    }

    // Print the top 10 most frequent IP addresses
    fprintf(file, "Top 10 most frequent IP addresses:\n");
    for (int i = 0; i < 10 && i < num_unique_ips; i++) {
        fprintf(file, "%s: %d\n", unique_ips[i], ip_counts[i]);
    }

    return 0;
}

int main() {
    // Open the log file
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Create a new log analyzer
    log_analyzer *analyzer = log_analyzer_new();
    if (analyzer == NULL) {
        perror("log_analyzer_new");
        return EXIT_FAILURE;
    }

    // Read the log file line by line and add each line to the log analyzer
    char line[MAX_LOG_LINE_SIZE];
    while (fgets(line, MAX_LOG_LINE_SIZE, log_file) != NULL) {
        size_t size = strlen(line);
        if (size > 0 && line[size - 1] == '\n') {
            size--;
        }

        if (log_analyzer_add_line(analyzer, line, size) != 0) {
            perror("log_analyzer_add_line");
            return EXIT_FAILURE;
        }
    }

    // Close the log file
    fclose(log_file);

    // Open the output file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Print the log analyzer to the output file
    if (log_analyzer_print(analyzer, output_file) != 0) {
        perror("log_analyzer_print");
        return EXIT_FAILURE;
    }

    // Analyze the log analyzer and print the results to the output file
    if (log_analyzer_analyze(analyzer, output_file) != 0) {
        perror("log_analyzer_analyze");
        return EXIT_FAILURE;
    }

    // Close the output file
    fclose(output_file);

    // Free the memory allocated by the log analyzer
    log_analyzer_free(analyzer);

    return EXIT_SUCCESS;
}