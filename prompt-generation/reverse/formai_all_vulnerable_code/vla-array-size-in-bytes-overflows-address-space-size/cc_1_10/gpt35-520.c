//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

//Define the struct for storing activity details
struct activity {
    int start; //Start time of the activity
    int end; //End time of the activity
};

//Comparator function for sorting the activities based on their end times
int cmpfunc(const void* a, const void* b) {
    struct activity* act_a = (struct activity*) a;
    struct activity* act_b = (struct activity*) b;
    return (act_a->end - act_b->end);
}

int main() {
    //Declare and initialize the variables
    int n, i, j;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    struct activity act[n];
    int selectedArr[n];
    int count = 1, curr_end, next_start;

    //Get the activity details from the user
    for (i=0; i<n; i++) {
        printf("Enter the start and end times for activity %d: ", i+1);
        scanf("%d %d", &act[i].start, &act[i].end);
    }

    //Sort the activities based on their end times
    qsort(act, n, sizeof(struct activity), cmpfunc);

    //Select the first activity as the starting point
    selectedArr[0] = 1;
    curr_end = act[0].end;

    //Select the activities with the earliest end time
    for (i=1; i<n; i++) {
        next_start = act[i].start;
        if (next_start >= curr_end) {
            selectedArr[count] = i + 1;
            count++;
            curr_end = act[i].end;
        }
    }

    //Print the selected activities
    printf("The selected activities are: ");
    for (i=0; i<count; i++) {
        printf("%d ", selectedArr[i]);
    }
    printf("\n");

    return 0;
}