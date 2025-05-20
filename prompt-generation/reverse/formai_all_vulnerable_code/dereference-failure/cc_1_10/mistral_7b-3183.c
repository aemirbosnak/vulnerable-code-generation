//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define SIZE 1024 * 1024
#define WORDS_COUNT 10

void print_instructions() {
    printf("\nWelcome to the Ken Thompson Style C Typing Speed Test!\n");
    printf("Type the following words as fast as you can:\n");
    printf("1. Fortran\n");
    printf("2. Cobol\n");
    printf("3. Pascal\n");
    printf("4. Ada\n");
    printf("5. Algol\n");
    printf("6. C++\n");
    printf("7. Java\n");
    printf("8. Python\n");
    printf("9. Ruby\n");
    printf("10. Swift\n");
    printf("Press Enter to start the test.\n");
    getchar();
}

void load_words(char **words) {
    char *file = "words.txt";
    int i = 0;
    FILE *fp = fopen(file, "r");

    while (fscanf(fp, "%s%*c", words[i]) != EOF) {
        i++;
    }

    fclose(fp);
}

void test(char **words) {
    int i, attempts = 0, correct_count = 0;
    char input[SIZE];
    clock_t start, end;

    printf("\nReady? Go!\n");
    start = clock();

    for (i = 0; i < WORDS_COUNT; i++) {
        printf("%s ", words[i]);
        fgets(input, SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(words[i], input) == 0) {
            correct_count++;
        }

        attempts++;
    }

    end = clock();
    printf("\nTest completed. Attempts: %d, Correct: %d\n", attempts, correct_count);
    printf("Your typing speed is %f words per minute.\n", (float) (WORDS_COUNT * 60.0 / (end - start)));
}

int main() {
    char *words[WORDS_COUNT];
    int i;

    print_instructions();

    mmap((void *) 0, SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    load_words(words);

    test(words);

    for (i = 0; i < WORDS_COUNT; i++) {
        free(words[i]);
    }
    free(words);

    munmap((void *) 0, SIZE);

    return 0;
}