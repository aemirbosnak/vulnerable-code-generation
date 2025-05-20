//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

Activity* selectActivities(Activity arr[], int n);

void printActivities(Activity arr[], int n) {
    printf("Selected activities: ");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i].start, arr[i].finish);
    }
}

int main() {
    //creating an array of activities
    Activity activities[] = {{1, 3}, {2, 5}, {3, 8}, {4, 10}, {5, 11}, {6, 15}, {7, 12}, {8, 13}, {9, 14}, {10, 16}};

    //calculating length of the array
    int n = sizeof(activities) / sizeof(activities[0]);

    //calling the selectActivities function
    Activity* selectedActivities = selectActivities(activities, n);

    //printing the selected activities
    printActivities(selectedActivities, n);

    return 0;
}

Activity* selectActivities(Activity arr[], int n) {
    //sorting the activities by their finish time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j].finish < arr[i].finish) {
                Activity temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //selecting the activities
    Activity* selectedActivities = (Activity*) malloc(n * sizeof(Activity));
    int i = 0;
    int j;
    selectedActivities[i] = arr[i];
    for (j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            i++;
            selectedActivities[i] = arr[j];
        }
    }
    return selectedActivities;
}