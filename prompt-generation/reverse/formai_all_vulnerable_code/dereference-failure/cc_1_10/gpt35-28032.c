//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void colorCodeConverter();
int colorPrompt();

int main() {
    printf("Welcome to the C Color Code Converter!\n");
    colorCodeConverter();
    return 0;   
}

void colorCodeConverter() {
    int choice;
    char hexCode[7];
    char rgbCode[12];
    
    choice = colorPrompt();
    
    if(choice == 1) {
        printf("Please enter a 6-digit hexadecimal color code: ");
        scanf("%s", hexCode);
        
        int r = (int) strtol(hexCode, NULL, 16) >> 16;
        int g = (int) strtol(hexCode + 2, NULL, 16) >> 8;
        int b = (int) strtol(hexCode + 4, NULL, 16);
        
        printf("The RGB color code for %s is rgb(%d, %d, %d).", hexCode, r, g, b);
    }
    else if(choice == 2) {
        int r, g, b;
        
        printf("Please enter the red value (0-255): ");
        scanf("%d", &r);
        printf("Please enter the green value (0-255): ");
        scanf("%d", &g);
        printf("Please enter the blue value (0-255): ");
        scanf("%d", &b);
        
        sprintf(rgbCode, "#%02x%02x%02x", r, g, b);
        
        printf("The hexadecimal color code for RGB(%d, %d, %d) is %s.", r, g, b, rgbCode);
    }
    else {
        printf("Invalid choice!");
    }
}

int colorPrompt() {
    int choice;
    
    printf("1. Convert hexadecimal color code to RGB color code.\n");
    printf("2. Convert RGB color code to hexadecimal color code.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}