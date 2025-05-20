//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G 6.67430E-11 //gravitational constant

//Defining structures

typedef struct{
    double x,y,z; //coordinates
    double vx,vy,vz; //velocity
    double fx,fy,fz; //force
    double mass; //mass of the object
    char* name; //name of the celestial object
} object;

typedef struct{
    object* objects[9]; //array of celestial objects
    double time_step; //time step delta t
    double time_elapsed; //time elapsed so far
    double simulation_time; //total simulation time
} simulation;

//Function Prototypes

void initialize_simulation(simulation* sim);
object* create_object(double x, double y, double z, double vx, double vy, double vz, double mass, char* name);
void print_object(object* obj);
void calculate_forces(simulation* sim);
void calculate_acceleration(object* obj1, object* obj2);
void update_positions(simulation* sim);
void update_velocities(simulation* sim);
double distance_between_objects(object* obj1, object* obj2);

//Main Function

int main(){
    simulation sim;
    initialize_simulation(&sim);

    printf("Welcome to Solar System Simulation.\n");
    printf("------------\n");
    printf("Simulation Started\n");

    for(double t=0; t<sim.simulation_time; t+=sim.time_step){
        calculate_forces(&sim);
        update_positions(&sim);
        update_velocities(&sim);

        if((int)t%86400 == 0){
            printf("------------\n");
            printf("Time Elapsed: %.0f day/s\n", t/86400);
            printf("------------\n");
            print_object(sim.objects[0]);
            print_object(sim.objects[1]);
            print_object(sim.objects[2]);
            print_object(sim.objects[3]);
            print_object(sim.objects[4]);
            print_object(sim.objects[5]);
            print_object(sim.objects[6]);
            print_object(sim.objects[7]);
        }
    }

    printf("------------\nSimulation Ended.\n");
    return 0;
}

//Function Definitions

void initialize_simulation(simulation* sim){
    //creating objects
    object* sun = create_object(0,0,0,0,0,0,1.989E30,"Sun");
    object* mercury = create_object(6.981E10,0,0,0,47890,0,3.285E23,"Mercury");
    object* venus = create_object(1.0748E11,0,0,0,35020,0,4.867E24,"Venus");
    object* earth = create_object(1.471E11,0,0,0,29783,0,5.972E24,"Earth");
    object* mars = create_object(2.066E11,0,0,0,24077,0,6.39E23,"Mars");
    object* jupiter = create_object(7.407E11,0,0,0,13070,0,1.898E27,"Jupiter");
    object* saturn = create_object(1.3526E12,0,0,0,9644,0,5.683E26,"Saturn");
    object* uranus = create_object(2.7413E12,0,0,0,6805,0,8.681E25,"Uranus");
    object* neptune = create_object(4.4435E12,0,0,0,5435,0,1.024E26,"Neptune");

    //adding objects to the simulation
    sim->objects[0] = sun;
    sim->objects[1] = mercury;
    sim->objects[2] = venus;
    sim->objects[3] = earth;
    sim->objects[4] = mars;
    sim->objects[5] = jupiter;
    sim->objects[6] = saturn;
    sim->objects[7] = uranus;
    sim->objects[8] = neptune;

    //setting simulation time and time step
    sim->simulation_time = 3.154E7*5; //5 years
    sim->time_step = 86400; //1 day
    sim->time_elapsed = 0;
}

object* create_object(double x, double y, double z, double vx, double vy, double vz, double mass, char* name){
    object* obj = (object*)malloc(sizeof(object));
    obj->x = x;
    obj->y = y;
    obj->z = z;
    obj->vx = vx;
    obj->vy = vy;
    obj->vz = vz;
    obj->fx = 0;
    obj->fy = 0;
    obj->fz = 0;
    obj->mass = mass;
    obj->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(obj->name, name);
    return obj;
}

void print_object(object* obj){
    printf("%s\n", obj->name);
    printf("Coordinates: (%.2f, %.2f, %.2f)\n", obj->x, obj->y, obj->z);
    printf("Velocity: (%.2f, %.2f, %.2f)\n", obj->vx, obj->vy, obj->vz);
    printf("Mass: %.2e kg\n", obj->mass);
    printf("------------\n");
}

void calculate_forces(simulation* sim){
    for(int i=0; i<9; i++){
        sim->objects[i]->fx = 0;
        sim->objects[i]->fy = 0;
        sim->objects[i]->fz = 0;
    }
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            calculate_acceleration(sim->objects[i], sim->objects[j]);
        }
    }
}

void calculate_acceleration(object* obj1, object* obj2){
    double r = distance_between_objects(obj1, obj2);
    double f = G*obj1->mass*obj2->mass/(r*r);
    double fx = f*(obj2->x-obj1->x)/r;
    double fy = f*(obj2->y-obj1->y)/r;
    double fz = f*(obj2->z-obj1->z)/r;

    obj1->fx += fx;
    obj1->fy += fy;
    obj1->fz += fz;

    obj2->fx -= fx;
    obj2->fy -= fy;
    obj2->fz -= fz;
}

void update_positions(simulation* sim){
    for(int i=0; i<9; i++){
        object* obj = sim->objects[i];
        obj->x += obj->vx*sim->time_step+0.5*obj->fx/obj->mass*(sim->time_step*sim->time_step);
        obj->y += obj->vy*sim->time_step+0.5*obj->fy/obj->mass*(sim->time_step*sim->time_step);
        obj->z += obj->vz*sim->time_step+0.5*obj->fz/obj->mass*(sim->time_step*sim->time_step);
    }
    sim->time_elapsed += sim->time_step;
}

void update_velocities(simulation* sim){
    for(int i=0; i<9; i++){
        object* obj = sim->objects[i];
        obj->vx += obj->fx/obj->mass*sim->time_step;
        obj->vy += obj->fy/obj->mass*sim->time_step;
        obj->vz += obj->fz/obj->mass*sim->time_step;
    }
}

double distance_between_objects(object* obj1, object* obj2){
    double x_dis = obj2->x-obj1->x;
    double y_dis = obj2->y-obj1->y;
    double z_dis = obj2->z-obj1->z;
    return sqrt(x_dis*x_dis+y_dis*y_dis+z_dis*z_dis);
}