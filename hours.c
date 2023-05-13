#include <cs50.h>
#include <stdio.h>

void calculate_total(int num_array[], const int length);
void calculate_average(int num_array[], const int length);

int main(void)
{
	// Get user input for the number of weeks
	// use constant integer to store the numbers of weeks -> there is no chance that 
	// somewhere the program can change its value
	const int weeks_learned = get_int("Numbers of weeks taking CS50: ");

	// create a dynamic array to store the hours
	int hours_learned[weeks_learned];

	// Get the learned hours for each week
	for(int i = 0; i < weeks_learned; i++)
	{
		hours_learned[i] = get_int("Week %i HW Hours: ", i);
	}

	// Ask the user which information he wants to calculate (A - average hours, T - total hours) 
	char calculation_mode = get_char("Enter T for total hours, A for average hours per week: ");

	// Calculate and print result
	if(calculation_mode == 'T')
	{
		calculate_total(hours_learned, weeks_learned);
	}
	else if(calculation_mode == 'A')
	{
		calculate_average(hours_learned, weeks_learned);
	}

	// exit status 0, the program has run successfully	
	return 0;
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