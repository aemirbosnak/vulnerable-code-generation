//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function declarations
void printIntro();
void listFiles(const char *path);
void checkDiskUsage();
void createDirectory(const char *dirName);
void deleteFile(const char *fileName);
void displayHelp();
void executeChoice(int choice);

int main() {
    int choice;

    printIntro();

    do {
        printf("\nEnter your choice (1-7), or 0 to exit: ");
        scanf("%d", &choice);
        executeChoice(choice);
    } while (choice != 0);

    printf("Goodbye!\n");
    return 0;
}

void printIntro() {
    printf("******************************************\n");
    printf("*        C System Administration Tool    *\n");
    printf("******************************************\n");
    printf("* 1. List files in a directory           *\n");
    printf("* 2. Check disk usage                     *\n");
    printf("* 3. Create a new directory               *\n");
    printf("* 4. Delete a file                        *\n");
    printf("* 5. Show help information                *\n");
    printf("* 6. Clear console                        *\n");
    printf("* 0. Exit                                 *\n");
    printf("******************************************\n");
}

void listFiles(const char *path) {
    struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir(path);

    if (dr == NULL) {
        printf("Could not open directory: %s\n", path);
        return;
    }

    printf("Files in directory '%s':\n", path);
    while ((de = readdir(dr)) != NULL) {
        if (de->d_name[0] != '.') {  // Ignore hidden files
            printf("%s\n", de->d_name);
        }
    }
    closedir(dr);
}

void checkDiskUsage() {
    printf("Disk usage:\n");
    system("df -h");
}

void createDirectory(const char *dirName) {
    if (mkdir(dirName, 0777) == 0) {
        printf("Directory '%s' created successfully.\n", dirName);
    } else {
        perror("Error creating directory");
    }
}

void deleteFile(const char *fileName) {
    if (remove(fileName) == 0) {
        printf("File '%s' deleted successfully.\n", fileName);
    } else {
        perror("Error deleting file");
    }
}

void displayHelp() {
    printf("Help Information:\n");
    printf("1. List files in a directory - Enter the directory path.\n");
    printf("2. Check disk usage - Displays the current disk usage in human-readable format.\n");
    printf("3. Create a new directory - Provide a name for the new directory.\n");
    printf("4. Delete a file - Specify the name of the file to delete.\n");
    printf("5. Show help information - Displays this help message.\n");
    printf("6. Clear console - Clears the terminal screen.\n");
}

void executeChoice(int choice) {
    char buffer[256];

    switch (choice) {
        case 1:
            printf("Enter directory path: ");
            scanf("%s", buffer);
            listFiles(buffer);
            break;
        case 2:
            checkDiskUsage();
            break;
        case 3:
            printf("Enter new directory name: ");
            scanf("%s", buffer);
            createDirectory(buffer);
            break;
        case 4:
            printf("Enter file name to delete: ");
            scanf("%s", buffer);
            deleteFile(buffer);
            break;
        case 5:
            displayHelp();
            break;
        case 6:
            system("clear");
            break;
        case 0:
            // exit option
            break;
        default:
            printf("Invalid choice! Please enter a number between 0 and 7.\n");
            break;
    }
}