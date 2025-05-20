//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <string.h>

#define LZW_SIZE 65536
#define LZW_WINDOW_SIZE 20

#define MAX_STRING_SIZE (LZW_SIZE - 1)

typedef struct {
    int count;
    char *string;
} lzw_state;

static char lzw_encode(lzw_state *state, char ch) {
    int index = state->count;
    if (index == LZW_SIZE) {
        return -1;
    }

    state->string[index] = ch;
    state->count++;
    return index;
}

static void lzw_encode_string(lzw_state *state, char *string) {
    for (int i = 0; i < strlen(string); i++) {
        lzw_encode(state, string[i]);
    }
}

static int lzw_decode(lzw_state *state, char *out_string) {
    int index = 0;
    for (int i = 0; i < LZW_SIZE; i++) {
        if (state->string[i]!= 0) {
            out_string[index++] = state->string[i];
        }
        if (index == LZW_WINDOW_SIZE) {
            index = 0;
        }
    }
    out_string[index] = 0;
    return index;
}

int main() {
    char input[] = "This is a test string for LZW compression algorithm";
    char output[strlen(input) + 1];

    lzw_state state;
    state.count = 0;
    state.string = (char*)malloc(LZW_SIZE);
    lzw_encode_string(&state, input);

    int encoded_size = strlen(state.string);
    printf("Encoded string: %s\n", state.string);
    printf("Encoded size: %d\n", encoded_size);

    lzw_state decoded_state;
    decoded_state.count = 0;
    decoded_state.string = (char*)malloc(LZW_SIZE);
    lzw_decode(&decoded_state, output);

    printf("Decoded string: %s\n", output);
    printf("Decoded size: %d\n", strlen(output));

    free(state.string);
    free(decoded_state.string);

    return 0;
}