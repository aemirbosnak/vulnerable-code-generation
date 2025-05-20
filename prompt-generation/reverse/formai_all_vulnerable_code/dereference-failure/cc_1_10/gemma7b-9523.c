//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRAMES 1024

typedef struct Frame {
    int frame_num;
    float red, green, blue;
    struct Frame* next;
} Frame;

Frame* head = NULL;

void frame_add(int frame_num, float r, float g, float b) {
    Frame* new_frame = malloc(sizeof(Frame));
    new_frame->frame_num = frame_num;
    new_frame->red = r;
    new_frame->green = g;
    new_frame->blue = b;
    new_frame->next = NULL;

    if (head == NULL) {
        head = new_frame;
    } else {
        Frame* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_frame;
    }
}

void frame_display() {
    Frame* current = head;
    while (current) {
        printf("Frame %d: R %.2f G %.2f B %.2f\n", current->frame_num, current->red, current->green, current->blue);
        current = current->next;
    }
}

int main() {
    frame_add(1, 255.0, 0.0, 0.0);
    frame_add(2, 0.0, 255.0, 0.0);
    frame_add(3, 0.0, 0.0, 255.0);
    frame_add(4, 255.0, 255.0, 255.0);

    frame_display();

    return 0;
}