/*
 * problem2/main.c
 *
 * https://projecteuler.net/problem=2
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */
# include <stdio.h>
# include <stdlib.h>
# define MAX_SIZE  (4000000)

/*
 * Sums all even fibonacci numbers up to and including the upper limit given
 * as a parameter.
 *
 * Parameter: end
 * 	the upper limit of fibonacci numbers to sum
 *
 * returns:
 * 	the sum of all even fibonacci numbers that are less than 'end'
 */
int sumEvenFibs(int end) {
	long sum = 0;
	int oddA = 1;
	int oddB = 1;
	int even = 2;
	while (even <= end) {
		sum += even;
		oddA = oddB + even;
		oddB = even + oddA;
		even = oddA + oddB;
	}
	return sum;
}

/*
 * Calls sumEvenFibs, prints the result to stdout, and exits successfully.
 */
int main() {
	int sum = sumEvenFibs(MAX_SIZE);
	printf("Sum of even fibonacci numbers up to 4,000,000: %d\n", sum);
	exit(EXIT_SUCCESS);
}
