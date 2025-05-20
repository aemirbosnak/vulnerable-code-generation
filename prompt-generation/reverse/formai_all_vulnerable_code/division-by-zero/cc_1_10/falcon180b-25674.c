//Falcon-180B DATASET v1.0 Category: Educational ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char c;

    srand(time(NULL));
    for (i = 0; i < 26; i++) {
        c = 'a' + i;
        printf("%c ", c);
    }
    printf("\n");

    for (j = 0; j < 26; j++) {
        c = 'A' + j;
        printf("%c ", c);
    }
    printf("\n");

    for (k = 0; k < 10; k++) {
        printf("%d ", rand() % 10);
    }
    printf("\n");

    for (l = 0; l < 10; l++) {
        m = rand() % 10;
        n = rand() % 10;
        o = rand() % 10;
        p = rand() % 10;
        q = rand() % 10;
        r = rand() % 10;
        s = rand() % 10;
        t = rand() % 10;
        u = rand() % 10;
        v = rand() % 10;
        w = rand() % 10;
        x = rand() % 10;
        y = rand() % 10;
        z = rand() % 10;

        printf("%d + %d = %d\n", m, n, m + n);
        printf("%d - %d = %d\n", o, p, o - p);
        printf("%d * %d = %d\n", q, r, q * r);
        printf("%d / %d = %d\n", s, t, s / t);
        printf("%d %% %d = %d\n", u, v, u % v);
        printf("%d ^ %d = %d\n", w, x, w ^ x);
        printf("%d | %d = %d\n", y, z, y | z);
    }

    return 0;
}