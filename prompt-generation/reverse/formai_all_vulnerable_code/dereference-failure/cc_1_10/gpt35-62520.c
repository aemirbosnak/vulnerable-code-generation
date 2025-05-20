//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_SIZE 200

typedef struct Sentence {
    char *text;
    int frequency;
    struct Sentence *next;
} Sentence;

typedef struct Word {
    char *text;
    int frequency;
    Sentence *sentences;
    struct Word *next;
} Word;

char *read_file(const char *filename);
void update_word_frequency(Word **word_list, char *text, Sentence *sentence);
void update_sentence_frequency(Sentence *sentence);
void add_to_sentence_list(Sentence **head, char *text);
int count_words(const char *text);
Word *get_most_frequent_words(Word *word_list, int max_words);
char *summarize_text(const char *text, int num_sentences);

int main() {
    char *text = read_file("example.txt");
    char *summary = summarize_text(text, 3);
    printf("%s\n", summary);
    free(text);
    free(summary);
    return 0;
}

char *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *text = malloc(file_size + 1);
    if (text == NULL) {
        printf("Error: Unable to allocate memory for file contents.\n");
        exit(EXIT_FAILURE);
    }
    fread(text, 1, file_size, fp);
    fclose(fp);
    text[file_size] = '\0';
    return text;
}

void update_word_frequency(Word **word_list, char *text, Sentence *sentence) {
    char *word;
    Word *current_word, *previous_word;
    current_word = *word_list;
    previous_word = NULL;
    while (1) {
        word = strtok(text, " ,.!?-");
        if (word == NULL) {
            break;
        }
        int found = 0;
        while (current_word != NULL) {
            if (strcmp(current_word->text, word) == 0) {
                current_word->frequency++;
                update_sentence_frequency(sentence);
                add_to_sentence_list(&current_word->sentences, sentence->text);
                found = 1;
                break;
            }
            previous_word = current_word;
            current_word = current_word->next;
        }
        if (!found) {
            Word *new_word = malloc(sizeof(Word));
            if (new_word == NULL) {
                printf("Error: Unable to allocate memory for new word.\n");
                exit(EXIT_FAILURE);
            }
            new_word->text = strdup(word);
            new_word->frequency = 1;
            new_word->sentences = sentence;
            new_word->next = NULL;
            if (previous_word == NULL) {
                *word_list = new_word;
            } else {
                previous_word->next = new_word;
            }
            update_sentence_frequency(sentence);
            add_to_sentence_list(&new_word->sentences, sentence->text);
            previous_word = new_word;
        }
        text = NULL;
    }
}

void update_sentence_frequency(Sentence *sentence) {
    sentence->frequency = 0;
    char *word = strtok(sentence->text, " ,.!?-");
    while (word != NULL) {
        Word *current_word = sentence->next->next;
        while (current_word != NULL) {
            if (strcmp(current_word->text, word) == 0) {
                sentence->frequency += current_word->frequency;
                break;
            }
            current_word = current_word->next;
        }
        word = strtok(NULL, " ,.!?-");
    }
}

void add_to_sentence_list(Sentence **head, char *text) {
    Sentence *current = *head, *previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
    }
    Sentence *new_sentence = malloc(sizeof(Sentence));
    if (new_sentence == NULL) {
        printf("Error: Unable to allocate memory for sentence.\n");
        exit(EXIT_FAILURE);
    }
    new_sentence->text = strdup(text);
    new_sentence->frequency = 0;
    new_sentence->next = NULL;
    if (previous == NULL) {
        *head = new_sentence;
    } else {
        previous->next = new_sentence;
    }
}

int count_words(const char *text) {
    int count = 0;
    char *copy = strdup(text);
    char *word = strtok(copy, " ,.!?-");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ,.!?-");
    }
    free(copy);
    return count;
}

Word *get_most_frequent_words(Word *word_list, int max_words) {
    Word *current_word, *most_frequent_word, *most_frequent_word_previous, *most_frequent_words = NULL;
    most_frequent_words = malloc(sizeof(Word));
    if (most_frequent_words == NULL) {
        printf("Error: Unable to allocate memory for word list.\n");
        exit(EXIT_FAILURE);
    }
    most_frequent_words->next = NULL;
    for (int i = 0; i < max_words; i++) {
        current_word = word_list;
        most_frequent_word_previous = NULL;
        most_frequent_word = current_word;
        while (current_word != NULL) {
            if (current_word->frequency > most_frequent_word->frequency) {
                most_frequent_word = current_word;
                most_frequent_word_previous = NULL;
            } else if (current_word->frequency == most_frequent_word->frequency) {
                most_frequent_word_previous = most_frequent_word;
                most_frequent_word = current_word;
            }
            current_word = current_word->next;
        }
        Word *new_word = malloc(sizeof(Word));
        if (new_word == NULL) {
            printf("Error: Unable to allocate memory for new word.\n");
            exit(EXIT_FAILURE);
        }
        new_word->text = strdup(most_frequent_word->text);
        new_word->frequency = most_frequent_word->frequency;
        new_word->sentences = most_frequent_word->sentences;
        new_word->next = NULL;
        if (most_frequent_word_previous == NULL) {
            word_list = most_frequent_word->next;
        } else {
            most_frequent_word_previous->next = most_frequent_word->next;
        }
        most_frequent_word->next = NULL;
        if (i == 0) {
            most_frequent_words = new_word;
        } else {
            current_word = most_frequent_words;
            while (current_word->next != NULL) {
                current_word = current_word->next;
            }
            current_word->next = new_word;
        }
    }
    return most_frequent_words;
}

char *summarize_text(const char *text, int num_sentences) {
    Sentence *sentences = NULL, *current_sentence, *previous_sentence;
    char *text_copy = strdup(text);
    char *sentence_text = strtok(text_copy, ".?!");

    while (sentence_text != NULL) {
        current_sentence = malloc(sizeof(Sentence));
        if (current_sentence == NULL) {
            printf("Error: Unable to allocate memory for sentence.\n");
            exit(EXIT_FAILURE);
        }
        current_sentence->text = strdup(sentence_text);
        current_sentence->frequency = 0;
        current_sentence->next = NULL;
        if (sentences == NULL) {
            sentences = current_sentence;
        } else {
            previous_sentence->next = current_sentence;
        }
        previous_sentence = current_sentence;
        sentence_text = strtok(NULL, ".?!");
    }

    free(text_copy);

    Word *word_list = NULL;
    current_sentence = sentences;
    while (current_sentence != NULL) {
        update_word_frequency(&word_list, current_sentence->text, current_sentence);
        current_sentence = current_sentence->next;
    }

    int num_words = count_words(text);
    int summary_size = (MAX_SUMMARY_SIZE < num_words) ? MAX_SUMMARY_SIZE : num_words;
    int num_summary_sentences = (num_sentences < num_words) ? num_sentences : num_words;

    Word *most_frequent_words = get_most_frequent_words(word_list, summary_size);

    char *summary = malloc(sizeof(char));
    strcpy(summary, "");

    for (int i = 0; i < num_summary_sentences; i++) {
        current_sentence = sentences;
        previous_sentence = NULL;
        while (current_sentence != NULL) {
            if (current_sentence->frequency > 0) {
                Word *current_word = most_frequent_words;
                int contains_most_frequent_word = 0;
                while (current_word != NULL) {
                    if (strstr(current_sentence->text, current_word->text) != NULL) {
                        contains_most_frequent_word = 1;
                        break;
                    }
                    current_word = current_word->next;
                }
                if (contains_most_frequent_word) {
                    if (strlen(summary) > 0) {
                        strcat(summary, " ");
                    }
                    strcat(summary, current_sentence->text);
                    current_sentence->frequency = 0;
                    break;
                }
            }
            previous_sentence = current_sentence;
            current_sentence = current_sentence->next;
        }
        if (current_sentence == NULL) {
            current_sentence = previous_sentence;
        }
    }

    Word *current_word = most_frequent_words;
    while (current_word != NULL) {
        Sentence *current_sentence = current_word->sentences;
        while (current_sentence != NULL) {
            free(current_sentence->text);
            Sentence *next_sentence = current_sentence->next;
            free(current_sentence);
            current_sentence = next_sentence;
        }
        free(current_word->text);
        Word *next_word = current_word->next;
        free(current_word);
        current_word = next_word;
    }

    return summary;
}