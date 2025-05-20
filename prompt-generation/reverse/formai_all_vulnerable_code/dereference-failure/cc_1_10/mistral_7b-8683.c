//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct {
    char name[256];
    int age;
    char favorite_color[16];
} Person;

void sanitize_input(char *input, int size) {
    for (int i = 0; i < size; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
        if (input[i] < ' ' || input[i] > '~') {
            input[i] = '\0';
        }
    }
}

int main() {
    Person p;
    char name[256];
    int age;
    char color[16];

    printf("Welcome, brave adventurer! I shall now ask you to reveal some personal information.\n");
    printf("What is your name? (max 255 characters)\n");
    fgets(name, sizeof(name), stdin);
    sanitize_input(name, strlen(name));

    printf("What is your age?\n");
    scanf("%d", &age);

    printf("What is your favorite color? (max 15 characters)\n");
    fgets(color, sizeof(color), stdin);
    sanitize_input(color, strlen(color));

    printf("Greetings, %s! You are %d years old and your favorite color is %s.\n", name, age, color);

    // Allocate memory for the Person structure
    Person *person = (Person *) mmap(NULL, sizeof(Person), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    // Copy the input data to the Person structure
    strcpy(person->name, name);
    person->age = age;
    strcpy(person->favorite_color, color);

    // Print the Person structure data
    printf("Your name: %s\n", person->name);
    printf("Your age: %d\n", person->age);
    printf("Your favorite color: %s\n", person->favorite_color);

    // Release the memory
    munmap(person, sizeof(Person));

    return 0;
}