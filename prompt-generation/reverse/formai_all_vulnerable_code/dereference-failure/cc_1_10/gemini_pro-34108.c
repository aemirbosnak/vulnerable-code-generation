//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *text;
    int len;
} Text;

typedef struct {
    Text *texts;
    int num_texts;
    int current_text;
    int total_chars;
} Test;

Test *create_test(int num_texts, int text_length) {
    Test *test = malloc(sizeof(Test));
    test->texts = malloc(sizeof(Text) * num_texts);
    test->num_texts = num_texts;
    test->current_text = 0;
    test->total_chars = 0;

    for (int i = 0; i < num_texts; i++) {
        test->texts[i].text = malloc(sizeof(char) * text_length);
        test->texts[i].len = text_length;

        for (int j = 0; j < text_length; j++) {
            test->texts[i].text[j] = 'a' + rand() % 26;
        }

        test->total_chars += text_length;
    }

    return test;
}

void destroy_test(Test *test) {
    for (int i = 0; i < test->num_texts; i++) {
        free(test->texts[i].text);
    }

    free(test->texts);
    free(test);
}

void print_test(Test *test) {
    for (int i = 0; i < test->num_texts; i++) {
        printf("%s\n", test->texts[i].text);
    }
}

int main() {
    srand(time(NULL));

    int num_texts = 10;
    int text_length = 100;

    Test *test = create_test(num_texts, text_length);

    print_test(test);

    char input[text_length];

    printf("Start typing!\n");

    int start_time = time(NULL);

    for (int i = 0; i < num_texts; i++) {
        scanf("%s", input);

        if (strcmp(input, test->texts[i].text) != 0) {
            printf("Error!\n");
            return 1;
        }
    }

    int end_time = time(NULL);

    double time_taken = end_time - start_time;

    double speed = test->total_chars / time_taken;

    printf("Your typing speed is %.2f characters per second.\n", speed);

    destroy_test(test);

    return 0;
}