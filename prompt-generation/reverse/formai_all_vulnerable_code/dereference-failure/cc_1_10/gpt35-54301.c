//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000 // maximum number of entries allowed in the csv file
#define MAX_COL_LEN 50 // maximum length of a single column

// struct for storing a single entry
typedef struct {
    char col1[MAX_COL_LEN];
    char col2[MAX_COL_LEN];
    char col3[MAX_COL_LEN];
} Entry;

// array for storing all entries
Entry entries[MAX_ENTRIES];

// function for reading the csv file
int read_csv(char *filename) {
    FILE *fp;
    char line[MAX_COL_LEN * 3]; // line buffer for storing each line of the file
    char *token; // pointer to current token in line
    int count = 0; // counter for number of entries read
    
    fp = fopen(filename, "r"); // open file for reading
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        return -1;
    }
    
    // read each line of the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        // tokenize line by comma delimiter
        token = strtok(line, ",");
        
        // store tokens in entry struct
        strcpy(entries[count].col1, token);
        token = strtok(NULL, ",");
        strcpy(entries[count].col2, token);
        token = strtok(NULL, ",");
        strcpy(entries[count].col3, token);

        count++; // increment entry counter
    }
    
    fclose(fp); // close file
    return count; // return number of entries read
}

// function for printing all entries
void print_entries(int count) {
    printf("Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s | %s | %s\n", entries[i].col1, entries[i].col2, entries[i].col3);
    }
}

// main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return -1;
    }
    
    int count = read_csv(argv[1]);
    if (count < 0) {
        return -1;
    }
    
    print_entries(count);
    
    return 0;
}