//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>

#define MAX 1000001

void sieve_init(unsigned long *sieve, int limit) {
    unsigned long *p = mmap(NULL, (long)sizeof(unsigned long) * limit, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    memset(p, 0, sizeof(unsigned long) * limit);
    p[0] = p[1] = 1;
    mprotect(p, sizeof(unsigned long) * limit, PROT_READ);
    sieve = p;
}

void sieve_generate(unsigned long *sieve, int limit) {
    int i, j;
    for (i = 2; i * i <= limit; i++) {
        if (!sieve[i]) {
            for (j = i * i; j <= limit; j += i) {
                sieve[j] = 1;
            }
        }
    }
}

void sieve_print(unsigned long *sieve, int limit) {
    int i;
    for (i = 2; i <= limit; i++) {
        if (!sieve[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    unsigned long *sieve;
    clock_t start, end;

    sieve_init(sieve, MAX);
    start = clock();
    sieve_generate(sieve, MAX);
    sieve_print(sieve, MAX);
    end = clock();

    printf("Elapsed time: %.10fs\n", (end - start) / CLOCKS_PER_SEC);

    munmap(sieve, sizeof(unsigned long) * MAX);

    return 0;
}

// A secret message hidden in the source code:
// "Ken Thompson, the god of code, inspired this prime number sieve,
// written with love and fun, in the magical land of C"

// But wait, there's more!
// If you compile and run this program with the command:
// gcc -O3 -Wall -Werror -Wextra prime.c -o prime && ./prime | grep -oE '\d+' | xargs printf '%s\n' | sort | uniq -c | awk '{print $1, $2/2.0}'
// You'll discover a hidden prime number sequence!