//Gemma-7B DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdlib.h>

typedef struct Pixel Pixel;
struct Pixel {
    int r, g, b, a;
    Pixel* next;
};

Pixel* createPixel(int r, int g, int b, int a) {
    Pixel* pixel = (Pixel*)malloc(sizeof(Pixel));
    pixel->r = r;
    pixel->g = g;
    pixel->b = b;
    pixel->a = a;
    pixel->next = NULL;
    return pixel;
}

Pixel* insertPixel(Pixel* head, int r, int g, int b, int a) {
    Pixel* pixel = createPixel(r, g, b, a);
    if (head == NULL) {
        head = pixel;
    } else {
        Pixel* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = pixel;
    }
    return head;
}

void freePixel(Pixel* pixel) {
    free(pixel);
}

int main() {
    Pixel* head = NULL;
    head = insertPixel(head, 255, 0, 0, 255);
    head = insertPixel(head, 0, 255, 0, 255);
    head = insertPixel(head, 0, 0, 255, 255);
    insertPixel(head, 255, 255, 255, 255);

    Pixel* current = head;
    while (current) {
        printf("R: %d, G: %d, B: %d, A: %d\n", current->r, current->g, current->b, current->a);
        freePixel(current);
        current = current->next;
    }

    return 0;
}