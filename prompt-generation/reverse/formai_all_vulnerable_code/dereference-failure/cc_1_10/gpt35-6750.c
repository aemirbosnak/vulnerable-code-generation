//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print current time
void getTime()
{
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);                   // Get current time
    localTime = localtime(&currentTime);  // Convert to local time
    printf("Current Time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}

// Function to display traffic light colors
void displayLight(int red, int yellow, int green)
{
    if(red == 1) printf("Red Light: ON\n");
    else printf("Red Light: OFF\n");
    if(yellow == 1) printf("Yellow Light: ON\n");
    else printf("Yellow Light: OFF\n");
    if(green == 1) printf("Green Light: ON\n");
    else printf("Green Light: OFF\n");
}

int main()
{
    int red = 1, yellow = 0, green = 0; // Initial states of traffic lights
    printf("Traffic Light Controller\n");
    printf("=========================\n");
    printf("Press Enter to start the simulation.\n");
    getchar(); // Wait for user input

    // Start the traffic light simulation
    while(1)
    {
        system("clear"); // Clear the console
        getTime();       // Print current time
        displayLight(red, yellow, green); // Display current traffic light status

        if(red == 1 && yellow == 0 && green == 0) // Red light is on
        {
            printf("\n");
            printf("Wait for 20 seconds...\n");
            sleep(20); // Wait for 20 seconds
            yellow = 1; // Turn on yellow light
            red = 0;    // Turn off red light
        }
        else if(red == 0 && yellow == 1 && green == 0) // Yellow light is on
        {
            printf("\n");
            printf("Wait for 5 seconds...\n");
            sleep(5);  // Wait for 5 seconds
            green = 1; // Turn on green light
            yellow = 0; // Turn off yellow light
        }
        else if(red == 0 && yellow == 0 && green == 1) // Green light is on
        {
            printf("\n");
            printf("Wait for 30 seconds...\n");
            sleep(30); // Wait for 30 seconds
            yellow = 1; // Turn on yellow light
            green = 0;  // Turn off green light
        }
        else // Error state
        {
            printf("Error: Unknown traffic light configuration.\n");
            exit(1); // Exit program
        }
    }

    return 0;
}