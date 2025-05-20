//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from standard input
char* readline() {
    char *s = malloc(100 * sizeof(char));
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0'; // remove newline character
    return s;
}

// Function to validate the input
int validate(char* line) {
    int n = strlen(line);
    for (int i = 0; i < n; i++) {
        char c = line[i];
        if (c == '.') continue;
        if (isdigit(c)) continue;
        if (i % 3 == 0 && i!= 0 && c!= '.' &&!isdigit(c)) {
            return 0;
        }
        if (i % 3 == 1 && i!= 0 && c!= '.' &&!isdigit(c)) {
            return 0;
        }
        if (i % 3 == 2 && i!= 0 && c!= '.' &&!isdigit(c)) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
int solve(char* line) {
    int n = strlen(line);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j += 3) {
            if (line[j] == '.') {
                char c = '1';
                int k = j + 1;
                while (validate(c + line[k]) == 0) {
                    c++;
                    k += 3;
                }
                line[j] = c;
                if (solve(line) == 0) return 0;
                line[j] = '.';
            }
        }
    }
    return 1;
}

// Function to print the Sudoku puzzle
void print(char* line) {
    int n = strlen(line);
    for (int i = 0; i < n; i++) {
        printf("%c", line[i]);
        if ((i + 1) % 3 == 0 && (i + 1)!= 0) {
            printf("\n");
        }
    }
}

int main() {
    char* line = readline();
    if (validate(line) == 0) {
        printf("Invalid input.\n");
        return 1;
    }
    if (solve(line) == 0) {
        printf("Unsolvable puzzle.\n");
        return 1;
    }
    print(line);
    return 0;
}