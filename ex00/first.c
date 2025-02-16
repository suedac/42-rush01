/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:18:45 by zgahrama          #+#    #+#             */
/*   Updated: 2025/02/15 17:23:54 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void check_rules(int arr[])
{
	// lets check 4s first:
}

int *put_nums(char *argv[])
{
	int *arr = malloc(16);
	char *input;
	int i;
	int array_i;

	input = argv[1];
	i = 0;
	array_i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			arr[array_i] = input[i] - '0';
			array_i++;
		}
		i++;
	}
	return arr;
}
void print(int *output)
{
	int i = 0;
	int j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			char digit;
			digit = output[j + i*4] + '0';
			write(1, &digit, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int *inputs;
	int *output = malloc(64);
	if (argc <= 1 || argc > 32)
	{
		return -1;
	}

	inputs = put_nums(argv);
	print(output);
	return 0;
}
