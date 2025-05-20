//FormAI DATASET v1.0 Category: System boot optimizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LEN 256

// Function prototypes
int getNumOfLines(char* filePath);
void readBootFile(char** bootFile, int numOfLines, char* filePath);
void optimizeBootFile(char** bootFile, int numOfLines);
void writeBootFile(char** bootFile, int numOfLines, char* filePath);

int main() {
    char* filePath = "/etc/system/boot";
    int numOfLines = getNumOfLines(filePath);
    char** bootFile = (char**) malloc(sizeof(char*) * numOfLines);
    
    readBootFile(bootFile, numOfLines, filePath);
    optimizeBootFile(bootFile, numOfLines);
    writeBootFile(bootFile, numOfLines, filePath);
    
    // Free up memory
    for(int i=0; i<numOfLines; i++) {
        free(bootFile[i]);
    }
    free(bootFile);
    
    return 0;
}

/**
 * Get the number of lines in a file
 * @param filePath - path to the file
 * @return number of lines in the file
 */
int getNumOfLines(char* filePath) {
    int count = 0;
    char line[MAX_LINE_LEN];
    FILE* fp = fopen(filePath, "r");
    
    // Count the number of lines in the file
    while(fgets(line, MAX_LINE_LEN, fp)) {
        count++;
    }
    
    // Close the file
    fclose(fp);
    
    return count;
}

/**
 * Read the contents of a file into memory
 * @param bootFile - pointer to memory to store file contents
 * @param numOfLines - number of lines in the file
 * @param filePath - path to the file
 */
void readBootFile(char** bootFile, int numOfLines, char* filePath) {
    char line[MAX_LINE_LEN];
    FILE* fp = fopen(filePath, "r");
    
    // Read each line of the file into memory
    for(int i=0; i<numOfLines; i++) {
        fgets(line, MAX_LINE_LEN, fp);
        bootFile[i] = (char*) malloc(sizeof(char) * strlen(line));
        strcpy(bootFile[i], line);
    }
    
    // Close the file
    fclose(fp);
}

/**
 * Optimize the boot file by removing unnecessary lines
 * @param bootFile - pointer to memory storing file contents
 * @param numOfLines - number of lines in the file
 */
void optimizeBootFile(char** bootFile, int numOfLines) {
    bool hasSwap = false;
    bool hasRoot = false;
    bool hasUser = false;
    
    // Loop through each line of the file
    for(int i=0; i<numOfLines; i++) {
        char* line = bootFile[i];
        
        // Check if line contains swap partition
        if(strstr(line, "swap") != NULL) {
            hasSwap = true;
            continue;
        }
        
        // Check if line contains root partition
        if(strstr(line, "root") != NULL) {
            hasRoot = true;
            continue;
        }
        
        // Check if line contains user partition
        if(strstr(line, "user") != NULL) {
            hasUser = true;
            continue;
        }
        
        // If line does not contain necessary partitions, remove it
        if(!hasSwap || !hasRoot || !hasUser) {
            free(bootFile[i]);
            bootFile[i] = NULL;
        }
    }
}

/**
 * Write the contents of memory back to a file
 * @param bootFile - pointer to memory storing file contents
 * @param numOfLines - number of lines in the file
 * @param filePath - path to the file
 */
void writeBootFile(char** bootFile, int numOfLines, char* filePath) {
    FILE* fp = fopen(filePath, "w");
    
    // Write each line of the file from memory back to the file
    for(int i=0; i<numOfLines; i++) {
        char* line = bootFile[i];
        
        if(line != NULL) {
            fputs(line, fp);
        }
    }
    
    // Close the file
    fclose(fp);
}