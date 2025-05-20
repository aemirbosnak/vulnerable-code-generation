//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
/*
 * This program demonstrates a configurable component for a performance-critical system.
 * The component reads configuration parameters from a file and performs mathematical calculations
 * based on those parameters. The calculations are timed to ensure that the component runs within
 * acceptable time limits.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_CONFIG_LEN 50
#define MAX_FILE_LEN 100

typedef struct config_params {
    double a, b, c;
    int n_iter;
} ConfigParams;

double calculate_result(double a, double b, double c, int n_iter) {
    double result = 0.0;
    int i;

    for (i = 0; i < n_iter; i++) {
        result = a * sin(result * b) + c;
    }

    return result;
}

void run_performance_test(ConfigParams params) {
    double start_time, end_time, result;
    int i;

    start_time = (double)clock() / CLOCKS_PER_SEC;

    for (i = 0; i < 100000; i++) {
        result = calculate_result(params.a, params.b, params.c, params.n_iter);
    }

    end_time = (double)clock() / CLOCKS_PER_SEC;

    printf("Result: %f\n", result);
    printf("Time elapsed: %f seconds\n", end_time - start_time);
}

int main(int argc, char *argv[]) {
    char config_file[MAX_FILE_LEN];
    char config_str[MAX_CONFIG_LEN];
    FILE *fp;
    ConfigParams params;

    if (argc == 1) {
        printf("Usage: %s <config_file>\n", argv[0]);
        exit(1);
    }

    strncpy(config_file, argv[1], MAX_FILE_LEN);

    fp = fopen(config_file, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", config_file);
        exit(1);
    }

    fgets(config_str, MAX_CONFIG_LEN, fp);
    fclose(fp);

    sscanf(config_str, "%lf,%lf,%lf,%d", &params.a, &params.b, &params.c, &params.n_iter);

    run_performance_test(params);

    return 0;
}