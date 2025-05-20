//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000
#define PRIME_NUM 17

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generate_prime_numbers(int *numbers, int count) {
    int i = 0;
    while (i < count) {
        int num = rand() % MAX_NUM + 1;
        if (is_prime(num)) {
            numbers[i] = num;
            i++;
        }
    }
    return i;
}

int generate_public_key(int *numbers, int count, int public_num) {
    int i = 0;
    while (i < count - 1) {
        if (numbers[i] == public_num) {
            return i;
        }
        i++;
    }
    return -1;
}

int generate_private_key(int *numbers, int count, int public_num) {
    int i = 0;
    while (i < count - 1) {
        if (numbers[i] == public_num) {
            return i;
        }
        i++;
    }
    return -1;
}

int encrypt(int message, int public_key, int prime_num) {
    int result = 1;
    int temp = message;
    while (temp > 0) {
        if (temp % 2 == 1) {
            result = (result * public_key) % prime_num;
        }
        temp /= 2;
    }
    return result;
}

int decrypt(int encrypted_message, int private_key, int prime_num) {
    int result = 1;
    int temp = encrypted_message;
    while (temp > 0) {
        if (temp % 2 == 1) {
            result = (result * private_key) % prime_num;
        }
        temp /= 2;
    }
    return result;
}

int main() {
    int count = 10;
    int *numbers = (int *)malloc(count * sizeof(int));
    generate_prime_numbers(numbers, count);

    int public_num = generate_public_key(numbers, count, PRIME_NUM);
    int private_num = generate_private_key(numbers, count, PRIME_NUM);

    int message = 12345;
    int encrypted_message = encrypt(message, public_num, PRIME_NUM);
    int decrypted_message = decrypt(encrypted_message, private_num, PRIME_NUM);

    printf("Message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    free(numbers);
    return 0;
}