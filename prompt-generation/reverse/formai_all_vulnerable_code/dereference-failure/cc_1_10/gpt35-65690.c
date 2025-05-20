//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char* format_input(char* input);
int find_matching_pair(char* input, int starting_index);

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    char* formatted_input = format_input(input);
    int starting_index = 0;
    int matching_index = 0;
    int num_pairs = 0;
    while(starting_index <= strlen(formatted_input)-2) {
        matching_index = find_matching_pair(formatted_input, starting_index+1);
        if(matching_index == -1) {
            printf("No matching pair found!\n");
            exit(1);
        }
        printf("Pair #%d: (%d, %d)\n", num_pairs+1, starting_index, matching_index);
        num_pairs++;
        starting_index = matching_index+1;
    }
    printf("Total pairs found: %d\n", num_pairs);
    return 0;
}

// Formats the input by removing all non-alphabetic characters and converting uppercase letters to lowercase
char* format_input(char* input) {
    char* formatted_input = (char*) malloc(sizeof(char)*strlen(input));
    int fi_index = 0;
    for(int i=0; i<strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            formatted_input[fi_index] = input[i] + 'a' - 'A';
            fi_index++;
        }
        else if(input[i] >= 'a' && input[i] <= 'z') {
            formatted_input[fi_index] = input[i];
            fi_index++;
        }
    }
    formatted_input[fi_index] = '\0';
    return formatted_input;
}

// Finds the index of the matching pair of parentheses or curly brackets in the input string, starting from the given index
int find_matching_pair(char* input, int starting_index) {
    char starting_char = input[starting_index-1];
    char matching_char = (starting_char == '(') ? ')' : '}';
    int num_open_chars = 1;
    for(int i=starting_index; i<strlen(input); i++) {
        if(input[i] == starting_char) {
            num_open_chars++;
        }
        else if(input[i] == matching_char) {
            num_open_chars--;
            if(num_open_chars == 0) {
                return i;
            }
        }
    }
    return -1; // No matching pair found
}