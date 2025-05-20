//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <math.h>

#define DICE_SIDES 20
#define ORACLE_SIZE 1024

typedef struct {
    int value;
    double entropy;
} Die;

typedef struct {
    Die dice[DICE_SIDES];
    int sum;
} Roll;

typedef struct {
    int seed;
    char data[ORACLE_SIZE];
} Oracle;

Oracle* init_oracle() {
    Oracle* oracle = mmap(NULL, ORACLE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (oracle == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    oracle->seed = time(NULL);
    srandom(oracle->seed);
    return oracle;
}

void roll_dice(Roll* roll, Oracle* oracle) {
    for (int i = 0; i < DICE_SIDES; i++) {
        Die* die = &roll->dice[i];
        die->value = random() % (DICE_SIDES + 1);
        die->entropy = log2(DICE_SIDES);

        int random_index = random() % ORACLE_SIZE;
        char random_char = oracle->data[random_index];

        switch (random_char) {
            case '+':
                die->entropy += 0.1;
                break;
            case '-':
                die->entropy -= 0.1;
                break;
            case '*':
                die->value *= 2;
                break;
            case '/':
                if (die->value > 1)
                    die->value /= 2;
                break;
        }

        roll->sum += die->value;
    }
}

void print_roll(Roll roll) {
    printf("Roll: [");
    for (int i = 0; i < DICE_SIDES; i++) {
        Die* die = &roll.dice[i];
        printf("%d (%0.2f) ", die->value, die->entropy);
    }
    printf("] Sum: %d\n", roll.sum);
}

int main() {
    Oracle* oracle = init_oracle();

    Roll roll;
    for (int i = 0; i < 10; i++) {
        roll_dice(&roll, oracle);
        print_roll(roll);
    }

    munmap(oracle, ORACLE_SIZE);

    return EXIT_SUCCESS;
}