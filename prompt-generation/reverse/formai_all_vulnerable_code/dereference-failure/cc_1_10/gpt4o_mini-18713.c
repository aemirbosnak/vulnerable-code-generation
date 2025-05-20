//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 512  // Number of characters per page
#define MAX_FILENAME 256

// Function to read a file and store it in a dynamically allocated buffer
char* loadFile(const char* filename, size_t* fileSize) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(*fileSize + 1);
    if (!buffer) {
        perror("Could not allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, *fileSize, file);
    buffer[*fileSize] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}

// Function to display a page of text
void displayPage(const char* text, size_t start, size_t size) {
    printf("%.*s", (int)size, &text[start]);
}

// Function to get the next page start position
size_t getNextPageStart(size_t current, size_t fileSize) {
    return (current + PAGE_SIZE < fileSize) ? current + PAGE_SIZE : fileSize;
}

// Function to get the previous page start position
size_t getPrevPageStart(size_t current) {
    return (current >= PAGE_SIZE) ? current - PAGE_SIZE : 0;
}

// Main eBook reader function
void eBookReader(const char* filename) {
    size_t fileSize;
    char* text = loadFile(filename, &fileSize);
    if (!text) return;

    size_t currentPageStart = 0;
    size_t currentPageEnd = getNextPageStart(currentPageStart, fileSize);

    char command;
    while (1) {
        system("clear"); // Clear the console for a new page
        displayPage(text, currentPageStart, currentPageEnd - currentPageStart);
        
        printf("\n\nCommands: [n] Next, [p] Previous, [q] Quit\n");
        printf("Enter command: ");
        command = getchar();
        getchar(); // Consume newline character
        
        if (command == 'n') {
            if (currentPageEnd < fileSize) {
                currentPageStart = currentPageEnd;
                currentPageEnd = getNextPageStart(currentPageStart, fileSize);
            } else {
                printf("You're already at the last page.\n");
                getchar(); // Wait for user input
            }
        } else if (command == 'p') {
            if (currentPageStart > 0) {
                currentPageEnd = currentPageStart;
                currentPageStart = getPrevPageStart(currentPageStart);
            } else {
                printf("You're already at the first page.\n");
                getchar(); // Wait for user input
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
            getchar(); // Wait for user input
        }
    }

    free(text);
}

int main() {
    char filename[MAX_FILENAME];

    printf("Welcome to the eBook Reader!\n");
    printf("Enter the name of the eBook file (including .txt extension): ");
    scanf("%s", filename);

    eBookReader(filename);
    
    printf("Thank you for using the eBook Reader. Goodbye!\n");
    return 0;
}