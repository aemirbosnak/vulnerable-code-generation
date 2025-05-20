//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char log_file[1024];
    strcpy(log_file, argv[1]);

    struct stat stat_buf;
    if (stat(log_file, &stat_buf)!= 0) {
        fprintf(stderr, "Error: %s does not exist\n", log_file);
        return EXIT_FAILURE;
    }

    int fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        fprintf(stderr, "Error: Failed to open %s for writing\n", log_file);
        return EXIT_FAILURE;
    }

    while (1) {
        time_t now = time(NULL);
        char buf[1024];
        snprintf(buf, sizeof(buf), "[%ld] Event: ", now);

        fputs(buf, stdout);
        printf("Message:\n");
        fflush(stdout);

        char input[1024];
        fgets(input, sizeof(input), stdin);

        fputs(input, stdout);
        fflush(stdout);

        fputs("\n", stdout);
        fflush(stdout);

        if (fputs("\n", stdout) == EOF) {
            fprintf(stderr, "Error: Failed to write to %s\n", log_file);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}