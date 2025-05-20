//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to compress the input string using Run Length Encoding
char* compress(const char* input) {
    int n = strlen(input);
    
    if (n == 0) return ""; // Return empty for empty input
    
    char* output = (char*)malloc(MAX_SIZE);
    int count = 1;
    int index = 0;

    for (int i = 1; i <= n; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            index += sprintf(output + index, "%c%d", input[i - 1], count);
            count = 1; // Reset count
        }
    }
    return output;
}

// Function to decompress a string that was compressed using Run Length Encoding
char* decompress(const char* input) {
    char* output = (char*)malloc(MAX_SIZE);
    int index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char char_to_repeat = input[i];
        i++;
        int count = 0;

        while (input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // Adjust index since we incremented it in the while loop

        for (int j = 0; j < count; j++) {
            output[index++] = char_to_repeat;
        }
    }
    output[index] = '\0'; // End the string
    return output;
}

// Function to display the menu
void showMenu() {
    printf("=================================\n");
    printf("         Compression Tool       \n");
    printf("=================================\n");
    printf("1. Compress a string\n");
    printf("2. Decompress a string\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

// Main function
int main() {
    int choice;
    char input[MAX_SIZE];

    do {
        showMenu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter a string to compress: ");
                fgets(input, MAX_SIZE, stdin);
                // Remove newline character from fgets
                input[strcspn(input, "\n")] = 0;

                char* compressed = compress(input);
                printf("Compressed String: %s\n", compressed);
                free(compressed);
                break;

            case 2:
                printf("Enter a string to decompress: ");
                fgets(input, MAX_SIZE, stdin);
                input[strcspn(input, "\n")] = 0;

                char* decompressed = decompress(input);
                printf("Decompressed String: %s\n", decompressed);
                free(decompressed);
                break;

            case 3:
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}