// C program for generating a
// random number in a given range.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates random numbers in range [lower, upper].
int * generateRandoms(int lower, int upper)
{
	int count = 10000;
	static int Randoms[10000]; //You may change the count
	int i;

	srand( (unsigned)time( NULL ) );

	for ( i = 0; i < count; ++i) {
      Randoms[i] = (rand() % (upper - lower + 1)) + lower ;
   }

	return Randoms;
}


