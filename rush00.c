#include <unistd.h>

void rush(int x, int y);

void rush(int x, int y)
{
	if (x<=0 || y<=0)
	{
		const char *error_message = "Width and height must be positive integers.\n";
		write(1, error_message, 43);
		return;
	}
	
	for (int i=0; i<y; i++)
	{
		if (i==0) //if its the first row for y axis
		{
			write(1, "/", 1); //start the first alphabet of the first row

			for (int j=1; j<x-1; j++) //loops through every item between second to second last position
			{
				write(1, "*", 1); //print "*" for the entire first row
			}

			write(1, "\\", 1); //print closing symbol for first row
		}
		
		else if (i == y-1) //if its the last row for y axis
		{
			write(1, "\\", 1);

                        for (int j=1; j<x-1; j++) //
                        {       
                                write(1, "*", 1); //print * for the entire last row
                        }
			
			if (x>1)
			{
				write(1, "/", 1); //print closing symbol for last row
			}
		}

		else if (y>2) //dealing with middle rows now
		{
			write(1, "*", 1); //print first * if not first or last row (middle row)
			for (int j=1; j<x-1; j++)
			{
				write(1, " ", 1); //print spaces for the middle rows
			}
			if (x>1)
			{
				write(1, "*", 1); //close the line with '*'
			}
		}

		write(1, "\n", 1); //jump to next line for next row		
	}
}

int main(void)
{
	rush(5,4);
	return (0);}
