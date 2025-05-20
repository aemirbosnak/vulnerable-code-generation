//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 512

typedef struct {
    char *timestamp;
    char *source;
    char *message;
} log_entry;

void analyze_log(char *filename);
void get_next_line(FILE *file, char *line_buffer, size_t max_line_len);
log_entry parse_log_entry(char *log_line);
void print_log_summary(log_entry *log_entries, size_t num_entries);

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyze_log(argv[1]);
    return EXIT_SUCCESS;
}

void analyze_log(char *filename) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("Error opening log file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    size_t num_entries = 0;
    log_entry *log_entries = NULL;

    char line_buffer[MAX_LINE_LEN];
    while(!feof(file)) {
        get_next_line(file, line_buffer, MAX_LINE_LEN);
        if(line_buffer[0] != '\0') {
            log_entry entry = parse_log_entry(line_buffer);
            num_entries++;
            log_entries = realloc(log_entries, num_entries * sizeof(log_entry));
            log_entries[num_entries-1] = entry;
        }   
    }

    fclose(file);
    print_log_summary(log_entries, num_entries);
    free(log_entries);
}

void get_next_line(FILE *file, char *line_buffer, size_t max_line_len) {
    if(fgets(line_buffer, max_line_len, file)) {
        // Remove trailing newline character
        line_buffer[strcspn(line_buffer, "\r\n")] = '\0';
    }
}

log_entry parse_log_entry(char *log_line) {
    log_entry entry;
    char *timestamp = strtok(log_line, " ");
    entry.timestamp = strdup(timestamp);

    char *source = strtok(NULL, ":");
    entry.source = strdup(source);

    char *message = strtok(NULL, "\n");
    entry.message = strdup(message);

    return entry;
}

void print_log_summary(log_entry *log_entries, size_t num_entries) {
    printf("Log Summary:\n");
    printf("Total Entries: %zu\n", num_entries);

    for(size_t i = 0; i < num_entries; i++) {
        printf("Timestamp: %s, Source: %s, Message: %s\n", 
                    log_entries[i].timestamp,
                    log_entries[i].source,
                    log_entries[i].message);
    }
}