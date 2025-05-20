//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct {
    size_t size;
    char *data;
} heap_buffer;

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

heap_buffer *read_csv(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) die("open");

    fseek(fd, 0, SEEK_END);
    size_t file_size = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    size_t header_size = 0;
    size_t record_size = 0;
    char header[256];

    if (getline(&header, sizeof(header), fd) < 0) die("getline");

    sscanf(header, "%s %n", "columns:", &header_size);

    size_t num_columns = strtol(header + header_size, NULL, 10);

    size_t record_size_total = num_columns * sizeof(char *) + (num_columns - 1) * sizeof(char);

    heap_buffer *buffer = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buffer == MAP_FAILED) die("mmap");

    char *csv = (char *)buffer;

    close(fd);

    char **records = calloc(1, (file_size / record_size_total) + 1);
    if (!records) die("calloc");

    char *current = csv;
    for (size_t i = 0; i < file_size / record_size_total; i++) {
        records[i] = strtok(current, ",");
        current += (strlen(records[i]) + 1);
    }

    return buffer;
}

void print_csv(heap_buffer *buffer) {
    char **records = (char **)buffer->data;
    size_t num_records = buffer->size / (sizeof(char *) + sizeof(char) * 1024);

    for (size_t i = 0; i < num_records; i++) {
        printf("%s", records[i]);
        printf(i == num_records - 1 ? "\n" : "\t| ");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    heap_buffer *buffer = read_csv(argv[1]);

    printf("-----------------------\n");
    printf("| Columns: %d          |\n", buffer->size / sizeof(char *));
    printf("-----------------------\n");

    print_csv(buffer);

    munmap(buffer, buffer->size);

    return EXIT_SUCCESS;
}