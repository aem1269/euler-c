/*
 * problem5/main.c
 *
 * https://projecteuler.net/problem=5
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */
#include <stdio.h>
#include <stdlib.h>
#define START (1)
#define END (20)

/*
 * Determines whether or not an array of factors has been completely reduced
 * to all '1's.
 *
 * Parameter: ary
 * 	The array to check
 * Parameter: size
 * 	The size of the array to check
 * Returns:
 * 	1 if the array consists only of '1's, 0 otherwise.
 */
int isCompletelyReduced(int* ary, int size) {
	int i;
	for (i=0; i<size; i++) {
		if (ary[i] != 1) {
			return 0;
		}
	}
	return 1;
}

/*
 * For all elements in an array, if the element is a multiple of 'factor',
 * divide it by 'factor'. Otherwise, don't do anything. If the array was
 * changed, return 1. Else, return 0.
 *
 * Parameter: ary
 * 	The array to factor
 * Parameter: size
 * 	The size of the array to factor
 * Parameter: factor
 * 	The factor to use to reduce elements in the array.
 * Returns:
 * 	1 if at least one element was factored. 0 otherwise.
 */
int factorArray(int* ary, int size, int factor) {
	int i;
	int found = 0;
	for (i=0; i<size; i++) {
		if (!(ary[i] % factor)) { /* if evenly divisible */
			ary[i] = ary[i] / factor;
			found = 1;
		}
	}
	return found;
}

/*
 * Finds the least common multiple of a range of integers between 'start'
 * and 'end', inclusively.
 *
 * Parameter: start
 * 	The smallest factor
 * Parameter: end
 * 	The largest factor
 * Returns:
 * 	The least common multiple of all numbers between 'start' and 'end'
 */
int findLcmOfRange(int start, int end) {
	int lcm = 1;
	int size = (end - start) + 1;
	int* factors = malloc(sizeof(start) * size);
	int i; /* iterates through indeces */
	int currentFactor = 2;

	/* Iterate through all indeces between 0 and the range of values */
	for (i=0; i<size; i++) {
		factors[i] = (i + start);
	}

	/* Reduce the array of factors, keeping track of the factors of each */
	/* number and multiplying them together. */
	while (! isCompletelyReduced(factors, size)) {
		while (factorArray(factors, size, currentFactor)) {
			lcm = lcm * currentFactor;
		}
		currentFactor++;
	}
	return lcm;
}

/*
 * The main function. Finds the least common multiple of the numbers
 * 1 to 20, prints it out, and exits successfully.
 */
int main() {
	int ans = findLcmOfRange(START, END);
	printf("LCM of all numbers 1 to 20 is %d\n", ans);
	exit(EXIT_SUCCESS);
}
