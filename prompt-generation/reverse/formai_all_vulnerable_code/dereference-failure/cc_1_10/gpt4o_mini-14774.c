//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128
#define NUM_SPECIAL_CHARS 10

const char special_chars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
const char lower_chars[] = "abcdefghijklmnopqrstuvwxyz";
const char upper_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";

void print_usage(char *program_name) {
    printf("Usage: %s <length> <use_uppercase> <use_digits> <use_special>\n", program_name);
}

int is_valid_length(int length) {
    return length >= 1 && length <= MAX_LENGTH;
}

char *generate_password(int length, int use_uppercase, int use_digits, int use_special) {
    char password[MAX_LENGTH + 1];
    char charset[MAX_LENGTH];

    int index = 0;

    // Add character sets to the charset based on the user's requirements
    strcpy(charset + index, lower_chars);
    index += strlen(lower_chars);

    if (use_uppercase) {
        strcpy(charset + index, upper_chars);
        index += strlen(upper_chars);
    }

    if (use_digits) {
        strcpy(charset + index, digits);
        index += strlen(digits);
    }

    if (use_special) {
        for (int i = 0; i < NUM_SPECIAL_CHARS; i++) {
            password[i] = special_chars[i];
        }
        index += NUM_SPECIAL_CHARS;
    }

    charset[index] = '\0';

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % index];
    }

    password[length] = '\0';  // Null-terminate the string

    // Allocate memory for the password string to return
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, password);
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int length = atoi(argv[1]);
    int use_uppercase = atoi(argv[2]);
    int use_digits = atoi(argv[3]);
    int use_special = atoi(argv[4]);

    if (!is_valid_length(length)) {
        fprintf(stderr, "Length must be between 1 and %d\n", MAX_LENGTH);
        return EXIT_FAILURE;
    }

    char *password = generate_password(length, use_uppercase, use_digits, use_special);
    printf("Generated Password: %s\n", password);
    
    free(password); // Free the allocated memory for the password
    return EXIT_SUCCESS;
}