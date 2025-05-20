//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>

int main() {
    
    int n; // number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    int jobs[n][2]; // array to store job information
    
    // get job information from user
    for(int i = 0; i < n; i++) {
        printf("Enter the start time of job %d: ", i+1);
        scanf("%d", &jobs[i][0]);
        printf("Enter the end time of job %d: ", i+1);
        scanf("%d", &jobs[i][1]);
    }
    
    // sort the jobs array based on end times using bubble sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(jobs[j][1] > jobs[j+1][1]) {
                int temp1 = jobs[j][0];
                int temp2 = jobs[j][1];
                jobs[j][0] = jobs[j+1][0];
                jobs[j][1] = jobs[j+1][1];
                jobs[j+1][0] = temp1;
                jobs[j+1][1] = temp2;
            }
        }
    }
    
    // schedule the jobs
    int scheduled[n];
    int num_jobs = 0;
    scheduled[num_jobs++] = 0;
    int last_end = jobs[0][1];
    for(int i = 1; i < n; i++) {
        if(jobs[i][0] >= last_end) {
            scheduled[num_jobs++] = i;
            last_end = jobs[i][1];
        }
    }
    
    // print out the scheduled jobs
    printf("Scheduled jobs: ");
    for(int i = 0; i < num_jobs; i++) {
        printf("%d ", scheduled[i]+1); // add 1 to get job number
    }
    printf("\n");
    
    return 0;
}