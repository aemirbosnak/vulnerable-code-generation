//FormAI DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 51 // filter length
#define Fs 8000 // sample rate
#define F_pass 1000 // passband frequency (Hz)
#define F_stop 1500 // stopband frequency (Hz)
#define A_pass 1.0 // passband ripple (dB)
#define A_stop 40.0 // stopband attenuation (dB)

// Parks-McClellan algorithm for designing FIR filter
void firpm(double* h, int n, int m, double* f, double* a, double* w, double type)
{
    int i, j;
    double delta, alpha, beta, gamma, f_sum, a_sum;
    double* b = calloc(n, sizeof(double));
    double* f_pts = malloc((m+1) * sizeof(double));

    // initial guess using equiripple approximation
    for(i = 1; i <= n/2; i++)
        b[n/2-i+1] = b[n/2+i] = (-1.0) / (M_PI * i);
    b[n/2] = 1.0;
    
    // iterate to convergence using Parks-McClellan algorithm
    while(1) {
        delta = 0.0;
        for(i = 0; i <= m; i++) {
            f_pts[i] = (i * type * M_PI) / m;
            a[i] = 0.0;
            for(j = 0; j < n; j++)
                a[i] += b[j] * cos(j * f_pts[i]);
            w[i] = 2.0 * ((i % 2) - 0.5);
        }
        for(i = 0; i <= m; i++) {
            alpha = w[i] * cos(f_pts[i]);
            beta = w[i] * sin(f_pts[i]);
            f_sum = a_sum = 0.0;
            for(j = 0; j <= m; j++) {
                gamma = alpha - cos(f_pts[j]);
                f_sum += (w[j] / gamma);
                a_sum += (w[j] * a[j]) / gamma;
            }
            delta += fabs(f_sum * b[n/2] - a_sum);
            h[n/2] = f_sum / ((double) m + 1);
            for(j = 0; j < n/2; j++) {
                h[j] = h[n-j-1] = 0;
                for(int k = 0; k <= m; k++) {
                    gamma = alpha - cos(f_pts[k]);
                    f_sum = sin(j*f_pts[k]) + w[k] * sin(j*f_pts[k]-f_pts[i]);
                    h[j] += (w[k] * f_sum) / gamma;
                }
                h[n-j-1] = h[j];
            }
            for(int k = 0; k <= n/2; k++)
                b[k] -= 2 * h[k] * h[n/2-i];
        }
        if(delta < 0.1 * pow(10, -A_stop/20)) break;
    }

    // return filter coefficients
    for(int k = 0; k < n; k++)
        h[k] *= w[k];
    free(b);
    free(f_pts);
}

int main()
{
    double h[N], x, y;
    int i;

    firpm(h, N, 512, &(double[]){0, F_pass/Fs, F_stop/Fs, 0.5}, &(double[]){1, 0}, &(double[]){1, A_stop/A_pass}, -1);

    printf("Coefficients:\n");
    for(i = 0; i < N; i++)
        printf("%4d: %f\n", i, h[i]);

    // simulate filter response to 1000 Hz sine wave
    printf("Filter response:\n");
    for(i = 0; i < 100; i++) {
        x = sin(2*M_PI * F_pass/Fs * i);
        y = 0.0;
        for(int k = 0; k < N; k++)
            y += h[k] * (k > i ? 0 : x-i+k);
        printf("%4d: %f\n", i, y);
    }

    return 0;
}