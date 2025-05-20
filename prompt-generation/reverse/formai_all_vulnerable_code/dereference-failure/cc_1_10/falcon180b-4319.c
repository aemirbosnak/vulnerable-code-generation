//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RED 0
#define GREEN 1
#define YELLOW 2

// Function to initialize the traffic lights
void init(int arr[][3], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            arr[i][j] = RED;
        }
    }
}

// Function to change the traffic light color
void changeLight(int arr[][3], int x, int y, int color)
{
    if (arr[x][y] == RED) {
        arr[x][y] = GREEN;
    } else if (arr[x][y] == GREEN) {
        arr[x][y] = YELLOW;
    } else if (arr[x][y] == YELLOW) {
        arr[x][y] = RED;
    }
}

// Function to print the traffic light status
void printLights(int arr[][3], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to simulate the traffic flow
void trafficFlow(int arr[][3], int n, int m)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            if (arr[i][j] == GREEN) {
                count++;
            }
        }
    }
    if (count == m) {
        srand(time(NULL));
        int x = rand() % n;
        int y = rand() % 3;
        while (arr[x][y]!= RED) {
            x = rand() % n;
            y = rand() % 3;
        }
        changeLight(arr, x, y, RED);
    }
}

int main()
{
    int n, m;
    printf("Enter the number of traffic lights: ");
    scanf("%d", &n);
    printf("Enter the number of green lights required: ");
    scanf("%d", &m);

    int arr[n][3];
    init(arr, n);

    while (1) {
        system("clear");
        printLights(arr, n);
        trafficFlow(arr, n, m);
        sleep(1);
    }

    return 0;
}