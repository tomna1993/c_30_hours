#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int get_weeks_learned(void);
void get_learned_hours(int array_hours_learned[], int num_weeks_learned);
char get_calculation_mode(void);
void calculate_total(int num_array[], const int length);
void calculate_average(int num_array[], const int length);

int main(void)
{
	// Get user input for the number of weeks
	// use constant integer to store the numbers of weeks -> there is no chance that 
	// somewhere the program can change its value
	const int weeks_learned = get_weeks_learned();

	// create a dynamic array to store the hours
	int hours_learned[weeks_learned];

	// Get the learned hours for each week
	get_learned_hours(hours_learned, weeks_learned);

	// Ask the user which information he wants to calculate (A - average hours, T - total hours) 
	char calculation_mode = get_calculation_mode(); 

	// Calculate and print result
	if(calculation_mode == 'T')
	{
		calculate_total(hours_learned, weeks_learned);
	}
	else
	{
		calculate_average(hours_learned, weeks_learned);
	}

	// exit status 0, the program has run successfully	
	return 0;
}

// Get number of weeks learned from user 
int get_weeks_learned(void)
{
	int number;

	// Ask again for a number if user inputs characters, strings or negative nuber	
	do	
	{
		number = get_int("Numbers of weeks taking CS50: ");
	}
	while (number < 1);

	return number;
}

// Get how much time the user spent with learning
void get_learned_hours(int array_hours_learned[], int num_weeks_learned)
{
	int hours;

	// Loop through the weeks and save learned hours
	for(int i = 0; i < num_weeks_learned; i++)
	{
		do
		{
			// Get user input
			hours = get_int("Week %i HW Hours: ", i+1);

			// Feedback to user, it's not possible to learn so much in a week
			if(hours > 100)
			{
				printf("You're kidding! No human can learn and focus that much! Try with another lie ;D\n");
			}
			// It's impossible to unlearn something or learn less hours than 0
			else if(hours < 0)
			{
				printf("Wow, impressive! How can you unlearn something?\n");
			}
		
		} while (hours <= 0 || hours > 100);
		// Save learned hours
		array_hours_learned[i] = hours;
	}	
}

// Get calculation mode from user
char get_calculation_mode(void)
{
	char input; 

	// ask for input mode until user enters 'T', 't', 'A', 'a'
	do
	{
		input = get_char("Enter T for total hours, A for average hours per week: ");
		// convert lowercase letter to uppercase
		input = toupper(input);

	} while (input != 'T' && input != 'A');

	return input;		
}

// Function to calculate the total amount of hours spent with studying and print out the sum
void calculate_total(int num_array[], int length)
{
	// declare a variable and initialize it to 0
	int total = 0;

	// iterate through the elements of the array and add them together
	for(int i = 0; i < length; i++)
	{
		total += num_array[i];
	}

	// print out the sum of the array
	printf("%i hours\n", total);
}

// Function to calculate the average of hours spent with studying and print out the result 
void calculate_average(int num_array[], int length)
{
	// declare a variable and initialize it to 0
	int total = 0;

	// iterate through the elements of the array and add them together
	for(int i = 0; i < length; i++)
	{
		total += num_array[i];
	}

	// calculate the average and print it out
	printf("%.1f hours\n", total / (float) length);
}