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

int	main(int argc, char *argv[])
{
	int arr[50];
	char *input;
	int i;
	int current_num;

	i = 0;
	current_num = 0;
	input = argv[1];

	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			arr[i] = input[i] - '0';
		}
		i++;
	}
	return (0);
}


