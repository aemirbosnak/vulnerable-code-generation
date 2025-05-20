//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 10

typedef struct {
    char *theory;
    struct theory_s *next;
} theory_t;

theory_t *theories = NULL;

void add_theory(char *theory) {
    theory_t *new_theory = malloc(sizeof(theory_t));
    new_theory->theory = strdup(theory);
    new_theory->next = theories;
    theories = new_theory;
}

void generate_theory() {
    theory_t *current = theories;
    int length = 1;

    if (current == NULL) {
        printf("No theories found.\n");
        return;
    }

    while (current->next != NULL) {
        length++;
        current = current->next;
    }

    int index = rand() % length;
    current = theories;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    printf("%s\n", current->theory);
}

int main() {
    srand(time(NULL));

    add_theory("The moon landing was faked.");
    add_theory("The Illuminati controls the world.");
    add_theory("The U.S. government is hiding alien technology.");
    add_theory("The 9/11 attacks were an inside job.");
    add_theory("The fluoride in our water is a mind control agent.");
    add_theory("The lizard people are among us.");
    add_theory("The pyramids were built by extraterrestrials.");
    add_theory("The CIA invented heavy metal music to control the youth.");
    add_theory("The NSA is listening to all of our conversations.");
    add_theory("The flat earth theory is the truth.");

    int choice;
    while (1) {
        printf("Press 1 to generate a conspiracy theory or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            generate_theory();
        } else {
            break;
        }
    }

    while (theories != NULL) {
        theory_t *temp = theories;
        theories = theories->next;
        free(temp->theory);
        free(temp);
    }

    return 0;
}