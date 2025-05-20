//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Constants for the size of the game screen
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

//Struct for holding the position of objects in the game
typedef struct
{
    int x;
    int y;
} Position;

//Function for generating a random integer between two values
int rand_between(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

//Function for generating a new random position within the bounds of the game screen
Position generate_position()
{
    Position pos;
    pos.x = rand_between(0, SCREEN_WIDTH - 1);
    pos.y = rand_between(0, SCREEN_HEIGHT - 1);
    return pos;
}

//Main function for the game
int main()
{
    //Seed the random number generator with the current time
    srand(time(NULL));

    //Generate the player's starting position
    Position player_pos = generate_position();

    //Generate a number of random obstacles
    int num_obstacles = rand_between(5, 10);
    Position* obstacle_positions = malloc(sizeof(Position) * num_obstacles);
    for (int i = 0; i < num_obstacles; i++)
    {
        obstacle_positions[i] = generate_position();
    }

    //Generate the goal position
    Position goal_pos = generate_position();

    //Loop for the game
    while (1)
    {
        //Clear the screen
        system("clear");

        //Print the game screen with the player, obstacles, and goal
        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < SCREEN_WIDTH; x++)
            {
                if (x == player_pos.x && y == player_pos.y)
                {
                    printf("@");
                }
                else if (x == goal_pos.x && y == goal_pos.y)
                {
                    printf("G");
                }
                else
                {
                    int obstacle_here = 0;
                    for (int i = 0; i < num_obstacles; i++)
                    {
                        if (obstacle_positions[i].x == x && obstacle_positions[i].y == y)
                        {
                            printf("#");
                            obstacle_here = 1;
                            break;
                        }
                    }
                    if (!obstacle_here)
                    {
                        printf(".");
                    }
                }
            }
            printf("\n");
        }

        //Get the player's next move
        char input;
        scanf(" %c", &input);
        int new_x = player_pos.x;
        int new_y = player_pos.y;
        switch (input)
        {
            case 'w':
                new_y--;
                break;
            case 'a':
                new_x--;
                break;
            case 's':
                new_y++;
                break;
            case 'd':
                new_x++;
                break;
            default:
                break;
        }

        //Check if the new position is valid
        int valid_move = 1;
        if (new_x < 0 || new_x >= SCREEN_WIDTH || new_y < 0 || new_y >= SCREEN_HEIGHT)
        {
            valid_move = 0;
        }
        for (int i = 0; i < num_obstacles; i++)
        {
            if (obstacle_positions[i].x == new_x && obstacle_positions[i].y == new_y)
            {
                valid_move = 0;
                break;
            }
        }

        //Move the player if the move is valid
        if (valid_move)
        {
            player_pos.x = new_x;
            player_pos.y = new_y;
            if (player_pos.x == goal_pos.x && player_pos.y == goal_pos.y)
            {
                printf("You win!\n");
                break;
            }
        }
    }

    //Free the memory used by the obstacle_positions array
    free(obstacle_positions);

    return 0;
}