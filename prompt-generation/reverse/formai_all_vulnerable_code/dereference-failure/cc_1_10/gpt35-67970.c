//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global Variables
char* user_message;
char* filename;

// Function Prototypes
void display_menu();
void write_to_file(const char* filename, const char* mode);
void read_from_file(const char* filename, const char* mode);

int main()
{
    // Dynamic Memory Allocation
    user_message = (char*) malloc(sizeof(char) * 100);
    filename = (char*) malloc(sizeof(char) * 30);

    int choice;

    printf("Welcome to Digital Diary!\n");
    printf("Please enter your name: ");

    char* user_name = (char*) malloc(sizeof(char) * 30);
    scanf("%s", user_name);

    printf("Hello, %s! What would you like to do today?\n", user_name);

    // Display Menu and Get Choice
    display_menu();
    scanf("%d", &choice);

    // User Input Operation
    switch (choice) 
    {
    case 1:
        printf("Please enter your message: ");
        getchar();
        fgets(user_message, 100, stdin);
        write_to_file(filename, "a");
        break;
    case 2:
        read_from_file(filename, "r");
        break;
    case 3:
        printf("Goodbye!\n");
        exit(0);
    default:
        printf("Invalid choice. Please select from 1, 2, or 3.\n");
        break;
    }

    // Freeing Memory
    free(user_message);
    free(filename);
    free(user_name);

    return 0;
}

void display_menu()
{
    printf("\n1. Write a new message.\n");
    printf("2. Read previously saved messages.\n");
    printf("3. Quit.\n");
    printf("Enter your choice: ");
}

void write_to_file(const char* filename, const char* mode)
{
    FILE* fp;

    // Current Date and Time
    time_t t = time(NULL);
    struct tm* tm_time = localtime(&t);

    // Opening the File
    fp = fopen(filename, mode);

    // Write to File
    fprintf(fp, "%d/%d/%d %d:%d:%d - %s", tm_time->tm_mon + 1, tm_time->tm_mday, tm_time->tm_year + 1900, 
            tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec, user_message);

    printf("\nMessage written successfully!\n");

    // Close File
    fclose(fp);
}

void read_from_file(const char* filename, const char* mode)
{
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, mode);

    // Error Handling
    if (fp == NULL) 
    {
        printf("\nNo messages found.\n");
        return;
    }

    printf("\nMessages:\n");

    // Reading from File
    while ((read = getline(&line, &len, fp)) != -1) 
    {
        printf("%s", line);
    }

    // Memory Deallocation
    if (line) 
    {
        free(line);
    }

    printf("\n");
    
    // Closing File
    fclose(fp);
}