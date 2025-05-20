//FormAI DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// Function to generate random numbers between min and max (inclusive)
int random_number(int min, int max) 
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Asynchronous function to wait for a random amount of time between 1 and 5 seconds
void wait_random_time(int* flag) 
{
    int delay = random_number(1, 5);
    sleep(delay);
    *flag = 1;
}

int main() 
{
    int fd, *flag1, *flag2, *flag3, *flag4;

    // Open a new file to write the result of each dice roll
    fd = open("dice_rolls.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Check for errors opening the file
    if (fd == -1) 
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Create flags to signal when each dice roll is complete
    flag1 = malloc(sizeof(int));
    flag2 = malloc(sizeof(int));
    flag3 = malloc(sizeof(int));
    flag4 = malloc(sizeof(int));

    *flag1 = 0;
    *flag2 = 0;
    *flag3 = 0;
    *flag4 = 0;

    // Start asynchronous function to roll dice for each player
    pid_t pid1 = fork();

    if (pid1 == 0) 
    {
        int roll = random_number(1, 6);
        dprintf(fd, "Player 1 rolled a %d\n", roll);
        wait_random_time(flag1);
        exit(0);
    }

    pid_t pid2 = fork();

    if (pid2 == 0) 
    {
        int roll = random_number(1, 6);
        dprintf(fd, "Player 2 rolled a %d\n", roll);
        wait_random_time(flag2);
        exit(0);
    }

    pid_t pid3 = fork();

    if (pid3 == 0) 
    {
        int roll = random_number(1, 6);
        dprintf(fd, "Player 3 rolled a %d\n", roll);
        wait_random_time(flag3);
        exit(0);
    }

    pid_t pid4 = fork();

    if (pid4 == 0) 
    {
        int roll = random_number(1, 6);
        dprintf(fd, "Player 4 rolled a %d\n", roll);
        wait_random_time(flag4);
        exit(0);
    }

    // Wait for each player's dice roll to complete before printing the winner
    while (*flag1 == 0 || *flag2 == 0 || *flag3 == 0 || *flag4 == 0) 
    {
        sleep(1);
    }

    // Read the results of each player's roll from the file
    lseek(fd, 0, SEEK_SET);

    char buffer[256];
    char* line;
    int max_roll = 0;
    char* winner;

    while (read(fd, buffer, sizeof(buffer)) > 0) 
    {
        line = strtok(buffer, "\n");
        while (line != NULL) 
        {
            int roll;
            sscanf(line, "Player %*d rolled a %d", &roll);
            if (roll > max_roll) 
            {
                max_roll = roll;
                winner = strdup(line);
            }
            line = strtok(NULL, "\n");
        }
    }

    // Print the winner
    printf("The winner is %s!\n", winner);

    // Clean up allocated memory and close the file
    free(flag1);
    free(flag2);
    free(flag3);
    free(flag4);

    close(fd);

    return 0;
}