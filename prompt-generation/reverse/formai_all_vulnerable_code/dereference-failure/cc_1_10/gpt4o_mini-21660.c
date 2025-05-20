//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define NUM_SPECIAL_CHARS 10
#define NUM_DIGITS 10
#define NUM_LOWERCASE 26
#define NUM_UPPERCASE 26

// Function to generate a random password
void generate_password(char *password) {
    const char special_chars[NUM_SPECIAL_CHARS] = "!@#$%^&*()";
    const char digits[NUM_DIGITS] = "0123456789";
    const char lowercase[NUM_LOWERCASE] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[NUM_UPPERCASE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Seed the random number generator
    srand(time(NULL));

    // Ensure we have at least one of each character type
    password[0] = special_chars[rand() % NUM_SPECIAL_CHARS];
    password[1] = digits[rand() % NUM_DIGITS];
    password[2] = lowercase[rand() % NUM_LOWERCASE];
    password[3] = uppercase[rand() % NUM_UPPERCASE];

    // Fill the rest of the password
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        int char_type = rand() % 4; // Randomly choose a character type
        switch (char_type) {
            case 0:
                password[i] = special_chars[rand() % NUM_SPECIAL_CHARS];
                break;
            case 1:
                password[i] = digits[rand() % NUM_DIGITS];
                break;
            case 2:
                password[i] = lowercase[rand() % NUM_LOWERCASE];
                break;
            case 3:
                password[i] = uppercase[rand() % NUM_UPPERCASE];
                break;
        }
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_index = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    // Null terminate the password string
    password[PASSWORD_LENGTH] = '\0';
}

// Function to save the generated password to a file
void save_password_to_file(const char *file_name, const char *password) {
    FILE *file = fopen(file_name, "a"); // Open file in append mode
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", password);
    fclose(file);
}

// Function to display the usage of the program
void display_usage(char *program_name) {
    printf("Usage: %s <num_passwords> <output_file>\n", program_name);
    printf("Generate random secure passwords and save them to the specified file.\n");
    printf("<num_passwords>: Number of passwords to generate\n");
    printf("<output_file>: Path to the file where passwords will be saved\n");
}

int main(int argc, char *argv[]) {
    // Check for the right number of command line arguments
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int num_passwords = atoi(argv[1]);
    const char *output_file = argv[2];

    // Check if the number of passwords is valid
    if (num_passwords <= 0) {
        fprintf(stderr, "Please provide a positive integer for number of passwords.\n");
        return EXIT_FAILURE;
    }

    // Generate passwords and save them to the output file
    for (int i = 0; i < num_passwords; i++) {
        char password[PASSWORD_LENGTH + 1];
        generate_password(password);
        printf("Generated Password %d: %s\n", i + 1, password);
        save_password_to_file(output_file, password);
    }

    printf("Successfully generated %d passwords and saved them to %s.\n", num_passwords, output_file);
    return EXIT_SUCCESS;
}