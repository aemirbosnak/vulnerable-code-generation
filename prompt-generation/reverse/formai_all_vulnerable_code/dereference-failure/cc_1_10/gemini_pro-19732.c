//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <time.h>

typedef struct {
    char *text;
    int size;
} Text;

typedef struct {
    Text *texts;
    int num_texts;
} TextCollection;

typedef struct {
    char *input;
    int size;
    int errors;
    clock_t start_time;
    clock_t end_time;
} TypingTest;

TextCollection text_collection;
TypingTest typing_test;

void load_text_collection() {
    text_collection.texts = malloc(sizeof(Text) * 10);
    text_collection.num_texts = 10;

    FILE *file = fopen("texts.txt", "r");
    for (int i = 0; i < text_collection.num_texts; i++) {
        char *text = calloc(1000, sizeof(char));
        while (!feof(file)) {
            fgets(text, 1000, file);
            strcat(text, "\n");
        }
        text_collection.texts[i].text = text;
        text_collection.texts[i].size = strlen(text);
    }
    fclose(file);
}

void free_text_collection() {
    for (int i = 0; i < text_collection.num_texts; i++) {
        free(text_collection.texts[i].text);
    }
    free(text_collection.texts);
}

void start_typing_test() {
    typing_test.input = malloc(1000 * sizeof(char));
    typing_test.size = 0;
    typing_test.errors = 0;
    typing_test.start_time = clock();
}

void end_typing_test() {
    typing_test.end_time = clock();
}

int get_wpm() {
    double elapsed_time = (typing_test.end_time - typing_test.start_time) / CLOCKS_PER_SEC;
    return (typing_test.size / 5) / elapsed_time * 60;
}

int get_accuracy() {
    int correct_characters = typing_test.size - typing_test.errors;
    return (correct_characters * 100) / typing_test.size;
}

void print_results() {
    printf("WPM: %d\n", get_wpm());
    printf("Accuracy: %d%%\n", get_accuracy());
}

int main() {
    load_text_collection();

    printf("Welcome to the Typing Tutor!\n\n");
    printf("Press any key to start the test.\n");
    getchar();

    start_typing_test();

    printf("Type the following text:\n\n");
    printf("%s", text_collection.texts[0].text);

    char c;
    while ((c = getchar()) != '\n') {
        if (c == text_collection.texts[0].text[typing_test.size]) {
            typing_test.size++;
        } else {
            typing_test.errors++;
        }
    }

    end_typing_test();
    free(typing_test.input);

    print_results();

    free_text_collection();

    return 0;
}