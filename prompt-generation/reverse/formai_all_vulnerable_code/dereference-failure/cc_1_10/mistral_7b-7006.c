//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define HASH_SIZE 101

typedef struct {
    char ip[16];
    int error_code;
    int count;
} LogEntry;

typedef struct {
    LogEntry data[HASH_SIZE];
    int size;
} HashTable;

HashTable table;

void hash(char *str, int *index) {
    int hash = 0;
    for (int i = 0; str[i]; i++) {
        hash += tolower(str[i]);
    }

    *index = hash % HASH_SIZE;
}

void init_hash_table() {
    table.size = 0;
}

int find_slot(char *ip) {
    int index;
    hash(ip, &index);
    return index;
}

void add_log_entry(char *ip, int error_code) {
    int index = find_slot(ip);
    if (table.data[index].count == 0) {
        strcpy(table.data[index].ip, ip);
        table.data[index].error_code = error_code;
        table.data[index].count = 1;
        table.size++;
    } else {
        table.data[index].count++;
    }
}

void read_log_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fd) != NULL) {
        char *ip_start = strchr(line, ' ');
        char *ip_end = strchr(ip_start, ' ');
        int error_code;

        if (!ip_start || !ip_end) {
            continue;
        }

        *ip_end = '\0';
        ip_end++;

        sscanf(line, "%s %d %*s", ip_start, &error_code);
        add_log_entry(ip_start, error_code);
    }

    close(fd);
}

int main() {
    init_hash_table();
    read_log_file("example.log");

    printf("IP addresses and their error code occurrences:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        if (table.data[i].count > 0) {
            printf("IP: %s, Error code: %d, Occurrences: %d\n", table.data[i].ip, table.data[i].error_code, table.data[i].count);
        }
    }

    return 0;
}