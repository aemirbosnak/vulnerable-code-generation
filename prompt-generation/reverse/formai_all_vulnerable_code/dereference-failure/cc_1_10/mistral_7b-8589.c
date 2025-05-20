//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ECHO_SIZE 100
#define SILENCE_TIME 1000

typedef struct {
    int number;
    char echo[ECHO_SIZE];
} WhisperedNumber;

void print_echo(WhisperedNumber whisper) {
    printf("%s", whisper.echo);
}

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int divider = 2; divider * divider <= number; divider++) {
        if (number % divider == 0) {
            return false;
        }
    }

    return true;
}

void generate_prime_echo(int prime, WhisperedNumber *whispered_primes) {
    char echo[ECHO_SIZE];

    sprintf(echo, "In the vast cosmic dance of digits,\nA number, prime and beautiful,\nWhispers to us, 'Behold!\nNumber %d, a diamond in the rough,\nGlistening in its purity,\nA testament to mathematical truth.\n", prime);

    strcpy(whispered_primes->echo, echo);
    whispered_primes->number = prime;
}

int main() {
    int limit, prime_count = 0;
    int *primes, prime;
    WhisperedNumber *whispered_primes = malloc(sizeof(WhisperedNumber) * 10);

    printf("Enter the limit: ");
    scanf("%d", &limit);

    srand(time(NULL));

    for (int i = 2; prime_count < 10; i++) {
        prime = i;

        if (is_prime(prime)) {
            prime_count++;
            generate_prime_echo(prime, whispered_primes + prime_count - 1);

            if (prime_count < 10) {
                i--;
                continue;
            }
        }

        while (rand() % (limit - prime + 1) != prime) {
            //
        }
    }

    for (int i = 1; i <= prime_count; i++) {
        print_echo(whispered_primes[i - 1]);
        printf("\n");
    }

    free(whispered_primes);

    sleep(SILENCE_TIME);

    return 0;
}