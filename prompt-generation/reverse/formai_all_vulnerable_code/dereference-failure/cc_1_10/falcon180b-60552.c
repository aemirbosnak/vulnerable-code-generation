//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *hex = malloc(strlen(line) * 2 + 1);
        if (hex == NULL) {
            fprintf(stderr, "malloc failed: %s\n", strerror(errno));
            return 1;
        }

        char *p = hex;
        for (int i = 0; i < strlen(line); i++) {
            char c = line[i];
            if (isxdigit(c)) {
                *p++ = c;
            } else {
                snprintf(p, 3, "%02X", (unsigned char)c);
                p += 2;
            }
        }
        *p = '\0';

        printf("%s\n", hex);
        free(hex);
    }

    fclose(file);
    return 0;
}