//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The Knuthian Password Strength Checker
//
// This program checks the strength of a password using a method devised by
// Donald Knuth. The strength of a password is measured by the time it would
// take to crack it using a brute-force attack.
//
// The program first calculates the entropy of the password. Entropy is a
// measure of the randomness of a password. The higher the entropy, the more
// difficult it is to crack.
//
// The program then uses the entropy to calculate the time it would take to
// crack the password using a brute-force attack.
//
// The program prints out the strength of the password, along with the time it
// would take to crack it.

// The entropy of a password is calculated using the following formula:
//
// H = log2(N) + log2(S) + log2(L)
//
// where:
//
// N is the number of possible characters in the password
// S is the number of symbols in the password
// L is the length of the password

// The time it would take to crack a password using a brute-force attack is
// calculated using the following formula:
//
// T = 2^H
//
// where:
//
// H is the entropy of the password

// The main function
int main(int argc, char *argv[])
{
    // Check the command line arguments
    if (argc != 2)
    {
        printf("Usage: %s <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the password from the command line
    char *password = argv[1];

    // Calculate the length of the password
    int length = strlen(password);

    // Calculate the number of possible characters in the password
    int N = 26 * 2 + 10; // 26 lowercase letters + 26 uppercase letters + 10 digits

    // Calculate the number of symbols in the password
    int S = 0;
    for (int i = 0; i < length; i++)
    {
        if (!isalnum(password[i]))
        {
            S++;
        }
    }

    // Calculate the entropy of the password
    double H = log2(N) + log2(S) + log2(length);

    // Calculate the time it would take to crack the password using a brute-force attack
    double T = pow(2, H);

    // Print out the strength of the password
    printf("The strength of the password is %.2f bits.\n", H);

    // Print out the time it would take to crack the password using a brute-force attack
    printf("It would take %.2f years to crack the password using a brute-force attack.\n", T / 31557600);

    return EXIT_SUCCESS;
}