//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void *malloc_or_die(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
        exit(1);
    }
    return ptr;
}

void free_or_die(void *ptr) {
    free(ptr);
    if (ptr == NULL) {
        fprintf(stderr, "Error freeing memory: %s\n", strerror(errno));
        exit(1);
    }
}

void read_csv(FILE *file, char **data) {
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        char *line = strtok(buffer, "\n");
        char *csv_line = strtok(NULL, ",");
        char *column = strtok(NULL, ",");
        *data = malloc_or_die(strlen(csv_line) + 1);
        strcpy(*data, csv_line);
        *data = malloc_or_die(strlen(column) + 1);
        strcpy(*data, column);
        free_or_die(data);
    }
}

int main() {
    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    char *data[2];
    read_csv(csv_file, data);

    printf("Column A: %s\n", data[0]);
    printf("Column B: %s\n", data[1]);

    fclose(csv_file);
    return 0;
}