//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove whitespace from a string
void remove_whitespace(char* str) {
    int i = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[i] = tolower(str[i]);
            i++;
        }
    }
    str[i] = '\0';
}

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to print a string with each word separated by a line break
void print_string(char* str) {
    char* word = strtok(str, " ");
    while (word!= NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
}

// Function to read an eBook file and display its contents
void read_ebook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char* line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file))!= -1) {
        remove_whitespace(line);
        printf("%s\n\n", line);
        int num_words = count_words(line);
        printf("Number of words: %d\n", num_words);
        print_string(line);
        printf("\n\n");
    }

    free(line);
    fclose(file);
}

int main() {
    char* filename = "example.txt";
    read_ebook(filename);
    return 0;
}