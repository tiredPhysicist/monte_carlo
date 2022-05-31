// Simple program to demonstrate an example of random walk monte carlo simulation
  
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include "random_number_generator.c"

double get_distance(int x, int y, int z);

// main function -
// where the execution of program begins
void random_walk_3d()
{
  
    // says welcome
    printf("Bienvenue! \n");
    
    // On to random walk...
        // You should also put this inside its own function
        // First lets define our coordinates: 
    float x, y, z;
    x = 0;
    y = 0;
    z = 0;

    // mapping: 
        // 0 -> +x
        // 1 => -x
        // 2 => +y
        // 3 => -y
        // 4 => +z
        // 5 => -z
    
    // lets create a for loop and take some random steps! 
    int i; int j; int counter = 0; 
    int num_steps = 10;
    int num_walks = 5;

    int lower = 0;
    int upper = 5;

    // call random number generator for my random steps
    int * my_random_steps;
    my_random_steps = generateRandoms(lower, upper);    

    double to_avg = 0;
    
    for (j = 0; j < num_walks; j++) {
        for (i = 0; i < num_steps; i++) {
            // if and else cases, they can be written as switch cases as well
            if (my_random_steps[i] == 0) {
                x++;
            } else if (my_random_steps[i] == 1) {
                x--;
            } else if (my_random_steps[i] == 2) {
                y++;
            } else if (my_random_steps[i] == 3) {
                y--;
            } else if (my_random_steps[i] == 4) {
                z++;
            } else if (my_random_steps[i] == 5) {
                z--;
            }
        }
        double my_distance = get_distance(x, y, z);

        to_avg = to_avg + my_distance;

    }

    double average_distance = to_avg / num_walks;
    printf("Average distance over %d walks of %d steps is %f\n", num_walks, num_steps, average_distance);

    //printf("Your current position after %d steps is: \n", num_steps); //This is here for logging purposes, should be deleted later
    //printf("x=%f, y=%f, z=%f\n", x,y,z);

}

double get_distance(int a, int b, int c) {
    double total = (a*a) + (b*b) + (c*c);
    double distance = sqrt(total);
    return distance;
}

