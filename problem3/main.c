/*
 * problem3/main.c
 *
 * https://projecteuler.net/problem=3
 * What is the largest prime factor of the number 600851475143
 *
 * NOTE: This program must be compiled with C99 for 64-bit integer support
 */
# define NUMBER (600851475143)
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>

/*
 * Gets the highest possible factor of a number (sqrt, rounded down)
 * Parameter: num
 * 	The number to check for the highest possible factor
 *
 * Returns:
 * 	The highest number that can possibly be a factor of num
 * 	I.E. floor(sqrt(num))
 */
int highestPossibleFactor(uint64_t num) {
	double value = (double) num;
	double root = sqrt(num);
	return (int) root;
}

/*
 * Uses the Sieve of Eratosthenes to create a boolean array, where
 * prime[i] == true iff i is prime.
 * Parameter: upperLimit
 * 	The highest number to check for primeness
 *
 * Returns:
 * 	An array of size upperLimit whose values correspond to the primeness
 * 	of their indeces.
 */
bool* getPrimes(int upperLimit) {
	/* array indicating primeness of integers */
	bool* prime = (bool*) malloc(upperLimit * sizeof(bool));

	/* upper limit of numbers to mark factors of */
	int innerLimit = highestPossibleFactor(upperLimit);

	/* marks composite values 'false' */
	int marker;

	int i;
	/* Initialize prime to all true */
	for (i = 0; i < upperLimit; i++) {
		prime[i] = true;
	}
	for (i = 2; i < innerLimit; i++) {
		/* If i isn't prime, we don't need to worry about it */
		/* as all its multiples have already been removed.   */
		if (!prime[i]) {
			continue;
		}
		/* mark off composite numbers */
		for (marker=i*i; marker < upperLimit; marker+=i) {
			prime[marker] = false;
		}
	}
	return prime;

}

/*
 * Finds the highest factor of 'num' that is a prime number
 * Parameter: num
 * 	The number against which to check divisibility
 *
 * Returns:
 * 	The highest factor of the number that is a prime number
 */
int getHighestPrimeFactor(uint64_t num) {
	int highest = highestPossibleFactor(num);
	bool* prime = getPrimes(highest);
	int i;
	for (i=highest-1; i!=0; i--) {
		if (!(prime[i])) continue;

		if (!(num % i)) {
			return i;
		}
	}
}

/*
 * Prints the largest prime factor of the number and exits successfully
 */
int main() {
	uint64_t number = NUMBER;
	int factor = getHighestPrimeFactor(number);
	printf("Highest prime factor of %" PRIu64 " = %d\n", number, factor);
	exit(EXIT_SUCCESS);
}
