/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:18:45 by zgahrama          #+#    #+#             */
/*   Updated: 2025/02/16 16:46:59 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*check_rules_four(int arr[], int output[])
{
	int	i;
	int	j;

	i = 8;
	j = 0;
	while (i < 15)
	{
		if (arr[i] == 4)
		{
			output[(i - 8) * 4 + 3] = 4;
			output[(i - 8) * 4 + 2] = 3;
			output[(i - 8) * 4 + 1] = 2;
			output[(i - 8) * 4] = 1;
		}
		i++;
	}
	while (j < 4)
	{
		if (arr[j] == 4)
		{
			output[j + 12] = 4;
			output[j + 8] = 3;
			output[j + 4] = 2;
			output[j] = 1;
		}
		j++;
	}
	return (output);
}

int	check_same_num(int num_row[], int num_arr[], int num)
		// before putting the number inside the arrays, arrays created from output
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (num_arr[i] == num )
		{
			return (31); // for error
		}
		else
		{
			continue ;
		}
		i++;
	}
	return (1); // success
}

int	*put_nums(char *argv[])
{
	int		*arr;
	char	*input;
	int		i;
	int		array_i;

	arr = malloc(16);
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
	return (arr);
}

void	print(int *output)
{
	int		i;
	int		j;
	char	digit;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			digit = output[j + i * 4] + '0';
			write(1, &digit, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	*inputs;
	int	*output;

	output = malloc(64);
	if (argc <= 1 || argc > 32)
	{
		return (-1);
	}
	inputs = put_nums(argv);
	print(output);
	return (0);
}
