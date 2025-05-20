//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAGIC_NUMBER 0xDEADBEEF

struct log_entry {
    time_t timestamp;
    int level;
    char message[MAX_LINE];
};

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening log file");
        return 1;
    }

    printf("\nWelcome to The Enchanted Scribe, where logs come to life!\n\n");

    char line[MAX_LINE];
    struct log_entry entry;
    while (fgets(line, MAX_LINE, fd) != NULL) {

        // Magic begins here
        if (MAGIC_NUMBER != *(int *)line) continue;

        sscanf(line, "%ld %d %[^:]:%s", &entry.timestamp, &entry.level, entry.message);

        switch (entry.level) {
            case 1: printf("\033[1;31m[ERROR] %s\n", entry.message); break;
            case 2: printf("\033[1;33m[WARNING] %s\n", entry.message); break;
            case 3: printf("\033[1;34m[INFO] %s\n", entry.message); break;
            case 4: printf("\033[1;36m[DEBUG] %s\n", entry.message); break;
            default: printf("Unknown log level: %d\n", entry.level); break;
        }

        // Free the message from any evil spirits
        memset(entry.message, 0, MAX_LINE);
    }

    close(fd);

    printf("\nThe Enchanted Scribe has finished its enchanting task.\n");
    return 0;
}