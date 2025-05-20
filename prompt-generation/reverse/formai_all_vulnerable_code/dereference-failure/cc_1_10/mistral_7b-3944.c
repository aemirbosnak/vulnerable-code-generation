//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 64
#define NUM_TOKENS 7

typedef struct {
    char level[MAX_TOKEN_LENGTH];
    char thread[MAX_TOKEN_LENGTH];
    int pid;
    char func[MAX_TOKEN_LENGTH];
    char msg[MAX_LINE_LENGTH - NUM_TOKENS * MAX_TOKEN_LENGTH];
} log_entry_t;

void parse_log_line(char *line, log_entry_t *entry) {
    char *token[NUM_TOKENS];
    int i;
    char *token_ptr = strtok(line, " []:");

    for (i = 0; i < NUM_TOKENS && token_ptr != NULL; ++i) {
        token[i] = token_ptr;
        token_ptr = strtok(NULL, " []:");
    }

    strcpy(entry->level, token[0]);
    strcpy(entry->thread, token[1]);
    entry->pid = atoi(token[2]);
    strcpy(entry->func, token[3]);
    strcpy(entry->msg, token[4]);
    strcat(entry->msg, token[5]);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    log_entry_t entry;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening logfile");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        parse_log_line(line, &entry);
        printf("[%s] [%s] [%d] [%s] : %s\n", entry.level, entry.thread, entry.pid, entry.func, entry.msg);
    }

    fclose(fp);
    return 0;
}