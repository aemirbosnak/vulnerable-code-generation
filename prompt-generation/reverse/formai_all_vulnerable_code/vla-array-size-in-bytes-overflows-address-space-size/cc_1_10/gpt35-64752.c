//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include<stdio.h>

int main(){

    int n, i, j, temp, maxProfit = 0;
    printf("Enter the number of jobs:\n");
    scanf("%d", &n);

    int deadline[n], profit[n];

    printf("Enter the deadline and profit for each job:\n");

    // Taking input
    for(i=0;i<n;i++){
        printf("Deadline and Profit for job %d:\n", i+1);
        scanf("%d %d", &deadline[i], &profit[i]);
    }

    // Sorting in descending order by profit
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(profit[j] < profit[j+1]){
                // Sorting profit
                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;
                // Sorting deadlines
                temp = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = temp;
            }
        }
    }

    int completedJobs[n];
    for(i=0;i<n;i++){
        completedJobs[i] = 0;
    }

    // Job scheduling
    for(i=0;i<n;i++){
        for(j=deadline[i]-1;j>=0;j--){
            if(completedJobs[j] == 0){
                completedJobs[j] = i+1;
                maxProfit += profit[i];
                break;
            }
        }
    }

    // Printing the schedule
    printf("Job Schedule:\n");
    for(i=0;i<n;i++){
        printf("Job %d\n", completedJobs[i]);
    }

    // Printing the maximum profit
    printf("Maximum Profit = %d\n", maxProfit);

    return 0;
}