//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <filename> <logfile>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    FILE *log = fopen(argv[2], "w");
    if (!log) {
        perror("Error opening logfile");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        int length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }

        int result = check(buffer);

        if (result == 1) {
            fprintf(log, "File '%s' is infected\n", buffer);
            exit(1);
        } else if (result == 0) {
            fprintf(log, "File '%s' is clean\n", buffer);
        }
    }

    fclose(file);
    fclose(log);
    return 0;
}

int check(char *file) {
    // Simulate checking file against a list of known malware signatures
    if (strstr(file, "virus")) {
        return 1;
    } else {
        return 0;
    }
}