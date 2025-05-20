//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A data point in a scatter plot
struct point {
    double x;
    double y;
};

// A scatter plot
struct scatterplot {
    int num_points;
    struct point *points;
};

// Create a new scatter plot
struct scatterplot *create_scatterplot(int num_points) {
    struct scatterplot *scatterplot = malloc(sizeof(struct scatterplot));
    scatterplot->num_points = num_points;
    scatterplot->points = malloc(sizeof(struct point) * num_points);
    return scatterplot;
}

// Free a scatter plot
void free_scatterplot(struct scatterplot *scatterplot) {
    free(scatterplot->points);
    free(scatterplot);
}

// Add a point to a scatter plot
void add_point(struct scatterplot *scatterplot, double x, double y) {
    scatterplot->points[scatterplot->num_points].x = x;
    scatterplot->points[scatterplot->num_points].y = y;
    scatterplot->num_points++;
}

// Compute the mean of a scatter plot
double mean(struct scatterplot *scatterplot) {
    double sum = 0;
    for (int i = 0; i < scatterplot->num_points; i++) {
        sum += scatterplot->points[i].x;
    }
    return sum / scatterplot->num_points;
}

// Compute the standard deviation of a scatter plot
double stddev(struct scatterplot *scatterplot) {
    double mean_x = mean(scatterplot);
    double sum_of_squares = 0;
    for (int i = 0; i < scatterplot->num_points; i++) {
        sum_of_squares += pow(scatterplot->points[i].x - mean_x, 2);
    }
    return sqrt(sum_of_squares / (scatterplot->num_points - 1));
}

// Compute the correlation coefficient between two scatter plots
double corr(struct scatterplot *scatterplot1, struct scatterplot *scatterplot2) {
    double mean_x1 = mean(scatterplot1);
    double mean_x2 = mean(scatterplot2);
    double sum_of_products = 0;
    for (int i = 0; i < scatterplot1->num_points; i++) {
        sum_of_products += (scatterplot1->points[i].x - mean_x1) * (scatterplot2->points[i].x - mean_x2);
    }
    return sum_of_products / ((scatterplot1->num_points - 1) * stddev(scatterplot1) * stddev(scatterplot2));
}

// Print a scatter plot to a file
void print_scatterplot(struct scatterplot *scatterplot, FILE *file) {
    for (int i = 0; i < scatterplot->num_points; i++) {
        fprintf(file, "%f %f\n", scatterplot->points[i].x, scatterplot->points[i].y);
    }
}

int main() {
    // Create a scatter plot of the data in the file "data.txt"
    FILE *file = fopen("data.txt", "r");
    struct scatterplot *scatterplot = create_scatterplot(100);
    double x, y;
    while (fscanf(file, "%lf %lf", &x, &y) != EOF) {
        add_point(scatterplot, x, y);
    }
    fclose(file);

    // Compute the mean, standard deviation, and correlation coefficient of the scatter plot
    double mean_x = mean(scatterplot);
    double stddev_x = stddev(scatterplot);
    double corr_xy = corr(scatterplot, scatterplot);

    // Print the mean, standard deviation, and correlation coefficient to the console
    printf("Mean: %f\n", mean_x);
    printf("Standard deviation: %f\n", stddev_x);
    printf("Correlation coefficient: %f\n", corr_xy);

    // Print the scatter plot to a file
    file = fopen("scatterplot.txt", "w");
    print_scatterplot(scatterplot, file);
    fclose(file);

    // Free the scatter plot
    free_scatterplot(scatterplot);

    return 0;
}