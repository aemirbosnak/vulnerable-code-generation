//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdint.h>
#include <stdbool.h>

#define NUM_INPUTS 8
#define NUM_OUTPUTS 1

typedef struct {
    uint8_t inputs[NUM_INPUTS];
    uint8_t select;
    uint8_t output;
} ShannonMux;

void shannonMuxInit(ShannonMux *mux) {
    for (int i = 0; i < NUM_INPUTS; i++) {
        mux->inputs[i] = 0;
    }
}

void shannonMuxEncode(ShannonMux *mux, uint8_t select, uint8_t input) {
    for (int i = 0; i < NUM_INPUTS; i++) {
        if (i == select) {
            mux->inputs[i] = input;
        } else {
            mux->inputs[i] |= (input << (i & 0x1));
        }
    }
}

void shannonMuxDecode(ShannonMux *mux) {
    mux->output = mux->inputs[mux->select];
}

void shannonMuxUpdate(ShannonMux *mux, uint8_t select, uint8_t input) {
    shannonMuxEncode(mux, select, input);
    shannonMuxDecode(mux);
}

void shannonMuxPrintState(ShannonMux *mux) {
    printf("Select: %d, Inputs: [", mux->select);
    for (int i = 0; i < NUM_INPUTS; i++) {
        printf("%d, ", mux->inputs[i]);
    }
    printf("], Output: %d\n", mux->output);
}

int main() {
    ShannonMux mux;
    shannonMuxInit(&mux);

    for (int i = 0; i < 16; i++) {
        shannonMuxUpdate(&mux, i % NUM_INPUTS, i / NUM_INPUTS % 2);
        shannonMuxPrintState(&mux);
    }

    return 0;
}