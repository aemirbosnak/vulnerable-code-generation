//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *text;
    int len;
} Text;

Text *create_text() {
    Text *text = malloc(sizeof(Text));
    text->text = malloc(1000);
    text->len = 0;
    return text;
}

void free_text(Text *text) {
    free(text->text);
    free(text);
}

void add_char(Text *text, char c) {
    text->text[text->len++] = c;
}

void add_string(Text *text, char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        add_char(text, str[i]);
    }
}

void generate_text(Text *text) {
    srand(time(NULL));
    int num_words = rand() % 100 + 10;
    for (int i = 0; i < num_words; i++) {
        int num_chars = rand() % 10 + 1;
        for (int j = 0; j < num_chars; j++) {
            char c = 'a' + rand() % 26;
            add_char(text, c);
        }
        add_char(text, ' ');
    }
}

void print_text(Text *text) {
    for (int i = 0; i < text->len; i++) {
        printf("%c", text->text[i]);
    }
}

void test_typing_speed() {
    Text *text = create_text();
    generate_text(text);

    printf("Type the following text as quickly and accurately as possible:\n");
    print_text(text);

    time_t start = time(NULL);
    char *input = malloc(1000);
    scanf("%s", input);
    time_t end = time(NULL);

    int correct_chars = 0;
    for (int i = 0; i < text->len; i++) {
        if (input[i] == text->text[i]) {
            correct_chars++;
        }
    }

    double wpm = (double)correct_chars / 5 / ((double)(end - start) / 60);
    printf("Your typing speed is %.2f WPM.\n", wpm);

    free_text(text);
    free(input);
}

int main() {
    test_typing_speed();
    return 0;
}