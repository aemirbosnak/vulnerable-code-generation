//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <string.h>

typedef struct {
    int start;
    int end;
} Sentence;

int main(int argc, char **argv) {
    // Check if the user provided a text file.
    if (argc < 2) {
        printf("Please provide a text file as the first argument.\n");
        return 1;
    }

    // Open the text file.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open the text file.\n");
        return 1;
    }

    // Get the size of the text file.
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the text file into a buffer.
    char *buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    // Close the text file.
    fclose(file);

    // Find all the sentences in the text.
    int num_sentences = 0;
    Sentence *sentences = NULL;
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?') {
            Sentence sentence = {i - 1, i};
            sentences = realloc(sentences, (num_sentences + 1) * sizeof(Sentence));
            sentences[num_sentences++] = sentence;
        }
    }

    // Summarize the text.
    char *summary = malloc(size / 10 + 1);
    int summary_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        Sentence sentence = sentences[i];
        int length = sentence.end - sentence.start + 1;
        if (length > summary_length) {
            memcpy(summary, buffer + sentence.start, length);
            summary_length = length;
        }
    }
    summary[summary_length] = '\0';

    // Print the summary.
    printf("Summary:\n");
    printf("%s\n", summary);

    // Free the allocated memory.
    free(buffer);
    free(sentences);
    free(summary);

    return 0;
}