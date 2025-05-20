//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
// Welcome to the Cyberpunk Greedy Algorithm Example
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the jobs we will be completing
typedef struct job {
    int jobnum;
    int deadline;
    int profit;
} job;

// Prototype for the function to sort the jobs in order of largest profit
void sort_jobs(job *jobs, int num_jobs);

int main() {
    int num_jobs;

    // Allow the user to input the number of jobs they want to complete
    printf("How many jobs would you like to complete? ");
    scanf("%d", &num_jobs);

    // Allocate memory for the jobs array
    job *jobs = (job*)malloc(num_jobs * sizeof(job));

    // Allow the user to input the details of each job
    for(int i = 0; i < num_jobs; i++) {
        printf("\nJob %d Details:\n", i+1);
        jobs[i].jobnum = i+1;
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }

    // Sort the jobs in order of largest profit
    sort_jobs(jobs, num_jobs);

    // Complete the jobs in order of profit until you reach the deadline
    int total_profit = 0;
    int current_deadline = jobs[0].deadline;

    for(int i = 0; i < num_jobs; i++) {
        if(jobs[i].deadline >= current_deadline) {
            current_deadline--;
            total_profit += jobs[i].profit;
            printf("\nJob %d completed, profit: %d\n", jobs[i].jobnum, jobs[i].profit);
        }
        if(current_deadline == 0) {
            printf("\nTime's up, you missed your deadline!\n");
            break;
        }
    }

    // Print the total profit made from completing the jobs
    printf("\nTotal profit: %d\n", total_profit);

    return 0;
}

void sort_jobs(job *jobs, int num_jobs) {
    for (int i = 0; i < num_jobs-1; i++) {
        // Find the maximum profit job and swap it with the current job
        int max_index = i;
        for (int j = i+1; j < num_jobs; j++) {
            if (jobs[j].profit > jobs[max_index].profit) {
                max_index = j;
            }
        }
        job temp = jobs[i];
        jobs[i] = jobs[max_index];
        jobs[max_index] = temp;
    }
}