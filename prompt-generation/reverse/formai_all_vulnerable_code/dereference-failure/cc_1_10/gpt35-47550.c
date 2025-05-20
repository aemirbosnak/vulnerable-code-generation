//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex_digit)
{
    if (hex_digit >= '0' && hex_digit <= '9')
        return (int)(hex_digit - '0');
    else if (hex_digit >= 'A' && hex_digit <= 'F')
        return (int)(hex_digit - 'A' + 10);
    else if (hex_digit >= 'a' && hex_digit <= 'f')
        return (int)(hex_digit - 'a' + 10);    
    else
        return -1;  // Return -1 for invalid digits
}

// Function to convert RGB colors to hexadecimal
char* RGB_to_hex(int R, int G, int B)
{
    char* hex_color = (char*)malloc(7 * sizeof(char));  // allocate memory for the hex color code
    
    sprintf(hex_color, "%02X%02X%02X", R, G, B);   // Use sprintf to format the hexadecimal string
    
    return hex_color;
}

// Function to convert hexadecimal colors to RGB
void hex_to_RGB(char *hex_color, int *R, int *G, int *B)
{   
    // Convert the first two hex digits to decimal for red
    *R = hex_to_dec(hex_color[0]) * 16 + hex_to_dec(hex_color[1]);
    
    // Convert the next two hex digits to decimal for green
    *G = hex_to_dec(hex_color[2]) * 16 + hex_to_dec(hex_color[3]);
    
    // Convert the last two hex digits to decimal for blue
    *B = hex_to_dec(hex_color[4]) * 16 + hex_to_dec(hex_color[5]);
}

int main()
{
    int R = 255, G = 0, B = 0;  // initialize RGB values
   
    // Convert RGB to hexadecimal
    char* hex_color = RGB_to_hex(R, G, B);
    
    printf("RGB color: (%d, %d, %d)\n", R, G, B);
    printf("Hex color: #%s\n", hex_color);
    
    // Convert hexadecimal to RGB
    hex_to_RGB(hex_color, &R, &G, &B);
    
    printf("Hex color: #%s\n", hex_color);
    printf("RGB color: (%d, %d, %d)\n", R, G, B);
    
    free(hex_color);  // deallocate memory for hex color string
    
    return 0;
}