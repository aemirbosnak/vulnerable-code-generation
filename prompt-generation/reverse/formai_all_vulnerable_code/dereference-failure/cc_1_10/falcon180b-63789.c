//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LENGTH 1000
#define ALPHABET_LENGTH 26
#define DIGIT_LENGTH 10
#define UPPER_CASE_A 65
#define LOWER_CASE_A 97

typedef struct {
    char* message;
    int length;
    int checksum;
} Checksum;

int is_valid_alphabet(char c) {
    if (isalpha(c)) {
        return true;
    } else {
        return false;
    }
}

int is_valid_digit(char c) {
    if (isdigit(c)) {
        return true;
    } else {
        return false;
    }
}

int is_valid_character(char c) {
    if (isalpha(c) || isdigit(c)) {
        return true;
    } else {
        return false;
    }
}

int get_index(char c) {
    if (isupper(c)) {
        return c - UPPER_CASE_A;
    } else {
        return c - LOWER_CASE_A;
    }
}

int get_checksum(Checksum* checksum) {
    int sum = 0;
    for (int i = 0; i < checksum->length; i++) {
        sum += get_index(checksum->message[i]);
    }
    return sum % 26 + 65;
}

void generate_checksum(Checksum* checksum) {
    int sum = get_checksum(checksum);
    char* checksum_str = malloc(2 * sizeof(char));
    sprintf(checksum_str, "%c", sum);
    strcat(checksum->message, checksum_str);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter your message: ");
    fgets(input, MAX_LENGTH, stdin);
    int length = strlen(input);

    if (length > MAX_LENGTH) {
        printf("Error: Message is too long.\n");
        return 1;
    }

    Checksum* checksum = malloc(sizeof(Checksum));
    checksum->message = malloc((length + 2) * sizeof(char));
    strcpy(checksum->message, input);
    checksum->length = length;

    int i = 0;
    while (i < length) {
        if (!is_valid_character(input[i])) {
            printf("Error: Message contains invalid characters.\n");
            free(checksum->message);
            free(checksum);
            return 1;
        }
        i++;
    }

    generate_checksum(checksum);

    printf("Your message with checksum is: %s\n", checksum->message);

    free(checksum->message);
    free(checksum);

    return 0;
}