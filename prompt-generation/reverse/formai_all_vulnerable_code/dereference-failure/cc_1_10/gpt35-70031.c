//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 100

char *get_summary(char *text);

int main() {
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vestibulum mi sit amet nibh congue venenatis. Morbi et ullamcorper diam. Fusce consequat felis vel posuere ullamcorper. Donec eget scelerisque enim. Sed dapibus fringilla felis, a vulputate velit tempus et. Integer sit amet augue suscipit, luctus nisl eu, accumsan velit. Sed quis lobortis arcu. Sed in lorem at lectus tristique mattis. Nulla facilisi. Aliquam et ex a mauris efficitur rutrum sed ut ligula. Sed euismod justo quis lacus eleifend pellentesque. Sed ut accumsan ipsum, sed laoreet purus. Sed quis rhoncus sapien. Sed id pulvinar ante, vel interdum velit. Sed et ullamcorper lectus, sit amet accumsan libero.";

    char *summary = get_summary(text);
    printf("%s", summary);

    free(summary);
    return 0;
}

char *get_summary(char *text) {
    char *summary = (char*) malloc(MAX_SUMMARY_LENGTH * sizeof(char));

    // initialize variables
    int total_words = 1;
    int current_word_count = 0;
    int chars_copied = 0;
    int i = 0;

    while (text[i] != '\0') {
        current_word_count++;

        if (text[i] == ' ' || text[i] == '.') {
            total_words++;

            if (current_word_count > MAX_SUMMARY_LENGTH / 3) {
                current_word_count = MAX_SUMMARY_LENGTH / 3;
            }

            strncat(summary, &text[i-current_word_count+1], current_word_count);
            chars_copied += current_word_count;
            summary[chars_copied] = ' ';
            chars_copied++;

            current_word_count = 0;

            if (total_words >= MAX_SUMMARY_LENGTH / 3) {
                break;
            }
        }

        i++;
    }

    if (total_words < MAX_SUMMARY_LENGTH / 3) {
        int remaining_chars = MAX_SUMMARY_LENGTH - chars_copied;
        strncat(summary, &text[i-current_word_count], remaining_chars);
    } else {
        strncat(summary, " ...", 4);
    }

    return summary;
}