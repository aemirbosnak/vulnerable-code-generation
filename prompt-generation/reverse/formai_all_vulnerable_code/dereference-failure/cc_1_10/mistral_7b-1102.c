//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#define ON  1
#define OFF 0

typedef struct {
    int state;
    char name[20];
} Light;

int main(void) {
    Light *lamp1 = malloc(sizeof(Light));
    Light *lamp2 = malloc(sizeof(Light));

    strcpy(lamp1->name, "Living Room");
    strcpy(lamp2->name, "Kitchen");

    lamp1->state = OFF;
    lamp2->state = ON;

shapeshift:
    if (lamp1->state == OFF && lamp2->state == OFF) {
        printf("Both %s and %s are off.\n", lamp1->name, lamp2->name);
        goto dimmer;
    } else if (lamp1->state == OFF && lamp2->state == ON) {
        printf("The %s is off but the %s is on.\n", lamp1->name, lamp2->name);
        goto switchit;
    } else if (lamp1->state == ON && lamp2->state == OFF) {
        printf("The %s is on but the %s is off.\n", lamp1->name, lamp2->name);
        goto flipflop;
    } else { // Both lamps are on
        printf("Both the %s and %s are on.\n", lamp1->name, lamp2->name);
        goto shapeshift;
    }

dimmer:
    if (lamp1->state == OFF) {
        printf("Dimming up %s...\n", lamp1->name);
        lamp1->state = ON;
        goto shapeshift;
    } else {
        printf("Dimming down %s...\n", lamp1->name);
        lamp1->state = OFF;
        goto shapeshift;
    }

switchit:
    lamp1->state = lamp2->state;
    printf("%s is now %s like %s.\n", lamp1->name, (lamp1->state == ON ? "on" : "off"), lamp2->name);
    goto shapeshift;

flipflop:
    lamp2->state = !lamp2->state;
    printf("%s is now %s.\n", lamp2->name, (lamp2->state == ON ? "on" : "off"));
    goto shapeshift;
}