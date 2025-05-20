//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 5

void print_diamond(int height) {
    int i, j, spaces, stars;
    char *line;

    height = height < 0 ? -height : height;

    line = (char *)malloc(height * 2 + 1);
    if (!line) {
        printf("Error: Unable to allocate memory.\n");
        return;
    }

    memset(line, ' ', height * 2);
    memset(line + height, '\0', height + 1);

    for (i = 0; i <= height; i++) {
        spaces = height - i - 1;
        stars = i * 2 + 1;

        printf("%s\n", line + spaces);

        for (j = 0; j < stars; j++)
            putchar('*');
        putchar('\n');
    }

    free(line);
}

int main(int argc, char *argv[]) {
    int height;

    if (argc < 2) {
        printf("Usage: %s <height>\n", argv[0]);
        return 1;
    }

    height = atoi(argv[1]);

    if (height > MAX_HEIGHT || height < 0) {
        printf("Error: Invalid height.\n");
        return 1;
    }

    print_diamond(height);
    return 0;
}