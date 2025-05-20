//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ***************************************************************************************
// * The Witch's Cauldron: A magical place where strings are brewed and charactors are counted *
// ***************************************************************************************

void print_welcome_message() {
    printf("\n***************************************************************************************\n");
    printf("*                                                                                        *\n");
    printf("*                          Welcome to The Enchanted Charactor Counter!                       *\n");
    printf("*                                                                                        *\n");
    printf("***************************************************************************************\n");
}

int count_char(const char* str, char target) {
    int count = 0;
    const char* search = str;

    while (*search != '\0') {
        if (*search == target) {
            count++;
        }
        search++;
    }

    return count;
}

void print_result(const char* str, char target, int count) {
    printf("\nString: %s\n", str);
    printf("Target character: %c\n", target);
    printf("Number of occurrences: %d\n", count);
}

int main(int argc, char* argv[]) {
    char* str;
    char target;
    int count;

    if (argc < 3) {
        printf("Usage: %s <string> <character>\n", argv[0]);
        return 1;
    }

    str = argv[1];
    target = argv[2][0];

    print_welcome_message();

    count = count_char(str, target);

    print_result(str, target, count);

    free(str);

    return 0;
}

// ***************************************************************************************
// * The End: Charactors have been counted, and the Witch is now ready for her next brew    *
// ***************************************************************************************