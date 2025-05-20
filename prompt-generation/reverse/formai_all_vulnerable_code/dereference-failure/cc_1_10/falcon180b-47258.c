//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    int* prime;
    int count;
} PrimeArray;

void init(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

int isPrime(int n) {
    if(n <= 1) {
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void sieve(PrimeArray* arr) {
    int* prime = arr->prime;
    int count = arr->count;
    int size = sizeof(prime)/sizeof(prime[0]);
    init(prime, size);
    prime[0] = prime[1] = 1;
    for(int i = 2; i <= size; i++) {
        if(prime[i - 1] == 0) {
            for(int j = i*i; j <= size; j += i) {
                prime[j - 1] = 1;
            }
        }
    }
    count = 0;
    for(int i = 0; i < size; i++) {
        if(prime[i] == 0) {
            arr->prime[count++] = i + 1;
        }
    }
    arr->count = count;
}

int main() {
    int n = 1000000;
    PrimeArray arr;
    arr.prime = (int*)malloc(n * sizeof(int));
    arr.count = 0;
    sieve(&arr);
    printf("Prime numbers up to %d:\n", n);
    for(int i = 0; i < arr.count; i++) {
        printf("%d ", arr.prime[i]);
    }
    printf("\n");
    free(arr.prime);
    return 0;
}