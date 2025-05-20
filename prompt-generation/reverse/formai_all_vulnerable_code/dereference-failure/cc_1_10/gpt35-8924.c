//FormAI DATASET v1.0 Category: Computer Biology ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define variables
    int num_cells, i, j, k, count;
    float cell_size, time_step, diffusion_coeff, concentration;

    // Get input from user
    printf("Enter number of cells: ");
    scanf("%d", &num_cells);

    printf("Enter size of each cell: ");
    scanf("%f", &cell_size);

    printf("Enter time step: ");
    scanf("%f", &time_step);

    printf("Enter diffusion coefficient: ");
    scanf("%f", &diffusion_coeff);

    printf("Enter initial concentration: ");
    scanf("%f", &concentration);

    // Allocate memory for cell concentrations
    float *concentrations = (float*) malloc(sizeof(float) * num_cells);

    // Set initial concentrations
    for(i = 0; i < num_cells; i++) {
        concentrations[i] = concentration;
    }

    // Loop over time steps
    for(k = 0; k < 1000; k++) {
        // Loop over cells
        for(i = 0; i < num_cells; i++) {
            // Calculate diffusion into cell based on neighboring cell concentrations
            float diffusion_in = 0, diffusion_out = 0;

            if (i > 0) {
                diffusion_in = diffusion_coeff * (concentrations[i-1] - concentrations[i]);
            }

            if (i < num_cells-1) {
                diffusion_out = diffusion_coeff * (concentrations[i] - concentrations[i+1]);
            }

            // Update cell concentration
            concentrations[i] += (diffusion_in + diffusion_out) * time_step;

            // Check if cell concentration goes negative
            if (concentrations[i] < 0) {
                concentrations[i] = 0;
            }
        }

        // Print concentrations every 10 time steps
        if (k % 10 == 0) {
            count = 0;
            printf("Concentrations after %d time steps:\n", k);
            for(j = 0; j < num_cells; j++) {
                printf("%f\t", concentrations[j]);
                count++;

                // Print 5 columns of data per row
                if(count == 5) {
                    printf("\n");
                    count = 0;
                }
            }
            printf("\n");
        }
    }

    // Free memory
    free(concentrations);

    return 0;
}