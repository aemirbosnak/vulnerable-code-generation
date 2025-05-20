//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define CHAR_SET_SIZE 20
#define DELAY 10000

typedef struct{
    int x, y;
}Point;

char char_set[CHAR_SET_SIZE][3] = {{"^"}, {"_"}, {"*"}, {"="}, {"+"}, {"%"}, {"&"}, {"@"}, {"#"}, {"$"}, {"<"}, {">"}, {"|"}, {"/"}, {"\\"}, {"("}, {")"}, {"-"}, {"."}};

void generate_random_point(Point* point){
    point->x = rand() % WIDTH;
    point->y = rand() % HEIGHT;
}

void print_char(int x, int y, char c){
    printf("\033[%d;%dH%c", y, x, c);
}

void print_char_at_point(Point point, char c){
    print_char(point.x, point.y, c);
}

void print_random_char_at_point(Point point){
    int random_char_index = rand() % CHAR_SET_SIZE;
    print_char_at_point(point, char_set[random_char_index][0]);
}

void generate_shape(Point start_point){
    Point current_point;
    int shape_length = rand() % 5 + 5;

    generate_random_point(&current_point);
    while(shape_length-- > 0){
        print_char_at_point(current_point, ' ');
        print_random_char_at_point(current_point);

        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        generate_random_point(&current_point);
        current_point.x += dx;
        current_point.y += dy;
    }

    print_char_at_point(start_point, ' ');
}

int main(int argc, char** argv) {
    srand(time(NULL));

    if(argc != 2){
        printf("Usage: %s <text input>\n", argv[0]);
        return 1;
    }

    char* input_text = argv[1];

    int text_length = strlen(input_text);

    for(int i = 0; i < text_length; i++){
        Point start_point;
        generate_random_point(&start_point);

        print_char_at_point(start_point, input_text[i]);
        generate_shape(start_point);
    }

    printf("\n");
    sleep(DELAY/1000.0);

    return 0;
}