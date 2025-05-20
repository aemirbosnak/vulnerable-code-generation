//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define BUFFER 1024

// Data structure for storing extracted data
typedef struct {
    char address[MAX];
    char target[MAX];
    int exp;
} ExtractedData;

int main() {
    printf("Accessing data...\n");
    
    // Read from file
    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    char buffer[BUFFER];
    ExtractedData extractedData;
    
    // Data mining
    while(fgets(buffer, BUFFER, fp)) {
        // Extract target
        char *token;
        token = strtok(buffer, ",");
        strcpy(extractedData.target, token);
        
        // Extract address
        token = strtok(NULL, ",");
        strcpy(extractedData.address, token);
        
        // Extract experience
        token = strtok(NULL, ",");
        extractedData.exp = atoi(token);
        
        // Analyze data
        if(extractedData.exp > 5 && strstr(extractedData.target, "MegaCorp") != NULL) {
            printf("Data breach detected!\n");
            printf("Target: %s\n", extractedData.target);
            printf("Address: %s\n", extractedData.address);
            printf("Experience: %d years\n", extractedData.exp);
            printf("Trace initiated...\n");
            
            // Initiate trace to find the hacker
            printf("Trace successful! Hacker identified as 'Ghost'.\n");
        }
    }
    
    printf("Data analysis complete. Program terminated.\n");
    
    // Close file
    fclose(fp);
    
    return 0;
}