//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DISKS 10

int n; // Number of disks
int towerA[MAX_DISKS], towerB[MAX_DISKS], towerC[MAX_DISKS];

void printTower(int tower[])
{
    printf("\n");
    for (int i = n - 1; i >= 0; i--)
    {
        if (tower[i] == 0)
            printf("          ");
        else
            printf("      %d     ", tower[i]);

        printf("\n");
    }
    printf("\n");
}

void moveDisk(int* source, int* destination)
{
    (*destination)--; // Move one step up
    *destination = *source; // Move disk

    (*source)++; // Move one step down
}

void move(int num_disks, int* source, int* destination, int* temp)
{
    if (num_disks == 1)
    {
        moveDisk(source, destination);
        return;
    }

    move(num_disks - 1, source, temp, destination);
    moveDisk(source, destination);
    move(num_disks - 1, temp, destination, source);
}

void solve()
{
    printTower(towerA);
    printf("TOWER OF HANOI : %d DISKS\n\n", n);

    move(n, &towerA[n - 1], &towerC[n - 1], &towerB[n - 1]);

    printTower(towerA);
    printTower(towerB);
    printTower(towerC);
}

bool validateInput(int argc, char** argv)
{
    if (argc != 2)
        return false;

    if (strlen(argv[1]) > 1 || argv[1][0] < '1' || argv[1][0] > MAX_DISKS + '0')
        return false;

    return true;
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);

    if (!validateInput(argc, argv))
    {
        printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_DISKS);
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        towerA[i] = i + 1;

    solve();

    return EXIT_SUCCESS;
}