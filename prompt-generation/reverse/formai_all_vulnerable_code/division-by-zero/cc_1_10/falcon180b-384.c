//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

Point generateRandomPoint(int upperBound) {
    Point result;
    result.x = rand() % upperBound;
    result.y = rand() % upperBound;
    return result;
}

void printPoint(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int extendedEuclidean(int a, int b, int *x, int *y) {
    int g = gcd(a, b);
    *x = (a / g) % b;
    *y = (b / g) % a;
    return g;
}

int modPow(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

Point multiplyPoint(Point p, int k, int m) {
    Point result;
    result.x = (p.x * k) % m;
    result.y = (p.y * k) % m;
    return result;
}

int main() {
    srand(time(NULL));

    int m = 23; // prime number
    int upperBound = 10; // maximum value for x and y coordinates

    Point P = generateRandomPoint(upperBound);
    printPoint(P);

    int x, y;
    int g = extendedEuclidean(m, P.y - P.x - 1, &x, &y);

    Point Q = multiplyPoint(P, g, m);
    printPoint(Q);

    printf("The order of the point (%d, %d) is %d\n", P.x, P.y, m - 1);

    return 0;
}