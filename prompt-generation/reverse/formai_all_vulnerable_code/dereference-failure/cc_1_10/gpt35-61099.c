//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    // Define the input string and pattern to replace
    char input[] = "Hello, <name>! Welcome to <location>.";
    char pattern[] = "<(.*?)>";

    // Prepare a regular expression object
    regex_t regex;
    regmatch_t match[2];
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        fprintf(stderr, "Failed to compile regex pattern.\n");
        return 1;
    }

    // Define replacements and populate them dynamically
    char* replacements[] = {
        "Alice",
        "Paris"
    };
    int num_replacements = sizeof(replacements) / sizeof(*replacements);

    // Iterate through the input string, replacing matches dynamically
    char* output = input;
    int start_pos = 0;
    while (regexec(&regex, output, 2, match, 0) == 0) {
        // Copy the portion of the input string before the match
        char* before = strndup(output, match[0].rm_so);
        printf("%s", before);
        free(before);

        // Replace the match with the corresponding replacement string
        int replacement_index = rand() % num_replacements;
        char* replacement = replacements[replacement_index];
        printf("%s", replacement);

        // Move the output buffer past the match
        start_pos += match[1].rm_eo;
        output += match[1].rm_eo;
    }

    // Print any remaining characters in the input string after the last match
    printf("%s", output + start_pos);

    // Clean up the regular expression object
    regfree(&regex);

    return 0;
}