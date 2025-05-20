//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GB 1073741824 // 1 GB = 1024^3 bytes

// Function declaration
void printBarChart(int* arr, int length);
void printLine(int amount, int max);

int main() {
    // Define array to store disk usage for each folder
    int diskUsage[5] = {0, 0, 0, 0, 0};
    
    // Folder paths to analyze
    char* folders[5] = {"C:\\Users\\User\\Desktop", 
                        "C:\\Program Files", 
                        "C:\\Windows", 
                        "C:\\Users\\User\\Documents", 
                        "C:\\"};
                        
    // Loop through each folder and calculate its disk usage
    for (int i = 0; i < 5; i++) {
        // Open directory
        char command[100];
        sprintf(command, "dir /s /a \"%s\" > temp.txt", folders[i]);
        system(command);
        
        // Parse output file
        FILE* filePointer = fopen("temp.txt", "r");
        char line[256];
        while (fgets(line, sizeof(line), filePointer)) {
            char* occurrence = strstr(line, "Total Files Listed:");
            if (occurrence != NULL) {
                char* token = strtok(occurrence, ":");
                token = strtok(NULL, ":");
                diskUsage[i] = atoi(token);
                break;
            }
        }
        
        // Close file and delete temp file
        fclose(filePointer);
        remove("temp.txt");
    }
    
    // Print results in form of bar chart
    printf("\nDisk Space Usage:\n");
    for (int i = 0; i < 5; i++) {
        // Convert disk usage to GB
        int gbUsage = diskUsage[i] / GB;
        
        // Print bar chart
        printf("%s: %d GB\n", folders[i], gbUsage);
        printBarChart(&gbUsage, 1);
    }
    
    return 0;
}

// Prints a bar chart to represent the disk usage as a percentage
// of the maximum disk space used by any of the folders analyzed
void printBarChart(int* arr, int length) {
    // Find max value in array
    int max = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Print bars for each value in array
    for (int i = 0; i < length; i++) {
        printLine(arr[i], max);
        printf("\n");
    }
    
    // Print axis labels
    for (int i = 0; i < max; i++) {
        if (i % (max/10) == 0) {
            printf("%d GB ", i+1);
        } else {
            printf("      ");
        }
    }
    printf("%d GB\n", max+1);
    printf("      ");
    for (int i = 0; i < max/10; i++) {
        printf("|     ");
    }
    printf("|\n");
}

// Prints a line of asterisks representing a percentage of the maximum length
void printLine(int amount, int max) {
    int length = (int)((float)amount / max * 50);
    
    for (int i = 0; i < length; i++) {
        printf("*");
    }
    for (int i = 0; i < 50-length; i++) {
        printf(" ");
    }
}