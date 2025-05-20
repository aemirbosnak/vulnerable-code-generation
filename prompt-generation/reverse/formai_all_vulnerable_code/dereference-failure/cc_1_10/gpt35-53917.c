//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
// It was a chilly night in London as I put pen to paper to write this temperature monitor program.
// My trusty Watson had joined me in the study, but was sound asleep in his chair.
// I set to work, determined to create a unique program that would keep track of the temperature in a logical and efficient way.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define MAX_RECORDS 100
#define MAX_TEMP 45
#define MIN_TEMP -10

// Global variables
int numRecords = 0;
int temps[MAX_RECORDS];

// Function declarations
void addTemp(int temp);
void printStats();
void printRecords();

// Main function
int main()
{
    // Welcome the user
    printf("Welcome to the temperature monitor program.\n");

    // Continue until the user quits
    while (true)
    {
        // Prompt the user for input
        printf("\nEnter a temperature between -10 and 45 degrees Celsius, or 'q' to quit: ");
        char input[10];
        fgets(input, 10, stdin);

        // Check if the user wants to quit
        if (input[0] == 'q')
        {
            break;
        }

        // Convert the input to an integer
        int temp = atoi(input);

        // Check if the input is valid
        if (temp >= MIN_TEMP && temp <= MAX_TEMP)
        {
            // Add the temperature to the records
            addTemp(temp);
            printf("Temperature recorded.\n");
        }
        else
        {
            printf("Invalid input.\n");
        }
    }

    // Print the final statistics
    printStats();

    // Print all the recorded temperatures
    printRecords();

    return 0;
}

// Function to add a temperature to the records
void addTemp(int temp)
{
    temps[numRecords] = temp;
    numRecords++;
}

// Function to print the statistics
void printStats()
{
    // Calculate the average temperature
    int total = 0;
    for (int i = 0; i < numRecords; i++)
    {
        total += temps[i];
    }
    double average = (double)total / numRecords;

    // Calculate the highest and lowest temperatures
    int highest = MIN_TEMP;
    int lowest = MAX_TEMP;
    for (int i = 0; i < numRecords; i++)
    {
        if (temps[i] > highest)
        {
            highest = temps[i];
        }
        if (temps[i] < lowest)
        {
            lowest = temps[i];
        }
    }

    // Print the statistics
    printf("\nStatistics:\n");
    printf("Number of records: %d\n", numRecords);
    printf("Highest temperature: %d\n", highest);
    printf("Lowest temperature: %d\n", lowest);
    printf("Average temperature: %0.2f\n", average);
}

// Function to print all the recorded temperatures
void printRecords()
{
    // Get the current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Print the recorded temperatures
    printf("\nRecorded temperatures as of %02d:%02d:%02d on %02d/%02d/%04d:\n", t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon+1, t->tm_year+1900);
    for (int i = 0; i < numRecords; i++)
    {
        printf("%d degrees Celsius\n", temps[i]);
    }
}