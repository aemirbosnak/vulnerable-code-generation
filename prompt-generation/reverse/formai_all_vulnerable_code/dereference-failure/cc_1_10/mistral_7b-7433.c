//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define TEST_FILE "typing_test.txt"
#define LINE_LENGTH 80
#define NUM_LINES 10

int main() {
    int fd, i, j, k, len;
    char *buf, test_str[NUM_LINES][LINE_LENGTH];
    struct stat file_stat;
    clock_t start, end;

    fd = open(TEST_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    fstat(&file_stat, TEST_FILE);
    len = file_stat.st_size;
    buf = malloc(len + 1);
    read(fd, buf, len);
    close(fd);
    buf[len] = '\0';

    for (i = 0; i < NUM_LINES; i++) {
        sscanf(buf, "%[^%c%n]%c%n", test_str[i], &len, &buf[len]);
        if (len > LINE_LENGTH) {
            test_str[i][LINE_LENGTH] = '\0';
        }
    }

    start = clock();
    for (i = 0; i < NUM_LINES; i++) {
        printf("%s", test_str[i]);
        for (j = 0; j < strlen(test_str[i]); j++) {
            for (k = 0; k < 10000; k++);
            putchar(test_str[i][j]);
            fflush(stdout);
            usleep(100);
        }
        printf("\n");
    }

    end = clock();
    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(buf);
    return 0;
}