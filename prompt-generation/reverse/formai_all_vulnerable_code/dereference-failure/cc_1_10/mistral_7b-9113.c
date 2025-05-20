//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Letter {
    char* content;
    struct Letter* next;
} Letter;

Letter* create_letter(char* content) {
    Letter* new_letter = (Letter*)malloc(sizeof(Letter));
    new_letter->content = (char*)malloc(strlen(content) + 1);
    strcpy(new_letter->content, content);
    new_letter->next = NULL;
    return new_letter;
}

void add_letter_to_stack(Letter** top, Letter* new_letter) {
    new_letter->next = *top;
    *top = new_letter;
}

void print_letter(Letter* letter) {
    printf("\n%s\n", letter->content);
}

void print_stack(Letter* top) {
    while (top != NULL) {
        print_letter(top);
        top = top->next;
    }
}

int main() {
    srand(time(NULL));
    Letter* love_stack = NULL;

    printf("Welcome to the Love Letter Game!\n");
    printf("You are sitting by the fireplace, pen in hand, writing a love letter to your beloved.\n");

    add_letter_to_stack(&love_stack, create_letter("Dear my love,\nYour smile lights up my world.\n"));
    add_letter_to_stack(&love_stack, create_letter("I long for the day when I can hold you in my arms.\n"));

    int choice;
    printf("\nDo you want to add a romantic poem to your letter? (1) Yes or (0) No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        add_letter_to_stack(&love_stack, create_letter("Your love is like a rose,\nBeautiful yet thorny.\n"));
    }

    printf("\nDo you want to add a heartfelt confession to your letter? (1) Yes or (0) No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        add_letter_to_stack(&love_stack, create_letter("I confess, my love, that I love you more than words can express.\n"));
    }

    printf("\nDo you want to add a surprise gift announcement to your letter? (1) Yes or (0) No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        add_letter_to_stack(&love_stack, create_letter("And as a surprise, I have booked a weekend getaway for us.\n"));
    }

    printf("\nYour love letter is now complete. It reads as follows:\n");
    print_stack(love_stack);

    int roll_dice = rand() % 3 + 1;

    switch (roll_dice) {
        case 1:
            add_letter_to_stack(&love_stack, create_letter("Suddenly, the doorbell rings.\nYour beloved has returned home!\n"));
            break;
        case 2:
            add_letter_to_stack(&love_stack, create_letter("Your beloved calls, their voice filled with joy and excitement.\nThey have received your letter and can't wait to see you.\n"));
            break;
        case 3:
            add_letter_to_stack(&love_stack, create_letter("Your beloved writes back, expressing their love and longing for you.\nThey are looking forward to spending the weekend with you.\n"));
            break;
    }

    print_stack(love_stack);

    return 0;
}