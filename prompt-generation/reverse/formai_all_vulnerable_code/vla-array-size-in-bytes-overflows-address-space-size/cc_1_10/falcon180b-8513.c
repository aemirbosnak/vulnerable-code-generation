//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define PI 3.14159265358979323846

void FFT(double x[], int n) {
    int i, j, k, l;
    double theta, w, wk, wr, temp;
    double even[n], odd[n];

    for (i = 0; i < n; i++) {
        even[i] = x[i];
        odd[i] = 0;
    }

    for (l = 2; l <= n; l *= 2) {
        theta = PI / l;
        w = cos(theta);
        wk = -2 * PI / l;

        for (k = 0; k < n / l; k++) {
            for (j = 0; j < l / 2; j++) {
                temp = even[j + k * l] + w * odd[j + k * l];
                odd[j + k * l] = even[j + k * l] - w * odd[j + k * l];
                even[j + k * l] = temp;
            }

            for (j = 0; j < l / 2; j++) {
                temp = even[j + k * l] + wk * odd[j + k * l];
                odd[j + k * l] = even[j + k * l] - wk * odd[j + k * l];
                even[j + k * l] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = even[i];
    }
}

int main() {
    double x[N], y[N];
    int i, n;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    printf("Enter the signal samples:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    FFT(x, n);

    printf("The frequency domain representation of the signal is:\n");
    for (i = 0; i < n; i++) {
        printf("%lf ", x[i]);
    }

    return 0;
}