//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define CAT_LANGUAGE_MAX_LENGTH 1024

typedef struct {
    char *cat_language;
    size_t cat_language_length;
} cat_language_t;

typedef struct {
    pthread_t thread_id;
    bool is_running;
    cat_language_t cat_language;
} cat_language_translator_t;

void *cat_language_translator_thread(void *arg) {
    cat_language_translator_t *translator = (cat_language_translator_t *)arg;
    while (translator->is_running) {
        char *human_language = malloc(CAT_LANGUAGE_MAX_LENGTH);
        if (human_language == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        printf("Enter a human language string to translate to cat language: ");
        fgets(human_language, CAT_LANGUAGE_MAX_LENGTH, stdin);
        size_t human_language_length = strlen(human_language);
        if (human_language_length > 0 && human_language[human_language_length - 1] == '\n') {
            human_language[human_language_length - 1] = '\0';
            human_language_length--;
        }
        translator->cat_language.cat_language = malloc(CAT_LANGUAGE_MAX_LENGTH);
        if (translator->cat_language.cat_language == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        translator->cat_language.cat_language_length = 0;
        for (size_t i = 0; i < human_language_length; i++) {
            switch (human_language[i]) {
                case 'a':
                case 'A':
                    strcat(translator->cat_language.cat_language, "meow ");
                    break;
                case 'e':
                case 'E':
                    strcat(translator->cat_language.cat_language, "purr ");
                    break;
                case 'i':
                case 'I':
                    strcat(translator->cat_language.cat_language, "hiss ");
                    break;
                case 'o':
                case 'O':
                    strcat(translator->cat_language.cat_language, "chirp ");
                    break;
                case 'u':
                case 'U':
                    strcat(translator->cat_language.cat_language, "growl ");
                    break;
                case ' ':
                    strcat(translator->cat_language.cat_language, " ");
                    break;
                default:
                    strcat(translator->cat_language.cat_language, "??? ");
                    break;
            }
        }
        translator->cat_language.cat_language_length = strlen(translator->cat_language.cat_language);
        printf("Cat language translation: %s\n", translator->cat_language.cat_language);
        free(human_language);
    }
    pthread_exit(NULL);
}

int main() {
    cat_language_translator_t translator;
    translator.is_running = true;
    pthread_create(&translator.thread_id, NULL, cat_language_translator_thread, &translator);
    while (true) {
        sleep(1);
    }
    translator.is_running = false;
    pthread_join(translator.thread_id, NULL);
    free(translator.cat_language.cat_language);
    return 0;
}