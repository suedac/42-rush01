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



/*int check_rules(int arr[])
{
	//lets check 4s first:

	// return the array(not 'an' array:D)
}*/

int* put_nums(char *argv[])
{
	int arr[50];
	char *input;
	int i;

	input = argv[1];
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			arr[i] = input[i] - '0';
		}
		i++;
	}
	return *arr;
}

int main(int argc, char *argv[])
{
	int arr[50];
	char *input;
	int i;

	i = 0;
	
	if (argc <= 1 || argc > 32)
	{
		return -1;
	}
	else
	{
		put_nums(*argv);
		return 0;
	}
}
