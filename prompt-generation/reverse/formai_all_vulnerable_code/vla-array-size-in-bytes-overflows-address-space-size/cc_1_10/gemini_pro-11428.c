//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII art data
static char *ascii_art[] = {
    "                       _           _   _        __ __         _     __  ___   ___  ",
    "                      | |_ ___    | | | |      / _` `_\\       | |   / _|/ _ \\ / _ \\ ",
    "    __ __ __ _ _   _  | __/ _ \\   | |_| | ___ | (_| | |  _   | |__| |_| | | | |  __/ ",
    "   / _` `_\\ __| | | | | || (_) |   \\  /| |/ _ \\  >_ <  _| |_  |  __|  _| | | | |    ",
    "  | (_| | | | | |_| | | \\___/    | | | | (_) | | (_) |  | __| | |  | | |_| | |_|\\  ",
    "   \\__,_| |_|_|\\__, |_|\\___/     |_| |_|\\___/  \\___/   \\__|  |_|  |_|\__\\___/\\___/  ",
    "                __/ |                                                              ",
    "               |___/                                                               "
};

// Thread data
struct thread_data {
    int row;
    int num_rows;
};

// Thread function
void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;

    // Print the specified rows of ASCII art
    for (int i = data->row; i < data->row + data->num_rows; i++) {
        printf("%s\n", ascii_art[i]);
    }

    return NULL;
}

int main() {
    // Get the number of threads from the user
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create the thread pool
    pthread_t threads[num_threads];

    // Divide the ASCII art into chunks for each thread
    int num_rows_per_thread = (sizeof(ascii_art) / sizeof(char *)) / num_threads;

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->row = i * num_rows_per_thread;
        data->num_rows = num_rows_per_thread;

        pthread_create(&threads[i], NULL, thread_func, (void *)data);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}