//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multivariable
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// System boot optimizer example program in a multivariable style

// Define the objective function to be minimized
double objective(double x, double y) {
    return x * x + y * y + 2 * x * y;
}

// Define the gradient of the objective function
void gradient(double x, double y, double *dx, double *dy) {
    *dx = 2 * x + 2 * y;
    *dy = 2 * y + 2 * x;
}

// Define the Hessian matrix of the objective function
void hessian(double x, double y, double **h) {
    h[0][0] = 2.0;
    h[0][1] = 2.0;
    h[1][0] = 2.0;
    h[1][1] = 2.0;
}

// Define the conjugate gradient method for minimizing the objective function
void conjugate_gradient(double *x, double *y, int max_iter) {
    // Initialize the search direction
    double dx = 1.0;
    double dy = 0.0;

    // Initialize the gradient
    double gx, gy;
    gradient(*x, *y, &gx, &gy);

    // Initialize the Hessian
    double **h = malloc(2 * sizeof(double *));
    for (int i = 0; i < 2; i++)
        h[i] = malloc(2 * sizeof(double));
    hessian(*x, *y, h);

    // Iterate over the conjugate gradient steps
    for (int iter = 0; iter < max_iter; iter++) {
        // Compute the step size
        double alpha = (gx * dx + gy * dy) / (dx * h[0][0] * dx + 2 * dx * dy * h[0][1] + dy * h[1][1] * dy);

        // Update the position
        *x += alpha * dx;
        *y += alpha * dy;

        // Compute the new gradient
        gradient(*x, *y, &gx, &gy);

        // Check for convergence
        if (fabs(gx) < 1e-6 && fabs(gy) < 1e-6)
            break;

        // Compute the new search direction
        double beta = (gx * dx + gy * dy) / (dx * h[0][0] * dx + 2 * dx * dy * h[0][1] + dy * h[1][1] * dy);
        dx = gx - beta * dx;
        dy = gy - beta * dy;
    }

    // Free the Hessian
    for (int i = 0; i < 2; i++)
        free(h[i]);
    free(h);
}

int main() {
    // Define the initial guess
    double x = 0.0;
    double y = 0.0;

    // Minimize the objective function using the conjugate gradient method
    conjugate_gradient(&x, &y, 1000);

    // Print the optimal solution
    printf("Optimal solution: (%.6f, %.6f)\n", x, y);

    // Check the optimality condition
    double gx, gy;
    gradient(x, y, &gx, &gy);
    assert(fabs(gx) < 1e-6 && fabs(gy) < 1e-6);

    return 0;
}