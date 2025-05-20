//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to synchronize two files
void file_sync(char* file_one, char* file_two) {
    FILE *f1, *f2;
    char ch1, ch2;
    int line_number = 1;
    int character_number = 0;

    // Open both files
    f1 = fopen(file_one, "r");
    f2 = fopen(file_two, "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Error in opening file.\n");
        exit(0);
    }

    // Get character from each file and compare
    ch1 = getc(f1);
    ch2 = getc(f2);

    while (ch1 != EOF || ch2 != EOF) {

        if (ch1 != ch2) {
            printf("Non-matching characters found in line %d, character %d of files %s and %s\n", 
                    line_number, character_number + 1, file_one, file_two);
            printf("Value in %s is %c and value in %s is %c\n", file_one, ch1, file_two, ch2);
            exit(0);
        }

        // Move to next line if end of line reached
        if (ch1 == '\n') {
            line_number++;
            character_number = 0;
        } else {
            character_number++;
        }

        // Get characters from files
        ch1 = getc(f1);
        ch2 = getc(f2);
    }

    // If files are identical print message
    printf("Both files are identical.\n");
}

int main() {
    char* file_one = "file1.txt";
    char* file_two = "file2.txt";

    file_sync(file_one, file_two);

    return 0;
}