#include "lists.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int digit_count(int);
int digit_pos(int);
float digit_dec(int);

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head pointer to singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
    	int nodes = 0;
	int limit = 0;
	float value1 = 0;
	float value2 = 0;
	float tmp = 0;
	int i = 0;
	float plc_val = 1;
	
	/*Empty list is palindrome*/
	if (*head == NULL)
		return (1);
	
	/*Count nodes*/
	while (current != NULL)
	{
		current = current->next;
		nodes++;
	}
	
	/*List with one node is palindrome*/
	if (nodes == 1)
		return (1);
	
	/*Palindrome even case*/
	if (nodes % 2 == 0)
	{
		limit = nodes / 2;
		current = *head;
		for(i = 0; i < limit; i++)
		{
			value1 = (value1 * digit_pos(digit_count(current->n))) + current->n;
printf("%d\n", digit_pos(digit_count(current->n)));
			current = current->next;
		}

		for(i = 0; current != NULL; i++)
		{
			value2 = (value2 / digit_pos(digit_count(current->n))) + current->n;
			if (i > 0)
				plc_val = plc_val * digit_dec(digit_count(current->n));
printf("tmp: %f; plc_val:%f\n", value2, plc_val);
			current = current->next;
		}
		value2 = (value2 / 0.001);
	}

printf("Value1: %f; Value2: %f; plc_val: %f\n", value1, value2, plc_val);

digit_count(456);

	if (value1 == value2)
	{
		printf("Shit is a palindrome\n");
		return(1);
	}

	return (0);
}


int digit_count(int value)
{

	if ((value / 10) == 0)
		return (1);
	else if ((value / 100) == 0)
		return (2);
	else if ((value / 1000) == 0)
		return (3);
}

int digit_pos(int count)
{
	int x[] = {1, 2, 3};
	int y[] = {10, 100, 1000};
	int i;

	for (i = 0; i < 3; i++)
	{
		if (count == x[i])
			return (y[i]);
	}
	return (0);
}

float digit_dec(int count)
{
	int x[] = {1, 2, 3};
	float y[] = {0.1, 0.01, 0.001};
	int i;

	for (i = 0; i < 3; i++)
	{
		if (count == x[i])
			return (y[i]);
	}
	return (0);
}
