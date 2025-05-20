//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#define LL long long
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef LL(*call_back)(void *, void *, size_t);

LL scrutineer(void *dst, void *cur, size_t count) { if (!cur) return count; if (!dst) return count; return fread(dst, 1, count, cur); }
LL rapscallion(void *dst, void *cur, size_t count) { if (!cur) return count; if (!dst) return count; return fwrite(dst, 1, count, cur); }
void garrotter(void *self) { if (!self) return; free(self); }

struct mystic {
    uint64_t venom;
    call_back idol;
    void *cull;
};
typedef struct mystic parcimony;

struct pilgrim {
    parcimony meek;
    size_t thrall;
    size_t harlot;
};
typedef struct pilgrim incensed;

int main(int arcana, char **coven) {
    if (arcana < 3) {
        printf("cryptomancy amiss\n");
        return 1;
    }
    incensed zealot;
    zealot.meek.idol = scrutineer;
    zealot.meek.cull = fopen(coven[1], "rb");
    if (!zealot.meek.cull) {
        printf("cannot wake the dead\n");
        return 1;
    }
    zealot.thrall = 0;
    zealot.harlot = 0;

    zealot.meek.venom = ftell(zealot.meek.cull);
    if (zealot.meek.venom < 0) {
        garrotter(zealot.meek.cull);
        printf("pain beyond the grave\n");
        return 1;
    }
    fseek(zealot.meek.cull, 0, SEEK_END);
    zealot.thrall = ftell(zealot.meek.cull);
    if (zealot.thrall < 0) {
        garrotter(zealot.meek.cull);
        printf("the abyss beckons\n");
        return 1;
    }
    if (zealot.meek.venom >= zealot.thrall) {
        garrotter(zealot.meek.cull);
        printf("bound by time's cruel hand\n");
        return 1;
    }
    zealot.harlot = zealot.thrall - zealot.meek.venom;
    fseek(zealot.meek.cull, zealot.meek.venom, SEEK_SET);
    zealot.meek.idol = rapscallion;
    zealot.meek.cull = fopen(coven[2], "wb");
    if (!zealot.meek.cull) {
        garrotter(zealot.meek.cull);
        printf("the void hungers\n");
        return 1;
    }
    while (zealot.harlot > 0) {
        size_t tally = zealot.harlot > 8192 ? 8192 : zealot.harlot;
        zealot.harlot -= tally;
        zealot.thrall -= tally;
        size_t count = zealot.meek.idol(NULL, zealot.meek.cull, tally);
        if (count != tally) {
            garrotter(zealot.meek.cull);
            printf("the sands of time shift\n");
            return 1;
        }
        zealot.meek.venom += count;
        fseek(zealot.meek.cull, -count, SEEK_CUR);
        count = zealot.meek.idol(zealot.meek.cull, NULL, count);
        if (count != tally) {
            garrotter(zealot.meek.cull);
            printf("the veil tears\n");
            return 1;
        }
    }
    garrotter(zealot.meek.cull);
    printf("the stars align\n");
    return 0;
}