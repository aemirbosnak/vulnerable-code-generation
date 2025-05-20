//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_FACTORIAL 20

typedef struct {
    int num;
    char pattern[21];
} factorial_t;

void print_pattern(factorial_t *fact) {
    int i;
    for (i = 0; i < fact->num; i++) {
        printf("%s", fact->pattern + i);
        usleep(500000 / fact->num);
    }
    printf("\n");
}

factorial_t create_pattern(int num) {
    factorial_t fact;
    int i;
    char temp[21];
    strcpy(temp, " ");
    for (i = 0; i <= num; i++) {
        temp[i] = '*';
    }
    strncpy(fact.pattern, temp, 21);
    fact.num = num;
    return fact;
}

int recursive_factorial(int num, factorial_t *fact) {
    if (num > 0) {
        fact = realloc(fact, sizeof(factorial_t) * (num + 1));
        fact[num] = create_pattern(num);
        usleep(500000 / num);
        printf("Calculating %d! ", num);
        print_pattern(&fact[num]);
        return num * recursive_factorial(num - 1, fact);
    } else {
        print_pattern(&fact[0]);
        return 1;
    }
}

int main() {
    factorial_t *fact = NULL;
    int result;
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > MAX_FACTORIAL) {
        printf("Number too large, try a number less than %d\n", MAX_FACTORIAL);
        return 1;
    }

    fact = malloc(sizeof(factorial_t));
    fact[0] = create_pattern(0);
    result = recursive_factorial(num, fact);

    printf("Result: %d\n", result);

    free(fact);
    return 0;
}