/*
 * Eric Gallager
 * George Washington University
 *
 * Assignment:
 * Write a program that generates a simple calendar for one month given what day the first day is and how many days there are in that month.
 * For example:
 * - Input: 
 * The first day is: Thu
 *	The days in the month: 31
 * 
 * - Output
 * 
 * Sun Mon Tue Wed Thu Fri Sat
 *					 1   2   3
 *  4   5    6   7   8   9  10
 * 11  12   13  14  15  16  17
 * 18  19   20  21  22  23  24
 * 25  26   27  28  29  30  31
 * 
 * Note: Probably you need to use character strings in this program,
 * 
 * to declare a char string s1 which can contain 9 characters at most: char s1[10];
 * 
 * to compare whether a char string s1 and another string s2 are equal: strcmp(s1, s2);
 * 
 * strcmp(s1, s2): The function returns an integer greater than, equal to, or less than 0,  if the string pointed to by s1 is greater than, equal to, or less than the string pointed to by s2 respectively.
 *
 * --- 
 * 
 * Algorithm:
 * 
 * 1. get_day_of_week() function:
 *	1a. Prompt user for input, specifying clearly what strings are acceptable
 *	1b. Get input and put it into a character string
 *	1c. Compare the input string against the possible options
 *	1d. If it matches one of the days, return a number corresponding to that day of the week.
 *	1e. Otherwise, ask the user to try again.
 * 2. get_month_length() function:
 *	2a. Prompt user for a number from 28 to 31
 *	2b. Get input & return it
 * 3. Put the first number in the cell corresponding to the number returned from the get_day_of_week() function
 * 4. Use nested loops to go through each column in each row until the number returned by the get_month_length() function is reached.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * get_day_of_week(): does just what its name says
 */
int get_day_of_week(int day); // Prototype
int get_day_of_week(int day) {
	day = 0; // Declare & initialize
	char day_string[4] = {'0', '0', '0', '0'}; // Declare & initialize
	int valid = 1; // Initialize truth-flag
	int i = 0; // Initialize loop-counter
	int check = 0; // Used later
	char sun[4] = "Sun"; // To be compared against later (Sunday)
	// printf("\n %s \n", sun); // Statement for debugging
	char mon[4] = "Mon"; // To be compared against later (Sunday)
	// printf("\n %s \n", mon); // Statement for debugging
	char tue[4] = "Tue"; // To be compared against later (Sunday)
	// printf("\n %s \n", tue); // Statement for debugging
	char wed[4] = "Wed"; // To be compared against later (Sunday)
	// printf("\n %s \n", wed); // Statement for debugging
	char thu[4] = "Thu"; // To be compared against later (Sunday)
	// printf("\n %s \n", thu); // Statement for debugging
	char fri[4] = "Fri"; // To be compared against later (Sunday)
	// printf("\n %s \n", fri); // Statement for debugging
	char sat[4] = "Sat"; // To be compared against later (Sunday)
	// printf("\n %s \n", sat); // Statement for debugging
	char * week[8] = {sun, mon, tue, wed, thu, fri, sat}; // Put days of the week into an array
	/* for (i = 0; i < 7; i++) {
		printf("\n day %i of the week is %s \n", i+1, week[i]); // Statement for debugging
	} */
	i = 0; // reset
	while (valid == 1) {
		printf("\n Choose a day from the following: Sun, Mon, Tue, Wed, Thu, Fri, Sat. (It must be typed with the exact correct 3 letters, including case)> "); // prompt
		scanf("%s", &day_string); // Get input (this way works, despite what the warnings might say)
		/* for (i = 0; i < 4; i++) { // This entire loop is for printing a debugging statement
			printf("\n day_string[%i] = %c \n", i, day_string[i]); // Statement for debugging
		}
		printf("\n day_string (the whole thing) is \"%s\" \n", day_string); // Statement for debugging */
		if (day_string[3] != '\0') { // If the string entered is 3 characters, the 4th cell should be a null termination. Check to make sure that this is true.
			printf("\n Your day abbreviation was spelled with an incorrect number of letters. Please try again. \n");
		} else {
			valid++;
		}
		i = 0; // reset
		for (i = 0; i < 7; i++) {
			check = strcmp(week[i], day_string); // compare the entered string with each string in week[]
			if (check == 0) {
				day = i+1; // assign whatever the loop-counter got up to to day
				// printf("\n Day = %i \n", day); // Statement for debugging
			}
		}
		if (day == 0) { // Should still be 0 if none of the strings matched
			printf("\n The string you entered is not a recognized string. Please try again. \n");
			valid = 1; // Keep us in this loop
		}
	}
	return day; // Placeholder
}

/*
 * get_month_length(): also does just what its name says
 */
int get_month_length(int month_length); // Prototype
int get_month_length(int month_length) {
	month_length = 0; // Declare & initialize
	int valid = 1; // Initialize truth-flag
	while (valid == 1) {
		printf("\n How long is the month (in days)?> "); // Prompt
		scanf("%d", &month_length); // Get input
		if (month_length < 28) {
			printf("\n Your month length is too short. Months must be 28 days or longer. Try again. \n");
		} else if (month_length > 31) {
			printf("\n Your month length is too long. Months must be 31 days or shorter. Try again. \n");
		} else {
			valid++;
		}
	}
	return month_length; // Pass back to main function
}

int main (int argc, const char * argv[]) { // Taken from template for arguments for main()
	int day = 0; // Declare & initialize
	int month_length = 0; // Declare & initialize
	int i = 0; // Initialize loop-counter, used later
	int j = 0; // Initialize loop-counter, used later
	int k = 0; // Initialize another counter-type variable thing
	// int calendar[7][6]; // Two-dimensional array for the calendar (actually never mind, not needed so I commented it out)
    printf("\n Message for security and/or debugging: \n This program's path is %s and it is running with %i argument(s). \n", argv[0], argc); // Statement for debugging
	printf("\n This program will generate a calendar based on the starting day of the month and the length of the month. First we will need the starting day:");
	day = (int)get_day_of_week(day); // Set day to user input
	// printf("\n day = %i \n", day); // Statement for debugging
	day--; // so it works right
	j = day;
	month_length = (int)get_month_length(month_length); // Set month_length to user input
	// printf("\n month_length = %d \n", month_length); // Statement for debugging
	printf("\n	Sun	Mon	Tue	Wed	Thu	Fri	Sat	\n"); // Top row
	for (j = 0; j < day; j++) { 
		printf("	"); // tab over until it gets to the right day
	}
	// k++;
	for (i = 0; i <= 6; i++) { // go through each row
		for (k = k; k <= month_length; k++) { // go through each column
			for (j = day; j < 7; j++) {
				k++; // just seeing what happens if I put this here
				if (k <= month_length) {
					printf("	%i", k); // Print each day
				}
				day = 0; // Reset because it only starts on a certain day in the first week
			}
			k--; // don't really get why I need this, but I do (to get the day numbers printed correctly)
			printf("\n"); // Each row ends in a newline
		}
		// day = 0; // Reset because it only starts on a certain day in the first week
	}
    return 0;
}

// newline \n

