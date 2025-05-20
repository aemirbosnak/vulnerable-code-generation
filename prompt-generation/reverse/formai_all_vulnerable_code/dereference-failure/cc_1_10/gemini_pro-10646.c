//GEMINI-pro DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Palette of shades for password strength
char *strength_shades[] = {
    "\033[31mWeak\033[0m",
    "\033[33mFair\033[0m",
    "\033[34mGood\033[0m",
    "\033[32mStrong\033[0m"
};

// Utilities
void flush_buff() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Password Validation
int validate_pass(char *pass) {
    int len = strlen(pass);
    if (len < 6) return 0;

    int upp = 0, low = 0, num = 0, sym = 0;
    for (int i = 0; i < len; i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') upp++;
        else if (pass[i] >= 'a' && pass[i] <= 'z') low++;
        else if (pass[i] >= '0' && pass[i] <= '9') num++;
        else sym++;
    }

    return (upp && low && num && sym);
}

// Password Strength
int pass_strength(char *pass) {
    int len = strlen(pass);
    if (!validate_pass(pass)) return -1;

    int score = 0;
    if (len > 8) score += 2;
    if (len > 12) score++;

    int upp = 0, low = 0, num = 0, sym = 0;
    for (int i = 0; i < len; i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') upp++;
        else if (pass[i] >= 'a' && pass[i] <= 'z') low++;
        else if (pass[i] >= '0' && pass[i] <= '9') num++;
        else sym++;
    }

    if (upp > 0) score += 2;
    if (low > 0) score += 2;
    if (num > 0) score += 2;
    if (sym > 0) score += 4;

    return score;
}

// Password Generation
char *generate_pass() {
    char *pass = malloc(10);
    int len = 10;

    // Seed random number generator
    srand(time(NULL));

    // Generate password
    for (int i = 0; i < len; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0: pass[i] = rand() % 26 + 'a'; break;
            case 1: pass[i] = rand() % 26 + 'A'; break;
            case 2: pass[i] = rand() % 10 + '0'; break;
            case 3: pass[i] = rand() % 16 + '!'; break;
        }
    }
    pass[len] = '\0';

    return pass;
}

// Main Function
int main() {
    // Welcome Message
    printf("\n\033[1;34mWelcome to the Password Manager!\033[0m\n");
    printf("\nWhat do you want to do?\n");
    printf("1. Generate a Password\n");
    printf("2. Validate a Password\n");
    printf("3. Check Password Strength\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");

    // User Choice
    int choice;
    scanf("%d", &choice);
    flush_buff();

    // Actions
    switch (choice) {
        case 1: {
            char *pass = generate_pass();
            printf("\nYour password is: %s\n", pass);
            break;
        }
        case 2: {
            char pass[32];
            printf("\nEnter your password: ");
            scanf("%s", pass);
            flush_buff();

            int valid = validate_pass(pass);
            printf("\nPassword is %s\n", valid ? "valid" : "invalid");
            break;
        }
        case 3: {
            char pass[32];
            printf("\nEnter your password: ");
            scanf("%s", pass);
            flush_buff();

            int strength = pass_strength(pass);
            if (strength == -1) {
                printf("\nPassword is invalid\n");
            } else {
                printf("\nPassword strength: %s\n", strength_shades[strength]);
            }
            break;
        }
        case 4: {
            printf("\nThank you for using the Password Manager!\n");
            break;
        }
        default: {
            printf("\nInvalid choice!\n");
        }
    }

    printf("\n\033[1;34mGoodbye!\033[0m\n");
    return 0;
}