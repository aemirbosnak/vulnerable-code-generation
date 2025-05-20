//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length;
    char password[100];
    srand(time(NULL));
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    printf("Enter the number of passwords you want to generate: ");
    int num_passwords;
    scanf("%d", &num_passwords);
    printf("Enter the minimum number of uppercase letters: ");
    int min_uppercase;
    scanf("%d", &min_uppercase);
    printf("Enter the minimum number of lowercase letters: ");
    int min_lowercase;
    scanf("%d", &min_lowercase);
    printf("Enter the minimum number of digits: ");
    int min_digits;
    scanf("%d", &min_digits);
    printf("Enter the minimum number of special characters: ");
    int min_special_chars;
    scanf("%d", &min_special_chars);
    int count = 0;
    while (count < num_passwords) {
        int uppercase = rand() % (length - min_uppercase) + min_uppercase;
        int lowercase = rand() % (length - min_lowercase) + min_lowercase;
        int digits = rand() % (length - min_digits) + min_digits;
        int special_chars = rand() % (length - min_special_chars) + min_special_chars;
        int remaining_length = length - uppercase - lowercase - digits - special_chars;
        for (int i = 0; i < remaining_length; i++) {
            password[i] = rand() % 26 + 97;
        }
        for (int i = 0; i < uppercase; i++) {
            password[i + remaining_length] = rand() % 26 + 65;
        }
        for (int i = 0; i < lowercase; i++) {
            password[i + remaining_length + uppercase] = rand() % 26 + 97;
        }
        for (int i = 0; i < digits; i++) {
            password[i + remaining_length + uppercase + lowercase] = rand() % 10 + 48;
        }
        for (int i = 0; i < special_chars; i++) {
            password[i + remaining_length + uppercase + lowercase + digits] = rand() % 10 + 33;
        }
        printf("Password %d: %s\n", count + 1, password);
        count++;
    }
    return 0;
}