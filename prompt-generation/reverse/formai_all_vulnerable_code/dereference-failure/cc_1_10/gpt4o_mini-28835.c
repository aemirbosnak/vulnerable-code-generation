//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <time.h>
#include <unistd.h>

#define MAX_QUOTES 5

// An array of motivational quotes
const char *quotes[MAX_QUOTES] = {
    "Keep your face always toward the sunshine—and shadows will fall behind you.",
    "The best way to predict the future is to create it.",
    "Believe you can and you're halfway there.",
    "Success is not the key to happiness. Happiness is the key to success.",
    "Don't watch the clock; do what it does. Keep going!"
};

// Function to get a random quote
const char* get_random_quote() {
    srand(time(0)); // Seed random number generator
    int random_index = rand() % MAX_QUOTES; // Get a random index
    return quotes[random_index]; // Return the random quote
}

// Function to display the quote
void display_quote() {
    const char* quote = get_random_quote();
    printf("💡 Motivational Quote: %s\n", quote); // Print the quote
}

// Function to save the quote to a file
void save_quote_to_file(const char* filename) {
    FILE *file = fopen(filename, "a"); // Open the file in append mode
    if (file == NULL) {
        perror("Error opening file");
        return; // Exit if file fails to open
    }
    
    const char* quote = get_random_quote();
    fprintf(file, "%s\n", quote); // Write the quote to the file
    fclose(file); // Close the file
    printf("✅ Saved quote to %s!\n", filename);
}

// Function to simulate plugin initiation
void initiate_plugin() {
    printf("🚀 Motivational Quote Plugin Initialized!\n");

    // Simulate user interaction
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Get a motivational quote\n");
        printf("2. Save a motivational quote to file\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_quote(); // Display a random quote
                break;
            case 2:
                save_quote_to_file("quotes.txt"); // Save quote to a file
                break;
            case 3:
                printf("🌟 Thank you for using the Motivational Quote Plugin! See you next time.\n");
                break;
            default:
                printf("❌ Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);
}

// Create a dynamic library for the plugin
void create_library() {
    void *handle = dlopen("./plugin.so", RTLD_LAZY); // Load the shared library
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror()); // Print error if loading fails
        exit(EXIT_FAILURE);
    }

    // Load initiate_plugin function
    void (*init_func)() = dlsym(handle, "initiate_plugin");
    if (!init_func) {
        fprintf(stderr, "%s\n", dlerror()); // Print error if loading function fails
        exit(EXIT_FAILURE);
    }

    init_func(); // Call the plugin initiation function
    dlclose(handle); // Close the library
}

int main() {
    create_library(); // Initiate the library and start the plugin
    return 0; // Exit the program
}