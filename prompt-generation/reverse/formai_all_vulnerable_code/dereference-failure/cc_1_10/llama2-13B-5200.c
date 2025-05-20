//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_LINE_LENGTH 1024
#define MAP_SIZE 1024 * 1024

int main() {
    // Create a map of integers to characters
    int *map = mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (map == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    // Fill the map with random integers and characters
    for (int i = 0; i < MAP_SIZE; i++) {
        int rnd = rand() % 26 + 1; // 1-26, inclusive
        char c = 'a' + rnd; // 'a' + 1-26, inclusive
        map[i] = rnd;
        printf("%d -> %c\n", rnd, c);
    }

    // Loop until the user presses Ctrl-C
    while (1) {
        // Read a line from the user
        char line[MAX_LINE_LENGTH];
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Check if the line is empty
        if (strlen(line) == 0) {
            continue;
        }

        // Find the first character in the line that is not a whitespace
        char *non_ws = strchr(line, '\0');
        if (non_ws == NULL) {
            continue;
        }

        // Find the index of the first character in the line that is not a whitespace
        int non_ws_index = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (!isspace(line[i])) {
                non_ws_index = i;
                break;
            }
        }

        // Look up the character in the map
        int rnd = map[non_ws_index];

        // Print the character and its index in the map
        printf("%c (%d)\n", line[non_ws_index], rnd);
    }

    // Unmap the memory
    munmap(map, MAP_SIZE);

    return 0;
}