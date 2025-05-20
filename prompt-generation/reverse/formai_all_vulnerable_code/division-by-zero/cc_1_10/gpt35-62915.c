//FormAI DATASET v1.0 Category: Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define MAX_EXPR_SIZE 100
#define MAX_THREADS 10

typedef struct {
    int index; // Thread index
    char *expression; // Expression to evaluate
    long result; // Result of evaluation
    pthread_t thread; // Thread ID
} async_result;

void *evaluate_expression(void *arg) {
    async_result *result = (async_result *) arg;
    char command[100];
    sprintf(command, "echo '%s' | bc", result->expression);
    FILE *fp = popen(command, "r");

    char line[100];
    fgets(line, sizeof(line), fp); // Read result from pipe
    result->result = strtol(line, NULL, 10); // Convert to long integer

    printf("Thread %d: Expression '%s' evaluated to %ld\n", result->index, result->expression, result->result);

    pclose(fp);
    return NULL;
}

int main() {
    char expression[MAX_EXPR_SIZE];
    async_result results[MAX_THREADS];

    while (1) {
        printf("Enter expression to evaluate (or 'quit' to exit): ");
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = 0; // Remove newline character

        if (strcmp(expression, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        }

        int num_threads;
        printf("Enter number of threads to use: ");
        scanf("%d", &num_threads);

        if (num_threads > MAX_THREADS) {
            printf("Maximum number of threads exceeded. Using %d threads instead.\n", MAX_THREADS);
            num_threads = MAX_THREADS;
        }

        // Split expression into chunks for each thread
        int chunk_size = strlen(expression) / num_threads;
        int remainder = strlen(expression) % num_threads;

        int start_index = 0;
        int end_index = chunk_size;

        // Create async_result structure for each thread
        for (int i = 0; i < num_threads; i++) {
            if (i == num_threads - 1) {
                end_index += remainder;
            }

            char sub_expression[MAX_EXPR_SIZE];
            strncpy(sub_expression, &expression[start_index], end_index - start_index);
            sub_expression[end_index - start_index] = '\0';

            results[i].index = i;
            results[i].expression = strdup(sub_expression);

            pthread_create(&results[i].thread, NULL, evaluate_expression, &results[i]);

            start_index = end_index;
            end_index += chunk_size;
        }

        // Wait for each thread to finish and add up results
        long total_result = 0;
        for (int i = 0; i < num_threads; i++) {
            pthread_join(results[i].thread, NULL);
            total_result += results[i].result;
            free(results[i].expression); // Free memory allocated by strdup
        }

        printf("Total result: %ld\n", total_result);
        fflush(stdout); // Flush output buffer
        while (getchar() != '\n'); // Clear input buffer
    }

    return 0;
}