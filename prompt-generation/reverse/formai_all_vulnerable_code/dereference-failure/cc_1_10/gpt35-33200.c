//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 640
#define MAX_ITER 10000

struct Complex {
    double real;
    double imag;
};

typedef struct Complex Complex;

Complex cadd(Complex a, Complex b) {
    Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

Complex cmul(Complex a, Complex b) {
    Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

double magnitude(Complex c) {
    double res = sqrt(c.real * c.real + c.imag * c.imag);
    return res;
}

int calculate(Complex c) {
    Complex z;
    z.real = 0;
    z.imag = 0;
    for (int i = 0; i < MAX_ITER; i++) {
        z = cadd(cmul(z, z), c);
        if (magnitude(z) > 2) {
            return i;
        }
    }
    return MAX_ITER;
}

void render(unsigned char* image, double cx, double cy, double scale) {
    Complex c;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            c.real = (x - WIDTH / 2) * scale + cx;
            c.imag = (y - HEIGHT / 2) * scale + cy;
            int i = calculate(c);
            image[y * WIDTH + x] = (unsigned char)(255 * i / MAX_ITER);
        }
    }
}

int main() {
    srand(time(NULL));
    double cx = ((double)rand()/(double)RAND_MAX) * 4 - 2;
    double cy = ((double)rand()/(double)RAND_MAX) * 4 - 2;
    double scale = ((double)rand()/(double)RAND_MAX) * 2 - 1;
    unsigned char* image = (unsigned char*)malloc(sizeof(unsigned char) * WIDTH * HEIGHT);
    render(image, cx, cy, scale);
    FILE* fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
    free(image);
    return 0;
}