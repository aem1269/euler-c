/*
 * problem1/main.c
 *
 * https://projecteuler.net/problem=1
 * Find the sum of all the multiples of 3 or 5 below 1000
 */
#include <stdio.h>
#include <stdlib.h>
#define UPPER_LIMIT (1000)
#define LOWER_LIMIT (0)

const int FACTORS[] = {3, 5};

/*
 * Determine if a value is evenly divisible by any numbers in an
 * array of factors.
 *
 * Parameter: factors
 * 	array of possible factors
 * Parameter: value
 * 	value whose divisibility is to be determined
 *
 * returns:
 * 	0 if the value is not divisible by any factors
 * 	value if the value is divisible by any factors
 */
int isDivisibleByAny(const int factors[], int value) {
	int length = sizeof(factors);
	int factor;
	int i;

	for (i=0; i < length; i++) {
		factor = factors[i];
		/* if value % i == 0, return that value. */
		if (!(value % factor)) {
			return value;
		}
	}
	/* not a multiple of any factor */
	return 0;
}

/*
 * Calculate the sum of the all multiples of 'factors'.
 *
 * Parameter: lowerLimit
 * 	starting point of the summation
 * Parameter: upperLimit
 * 	finishing point of the summation
 * Parameter: factors
 * 	array of factors to use when determining divisibility
 *
 * returns:
 * 	the sum of all values greater than lowerLimit, less than lowerLimit,
 * 	and divisible by some integer in 'factors'.
 */
int sumMultiples(int lowerLimit, int upperLimit, const int factors[]) {
	int i;
	int sum = 0;
	for (i=lowerLimit; i < upperLimit; i++) {
		sum += isDivisibleByAny(factors, i);
	}

	return sum;
}

/*
 * Executes the program, prints the sum of all requested multiples, and exits
 * with code EXIT_SUCCESS.
 */
int main() {
	int sum = sumMultiples(LOWER_LIMIT, UPPER_LIMIT, FACTORS);
	printf("Sum of values %d to %d: %d\n", LOWER_LIMIT, UPPER_LIMIT, sum);
	exit(EXIT_SUCCESS);
}
