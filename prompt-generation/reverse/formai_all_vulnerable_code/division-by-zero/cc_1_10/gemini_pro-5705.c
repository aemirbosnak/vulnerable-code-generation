//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets for password generation
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_DIGITS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_+=-`~?"

// Define the default configuration parameters
#define DEFAULT_PASSWORD_LENGTH 12
#define DEFAULT_INCLUDE_LOWERCASE 1
#define DEFAULT_INCLUDE_UPPERCASE 1
#define DEFAULT_INCLUDE_DIGITS 1
#define DEFAULT_INCLUDE_SYMBOLS 0

// Define the structure to hold the configuration parameters
typedef struct {
    int password_length;
    int include_lowercase;
    int include_uppercase;
    int include_digits;
    int include_symbols;
} password_config_t;

// Function to generate a random character from a given character set
char generate_random_char(char *charset) {
    int index = rand() % strlen(charset);
    return charset[index];
}

// Function to generate a random password based on the given configuration
char *generate_random_password(password_config_t config) {
    // Allocate memory for the password
    char *password = malloc(config.password_length + 1);

    // Initialize the password to empty
    password[0] = '\0';

    // Generate the password characters
    for (int i = 0; i < config.password_length; i++) {
        char charset[] = "";
        if (config.include_lowercase) {
            strcat(charset, CHARSET_LOWERCASE);
        }
        if (config.include_uppercase) {
            strcat(charset, CHARSET_UPPERCASE);
        }
        if (config.include_digits) {
            strcat(charset, CHARSET_DIGITS);
        }
        if (config.include_symbols) {
            strcat(charset, CHARSET_SYMBOLS);
        }
        password[i] = generate_random_char(charset);
    }

    // Null-terminate the password
    password[config.password_length] = '\0';

    // Return the password
    return password;
}

// Function to print the password generation configuration
void print_password_generation_configuration(password_config_t config) {
    printf("Password Generation Configuration:\n");
    printf("  Password Length: %d\n", config.password_length);
    printf("  Include Lowercase: %s\n", config.include_lowercase ? "Yes" : "No");
    printf("  Include Uppercase: %s\n", config.include_uppercase ? "Yes" : "No");
    printf("  Include Digits: %s\n", config.include_digits ? "Yes" : "No");
    printf("  Include Symbols: %s\n", config.include_symbols ? "Yes" : "No");
}

// Function to get the password generation configuration from the user
void get_password_generation_configuration(password_config_t *config) {
    // Get the password length
    printf("Enter the desired password length (default: %d): ", DEFAULT_PASSWORD_LENGTH);
    scanf("%d", &config->password_length);

    // Get the include lowercase option
    printf("Include lowercase characters (Yes/No) [default: Yes]: ");
    char include_lowercase[4];
    scanf("%s", include_lowercase);
    config->include_lowercase = strcmp(include_lowercase, "Yes") == 0 || strcmp(include_lowercase, "Y") == 0;

    // Get the include uppercase option
    printf("Include uppercase characters (Yes/No) [default: Yes]: ");
    char include_uppercase[4];
    scanf("%s", include_uppercase);
    config->include_uppercase = strcmp(include_uppercase, "Yes") == 0 || strcmp(include_uppercase, "Y") == 0;

    // Get the include digits option
    printf("Include digits (Yes/No) [default: Yes]: ");
    char include_digits[4];
    scanf("%s", include_digits);
    config->include_digits = strcmp(include_digits, "Yes") == 0 || strcmp(include_digits, "Y") == 0;

    // Get the include symbols option
    printf("Include symbols (Yes/No) [default: No]: ");
    char include_symbols[4];
    scanf("%s", include_symbols);
    config->include_symbols = strcmp(include_symbols, "Yes") == 0 || strcmp(include_symbols, "Y") == 0;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the password generation configuration from the user
    password_config_t config;
    get_password_generation_configuration(&config);

    // Print the password generation configuration
    print_password_generation_configuration(config);

    // Generate the random password
    char *password = generate_random_password(config);

    // Print the generated password
    printf("\nYour random password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}