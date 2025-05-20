//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    Text *texts;
    int num_texts;
} TextList;

TextList *text_list_new() {
    TextList *text_list = malloc(sizeof(TextList));
    text_list->texts = NULL;
    text_list->num_texts = 0;
    return text_list;
}

void text_list_free(TextList *text_list) {
    for (int i = 0; i < text_list->num_texts; i++) {
        free(text_list->texts[i].text);
    }
    free(text_list->texts);
    free(text_list);
}

Text *text_new(const char *text) {
    Text *new_text = malloc(sizeof(Text));
    new_text->length = strlen(text);
    new_text->text = malloc(new_text->length + 1);
    strcpy(new_text->text, text);
    return new_text;
}

void text_list_add(TextList *text_list, Text *text) {
    text_list->texts = realloc(text_list->texts, (text_list->num_texts + 1) * sizeof(Text));
    text_list->texts[text_list->num_texts++] = *text;
}

char *text_summarize(TextList *text_list) {
    // Calculate the total length of all the texts
    int total_length = 0;
    for (int i = 0; i < text_list->num_texts; i++) {
        total_length += text_list->texts[i].length;
    }

    // Allocate a buffer for the summarized text
    char *summarized_text = malloc(total_length + 1);

    // Copy the texts into the buffer
    int offset = 0;
    for (int i = 0; i < text_list->num_texts; i++) {
        memcpy(summarized_text + offset, text_list->texts[i].text, text_list->texts[i].length);
        offset += text_list->texts[i].length;
    }

    // Terminate the string
    summarized_text[total_length] = '\0';

    // Return the summarized text
    return summarized_text;
}

int main() {
    // Create a text list
    TextList *text_list = text_list_new();

    // Add some texts to the list
    text_list_add(text_list, text_new("This is the first text."));
    text_list_add(text_list, text_new("This is the second text."));
    text_list_add(text_list, text_new("This is the third text."));

    // Summarize the texts
    char *summarized_text = text_summarize(text_list);

    // Print the summarized text
    printf("%s\n", summarized_text);

    // Free the summarized text
    free(summarized_text);

    // Free the text list
    text_list_free(text_list);

    return 0;
}