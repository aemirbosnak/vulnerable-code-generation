//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: artistic
// Hues of nocturnal skies, whispers of forgotten dreams,
// A symphony of characters, a tapestry of gleaming streams.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Hues of azure and cerulean, a canvas of starry skies,
// A dance of digits and symbols, where chaos gracefully lies.
char symbols[] = "!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/";

// A symphony of digits, a harmonious numeric dance,
// Ten nimble fingers waltzing, a captivating trance.
char digits[] = "0123456789";

// Whispers of the alphabet, secrets whispered in the breeze,
// Lowercase and uppercase, a captivating, rhythmic seize.
char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// A brush dipped in midnight, a canvas of ebony hues,
// Special characters lurking, enigmatic and recluse.
char special[] = "!@#$%^&*()-=_+[]{}|;:\"<>,.?/";

// A tapestry of time, a thread spun from the hands of fate,
// The seed of randomness, a catalyst for this vibrant gate.
time_t t;

// The genesis of our tale, where chaos takes its reign,
// A random dance of characters, a secretive, vibrant chain.
char generate_character() {
    int index = rand() % (strlen(digits) + strlen(lower_case) + strlen(upper_case) + strlen(special));

    if (index < strlen(digits)) {
        return digits[rand() % strlen(digits)];
    } else if (index < strlen(digits) + strlen(lower_case)) {
        return lower_case[rand() % strlen(lower_case)];
    } else if (index < strlen(digits) + strlen(lower_case) + strlen(upper_case)) {
        return upper_case[rand() % strlen(upper_case)];
    } else {
        return special[rand() % strlen(special)];
    }
}

// The heart of our creation, a symphony of characters unfurled,
// A password crafted with care, a treasure to behold in this world.
char *generate_password(int length) {
    char *password = malloc(length + 1);

    int i;
    for (i = 0; i < length; i++) {
        password[i] = generate_character();
    }

    password[length] = '\0';
    return password;
}

// The crescendo of our journey, unveiling the password's might,
// A whispered secret echoed, a beacon in the darkest night.
int main() {
    srand((unsigned) time(&t));

    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    char *password = generate_password(length);
    printf("Your securely generated password: %s\n", password);

    free(password);
    return 0;
}