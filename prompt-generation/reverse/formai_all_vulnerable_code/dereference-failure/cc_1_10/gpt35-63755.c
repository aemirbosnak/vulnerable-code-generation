//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

// Constants
#define BUFFER_SIZE 1024
#define NUM_PROCESSES 2

// Variables
int player_scores[NUM_PROCESSES] = {0};
int pipe_fd[NUM_PROCESSES][2];

// Prototypes
void child_process(int player_num);
void parent_process();
void close_pipes();

/**
 * Entry point of the program
 */
int main(int argc, char const *argv[])
{
    printf("Welcome to the Interprocess Communication Game!\n");

    // Create pipes
    for(int i = 0; i < NUM_PROCESSES; i++)
    {
        if(pipe(pipe_fd[i]) == -1)
        {
            printf("Error creating pipe %d: %s\n", i, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // Create child processes
    pid_t pid;
    for(int i = 0; i < NUM_PROCESSES; i++)
    {
        pid = fork();
        if(pid == -1)
        {
            printf("Error creating child process %d: %s\n", i, strerror(errno));
            exit(EXIT_FAILURE);
        }
        else if(pid == 0)
        {
            child_process(i);
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process loop
    parent_process();

    // Close pipes
    close_pipes();

    printf("Thanks for playing!\n");

    return 0;
}

/**
 * Child process code
 */
void child_process(int player_num)
{
    printf("Player %d ready!\n", player_num);

    // Close unused pipe ends
    for(int i = 0; i < NUM_PROCESSES; i++)
    {
        if(i != player_num)
        {
            close(pipe_fd[i][0]);
        }
    }

    // Play the game
    int num_guesses = 0;
    char buffer[BUFFER_SIZE];
    while(num_guesses < 3)
    {
        printf("Player %d, enter your guess: ", player_num);
        fflush(stdout);
        fgets(buffer, BUFFER_SIZE, stdin);

        // Write guess to other player
        write(pipe_fd[(player_num + 1) % NUM_PROCESSES][1], buffer, strlen(buffer));

        // Read other player's guess
        read(pipe_fd[player_num][0], buffer, BUFFER_SIZE);

        // Convert guesses to integers and compare
        int my_guess = atoi(buffer);
        int other_guess = atoi(buffer + strlen(buffer) / 2);

        if(my_guess > other_guess)
        {
            player_scores[player_num]++;
            printf("Your guess was bigger! Your score: %d\n", player_scores[player_num]);
        }
        else if(my_guess < other_guess)
        {
            player_scores[(player_num + 1) % NUM_PROCESSES]++;
            printf("Your guess was smaller! Your score: %d\n", player_scores[player_num]);
        }
        else
        {
            printf("It's a tie! Your score: %d\n", player_scores[player_num]);
        }

        num_guesses++;
    }

    printf("Player %d has finished playing!\n", player_num);

    // Close used pipe ends
    close(pipe_fd[player_num][0]);
    close(pipe_fd[(player_num + 1) % NUM_PROCESSES][1]);
}

/**
 * Parent process code
 */
void parent_process()
{
    // Close unused pipe ends
    for(int i = 0; i < NUM_PROCESSES; i++)
    {
        close(pipe_fd[i][1]);
    }

    char buffer[BUFFER_SIZE];
    while(1)
    {
        // Read player 1's guess
        read(pipe_fd[0][0], buffer, BUFFER_SIZE);

        // Write guess to player 2
        write(pipe_fd[1][1], buffer, strlen(buffer));

        // Read player 2's guess
        read(pipe_fd[1][0], buffer, BUFFER_SIZE);

        // Write guess to player 1
        write(pipe_fd[0][1], buffer, strlen(buffer));

        // Check for game over
        int max_score = NUM_PROCESSES * 3;
        if(player_scores[0] >= max_score || player_scores[1] >= max_score)
        {
            break;
        }
    }

    // Print final scores
    printf("Final scores: Player 1: %d, Player 2: %d\n", player_scores[0], player_scores[1]);
}

/**
 * Close all pipes
 */
void close_pipes()
{
    for(int i = 0; i < NUM_PROCESSES; i++)
    {
        close(pipe_fd[i][0]);
        close(pipe_fd[i][1]);
    }
}