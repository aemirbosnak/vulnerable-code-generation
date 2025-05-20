//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
/* 
A performance-critical component that performs a fast Fourier transform (FFT) algorithm on a large data set. 
This algorithm is commonly used in digital signal processing and requires fast computation to analyze data in real time. 
The program utilizes multithreading to speed up the computation and optimize the CPU usage. 

Author: John Doe
Date: 2021-08-01
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAX_THREADS 4

/* Global variables */
int n, num_threads;
double *X_re, *X_im, *W_re, *W_im;

/* Function prototypes */
void fft(int start, int stride);
void *worker_thread(void *thread_arg);

/* Main function */
int main(int argc, char *argv[]) {
    /* Get input parameters */
    if (argc < 3) {
        printf("Usage: %s <n> <num_threads>\n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    /* Initialize arrays */
    X_re = (double *) malloc(n * sizeof(double));
    X_im = (double *) malloc(n * sizeof(double));
    W_re = (double *) malloc(n * sizeof(double));
    W_im = (double *) malloc(n * sizeof(double));

    /* Generate input data */
    for (int i = 0; i < n; i++) {
        X_re[i] = sin(i);
        X_im[i] = 0.0;
    }

    /* Generate twiddle factors */
    for (int i = 0; i < n; i++) {
        W_re[i] = cos(2.0 * M_PI / (double) n * (double) i);
        W_im[i] = sin(2.0 * M_PI / (double) n * (double) i);
    }

    /* Create threads */
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, worker_thread, (void *) i);
    }

    /* Wait for threads to finish */
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    /* Free memory */
    free(X_re);
    free(X_im);
    free(W_re);
    free(W_im);

    return 0;
}

/* Fast Fourier Transform */
void fft(int start, int stride) {
    if (stride < n) {
        fft(start, stride * 2);
        fft(start + stride, stride * 2);
        for (int k = start; k < n; k += (stride * 2)) {
            double t_re = X_re[k + stride] * W_re[k / stride] - X_im[k + stride] * W_im[k / stride];
            double t_im = X_re[k + stride] * W_im[k / stride] + X_im[k + stride] * W_re[k / stride];
            X_re[k + stride] = X_re[k] - t_re;
            X_im[k + stride] = X_im[k] - t_im;
            X_re[k] += t_re;
            X_im[k] += t_im;
        }
    }
}

/* Worker thread function */
void *worker_thread(void *thread_arg) {
    int tid = (int) thread_arg;
    int start = tid * (n / num_threads);
    int end = (tid + 1) * (n / num_threads);

    /* Perform FFT on segment of data */
    fft(start, 1);

    pthread_exit(NULL);
}