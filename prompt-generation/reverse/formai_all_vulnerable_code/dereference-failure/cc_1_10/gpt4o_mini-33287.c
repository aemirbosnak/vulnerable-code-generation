//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define PAGE_SIZE 10

// Struct to hold configuration
typedef struct {
    int fontSize;
    char bgColor[10];
} Config;

// Function prototypes
void loadBook(const char *filename);
void displayPage(int startLine, int totalLines, Config config);
int countLines(const char *filename);
void changeConfig(Config *config);

// Global variables
char** lines;
int totalLines = 0;

// Main function
int main(int argc, char *argv[]) {
    Config config = {12, "white"};

    if (argc != 2) {
        printf("Usage: %s <ebook_filename.txt>\n", argv[0]);
        return 1;
    }
    
    loadBook(argv[1]);

    int currentPage = 0;
    while (1) {
        displayPage(currentPage * PAGE_SIZE, totalLines, config);
        printf("Enter 'n' for next page, 'p' for previous page, 'c' to change config, 'q' to quit: ");
        
        char input;
        scanf(" %c", &input);

        switch (input) {
            case 'n':
                if (currentPage < (totalLines / PAGE_SIZE)) {
                    currentPage++;
                }
                break;
            case 'p':
                if (currentPage > 0) {
                    currentPage--;
                }
                break;
            case 'c':
                changeConfig(&config);
                break;
            case 'q':
                goto end;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

end:
    for (int i = 0; i < totalLines; i++) {
        free(lines[i]);
    }
    
    free(lines);
    return 0;
}

// Load book from file
void loadBook(const char *filename) {
    totalLines = countLines(filename);
    lines = malloc(totalLines * sizeof(char*));
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < totalLines; i++) {
        lines[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
        fgets(lines[i], MAX_LINE_LENGTH, file);
    }

    fclose(file);
}

// Display a page of the book
void displayPage(int startLine, int totalLines, Config config) {
    printf("\033[2J\033[H"); // Clear screen
    printf("Font Size: %d\n", config.fontSize);
    printf("Background Color: %s\n", config.bgColor);
    printf("====================== Page %d ======================\n", (startLine / PAGE_SIZE) + 1);
    
    for (int i = startLine; i < startLine + PAGE_SIZE && i < totalLines; i++) {
        printf("%s", lines[i]);
    }
    
    printf("================================================\n");
}

// Count the number of lines in the file
int countLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Change configuration settings like font size and background color
void changeConfig(Config *config) {
    printf("Current Font Size: %d\n", config->fontSize);
    printf("Current Background Color: %s\n", config->bgColor);
    
    printf("Enter new font size (default is 12): ");
    int newSize;
    scanf("%d", &newSize);
    if (newSize > 0) {
        config->fontSize = newSize;
    }

    printf("Enter new background color (e.g., white, black): ");
    scanf("%s", config->bgColor);
}