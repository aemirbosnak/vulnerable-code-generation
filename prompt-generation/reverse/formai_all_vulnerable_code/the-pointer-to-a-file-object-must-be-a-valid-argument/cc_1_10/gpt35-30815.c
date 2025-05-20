//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024 

void optimize_boot() {

    int line_num = 0;
    int removed_num = 0;

    // Opening the file
    FILE *file = fopen("/etc/rc.local", "r");

    // Creating a temporary file
    FILE *temp = fopen("/tmp/rc.local.tmp", "w+");

    char buffer[BUFFER_SIZE];

    // Randomly sleep to simulate the optimizer working
    printf("Optimizing boot sequence. Please wait...\n");
    srand(time(NULL));
    sleep(rand() % 5);

    // Looping through the lines of the file
    while (fgets(buffer, BUFFER_SIZE, file)) {
        line_num++;

        // Removing unnecessary lines
        if (strstr(buffer, "NFS Mount")) {
            printf("Removing unnecessary line %d\n", line_num);
            removed_num++;
        } else {
            fputs(buffer, temp);
        }
    }

    // Closing both files
    fclose(file);
    fclose(temp);

    // Replacing the original file with the temporary file
    if (removed_num > 0) {
        printf("Removed %d unnecessary lines from boot sequence.\n", removed_num);
        if (rename("/tmp/rc.local.tmp", "/etc/rc.local") != 0) {
            perror("Error replacing /etc/rc.local with temporary file");
        }
    } else {
        printf("No unnecessary lines found in boot sequence.\n");
        remove("/tmp/rc.local.tmp");
    }
}

int main() {
    optimize_boot();
    return 0;
}