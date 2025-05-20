//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_WIDTH 80
#define PRINT_HEIGHT 25

int main() {
    // Initialize the printing parameters
    int x = 0;
    int y = 0;
    int char_width = 0;
    int char_height = 0;

    // Get the current time and date
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Calculate the printing dimensions
    char_width = PRINT_WIDTH * (current_time->tm_mday + 1);
    char_height = PRINT_HEIGHT * (current_time->tm_mon + 1);

    // Print the header
    printf("==============================================\n");
    printf("|                                             |");
    for (int i = 0; i < char_width; i++) {
        printf("|   %c", ' ');
    }
    printf("|\n");

    // Print the date and time
    printf("|  Date: %s", asctime(current_time));
    printf("|  Time: %s", ctime(current_time));
    printf("|\n");

    // Print the message
    char message[PRINT_HEIGHT][PRINT_WIDTH];
    for (int i = 0; i < PRINT_HEIGHT; i++) {
        for (int j = 0; j < PRINT_WIDTH; j++) {
            message[i][j] = ' ';
        }
    }
    message[0][0] = 'H';
    message[0][1] = 'E';
    message[0][2] = 'L';
    message[0][3] = 'L';
    message[1][0] = 'O';
    message[1][1] = ' ';
    message[2][0] = 'C';
    message[2][1] = 'R';
    message[2][2] = 'E';
    message[3][0] = 'A';
    message[3][1] = 'T';
    message[3][2] = 'E';

    // Print the message
    for (int i = 0; i < PRINT_HEIGHT; i++) {
        for (int j = 0; j < PRINT_WIDTH; j++) {
            printf("%c", message[i][j]);
        }
        printf("\n");
    }

    // Print the footer
    printf("==============================================\n");
    printf("|                                             |");
    for (int i = 0; i < char_width; i++) {
        printf("|   %c", ' ');
    }
    printf("|\n");

    return 0;
}