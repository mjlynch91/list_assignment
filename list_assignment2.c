/* Program that puts the first 10 elements of the peroidic table into a list ADT and prints their name, atomic symbol and atomic weight.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct list //defining a list to store atomic properties
{
	char* name;
	char* symbol;
	double mass;
	struct list* next;
} list;

list* create_list(char* c_name, char* c_symbol, double c_mass) //creating a list in the same manner the teacher did except with some new data
{
	list* head = malloc(sizeof(list));
	head->name = c_name;
	head->symbol = c_symbol;
	head->mass = c_mass;
	head->next = NULL;
	return head;
}

list* add_to_front(char* c_name, char* c_symbol, double c_mass, list* h) //same function as teacher used, with more arguments
{
	list* head = create_list(c_name, c_symbol, c_mass);
	head->next = h;
	return head;
}

list* array_to_list(char* names[], char* symbols[], double masses[], int size) //same function as teacher used, with more arguments
{
	list* head = create_list(names[0], symbols[0], masses[0]);
	int i;
	for (i = 1; i < size; i++)
	{
		head = add_to_front(names[i], symbols[i], masses[i], head);
	}
	return head;
}

void print_list(list* h, char* title) //same function as teacher used, with more arguments
{
	printf("%s\n", title);
	printf("  Name\t\tSymbol\tAtomic Mass\n");
	while (h != NULL)
	{
		if ((strlen(h->name)) <= 5) //if the name is less that 5 characters put two tabs, else put one. This is to make output look nicer.
		{
			//printf("%d\n", strlen(h->name));
			printf("  %s\t\t%s\t%.3f \n", h->name, h->symbol, h->mass);
			h = h->next;
		}
		else
		{

			printf("  %s\t%s\t%.3f \n", h->name, h->symbol, h->mass);
			h = h->next;
		}

	}
}

void *reverse_char_array(char* array[],int size) //function to reverse a character array. I did this rather than finding a way to reverse the list which would take me way longer to figure out how to do.
{
	int i;
	int j = size-1;
	for(i = 0; i<j; i++)
	{
		char* temp = array[i];
		array[i] = array[j];
		array[j]=temp;
		j--;		
	}
}

void *reverse_dbl_array(double array[],int size) //same as reversing the character array except with double as argument
{
	int i;
	int j = size-1;
	for(i = 0; i<j; i++)
	{
		double temp = array[i];
		array[i] = array[j];
		array[j]=temp;
		j--;		
	}
}

int main()
{
	list list_of_elements;
	list* head = NULL;

	char* names[10] = { "Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Fluorine","Neon" }; //names of the first 10 elements of the periodic table
	reverse_char_array(names,10);
	char* symbols[10] = { "H","He","Li","Be","B","C","N","O","F","Ne" }; //symbols for the first 10 elements of the peroidic table
	reverse_char_array(symbols,10);
	double mass[10] = { 1.008,4.003,6.941,9.012,10.811,12.011,14.007,15.999,18.998,20.180 }; //atmoic masses of the first 10 elements of the periodic table
	reverse_dbl_array(mass,10);
	
	head = array_to_list(names, symbols, mass, 10);
	print_list(head, "The first 10 elements of the Periodic Table\n");

	return 0;
}
