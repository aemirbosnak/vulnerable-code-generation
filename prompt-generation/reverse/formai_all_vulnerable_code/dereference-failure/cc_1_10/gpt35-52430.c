//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char* codeTable[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};
char* morseCode;

void* conversion(void* arg) {
    int* i = (int*) arg;
    if (morseCode[*i] == '/') {
        printf(" ");
    } else if (morseCode[*i] == ' ') {
        /* Do nothing */
    } else {
        int index = (int) morseCode[*i] - 65;
        if (index > 25) {
            index = (int) morseCode[*i] - 22;
        }
        printf("%s ", codeTable[index]);
    }
    free(arg);
    pthread_exit(NULL);
}

int main() {
    morseCode = (char*) malloc(100 * sizeof(char));
    printf("Enter text to convert to Morse code: ");
    fgets(morseCode, 100, stdin);
    int len = strlen(morseCode);

    pthread_t threads[len];
    int thread_args[len];
    int rc;

    for (int i = 0; i < len; i++) {
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, conversion, &thread_args[i]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < len; i++) {
        pthread_join(threads[i], NULL);
    }

    free(morseCode);
    morseCode = NULL;

    return 0;
}