//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between 0 and given number
int rand_range(int limit) {
    int num = rand() % limit;
    return num;
}

// Function to generate a random letter between 'a' and 'z'
char rand_char() {
    int num = rand_range(26);
    return num + 'a';
}

// Function to generate a random string of given length
char* generate_string(int length) {
    char* str = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        str[i] = rand_char();
    }
    str[length] = '\0';
    return str;
}

// Function to generate a random conspiracy theory
void generate_theory(void) {
    int num_agents = rand_range(3) + 3;
    char* agents[num_agents];
    for (int i = 0; i < num_agents; i++) {
        agents[i] = generate_string(rand_range(5) + 3);
    }

    int num_conspiracies = rand_range(5) + 2;
    char* conspiracies[num_conspiracies];
    for (int i = 0; i < num_conspiracies; i++) {
        conspiracies[i] = generate_string(rand_range(10) + 5);
    }

    printf("Conspiracy Theory:\n");
    printf("- The %s, %s, and %s have joined forces to hide the truth about...\n", agents[0], agents[1], agents[2]);
    printf("- They have established a secret organization called '%s'\n", generate_string(rand_range(15) + 7));
    printf("- Their main goal is to suppress the discovery of '%s'\n", conspiracies[0]);
    printf("- However, a brave whistleblower named %s has leaked information about their activities to the public.\n", generate_string(rand_range(8) + 4));
    printf("- The whistleblower has provided evidence in the form of a %s file called '%s'.\n", (rand() % 2 == 0) ? "PDF" : "JPG", generate_string(rand_range(15) + 7));
    printf("- The %s community is currently analyzing the file to uncover the truth.\n", (rand() % 2 == 0) ? "hacker" : "journalist");

    for (int i = 0; i < num_agents; i++) {
        free(agents[i]);
    }

    for (int i = 0; i < num_conspiracies; i++) {
        free(conspiracies[i]);
    }
}

int main(void) {
    srand(time(NULL));
    generate_theory();
    return 0;
}