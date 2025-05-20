//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define a structure for jobs containing their start, end, and profit time
struct job {
    int start;
    int end;
    int profit;
};

// Define a nested structure to hold the array of jobs and their length
struct job_set {
    struct job* arr;
    int length;
};

// Define a function to sort the jobs by their ending time in ascending order
int cmp(const void *a, const void *b) {
    struct job* jobA = (struct job*)a;
    struct job* jobB = (struct job*)b;

    return (jobA->end - jobB->end);
}

// Define the greedy algorithm function to maximize the profit
int max_profit(struct job_set jobs) {
    // Sort the jobs in the set by their ending time (in ascending order)
    qsort(jobs.arr, jobs.length, sizeof(jobs.arr[0]), cmp);

    // Create a dynamic programming table to store the profit values
    int* profit_table = (int*)calloc(jobs.length, sizeof(int));

    // Initialize the first profit value to be the profit of the first job
    profit_table[0] = jobs.arr[0].profit;

    // Loop through each job in the set
    for (int i = 1; i < jobs.length; i++) {
        int current_profit = jobs.arr[i].profit;
        int latest_job_index = -1;

        // Find the latest job that does not conflict with the current job
        for (int j = i - 1; j >= 0; j--) {
            if (jobs.arr[j].end <= jobs.arr[i].start) {
                latest_job_index = j;
                break;
            }
        }

        // Add the profit of the latest non-conflicting job, if one exists, to the current profit
        if (latest_job_index != -1) {
            current_profit += profit_table[latest_job_index];
        }

        // Choose the maximum between the current profit and the previous maximum profit
        profit_table[i] = (current_profit > profit_table[i - 1]) ? current_profit : profit_table[i - 1];
    }

    // Store the final maximum profit value and free the dynamic programming table
    int final_max_profit = profit_table[jobs.length - 1];
    free(profit_table);

    return final_max_profit;
}

int main() {
    // Create an example job set
    struct job_set jobs = {
        .arr = (struct job[]){
            {1, 4, 2}, {3, 8, 5}, {2, 6, 3}, {4, 7, 4}},
        .length = 4
    };

    // Calculate the maximum profit using the greedy algorithm and print the result
    int final_max_profit = max_profit(jobs);
    printf("The maximum profit that can be earned is $%d.\n", final_max_profit);

    return 0;
}