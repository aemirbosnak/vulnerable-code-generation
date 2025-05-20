//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Text;

Text *create_text(int length) {
    Text *text = malloc(sizeof(Text));
    text->text = malloc(length + 1);
    text->length = length;
    for (int i = 0; i < length; i++) {
        text->text[i] = 'a' + rand() % 26;
    }
    text->text[length] = '\0';
    return text;
}

void destroy_text(Text *text) {
    free(text->text);
    free(text);
}

int main() {
    srand(time(NULL));
    int length = 100;
    Text *text = create_text(length);
    printf("Type the following text as quickly and accurately as possible:\n\n");
    printf("%s\n\n", text->text);
    clock_t start = clock();
    char *input = malloc(length + 1);
    scanf("%s", input);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    int errors = 0;
    for (int i = 0; i < length; i++) {
        if (input[i] != text->text[i]) {
            errors++;
        }
    }
    printf("\nTime taken: %f seconds\n", time_taken);
    printf("Errors: %d\n", errors);
    printf("WPM: %f\n", length / 5.0 / time_taken * 60.0);
    destroy_text(text);
    free(input);
    return 0;
}