#include <cs50.h>
#include <stdio.h>

void calculate_total(int num_array[]);
void calculate_average(int num_array[]);

int main(void)
{
	// Get user input for the number of weeks
	const int weeks_learned = get_int("Numbers of weeks taking CS50: ");

	int hours_learned[weeks_learned];

	// Get the learned hours for each week
	for(int i = 0; i < weeks_learned; i++)
	{
		hours_learned[i] = get_int("Week %i HW Hours: ");
	}

	// Ask the user which information he wants to calculate (A - average hours, T - total hours) 
	char calculation_mode = get_char("Enter T for total hours, A for average hours per week: ");

	// Calculate and print result
	if(calculation_mode == 'T')
	{
		calculate_total(hours_learned);
	}
	else if(calculation_mode == 'A')
	{
		calculate_average(hours_learned);
	}
	
	return 0;
}

void calculate_total(int num_array[])
{
}

void calculate_average(int num_array[])
{
}