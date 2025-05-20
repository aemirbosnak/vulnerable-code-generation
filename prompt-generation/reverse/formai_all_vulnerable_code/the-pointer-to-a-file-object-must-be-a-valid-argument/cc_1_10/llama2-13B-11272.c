//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 1024
#define DEF_LEN 100

// Function to read a file and calculate statistical data
void read_file(char *file_name, int *num_words, int *avg_len, int *max_len, int *num_unique) {
    FILE *file = fopen(file_name, "r");
    char line[MAX_LEN];
    int i = 0;

    // Calculate number of words and average length
    *num_words = 0;
    *avg_len = 0;
    while (fgets(line, DEF_LEN, file)) {
        i++;
        *num_words++;
        *avg_len += strcspn(line, " ");
    }

    // Calculate maximum length and number of unique words
    *max_len = strcspn(line, " ");
    *num_unique = 0;
    for (int j = 0; j < i; j++) {
        char *word = strtok(line, " ");
        if (word == NULL) break;
        *num_unique++;
    }

    fclose(file);
}

int main() {
    char file_name[] = "example.txt";
    int num_words, avg_len, max_len, num_unique;

    // Read the file and calculate statistical data
    read_file(file_name, &num_words, &avg_len, &max_len, &num_unique);

    // Print statistical data
    printf("File %s contains %d words with an average length of %d and a maximum length of %d\n",
           file_name, num_words, avg_len / num_words, max_len);
    printf("The file contains %d unique words\n", num_unique);

    return 0;
}