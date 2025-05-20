//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define MYSTIC_TRIANGLE_SIZE 10

typedef struct MysticTriangle {
    int a;
    int b;
    int c;
} MysticTriangle;

void print_triangle(MysticTriangle *triangle) {
    char *symbols = " ^vV<( )*>*&%@#";
    int row = 0;

    printf("\033[2J"); // clear terminal

    while (row < 3) {
        int col = 0;
        if (row == 0 && triangle->a > 0) {
            printf("%c%d ", symbols[(triangle->a - 1) % strlen(symbols)], col);
            col++;
        } else {
            printf("   ");
        }

        if (row == 1 && triangle->b > 0) {
            printf("%c%d ", symbols[(triangle->b - 1) % strlen(symbols)], col);
            col++;
        } else {
            printf("   ");
        }

        if (row == 2 && triangle->c > 0) {
            printf("%c%d \n", symbols[(triangle->c - 1) % strlen(symbols)], col);
            row++;
            col = 0;
        } else {
            printf("\n");
            row++;
        }
    }
}

int main() {
    MysticTriangle *triangle = malloc(sizeof(MysticTriangle));
    triangle->a = 3;
    triangle->b = 5;
    triangle->c = 7;

    print_triangle(triangle);

    free(triangle);

    return 0;
}