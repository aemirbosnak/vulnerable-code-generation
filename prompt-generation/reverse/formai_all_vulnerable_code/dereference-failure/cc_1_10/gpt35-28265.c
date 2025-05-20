//FormAI DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to detect user input
char getUserInput()
{
    char c;
    printf("Enter your light preference (ON/OFF): ");
    scanf(" %c", &c);
    return toupper(c);
}

int main()
{
    // Set initial light state to "OFF"
    char lightState = 'OFF';
    
    // Display welcome message and instructions
    printf("Welcome to the Smart Home Light Control Program!\n");
    printf("You can turn the light on or off by typing 'ON' or 'OFF'.\n");
    printf("Enter 'QUIT' to exit the program.\n\n");
    
    // Loop until user enters "QUIT"
    while(1)
    {
        // Get user input
        char userInput = getUserInput();
        
        // Check if user wants to quit
        if(userInput == 'QUIT')
        {
            printf("Exiting program...\n");
            break;
        }

        // If user entered "ON"
        if(userInput == 'ON')
        {
            // If light is already on, notify user
            if(lightState == 'ON')
            {
                printf("The light is already on!\n");
            }
            // Otherwise, turn light on
            else
            {
                lightState = 'ON';
                printf("Turning light on...\n");
            }
        }
        
        // If user entered "OFF"
        else if(userInput == 'OFF')
        {
            // If light is already off, notify user
            if(lightState == 'OFF')
            {
                printf("The light is already off!\n");
            }
            // Otherwise, turn light off
            else
            {
                lightState = 'OFF';
                printf("Turning light off...\n");
            }
        }
        
        // If user entered something else, notify user of error
        else
        {
            printf("Invalid input! Please enter 'ON', 'OFF', or 'QUIT'.\n");
        }

        /* Randomly change the shape of the program based on the current time 
           (just for fun!) */

        // Get current time
        time_t currentTime;
        time(&currentTime);

        // Get current second (0-59)
        int currentSecond = localtime(&currentTime)->tm_sec;

        // If current second is even, make program square-shaped
        if(currentSecond % 2 == 0)
        {
            printf("------------\n");
            printf("|          |\n");
            printf("|          |\n");
            printf("|  %5s   |\n", lightState);
            printf("|          |\n");
            printf("|          |\n");
            printf("------------\n");
        }
        // If current second is odd, make program triangle-shaped
        else
        {
            printf("     /\\\n");
            printf("    /  \\\n");
            printf("   /    \\\n");
            printf("  /------\\\n");
            printf(" /        \\\n");
            printf("/    %5s   \\\n", lightState);
            printf("-----------\n");
        }
    }

    return 0;
}