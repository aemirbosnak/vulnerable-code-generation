//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double distance;
    double velocity;
} UFO;

typedef struct {
    int num_ufos;
    UFO *ufos;
} Invasion;

double calc_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double calc_velocity(double distance, double time) {
    return distance / time;
}

double calc_arrival_time(double distance, double velocity) {
    return distance / velocity;
}

double calc_invasion_probability(Invasion invasion) {
    double total_distance = 0;
    double total_velocity = 0;
    for (int i = 0; i < invasion.num_ufos; i++) {
        total_distance += invasion.ufos[i].distance;
        total_velocity += invasion.ufos[i].velocity;
    }
    double average_distance = total_distance / invasion.num_ufos;
    double average_velocity = total_velocity / invasion.num_ufos;
    double average_arrival_time = calc_arrival_time(average_distance, average_velocity);
    return 1 / average_arrival_time;
}

int main() {
    int num_ufos;
    printf("Enter the number of UFOs: ");
    scanf("%d", &num_ufos);

    Invasion invasion;
    invasion.num_ufos = num_ufos;
    invasion.ufos = malloc(sizeof(UFO) * num_ufos);

    for (int i = 0; i < num_ufos; i++) {
        printf("Enter the distance of UFO %d: ", i + 1);
        scanf("%lf", &invasion.ufos[i].distance);
        printf("Enter the velocity of UFO %d: ", i + 1);
        scanf("%lf", &invasion.ufos[i].velocity);
    }

    double probability = calc_invasion_probability(invasion);
    printf("The probability of an alien invasion is: %lf\n", probability);

    return 0;
}