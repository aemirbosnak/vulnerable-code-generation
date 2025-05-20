//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>

#define CHUNK_SIZE 1024

typedef struct task_data_t {
    char *input_file_path;
    char *output_file_path;
} task_data;

typedef struct async_task_t {
    task_data *data;
    void (*callback)(void*);
    bool finished;
} async_task;

async_task *create_async_task(task_data *data, void (*callback)(void*)) {
    async_task *task = malloc(sizeof(async_task));
    task->data = data;
    task->callback = callback;
    task->finished = false;
    return task;
}

void destroy_async_task(async_task *task) {
    if (task != NULL) {
        if (task->data != NULL) free(task->data);
        free(task);
    }
}

char *read_file(const char *file_path) {
    char *input_data = NULL;
    int input_fd = open(file_path, O_RDONLY);
    if (input_fd == -1) {
        fprintf(stderr, "Error opening file %s: %s\n", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    char chunk[CHUNK_SIZE + 1];
    ssize_t read_size = 0;
    size_t input_data_size = 0;
    while ((read_size = read(input_fd, chunk, CHUNK_SIZE)) > 0) {
        input_data_size += read_size;
        input_data = realloc(input_data, input_data_size + 1);
        strncat(input_data, chunk, read_size);
    }
    input_data[input_data_size] = '\0';
    close(input_fd);
    return input_data;
}

void write_file(const char *file_path, const char *output) {
    int output_fd = open(file_path, O_CREAT | O_WRONLY, 0644);
    if (output_fd == -1) {
        fprintf(stderr, "Error opening file %s: %s\n", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (write(output_fd, output, strlen(output)) == -1) {
        fprintf(stderr, "Error writing to file %s: %s\n", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    close(output_fd);
}

void process_text(void *task) {
    async_task *text_task = (async_task*) task;
    task_data *data = text_task->data;
    char *input_data = read_file(data->input_file_path);
    char *output = malloc(strlen(input_data) + 1);
    char *input_copy = strdup(input_data);
    char *word = strtok(input_copy, " \n");
    while (word != NULL) {
        bool palindrome = true;
        size_t length = strlen(word);
        for (size_t i = 0; i < length / 2; i++) {
            if (word[i] != word[length - i - 1]) {
                palindrome = false;
                break;
            }
        }
        if (palindrome) {
            strcat(output, "_");
        } else {
            strcat(output, word);
        }
        strcat(output, " ");
        word = strtok(NULL, " \n");
    }
    write_file(data->output_file_path, output);
    free(input_data);
    free(input_copy);
    free(output);
    text_task->finished = true;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    task_data *data = malloc(sizeof(*data));
    data->input_file_path = argv[1];
    data->output_file_path = argv[2];
    async_task *text_task = create_async_task(data, NULL);
    process_text(text_task);
    while (!text_task->finished) {
        printf("Processing text...\n");
        usleep(rand() % 1000000 + 500000);
    }
    destroy_async_task(text_task);
    printf("Text processing done!\n");
    return EXIT_SUCCESS;
}