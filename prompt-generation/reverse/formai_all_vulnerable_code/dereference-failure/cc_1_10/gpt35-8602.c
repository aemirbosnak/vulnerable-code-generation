//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE  1024

char *buffer;

// Function to detect intrusion
int detect_intrusion(char *user_input) {
    int score = 0;
    int len = strlen(user_input);
    int i;

    // Check if user input is too long
    if (len > MAX_BUFFER_SIZE) {
        score += 5;
    }

    // Check for potential malicious strings
    if (strstr(user_input, "rm -rf")) {
        score += 10;
    }
    if (strstr(user_input, "system(")) {
        score += 5;
    }
    if (strstr(user_input, "exec(")) {
        score += 5;
    }
    if (strstr(user_input, "popen(")) {
        score += 5;
    }
    if (strstr(user_input, "subprocess.")) {
        score += 5;
    }
    if (strstr(user_input, "os.popen(")) {
        score += 5;
    }
    if (strstr(user_input, "import os")) {
        score += 5;
    }

    // Check for potentially dangerous characters
    for (i = 0; i < len; i++) {
        if (user_input[i] == '\'') {
            score += 1;
        }
        if (user_input[i] == ';') {
            score += 1;
        }
        if (user_input[i] == '`') {
            score += 1;
        }
        if (user_input[i] == '|') {
            score += 1;
        }
    }

    // Return the intrusion score
    return score;
}

int main() {
    buffer = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE);

    while (1) {
        // Prompt user for input
        printf("Enter your input: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        // Detect intrusion
        int score = detect_intrusion(buffer);

        // Check for intrusion
        if (score > 0) {
            printf("Intrusion detected! Score: %d\n", score);
        }
        else {
            printf("Input accepted.\n");
        }
    }

    free(buffer);
    return 0;
}