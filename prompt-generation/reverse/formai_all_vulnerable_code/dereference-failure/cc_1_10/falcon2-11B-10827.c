//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to analyze the log file and count occurrences of a given keyword
int count_occurrences(const char *filename, const char *keyword) {
    FILE *fp;
    int count = 0;
    
    // Open the file for reading
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return -1;
    }
    
    // Read each line in the file
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';
        
        // Check if the line contains the keyword
        if (strstr(line, keyword)!= NULL) {
            // Increment the count if the line contains the keyword
            count++;
        }
    }
    
    // Close the file
    fclose(fp);
    
    // Return the count
    return count;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <logfile> <keyword>\n", argv[0]);
        exit(1);
    }
    
    const char *logfile = argv[1];
    const char *keyword = argv[2];
    
    // Count the occurrences of the keyword in the log file
    int count = count_occurrences(logfile, keyword);
    
    // Print the result
    if (count > 0) {
        printf("%s appears %d times in the log file.\n", keyword, count);
    } else {
        printf("%s does not appear in the log file.\n", keyword);
    }
    
    return 0;
}