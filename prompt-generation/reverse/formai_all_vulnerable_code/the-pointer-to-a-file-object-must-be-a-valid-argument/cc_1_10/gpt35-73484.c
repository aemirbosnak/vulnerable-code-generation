//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // maximum length of a line in the input text file

/* A function to check whether a character is a vowel */
int is_vowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'}; // list of vowels
    for (int i = 0; i < 5; i++) {
        if (c == vowels[i]) {
            return 1; // the character is a vowel
        }
    }
    return 0; // the character is not a vowel 
}

/* A function to count the number of vowels in a given string */
int count_vowels(char* str) {
    int count = 0;
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (is_vowel(str[i])) {
            count++;
        }
    }
    return count;
}

/* The main function */
int main() {
    char input_file_name[] = "input.txt";
    char output_file_name[] = "output.txt";
    
    FILE *input_file = fopen(input_file_name, "r"); // open the input file for reading
    FILE *output_file = fopen(output_file_name, "w"); // open the output file for writing
    
    char line[MAX_LINE_LENGTH]; // buffer to hold a line of text
    
    int line_num = 1; // keep track of the line number
    
    /* Read each line from the input file, process it, and write the results to the output file */
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) { // read a line from the input file
        int num_vowels = count_vowels(line); // count the number of vowels in the line
        fprintf(output_file, "Line %d has %d vowels.\n", line_num, num_vowels); // write the result to the output file
        line_num++; // increment the line number
    }
    
    /* Close the input and output files */
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}