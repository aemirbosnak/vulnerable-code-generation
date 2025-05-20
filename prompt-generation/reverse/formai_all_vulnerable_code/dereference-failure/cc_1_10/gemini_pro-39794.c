//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    MANDELBROT,
    JULIA
} fractal_type_t;

typedef struct {
    fractal_type_t type;
    double a;
    double b;
    double zoom;
    int iterations;
} fractal_parameters_t;

void draw_fractal(const fractal_parameters_t *params) {
    int i, j;
    double cx, cy, zx, zy, z2;

    for (i = 0; i < params->zoom; i++) {
        for (j = 0; j < params->zoom; j++) {
            cx = (i - params->zoom / 2.0) / (params->zoom / 4.0);
            cy = (j - params->zoom / 2.0) / (params->zoom / 4.0);
            zx = cx;
            zy = cy;
            z2 = zx * zx + zy * zy;
            for (int k = 0; k < params->iterations; k++) {
                if (z2 > 4.0) {
                    break;
                }
                zx = cx + zx * zy - zy * zx;
                zy = cy + zy * zx - zx * zy;
                z2 = zx * zx + zy * zy;
            }
            printf("%c", (z2 > 4.0) ? '.' : '*');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    fractal_parameters_t params;

    if (argc != 6) {
        fprintf(stderr, "Usage: %s <fractal-type> <a> <b> <zoom> <iterations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    params.type = atoi(argv[1]);
    params.a = atof(argv[2]);
    params.b = atof(argv[3]);
    params.zoom = atof(argv[4]);
    params.iterations = atoi(argv[5]);

    draw_fractal(&params);

    return EXIT_SUCCESS;
}