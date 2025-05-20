//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAGIC_NUMBER 42

void handle_error(const char* message) {
    printf("😱 %s\n", message);
    sleep(1);
    printf("🤷‍♂️ Moving on...\n");
}

int main() {
    int x = 5;
    int y = 0;
    char* message = "Hello, world!";

    // Example 1: NULL pointer dereference
    if (message == NULL) {
        handle_error("Whoops, null pointer dereference!");
    }

    // Example 2: Divide by zero
    if (x / y == 0) {
        handle_error("Oops, divide by zero!");
    }

    // Example 3: Out-of-range value
    if (x > MAGIC_NUMBER) {
        handle_error("Whoa, that's too big!");
    }

    // Example 4: Buffer overflow
    char buffer[10];
    strcpy(buffer, "This is a really long string");
    if (strlen(buffer) >= 10) {
        handle_error("Buffer overflow!");
    }

    // Example 5: Segmentation fault
    int* p = &x;
    *p = 10;
    if (x == 10) {
        handle_error("Segmentation fault!");
    }

    return 0;
}