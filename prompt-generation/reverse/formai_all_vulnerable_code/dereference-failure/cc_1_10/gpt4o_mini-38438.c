//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct Dream {
    int fragments;
    char *echo;
    struct Dream *next;
} Dream;

void weaveDream(Dream **head, const char *echo) {
    Dream *newDream = (Dream *)malloc(sizeof(Dream));
    newDream->fragments = rand() % 100;
    newDream->echo = (char *)malloc(strlen(echo) + 1);
    strcpy(newDream->echo, echo);
    newDream->next = *head;
    *head = newDream;
}

void reflectOnDreams(Dream *head) {
    Dream *current = head;
    while (current != NULL) {
        printf("Dream fragment %d whispers: %s\n", current->fragments, current->echo);
        current = current->next;
    }
}

void freeDreams(Dream *head) {
    Dream *current = head;
    while (current != NULL) {
        Dream *temp = current;
        current = current->next;
        free(temp->echo);
        free(temp);
    }
}

void surrealistSyntaxParser(const char *code) {
    printf("\nParsing the surrealist code: \"%s\"\n", code);
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '(') {
            printf("An upside-down thought appears at line %d!\n", i);
        } else if (code[i] == '}') {
            printf("A door closes softly, echoing secrets at line %d!\n", i);
        } else {
            printf("Character '%c' glides through the cosmos at line %d.\n", code[i], i);
        }
    }
}

int main() {
    Dream *dreamList = NULL;

    weaveDream(&dreamList, "A cat with a clock in its belly dances.");
    weaveDream(&dreamList, "Rain falls upwards, whispering forgotten tales.");
    weaveDream(&dreamList, "Time tricks the sun; the shadows laugh delightfully.");
    weaveDream(&dreamList, "Stars spill their secrets into the ocean of dreams.");
    
    printf("In the theater of the mind:\n");
    reflectOnDreams(dreamList);
    
    surrealistSyntaxParser("while(dream) { reflect(); }");

    freeDreams(dreamList);
    return 0;
}