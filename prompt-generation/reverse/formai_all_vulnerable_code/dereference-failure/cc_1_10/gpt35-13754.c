//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define the surrealistic painting of our colour code converter
void surrealistic_painting(void){
    printf("\n~~~~~~~~~~~~~~~\n");
    printf("|    |  |    | |\n");
    printf("|  | |  | |  | |\n");
    printf("|---|---|-|--| |\n");
    printf("|  | |  | |  | |\n");
    printf("|  | |  | |  | |\n");
    printf("~~~~~~~~~~~~~~~\n");
}

// Declare the function to convert hex code to RGB code
void hex_to_rgb(char hex_code[]);

int main(){
    char choice;
    char hex_code[7];

    // Ask the user if they would like to start the program
    printf("Do you want to start the Color Code Converter? [y/n]: ");
    scanf("%c", &choice);

    // Create an infinite loop until user decides to exit
    while(1){
        // If user chooses to start program
        if(choice == 'y'){
            printf("\nEnter a 6-digit hexadecimal color code to convert (without '#' symbol): ");
            scanf("%s", &hex_code);

            // Convert the hex code to RGB code
            hex_to_rgb(hex_code);

            // Ask user if they want to convert another code or exit
            printf("\nDo you want to convert another code? [y/n]: ");
            scanf(" %c", &choice);
        }
        // If user decides to exit the program
        else if(choice == 'n'){
            printf("\nExiting Color Code Converter...");
            exit(0);
        }
        // If user inputs an incorrect value
        else{
            printf("\nInvalid choice! Please enter 'y' or 'n' to continue.\n");
            printf("Do you want to start the Color Code Converter? [y/n]: ");
            scanf(" %c", &choice);
        }
    }

    return 0;
}

// Define the function to convert hex code to RGB code
void hex_to_rgb(char hex_code[]){
    int r, g, b;
    // Convert the 2-digit substrings of the hex code to decimal values for RGB
    r = (int)strtol(hex_code, NULL, 16) >> 16;
    g = (int)strtol(hex_code + 2, NULL, 16) >> 8;
    b = (int)strtol(hex_code + 4, NULL, 16);
    // Print the resulting RGB code to the user
    printf("\nRGB code: %d,%d,%d\n", r,g,b);
    surrealistic_painting(); // Call the surrealistic painting function to add a touch of surrealist art to the program
}