//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LEN 1024
#define MAX_LOG_LEN 100000

typedef struct {
    char *log_line;
    int len;
} log_entry_t;

typedef struct {
    log_entry_t *entries;
    int num_entries;
} log_buffer_t;

void log_buffer_init(log_buffer_t *buf, int capacity) {
    buf->entries = calloc(capacity, sizeof(log_entry_t));
    buf->num_entries = 0;
}

void log_buffer_add(log_buffer_t *buf, const char *log_line) {
    log_entry_t *entry = calloc(1, sizeof(log_entry_t));
    entry->log_line = log_line;
    entry->len = strlen(log_line);
    buf->entries[buf->num_entries] = *entry;
    buf->num_entries++;
}

void log_buffer_print(log_buffer_t *buf) {
    int i;
    for (i = 0; i < buf->num_entries; i++) {
        printf("%s\n", buf->entries[i].log_line);
    }
}

int main() {
    log_buffer_t log_buffer;
    log_buffer_init(&log_buffer, 10);

    char *log_lines[] = {
        "Hello, world!",
        "This is a test log line.",
        "This is another test log line.",
        "And yet another one.",
        "The fourth line is longer than the others.",
        "This is a very long log line that will wrap to multiple lines.",
        "This is a even longer log line that will wrap to multiple lines.",
    };

    int i;
    for (i = 0; i < sizeof(log_lines) / sizeof(char *); i++) {
        log_buffer_add(&log_buffer, log_lines[i]);
    }

    log_buffer_print(&log_buffer);

    return 0;
}