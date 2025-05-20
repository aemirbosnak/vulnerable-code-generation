//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 1000

typedef struct {
    char *text;
    int len;
} Text;

typedef struct {
    float positive;
    float negative;
    float neutral;
} Sentiment;

Text *new_text(char *text) {
    Text *t = malloc(sizeof(Text));
    t->text = text;
    t->len = strlen(text);
    return t;
}

void free_text(Text *t) {
    free(t->text);
    free(t);
}

Sentiment *new_sentiment() {
    Sentiment *s = malloc(sizeof(Sentiment));
    s->positive = 0.0;
    s->negative = 0.0;
    s->neutral = 0.0;
    return s;
}

void free_sentiment(Sentiment *s) {
    free(s);
}

void analyze_sentiment(Text *t, Sentiment *s) {
    char *words[] = {"love", "hate", "good", "bad", "happy", "sad"};
    float weights[] = {1.0, -1.0, 0.5, -0.5, 0.75, -0.75};
    for (int i = 0; i < t->len; i++) {
        for (int j = 0; j < sizeof(words) / sizeof(char *); j++) {
            if (strstr(t->text, words[j]) != NULL) {
                s->positive += weights[j];
            }
        }
    }
    s->negative = -s->positive;
    s->neutral = 1.0 - fabs(s->positive);
}

void print_sentiment(Sentiment *s) {
    printf("Positive: %.2f%%\n", s->positive * 100);
    printf("Negative: %.2f%%\n", s->negative * 100);
    printf("Neutral: %.2f%%\n", s->neutral * 100);
}

int main() {
    Text *t = new_text("I love this movie!");
    Sentiment *s = new_sentiment();
    analyze_sentiment(t, s);
    print_sentiment(s);
    free_text(t);
    free_sentiment(s);
    return 0;
}