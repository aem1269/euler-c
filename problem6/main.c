/*
 * problem6/main.c
 *
 * https://projecteuler.net/problem=6
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */
#include <stdio.h>
#include <stdlib.h>
#define START (1)
#define END (100)

/*
 * Efficient method to get the sum of a range of numbers.
 *
 * Parameter: start
 * 	The first number to add
 * Parameter: end
 * 	The last number to add
 * Returns:
 * 	The sum of all integers between 'start' and 'end'
 */
int getSum(int start, int end) {
	return (end + start) * (end - start + 1) / 2;
}

/*
 * Gets the square of the sum of a range of numbers.
 *
 * Parameter: start
 * 	The first number in the summation
 * Parameter: end
 * 	The last number in the summation
 * Returns:
 * 	The square of the sum of all integers between 'start' and 'end'.
 */
int getSumSquared(int start, int end) {
	int sum = getSum(start, end);
	return sum * sum;
}

/*
 * Gets the sum of the squares of a range of numbers.
 *
 * Parameter: start
 * 	The first number to square
 * Parameter: end
 * 	The last number to square
 * Returns:
 * 	The sum of the squares of all integers between 'start' and 'end'
 */
int getSquareSum(int start, int end) {
	int sum = 0;
	int i; /* iterates from 'start' to 'end' */
	for (i=start; i<=end; i++) {
		sum += i * i;
	}
	return sum;
}

/*
 * Finds the difference between the sum of the squares of the first 100 natural
 * numbers and the square of the sum of the first 100 natural numbers, prints
 * it, and exits successfully
 */
int main() {
	int difference = getSumSquared(START, END) - getSquareSum(START, END);
	printf("Square of sum - sum of squares = %d\n", difference);
	exit(EXIT_SUCCESS);
}
