//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MIN_RESPONSE_TIME 500
#define MAX_RESPONSE_TIME 3000

struct log_entry {
    char *request;
    int response_code;
    double response_time;
};

void parse_log_line(char *line, struct log_entry *entry);
void calculate_satisfaction_rate(struct log_entry *entries, int num_entries);
void print_satisfaction_report(struct log_entry *entries, int num_entries);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char *log_file = argv[1];
    FILE *log_file_ptr = fopen(log_file, "r");
    if (log_file_ptr == NULL) {
        printf("Error: unable to open log file %s\n", log_file);
        return 2;
    }

    struct log_entry *entries = calloc(1, sizeof(struct log_entry));
    int num_entries = 0;

    while (fgets(entries[num_entries].request, MAX_LINE_LENGTH, log_file_ptr) != NULL) {
        parse_log_line(entries[num_entries].request, &entries[num_entries]);
        num_entries++;
    }

    calculate_satisfaction_rate(entries, num_entries);
    print_satisfaction_report(entries, num_entries);

    fclose(log_file_ptr);
    free(entries);

    return 0;
}

void parse_log_line(char *line, struct log_entry *entry) {
    char *request = strtok(line, " ");
    int response_code = atoi(strtok(NULL, " "));
    double response_time = atof(strtok(NULL, "\n"));

    entry->request = request;
    entry->response_code = response_code;
    entry->response_time = response_time;
}

void calculate_satisfaction_rate(struct log_entry *entries, int num_entries) {
    int success_count = 0;
    double total_response_time = 0;

    for (int i = 0; i < num_entries; i++) {
        if (entries[i].response_code == 200) {
            success_count++;
            total_response_time += entries[i].response_time;
        }
    }

    double avg_response_time = total_response_time / success_count;
    double satisfaction_rate = (double)success_count / num_entries * 100;

    printf("Satisfaction Rate: %f %%\n", satisfaction_rate);
}

void print_satisfaction_report(struct log_entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        if (entries[i].response_code == 200) {
            printf("Request: %s\n", entries[i].request);
            printf("Response Time: %f ms\n", entries[i].response_time);
        }
    }
}