//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

#define DIGITS "0123456789"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define SYMBOLS "!@$&*?-"

void shuffle(char *array, size_t n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

char* generate_password(int length, int digits, int lowercase, int uppercase, int symbols) {

    // check the inputs are correct
    if (length <= 0 || digits < 0 || lowercase < 0 || uppercase < 0 || symbols < 0) {
        printf("Invalid Input.\n");
        return " ";
    }

    // check that there are enough characters to create a password
    if (digits + lowercase + uppercase + symbols > length) {
        printf("Cannot generate the password.\n");
        return " ";
    }

    // allocate memory for the password string and initialize it with null characters
    char *password = calloc(length + 1, sizeof(char));
    if (password == NULL) {
        printf("Memory allocation error.\n");
        return " ";
    }

    // set up the required character sets
    char *digit_set = digits ? DIGITS : "";
    char *lower_set = lowercase ? LOWER : "";
    char *upper_set = uppercase ? UPPER : "";
    char *symbol_set = symbols ? SYMBOLS : "";

    // count the number of characters that can be used in the password
    int num_available_chars = strlen(digit_set) + strlen(lower_set) + strlen(upper_set) + strlen(symbol_set);

    // check that there are enough characters to create a password
    if (num_available_chars < length) {
        printf("Cannot generate password.\n");
        return " ";
    }

    // create a temporary string to hold the available characters
    char *all_chars = calloc(num_available_chars + 1, sizeof(char));
    if (all_chars == NULL) {
        printf("Memory allocation error.\n");
        return " ";
    }

    // copy the character sets into the temporary string
    int index = 0;
    index += strlen(strcpy(all_chars+index, digit_set));
    index += strlen(strcpy(all_chars+index, lower_set));
    index += strlen(strcpy(all_chars+index, upper_set));
    index += strlen(strcpy(all_chars+index, symbol_set));

    // initialize the random generator
    srand(time(NULL));

    // fill the password string with randomly generated characters
    for (int i=0; i<length; i++) {
        int random_index = rand() % num_available_chars;
        password[i] = all_chars[random_index];
    }

    // shuffle the password string
    shuffle(password, length);

    return password;
}

int main() {

    int length = 15;
    int digits = 2;
    int lowercase = 5;
    int uppercase = 4;
    int symbols = 3;

    char *password = generate_password(length, digits, lowercase, uppercase, symbols);

    printf("Your password is: %s\n", password);

    free(password);

    return 0;

}