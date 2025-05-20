//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main()
{
    // Welcome message to the user 
    printf("Welcome to the Mind-Bending C Color Code Converter Program!\n");

    // Prompt the user to enter a color code 
    printf("Please enter a 6-digit hexadecimal color code: ");
    char color_code[7];
    fgets(color_code, sizeof(color_code), stdin);

    // Convert the entered color code from string to integer
    int r = (int) strtol(color_code, NULL, 16);
    int g = (int) strtol(color_code+2, NULL, 16);
    int b = (int) strtol(color_code+4, NULL, 16);

    // Display the converted values
    printf("\nThe RGB values for the entered color code are:\n");
    printf("R: %d\n", r);
    printf("G: %d\n", g);
    printf("B: %d\n", b);

    // Ask the user if they want to convert another color code
    printf("\nDo you want to convert another color code? (Y/N): ");
    char response[2];
    fgets(response, sizeof(response), stdin);

    // If the user responds with "yes", restart the program
    if (response[0] == 'y' || response[0] == 'Y') {
        main();
    }

    // If the user responds with "no", exit the program
    else if (response[0] == 'n' || response[0] == 'N') {
        printf("\nThank you for using the Mind-Bending C Color Code Converter Program!\n");
        exit(0);
    }

    // If the user enters an invalid response, display an error message and restart the program
    else {
        printf("\nInvalid entry. Please enter Y/N.\n");
        main();
    }

    // Return 0
    return 0;
}