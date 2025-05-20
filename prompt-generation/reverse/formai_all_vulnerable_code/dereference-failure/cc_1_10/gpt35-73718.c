//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_SUMMARY 500

char* summarize(char* text, int max_summary) {
    char* summary = (char*) malloc(max_summary * sizeof(char));
    int i = 0;
    int j = 0;
    int len = strlen(text);
    int sentence_count = 0;
    int words_in_sentence = 0;
    int summary_length = 0;

    // loop through text
    while(i < len && summary_length < max_summary) {
        // count words in sentence
        while(text[i] != '.' && text[i] != '?' && text[i] != '!' && i < len) {
            if (text[i] == ' ' && i > 0 && text[i - 1] != ' ') {
                words_in_sentence++;
            }
            i++;
        }
        if (i == len) {
            break;
        }

        // count end of sentence
        sentence_count++;
        if (sentence_count > 1) {
            summary[summary_length++] = ' ';
        }

        // copy sentence
        j = i - words_in_sentence;
        while(j < i) {
            summary[summary_length++] = text[j++];
        }
        summary[summary_length++] = text[i++];

        // reset word count
        words_in_sentence = 0;
    }

    summary[summary_length] = '\0';
    return summary;
}

int main() {
    char text[MAX_LEN] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris hendrerit dolor eu risus eleifend, sit amet iaculis nisl bibendum. Fusce vel aliquam nunc, a fringilla purus. Sed elementum, enim sit amet mollis lobortis, nibh dolor eleifend lacus, vel sollicitudin nisi lacus non dolor. Mauris in convallis massa. Maecenas faucibus sapien sit amet leo feugiat, eu porta sapien tincidunt. Sed mollis malesuada magna, vitae gravida leo faucibus non. Integer consectetur luctus eros, vel finibus nunc dictum in. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Donec malesuada lacinia aliquam. Vivamus ullamcorper, urna id tristique pretium, libero tortor vestibulum justo, non pretium tortor enim vel metus.";

    char* summary = summarize(text, MAX_SUMMARY);
    printf("Original Text:\n%s\n\n", text);
    printf("Summary:\n%s", summary);

    free(summary);
    return 0;
}