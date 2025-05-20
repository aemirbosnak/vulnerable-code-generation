//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Declare variables
    int i, j, k, l, m, n, o, p, q, r;
    int x, y, z;
    double a, b, c, d, e, f, g, h, v, w;
    char *s, *t, *u;

    // Initialize variables
    i = j = k = l = m = n = o = p = q = r = 0;
    x = y = z = 0;
    a = b = c = d = e = f = g = h = v = w = 0.0;
    s = t = u = NULL;

    // Perform calculations
    for (i = 0; i < 1000000; i++) {
        j += i;
        k -= i;
        l *= i;
        m /= i;
        n %= i;
        o &= i;
        p |= i;
        q ^= i;
        r <<= i;
        r >>= i;
    }

    for (x = 0.0; x < 1000000.0; x += 0.1) {
        y += x;
        z -= x;
        a *= x;
        b /= x;
        c += x;
        d -= x;
        e *= x;
        f /= x;
    }

    for (s = "Hello"; *s != '\0'; s++) {
        t = s;
        u = s;
    }

    // Output results
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("k = %d\n", k);
    printf("l = %d\n", l);
    printf("m = %d\n", m);
    printf("n = %d\n", n);
    printf("o = %d\n", o);
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("r = %d\n", r);
    printf("x = %f\n", x);
    printf("y = %f\n", y);
    printf("z = %f\n", z);
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    printf("d = %f\n", d);
    printf("e = %f\n", e);
    printf("f = %f\n", f);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    printf("u = %s\n", u);

    return 0;
}