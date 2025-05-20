//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return 1;
    }

    char *color = argv[1];
    int len = strlen(color);
    int r, g, b;

    for (int i = 0; i < len; i++) {
        char c = color[i];

        if (c >= '0' && c <= '9') {
            r = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            r = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            r = c - 'a' + 10;
        } else {
            printf("Invalid color code\n");
            return 1;
        }

        if (i < len - 1) {
            c = color[i + 1];

            if (c >= '0' && c <= '9') {
                g = c - '0';
            } else if (c >= 'A' && c <= 'F') {
                g = c - 'A' + 10;
            } else if (c >= 'a' && c <= 'f') {
                g = c - 'a' + 10;
            } else {
                printf("Invalid color code\n");
                return 1;
            }

            if (i < len - 2) {
                c = color[i + 2];

                if (c >= '0' && c <= '9') {
                    b = c - '0';
                } else if (c >= 'A' && c <= 'F') {
                    b = c - 'A' + 10;
                } else if (c >= 'a' && c <= 'f') {
                    b = c - 'a' + 10;
                } else {
                    printf("Invalid color code\n");
                    return 1;
                }

                printf("R: %d, G: %d, B: %d\n", r, g, b);
            }
        }
    }

    return 0;
}