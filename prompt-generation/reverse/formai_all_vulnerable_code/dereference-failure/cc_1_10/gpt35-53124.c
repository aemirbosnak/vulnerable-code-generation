//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to print the selected activities in optimal order
void printActivities(int *start_time, int *finish_time, int n)
{
    int i, j;
    i = 0;
    printf("Selected activities are :\n");
  
    // The first activity is always selected
    printf("(%d, %d)\n", start_time[i], finish_time[i]);
  
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If start time of this activity is greater than or equal to the finish time of previously
      // selected activity, then select it
      if (start_time[j] >= finish_time[i])
      {
          printf("(%d, %d)\n", start_time[j], finish_time[j]);
          i = j;
      }
    }
}
 
// Driver program
int main()
{
    int n, i; 
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int *start_time = (int*) malloc(sizeof(int) * n);
    int *finish_time = (int*) malloc(sizeof(int) * n);

    // Accept start time and finish time for all activities
    printf("Enter the start and finish time for each activity:\n");
    for(i=0; i<n; i++){
        printf("Activity %d: ", i+1);
        scanf("%d%d", &start_time[i], &finish_time[i]);
    }

    // Sort activities based on their finishing time
    int j;
    for(i=1; i<n; i++){
        int key1 = finish_time[i];
        int key2 = start_time[i];
        j = i-1;
        while(j>=0 && finish_time[j]>key1){
            finish_time[j+1] = finish_time[j];
            start_time[j+1] = start_time[j];
            j = j-1;
        }
        finish_time[j+1] = key1;
        start_time[j+1] = key2;
    }

    // Print the selected activities in optimal order
    printActivities(start_time, finish_time, n);
    return 0;
}