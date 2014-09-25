/*
 * problem4/main.c
 *
 * https://projecteuler.net/problem=4
 * Find the largest palindrome made from the product of two 3-digit numbers
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Determines if a given integer is a palindrome
 *
 * Parameter: num
 * 	The potential palindrome
 * Returns:
 * 	0 if the number is not a palindrome
 * 	A non-zero value otherwise.
 */
int isPalindrome(int num) {
	char* s = malloc(sizeof(char) * 7); /*6 digits and a null terminator*/
	char* front = s;
	char* back = s + 6;
	sprintf(s, "%d", num);

	/* move to the last character */
	while (!(*(--back)));
	while (front < back) {
		if (*(front++) != *(back--)) {
			return 0;
		}
	}
	return 1;
}

/*
 * Finds the highest palindrome that is the product of two 3-digit numbers
 *
 * Returns: Highest palindrome that is the product of two 3-digit numbers.
 */
int findHighestValidPalindrome() {
	int a, b, prod;
	int highest = 0;
	for (a = 999; a >= 100; a--) {
		for (b = a; b >= 100; b--) {
			/* prod is decreasing in this loop, so once it's   */
			/* less than the highest prime, we can stop caring */
			/* and break out of this loop.                     */
			prod = a * b;
			if (prod < highest) {
				if (a == b) return highest;
				else break;
			}
			if (isPalindrome(prod)) {
				highest = prod;
				break;
			}

		}
	}
	return highest;
}

/*
 * Finds the largest such palindrome and exits successfully
 */
int main() {
	int palindrome = findHighestValidPalindrome();
	printf("Largest palindrome found: %d\n", palindrome);
	exit(EXIT_SUCCESS);
}

