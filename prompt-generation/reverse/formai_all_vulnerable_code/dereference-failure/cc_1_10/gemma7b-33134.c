//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

char *read_file(char *filename)
{
    FILE *fp;
    char *buffer;
    size_t size;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    size = 0;
    buffer = NULL;
    while (!feof(fp)) {
        buffer = realloc(buffer, size + 1);
        size++;
        fgets(buffer, size, fp);
    }

    fclose(fp);
    return buffer;
}

int sentiment_analysis(char *text)
{
    int positive_words = 0;
    int negative_words = 0;
    char *word_list[] = {"happy", "joy", "love", "good", "excellent",
                           "sad", "hate", "anger", "frustrated", "terrible"};

    for (int i = 0; i < 10; i++) {
        if (strstr(text, word_list[i]) != NULL) {
            if (word_list[i] == word_list[0] || word_list[i] == word_list[1] || word_list[i] == word_list[2]) {
                positive_words++;
            } else {
                negative_words++;
            }
        }
    }

    if (positive_words > negative_words) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char *filename = "/home/user/Documents/my_text.txt";
    char *text = read_file(filename);

    int sentiment = sentiment_analysis(text);

    if (sentiment == 1) {
        system("echo 'The text is positive!'");
    } else {
        system("echo 'The text is negative!'");
    }

    return 0;
}