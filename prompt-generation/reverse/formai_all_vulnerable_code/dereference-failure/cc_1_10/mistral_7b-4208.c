//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FORTUNES_COUNT 10

typedef struct {
    char *fortune;
    int id;
} Fortune;

Fortune fortunes[FORTUNES_COUNT] = {
    {"The future is bright and full of kernel updates.", 0},
    {"Your patch will be merged soon, have patience.", 1},
    {"The next commit will bring peace and harmony.", 2},
    {"Your bug report is valid, trust me.", 3},
    {"The community will appreciate your contribution.", 4},
    {"The next release will bring you fame and fortune.", 5},
    {"Your code is awesome, keep it up!", 6},
    {"Your pull request will bring joy to many.", 7},
    {"The next feature will change the world.", 8},
    {"Your work will be remembered for generations.", 9}
};

void print_fortune(int id) {
    printf("Fortune #%d:\n", id);
    printf("%s\n", fortunes[id].fortune);
}

void seed_random() {
    unsigned seed[3];
    FILE *rfile;
    int i;

    if ((rfile = fopen("/dev/urandom", "r")) != NULL) {
        if (fread(seed, sizeof(unsigned), 3, rfile) != 3) {
            fprintf(stderr, "Error reading /dev/urandom\n");
            exit(EXIT_FAILURE);
        }
        fclose(rfile);
    } else {
        for (i = 0; i < 3; i++)
            seed[i] = time(NULL);
    }

    srand(seed[0] ^ seed[1] ^ seed[2]);
}

int main() {
    int i, id;

    seed_random();
    srand(time(NULL));

    id = rand() % FORTUNES_COUNT;

    print_fortune(id);

    return EXIT_SUCCESS;
}