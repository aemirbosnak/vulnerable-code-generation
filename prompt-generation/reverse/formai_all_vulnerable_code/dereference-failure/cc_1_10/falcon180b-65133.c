//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000
#define PRIME 1
#define COMPOSITE 0

// Function to check if a number is prime or not
int isPrime(int n) {
    int i;
    for(i=2;i<=sqrt(n);i++) {
        if(n%i==0) {
            return COMPOSITE;
        }
    }
    return PRIME;
}

// Function to generate prime numbers
void generatePrimes(int start, int end, int *primes, int *count) {
    int i,j,k;
    int temp[MAX];
    int index=0;
    // Initialize the array with all prime numbers from 2 to end
    for(i=2;i<=end;i++) {
        if(isPrime(i)==PRIME) {
            temp[index++]=i;
        }
    }
    // Generate prime numbers within the given range
    for(i=start;i<=end;i++) {
        if(isPrime(i)==COMPOSITE) {
            continue;
        }
        for(j=0;j<index;j++) {
            if(i%temp[j]==0) {
                break;
            }
        }
        if(j==index) {
            primes[(*count)++]=i;
        }
    }
}

int main() {
    int start,end,count=0;
    int *primes;
    srand(time(NULL));
    start=rand()%1000000+1;
    end=rand()%1000000+1;
    printf("Generating prime numbers between %d and %d...\n",start,end);
    primes=(int*)malloc(MAX*sizeof(int));
    generatePrimes(start,end,primes,&count);
    printf("Total %d prime numbers generated:\n",count);
    for(int i=0;i<count;i++) {
        printf("%d ",primes[i]);
    }
    return 0;
}