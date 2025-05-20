//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

void shuffle_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % (n - i) + i;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void distort_text(char *input_text, char *output_text, int length) {
    for (int i = 0; i < length; i++) {
        char c = input_text[i];
        if (isalpha(c)) {
            int index = rand() % 26;
            output_text[i] = index > 13 ? (char)('a' + index - 13) : (char)('A' + index);
        } else {
            output_text[i] = c;
        }
    }
    output_text[length] = '\0';
}

int main() {
    srand(time(NULL));

    FILE *reality_file = fopen("reality.txt", "r");
    FILE *dream_file = fopen("dream.txt", "w");

    if (reality_file == NULL || dream_file == NULL) {
        perror("Error opening files");
        return 1;
    }

    char reality_buffer[BUFFER_SIZE];
    char dream_buffer[BUFFER_SIZE];

    fgets(reality_buffer, BUFFER_SIZE, reality_file);

    int length = strlen(reality_buffer);
    char *reality_text = (char *)malloc((length + 1) * sizeof(char));
    strcpy(reality_text, reality_buffer);

    shuffle_array(reality_text, length);

    distort_text(reality_text, dream_buffer, length);

    fprintf(dream_file, "%s", dream_buffer);

    fclose(reality_file);
    fclose(dream_file);

    free(reality_text);

    printf("Content of reality.txt has been successfully distorted and written to dream.txt.\n");

    return 0;
}