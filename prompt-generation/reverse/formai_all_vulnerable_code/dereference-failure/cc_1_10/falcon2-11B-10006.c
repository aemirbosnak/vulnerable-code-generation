//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void beautify_html(FILE *file) {
    char buf[BUF_SIZE];
    char line[BUF_SIZE];
    char tab[BUF_SIZE];
    int spaces = 0;

    while (fgets(buf, BUF_SIZE, file)) {
        int i = 0;
        while (i < strlen(buf) && isblank(buf[i])) {
            i++;
        }

        if (i == strlen(buf)) {
            continue;
        }

        strncpy(line, buf + i, strlen(buf) - i);
        strcpy(tab, "");

        for (int j = 0; j < spaces; j++) {
            tab[j] = '\t';
        }

        printf("%s\n%s\n", tab, line);
        fflush(stdout);

        spaces++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    beautify_html(file);
    fclose(file);

    return 0;
}