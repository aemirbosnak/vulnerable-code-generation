//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

typedef struct {
    int length;
    int num_uppercase;
    int num_lowercase;
    int num_numbers;
    int num_special_chars;
} password_settings;

const char* uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char* lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
const char* number_chars = "0123456789";
const char* special_chars = "!@#$%^&*()_+'\"<>?,./;:[\\]{}|`~";

// Function to generate a random character from a given character set
char random_char(const char* char_set) {
    int set_length = strlen(char_set);
    int char_index = rand() % set_length;
    
    return char_set[char_index];
}

void* generate_password(void* settings_ptr) {
    password_settings* settings = (password_settings*) settings_ptr;
    char* password = (char*) malloc((settings->length + 1) * sizeof(char));
    
    srand(time(NULL));
    
    // Generate uppercase characters
    for (int i = 0; i < settings->num_uppercase; i++) {
        password[i] = random_char(uppercase_chars);
    }
    
    // Generate lowercase characters
    for (int i = 0; i < settings->num_lowercase; i++) {
        password[settings->num_uppercase + i] = random_char(lowercase_chars);
    }
    
    // Generate numeric characters
    for (int i = 0; i < settings->num_numbers; i++) {
        password[settings->num_uppercase + settings->num_lowercase + i] = random_char(number_chars);
    }
    
    // Generate special characters
    for (int i = 0; i < settings->num_special_chars; i++) {
        password[settings->num_uppercase + settings->num_lowercase + settings->num_numbers + i] = random_char(special_chars);
    }
    
    // Shuffle the password randomly
    for (int i = 0; i < settings->length; i++) {
        int j = rand() % settings->length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    password[settings->length] = '\0';
    printf("Generated password: %s\n", password);
    
    free(password);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;
    password_settings settings;
    
    settings.length = 12;
    settings.num_uppercase = 2;
    settings.num_lowercase = 6;
    settings.num_numbers = 2;
    settings.num_special_chars = 2;
    
    pthread_create(&thread_id, NULL, generate_password, &settings);
    pthread_join(thread_id, NULL);
    
    return 0;
}