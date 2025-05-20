//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_BIT_COUNT 32

typedef struct {
    char word[MAX_WORD_SIZE];
    int bit_count;
    int code[MAX_BIT_COUNT];
} Code;

int compare_codes(const void* a, const void* b) {
    Code* c1 = (Code*)a;
    Code* c2 = (Code*)b;
    return c1->bit_count - c2->bit_count;
}

Code* huffman_encoding(char* text) {
    int word_count = strlen(text) + 1;
    Code* codes = (Code*)malloc(sizeof(Code) * word_count);
    int* counts = (int*)malloc(sizeof(int) * word_count);
    memset(counts, 0, sizeof(int) * word_count);

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (counts[c] == 0) {
            codes[i].word[0] = c;
            codes[i].bit_count = 1;
            codes[i].code[0] = 0;
            counts[c] = 1;
        } else {
            counts[c]++;
        }
    }

    for (int i = 0; i < word_count - 1; i++) {
        int min_index = 0;
        int min_count = counts[codes[i].word[0]];
        for (int j = 1; j < word_count; j++) {
            if (counts[codes[j].word[0]] < min_count) {
                min_index = j;
                min_count = counts[codes[j].word[0]];
            }
        }

        Code* left_child = &codes[min_index];
        Code* right_child = &codes[min_index + 1];

        for (int i = 0; i < MAX_BIT_COUNT; i++) {
            left_child->code[i] = 0;
            right_child->code[i] = 0;
        }

        int left_bit_count = 0;
        int right_bit_count = 0;
        for (int i = 0; i < MAX_WORD_SIZE; i++) {
            if (left_child->word[i] == '1') {
                left_bit_count++;
            }
            if (right_child->word[i] == '1') {
                right_bit_count++;
            }
        }

        for (int i = 0; i < MAX_BIT_COUNT; i++) {
            if (left_child->code[i] == 0) {
                left_child->code[i] = 1;
                left_bit_count--;
                break;
            }
        }

        for (int i = 0; i < MAX_BIT_COUNT; i++) {
            if (right_child->code[i] == 0) {
                right_child->code[i] = 1;
                right_bit_count--;
                break;
            }
        }

        left_child->bit_count += left_bit_count;
        right_child->bit_count += right_bit_count;

        codes[min_index].bit_count += left_child->bit_count + right_child->bit_count;
        codes[min_index + 1].bit_count = left_child->bit_count + right_child->bit_count;

        memcpy(codes + min_index + 1, left_child, sizeof(Code));
        memcpy(codes + min_index + 2, right_child, sizeof(Code));

        counts[codes[min_index + 1].word[0]] += counts[codes[min_index].word[0]];
        counts[codes[min_index + 2].word[0]] += counts[codes[min_index].word[0]];
        counts[codes[min_index].word[0]] = 0;
    }

    qsort(codes, word_count, sizeof(Code), compare_codes);

    for (int i = 0; i < word_count; i++) {
        printf("%s %d ", codes[i].word, codes[i].bit_count);
        for (int j = 0; j < codes[i].bit_count; j++) {
            printf("%d ", codes[i].code[j]);
        }
        printf("\n");
    }

    free(counts);
    return codes;
}

int main() {
    char* text = "abracadabra";
    Code* codes = huffman_encoding(text);
    return 0;
}