//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>

int main() {
    int n; // number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int start[n], end[n];
    // taking inputs
    for (int i = 0; i < n; i++) {
        printf("Enter start time of activity %d: ", i + 1);
        scanf("%d", &start[i]);

        printf("Enter end time of activity %d: ", i + 1);
        scanf("%d", &end[i]);
    }

    // implementing selection sort on the end time array
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (end[j] < end[min]) {
                min = j;
            }
        }
        int temp = end[i];
        end[i] = end[min];
        end[min] = temp;

        temp = start[i];
        start[i] = start[min];
        start[min] = temp;
    }

    int selected[n];
    int count = 1; // first activity is always selected
    selected[0] = 0; // index of first activity

    int last_end_time = end[0];
    for (int i = 1; i < n; i++) {
        if (start[i] >= last_end_time) {
            // next activity starts after last activity ends
            selected[count] = i; // selecting this activity
            count++;
            last_end_time = end[i]; // updating the last end time
        }
    }

    // print the selected activities
    printf("Selected activities are: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", selected[i] + 1);
    }
    printf("\n");

    return 0;
}