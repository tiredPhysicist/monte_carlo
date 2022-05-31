#include <stdio.h>
#include <math.h>


int * shuffle_doors(int *array, size_t n);

// Monte carlo simulation for Monthy Hall problem
void monty_hall() {
    
    //We have three doors, with 2 goats and a car behind them
    // 0 means goat and 1 means car
    int doors[3] = {0, 1, 0};

    float switch_win_probability; float stick_win_probability;

    float switch_wins = 0; float stick_wins = 0;
    
    int num_iterations = 1000; 
    int i;

    int lower = 0;
    int upper = 2;


    for (i = 0; i < num_iterations; i++) {
        // Randomly placing the car and the goats behind the three doors:
        int * new_doors = shuffle_doors(doors, 3);
        // call random number generator for my random steps
        int * my_random_choices;
        my_random_choices = generateRandoms(lower, upper);
        

        if (new_doors[my_random_choices[i]] != 1) {
            switch_wins++;
        }  else {
            stick_wins++;
        }

        stick_win_probability = stick_wins / (i + 1);
        switch_win_probability = switch_wins / (i + 1);
    }

    printf("Winning probability if you always switch: %f\n", switch_win_probability*100);
    printf("Winning probability if you always stick: %f\n", stick_win_probability*100);

}

int * shuffle_doors(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
    return array;
}