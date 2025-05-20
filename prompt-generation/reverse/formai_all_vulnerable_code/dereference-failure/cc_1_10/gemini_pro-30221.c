//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HSIZE 256
#define MSIZE 1024
#define RSIZE 128

typedef unsigned char byte;
typedef struct {
    byte *h, *m, *r;
    size_t hs, ms, rs;
} state_t;

state_t *
state_init(void)
{
    state_t *state = malloc(sizeof(state_t));
    state->h = malloc(HSIZE);
    state->m = malloc(MSIZE);
    state->r = malloc(RSIZE);
    state->hs = HSIZE;
    state->ms = MSIZE;
    state->rs = RSIZE;
    return state;
}

void
state_free(state_t *state)
{
    free(state->h);
    free(state->m);
    free(state->r);
    free(state);
}

void
state_update(state_t *state, const void *buf, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        state->m[state->ms++] = ((byte *)buf)[i];
        if (state->ms >= MSIZE) {
            state->r[state->rs++] = state->h[0];
            memcpy(state->h, state->m, HSIZE);
            state->ms = 0;
        }
    }
}

void
state_final(state_t *state)
{
    while (state->ms > 0) {
        state->r[state->rs++] = state->h[0];
        memcpy(state->h, state->m, HSIZE);
        state->ms = 0;
    }
}

void
state_print(state_t *state)
{
    size_t i;
    for (i = 0; i < state->rs; i++)
        printf("%02x", state->r[i]);
    printf("\n");
}

int
main(int argc, char *argv[])
{
    state_t *state = state_init();
    state_update(state, "The quick brown fox jumps over the lazy dog", 43);
    state_final(state);
    state_print(state);
    state_free(state);
    return 0;
}