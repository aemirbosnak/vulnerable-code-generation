//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_INPUT_SIZE 1000

char *read_input(char *input_file_path);
char *summarize_text(char *input_text);
int count_words(char *text);
char **tokenize_text(char *text, int word_count);
char *join_strings(char **strings, int num_strings);
int score_sentence(char *sentence, char **keywords, int num_keywords);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Error: Invalid number of command-line arguments. Please provide input file path.\n");
        return 1;
    }

    char *input_file_path = argv[1];
    char *input_text = read_input(input_file_path);
    char *summary = summarize_text(input_text);

    printf("Input Text:\n%s\n\n", input_text);
    printf("Summary:\n%s", summary);

    free(input_text);
    free(summary);
    return 0;
}

char *read_input(char *input_file_path)
{
    FILE *input_file = fopen(input_file_path, "r");
    char *input_text = malloc(sizeof(char) * MAX_INPUT_SIZE);
    char line[MAX_STRING_LENGTH];

    while (fgets(line, MAX_STRING_LENGTH, input_file) != NULL) {
        strcat(input_text, line);
    }

    fclose(input_file);
    return input_text;
}

char *summarize_text(char *input_text)
{
    int word_count = count_words(input_text);
    char **sentences = tokenize_text(input_text, word_count);
    int num_sentences = word_count / 10;
    num_sentences = num_sentences > 10 ? 10 : num_sentences;
    char *summary = malloc(sizeof(char) * MAX_INPUT_SIZE);

    char **keywords = malloc(sizeof(char *) * 3); // Important keywords to consider
    keywords[0] = "good";
    keywords[1] = "bad";
    keywords[2] = "interesting";

    int *scores = malloc(sizeof(int) * num_sentences);
    for (int i = 0; i < num_sentences; i++) {
        scores[i] = score_sentence(sentences[i], keywords, 3);
    }

    for (int i = 0; i < num_sentences; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (scores[i] < scores[j]) {
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                char *temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    for (int i = 0; i < num_sentences; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, ". ");
    }

    free(sentences);
    free(keywords);
    free(scores);
    return summary;
}

int count_words(char *text)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; i < strlen(text); i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    return count;
}

char **tokenize_text(char *text, int word_count)
{
    char **sentences = malloc(sizeof(char *) * word_count);
    char *sentence;
    int sentence_index = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[sentence_index] = malloc(sizeof(char) * MAX_STRING_LENGTH);
            strncpy(sentences[sentence_index], sentence, strlen(sentence));
            sentences[sentence_index][strlen(sentence)] = '\0';
            sentence_index++;
            sentence = "";
        } else {
            if (text[i] != '\n' && text[i] != '\r' && text[i] != '"') {
                sentence = strncat(sentence, &text[i], 1);
            }
        }
    }

    return sentences;
}

int score_sentence(char *sentence, char **keywords, int num_keywords)
{
    int score = 0;

    for (int i = 0; i < num_keywords; i++) {
        if (strstr(sentence, keywords[i]) != NULL) {
            score += 10;
        }
    }

    return score;
}

char *join_strings(char **strings, int num_strings)
{
    char *joined_string = malloc(sizeof(char) * MAX_INPUT_SIZE);
    for (int i = 0; i < num_strings; i++) {
        strcat(joined_string, strings[i]);
    }
    return joined_string;
}