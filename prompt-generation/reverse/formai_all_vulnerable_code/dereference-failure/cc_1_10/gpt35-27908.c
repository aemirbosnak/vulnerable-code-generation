//FormAI DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct log {
    char timestamp[20];
    char log_entry[100];
    char source[20];
} log_t;

// Function to parse log file and extract relevant information
void parse_log_file(FILE *fptr, log_t **logs, int *num_logs) {
    char line[200];
    int i = 0;
    while(fgets(line, sizeof(line), fptr) != NULL) {
        char *pch = strtok(line, "|");
        if(pch != NULL) {
            strcpy(logs[i]->timestamp, pch);
            pch = strtok(NULL, "|");
            if(pch != NULL) {
                strcpy(logs[i]->log_entry, pch);
                pch = strtok(NULL, "|");
                if(pch != NULL) {
                    strcpy(logs[i]->source, pch);
                    i++;
                }
            }
        }
    }
    *num_logs = i;
}

// Function to print all logs containing a particular keyword
void print_log_by_keyword(log_t **logs, int num_logs, char *keyword) {
    printf("Logs containing keyword '%s':\n", keyword);
    for(int i=0; i<num_logs; i++) {
        if(strstr(logs[i]->log_entry, keyword) != NULL) {
            printf("%s | %s | %s\n", logs[i]->timestamp, logs[i]->log_entry, logs[i]->source);
        }
    }
}

// Function to calculate frequency of each source
void get_log_frequency_by_source(log_t **logs, int num_logs, char **sources, int num_sources, int *frequency) {
    for(int i=0; i<num_logs; i++) {
        for(int j=0; j<num_sources; j++) {
            if(strcmp(logs[i]->source, sources[j]) == 0) {
                frequency[j]++;
            }
        }
    }
}

int main() {
    int num_logs = 0;
    log_t **logs = (log_t **) malloc(sizeof(log_t *));
    logs[0] = (log_t *) malloc(sizeof(log_t));
    FILE *fptr;
    fptr = fopen("log.txt", "r");
    if(fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    else {
        parse_log_file(fptr, logs, &num_logs);
    }
    fclose(fptr);

    // Print all logs containing the keyword "error"
    print_log_by_keyword(logs, num_logs, "error");

    // Calculate frequency of each source
    char *sources[] = {"source1", "source2", "source3"};
    int num_sources = 3;
    int *frequency = (int *) calloc(num_sources, sizeof(int));
    get_log_frequency_by_source(logs, num_logs, sources, num_sources, frequency);
    printf("Frequency of logs for each source:\n");
    for(int i=0; i<num_sources; i++) {
        printf("%s: %d\n", sources[i], frequency[i]);
    }

    // Free memory
    free(frequency);
    for(int i=0; i<num_logs; i++) {
        free(logs[i]);
    }
    free(logs);

    return 0;
}