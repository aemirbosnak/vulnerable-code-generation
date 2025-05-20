//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function Declarations
void displayMenu();
void displayTemperature(float temperature);
float readTemperature();
void createLogFile(float temperature);

int main() {
    int choice;
    float temperature;

    // Setting the background color and clear the screen
    printf("\033[H\033[J"); // Clear the screen
    printf("\033[1;32m"); // Change text to green

    // Introduction
    printf(" *********************************\n");
    printf(" *     🌡️ Temperature Monitor    *\n");
    printf(" *      by Artistic Programmer     *\n");
    printf(" *********************************\n");

    while (1) {
        displayMenu();
        printf(" Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Read Temperature
                temperature = readTemperature();
                displayTemperature(temperature);
                break;

            case 2: // Log Temperature
                temperature = readTemperature();
                createLogFile(temperature);
                break;

            case 3: // Exit
                printf("\033[0m"); // Reset text color
                printf(" Exiting the Temperature Monitor. Goodbye! 🌡️\n");
                return 0;

            default:
                printf(" Invalid option! Please try again. \n");
                break;
        }
    }
}

void displayMenu() {
    printf("\n 🌡️  Main Menu 🌡️\n");
    printf(" 1. Read Current Temperature\n");
    printf(" 2. Log Current Temperature\n");
    printf(" 3. Exit\n");
}

void displayTemperature(float temperature) {
    printf("\n 🥵 Current Temperature: %.2f°C\n", temperature);
    if (temperature < 0) {
        printf(" ❄️ It's freezing out there! Stay warm! \n");
    } else if (temperature < 15) {
        printf(" 🌬️ A bit chilly! Don’t forget your coat! \n");
    } else if (temperature < 25) {
        printf(" ☀️ It's a comfortable temperature! Enjoy! \n");
    } else {
        printf(" 🔥 Hot day! Stay hydrated! \n");
    }
}

float readTemperature() {
    // Simulate reading temperature
    srand(time(NULL));
    float temperature = (float)(rand() % 401 - 100) / 10; // Random temperature between -10.0 to 30.0
    return temperature;
}

void createLogFile(float temperature) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        perror("Unable to open log file.");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "%02d-%02d-%04d %02d:%02d:%02d - Temperature: %.2f°C\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, temperature);

    fclose(file);
    printf(" 📥 Temperature logged successfully!\n");
}