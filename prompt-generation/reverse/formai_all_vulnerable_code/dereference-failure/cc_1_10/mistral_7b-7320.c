//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_BUFFER 1024
#define NUM_FILE_DES 2

int main(void)
{
    int file_des[NUM_FILE_DES];
    int i;
    fd_set readfds;
    struct timeval tv;
    char buffer[MAX_BUFFER];
    int num_bytes;

    // Open two files for reading
    file_des[0] = open("haunted_house_left.txt", O_RDONLY);
    file_des[1] = open("haunted_house_right.txt", O_RDONLY);

    if (file_des[0] < 0 || file_des[1] < 0) {
        perror("Failed to open files");
        exit(EXIT_FAILURE);
    }

    // Initialize the file descriptors set
    FD_ZERO(&readfds);
    for (i = 0; i < NUM_FILE_DES; i++) {
        FD_SET(file_des[i], &readfds);
    }

    while (1) {
        tv.tv_sec = 0;
        tv.tv_usec = 1000;

        // Wait for input from one of the files or a signal
        if (select(NUM_FILE_DES, &readfds, NULL, NULL, &tv) < 0) {
            perror("Error in select");
            exit(EXIT_FAILURE);
        }

        // Check which file has data available
        for (i = 0; i < NUM_FILE_DES; i++) {
            if (FD_ISSET(file_des[i], &readfds)) {
                // Read data from the file
                num_bytes = read(file_des[i], buffer, MAX_BUFFER);

                if (num_bytes > 0) {
                    printf("%s", buffer);
                    fflush(stdout);
                } else {
                    close(file_des[i]);
                    FD_CLR(file_des[i], &readfds);
                    i--;
                    break;
                }
            }
        }
    }

    // Close all open files
    for (i = 0; i < NUM_FILE_DES; i++) {
        close(file_des[i]);
    }

    return EXIT_SUCCESS;
}