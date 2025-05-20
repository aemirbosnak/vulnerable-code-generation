//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the longest common substring between two strings
char* find_longest_common_substring(char* str1, char* str2, int m, int n) {
    // Base case: if either of the strings is empty, return the other string
    if (m == 0 || n == 0)
        return str2;

    // Recursive case: find the longest common substring between the first characters of the strings
    if (str1[m-1] == str2[n-1]) {
        int len = 1 + find_longest_common_substring(str1, str2, m-1, n-1);
        char* res = (char*)malloc((len + 1) * sizeof(char));
        res[len] = '\0';
        strncpy(res, str1, len);
        return res;
    } else {
        int len = find_longest_common_substring(str1, str2, m, n-1);
        char* res = (char*)malloc((len + 1) * sizeof(char));
        res[len] = '\0';
        strncpy(res, str2, len);
        return res;
    }
}

// Function to generate a summary of a given text
void summarize_text(char* text) {
    // Initialize the summary text with an empty string
    char* summary = (char*)malloc(1 * sizeof(char));
    summary[0] = '\0';

    // Find the longest common substring between the input text and the summary text
    char* longest_common_substring = find_longest_common_substring(text, summary, strlen(text), strlen(summary));

    // Update the summary text with the longest common substring
    strcat(summary, longest_common_substring);

    // Print the summary text
    printf("Summary: %s\n", summary);

    // Free the memory allocated for the longest common substring
    free(longest_common_substring);
}

int main() {
    char* text = "This is a sample text to summarize. This text contains several words and phrases. The goal is to summarize this text while preserving the main ideas and concepts.";

    summarize_text(text);

    return 0;
}