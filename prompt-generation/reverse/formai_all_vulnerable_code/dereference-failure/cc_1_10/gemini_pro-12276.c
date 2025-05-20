//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ASCII art for a retro thermometer
char *thermometer[] = {
    "  ______________",
    " |              |",
    " |____________  |",
    "  |            |  |",
    "  |____________|  |",
    "   |            |   |",
    "   |____________|   |",
    "    |            |    |",
    "    |____________|    |",
    "     |            |     |",
    "     |____________|     |",
    "      |            |      |",
    "      |____________|      |",
    "       |            |       |",
    "       |____________|       |",
    "        |            |        |",
    "        |____________|        |",
    "         |            |         |",
    "         |____________|         |",
    "          |            |          |"
};

// Function to update the thermometer with the current temperature
void update_thermometer(float temperature) {
    // Calculate the number of lines to fill in the thermometer
    int lines_to_fill = (int) (temperature / 5);

    // Fill in the lines of the thermometer
    for (int i = 0; i < lines_to_fill; i++) {
        thermometer[i][1] = '|';
        thermometer[i][2] = ' ';
    }

    // Clear the rest of the lines in the thermometer
    for (int i = lines_to_fill; i < 20; i++) {
        thermometer[i][1] = ' ';
        thermometer[i][2] = ' ';
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the current temperature
    float temperature = (float) (rand() % 100);

    // Update the thermometer
    update_thermometer(temperature);

    // Print the thermometer
    for (int i = 0; i < 20; i++) {
        printf("%s\n", thermometer[i]);
    }

    // Print the current temperature
    printf("Current temperature: %.1f degrees Celsius\n", temperature);

    return 0;
}