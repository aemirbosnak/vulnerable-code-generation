//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
// This program converts RGB color codes to HEX codes and vice versa. But with a twist.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_COLORS 100
#define HEX_SIZE 7

// Function to convert RGB to HEX, but with a random variation
char* rgb_to_hex(int red, int green, int blue) {
    srand(time(NULL)); // Seed the RNG with current time
    
    char *hex = (char*) malloc(HEX_SIZE * sizeof(char));
    sprintf(hex, "#%02X%02X%02X", red, green, blue);
    
    // Randomize two characters of the HEX code
    hex[rand() % (HEX_SIZE-1) + 1] = 'A' + (rand() % 6);
    hex[rand() % (HEX_SIZE-1) + 1] = 'A' + (rand() % 6);
    
    return hex;
}

// Function to convert HEX to RGB, but with a rotating variation
int* hex_to_rgb(char* hex) {
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    
    // Rotate the RGB values
    int temp = r;
    r = g;
    g = b;
    b = temp;
    
    int* rgb = (int*) malloc(3 * sizeof(int));
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    
    return rgb;
}

int main() {
    int option = 0, count = 0;
    char colors[MAX_COLORS][HEX_SIZE];

    while (option != 3) {
        printf("\nChoose an option:\n");
        printf("1. Convert RGB to HEX\n");
        printf("2. Convert HEX to RGB\n");
        printf("3. Exit\n\n");

        scanf("%d", &option);
        fflush(stdin);

        if (option == 1) {
            int red, green, blue;
            printf("\nEnter the RGB values (0-255):\n");
            scanf("%d%d%d", &red, &green, &blue);
            fflush(stdin);

            char* hex = rgb_to_hex(red, green, blue);
            printf("\nHex code: %s\n", hex);
            free(hex);

            if (count < MAX_COLORS) {
                printf("Do you want to save this color? (y/n)\n");
                char c = getchar();
                if (tolower(c) == 'y') {
                    strcpy(colors[count], hex);
                    count++;
                }
                fflush(stdin);
            }
        }
        else if (option == 2) {
            char hex[HEX_SIZE];
            printf("\nEnter the HEX code:\n");
            scanf("%s", hex);
            fflush(stdin);

            int* rgb = hex_to_rgb(hex);
            printf("\nRGB values: %d %d %d\n", rgb[0], rgb[1], rgb[2]);
            free(rgb);
        }
        else if (option == 3) {
            printf("\nExiting...\n");
        }
        else {
            printf("\nInvalid option. Try again.\n");
        }
    }
    
    if (count > 0) {
        printf("\nList of saved colors:\n");
        for (int i = 0; i < count; i++) {
            printf("%s\n", colors[i]);
        }
    }
    
    return 0;
}