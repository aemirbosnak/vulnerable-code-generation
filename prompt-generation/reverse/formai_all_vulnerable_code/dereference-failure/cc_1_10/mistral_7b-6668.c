//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM 10000

typedef struct {
    int num;
    char *name;
} Fact;

Fact factorial(int n) {
    Fact result = { 0, NULL };

    if (n < 0) {
        result.num = -1;
        result.name = malloc(strlen("Error: Negative number") + 1);
        strcpy(result.name, "Error: Negative number");
        return result;
    } else if (n > MAX_NUM) {
        result.num = -2;
        result.name = malloc(strlen("Error: Number too large") + 1);
        strcpy(result.name, "Error: Number too large");
        return result;
    }

    if (n == 0 || n == 1) {
        result.num = 1;
        result.name = NULL;
        return result;
    }

    Fact temp = factorial(n - 1);

    if (temp.num == -1 || temp.num == -2) {
        free(temp.name);
        free(result.name);
        return temp;
    }

    result.num = temp.num * n;
    result.name = NULL;

    return result;
}

void print_result(Fact fact) {
    if (fact.num == -1 || fact.num == -2) {
        printf("%s\n", fact.name);
    } else {
        printf("Factorial of %d is %d\n", fact.num, fact.num);
    }

    if (fact.name != NULL) {
        free(fact.name);
    }
}

int main(int argc, char *argv[]) {
    int num;

    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    num = atoi(argv[1]);

    Fact fact = factorial(num);

    print_result(fact);

    return 0;
}