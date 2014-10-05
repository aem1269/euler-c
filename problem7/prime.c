/*
 * problem7/prime.c
 *
 * Contains useful functions for dealing with prime numbers
 */
#include <stdlib.h>
#include "prime.h"

/*
 * Determine whether a number is prime using the simplest algorithm
 *
 * Parameter: number
 * 	The number for which to determine primeness
 * Returns:
 * 	1 if number is prime, otherwise 0
 */
int isPrime(int number) {
	int factor;
	for (factor=0; factor * factor < number; factor++) {
		if (!(number % factor)) {
			return 0;
		}
	}
	return 1;
}

/*
 * Get the 'n'th prime number
 * Parameter: n
 * 	The number of the prime to get
 * Returns:
 * 	The 'n'th prime number
 */
int getPrime(int n) {
	int* primes = (int*) malloc(sizeof(n) * n);
	int i;
	int primesFound = 1;
	primes[0] = 2;
	for (i=3; primesFound != n; i+=2) {
		if (isPrimeWithArray(i, primes, primesFound)) {
			primes[primesFound] = i;
			primesFound++;
		}
	}
	free(primes);
	return i-2;

}

/*
 * Determine if a number is prime by checking for factors in a given array.
 *
 * Parameter: number
 * 	The number to check
 * Parameter: primes
 * 	A pointer to an array containing prime numbers less than 'number'
 * Parameter: primesFound
 * 	The number of primes found in 'primes'
 * Returns:
 * 	1 if 'number' is prime, 0 otherwise
 */
int isPrimeWithArray(int number, int* primes, int primesFound) {
	int i;
	for (i=0; i<primesFound; i++) {
		if (!(number % primes[i])) {
			return 0;
		}
	}
	return 1;
}
