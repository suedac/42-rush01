#include <stdlib.h>
#include <unistd.h>

int	*check_rules_four(int arr[], int output[]) {
	int i;
	int j;

	i = 8;
	j = 0;
	while (i < 15) {
		if (arr[i] == 4) {
			output[(i - 8) * 4 + 3] = 4;
			output[(i - 8) * 4 + 2] = 3;
			output[(i - 8) * 4 + 1] = 2;
			output[(i - 8) * 4] = 1;
		}
		i++;
	}
	while (j < 4) {
		if (arr[j] == 4) {
			output[j + 12] = 4;
			output[j + 8] = 3;
			output[j + 4] = 2;
			output[j] = 1;
		}
		j++;
	}
	return (output);
}

int	check_same_num(int num_arr[], int num) {
	int i;

	i = 0;
	while (i < 4) {
		if (num_arr[i] == num) {
			return (31); // for error
		}
		i++;
	}
	return (1); // success
}

int	*num_input_one_up_down(int output[], int arr[]) {
	int i;

	i = 0;
	while (i < 4) {
		if (arr[i] == 1) {
			output[i] = 4;
		}
		i++;
	}
	i = 4;
	while (i < 8) {
		if (arr[i] == 1) {
			output[i + 8] = 4;
		}
		i++;
	}
	return (output);
}

int	*num_input_one_left_right(int output[], int arr[]) {
	int i;
	int j;

	i = 8;
	j = 0;
	while (i < 11) {
		if (arr[i] == 1) {
			output[j] = 4;
		}
		i++;
		j += 4;
	}
	j = 3;
	while (i < 16) {
		if (arr[i] == 1) {
			output[j] = 4;
		}
		i++;
		j += 4;
	}
	return (output);
}

int	*check_two_two(int output[], int arr[]) {
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 4) {
		if (arr[i] == 2 && arr[i + 4] == 2) {
			if (output[1] == 4) {
				output[j] = 3;
				output[j + 2] = 1;
				output[j + 3] = 2;
			} else if (output[2] == 4) {
				output[j] = 2;
				output[j + 1] = 1;
				output[j + 3] = 3;
			}
		}
		j += 4;
		i++;
	}
	i = 8;
	j = 0;
	while (i < 16) {
		if (arr[i] == 2 && arr[i + 4] == 2) {
			if (output[1] == 4) {
				output[j] = 3;
				output[j + 2] = 1;
				output[j + 3] = 2;
			} else if (output[2] == 4) {
				output[j] = 2;
				output[j + 1] = 1;
				output[j + 3] = 3;
			}
		}
		j++;
		i++;
	}
	return (output);
}

int	*check_two_three(int output[], int arr[]) {
	int i;

	i = 0;
	while (i < 4) {
		if ((arr[i] == 3 && arr[i + 4] == 2) || (arr[i] == 2 && arr[i + 4] == 3)) {
			if (output[2] == 4) {
				if (output[3] == 1) {
					output[0] = 2;
					output[1] = 3;
				}
				if (output[3] == 2) {
					output[0] = 1;
					output[1] = 3;
				}
			}
			if (output[1] == 4) {
				if (output[3] == 1) {
					output[0] = 2;
					output[2] = 3;
				}
				if (output[3] == 2) {
					output[0] = 1;
					output[2] = 3;
				}
			}
		}
		i++;
	}
	i = 8;
	while (i < 12) {
		if ((arr[i] == 3 && arr[i + 4] == 2) || (arr[i] == 2 && arr[i + 4] == 3)) {
			if (output[8] == 4) {
				if (output[12] == 1) {
					output[0] = 2;
					output[4] = 3;
				}
				if (output[12] == 2) {
					output[0] = 1;
					output[4] = 3;
				}
			}
			if (output[4] == 4) {
				if (output[12] == 1) {
					output[0] = 2;
					output[8] = 3;
				}
				if (output[12] == 2) {
					output[0] = 1;
					output[8] = 3;
				}
			}
		}
		i++;
	}
	return (output);
}

int	*put_nums(char *argv[]) {
	int		*arr;
	char	*input;
	int		i;
	int		array_i;

	arr = malloc(sizeof(int) * 16);  // Correct memory allocation for 16 integers
	input = argv[1];
	i = 0;
	array_i = 0;
	while (input[i] != '\0') {
		if (input[i] != ' ') {
			arr[array_i] = input[i] - '0';
			array_i++;
		}
		i++;
	}
	return (arr);
}

void	print(int *output) {
	int		i;
	int		j;
	char	digit;

	i = 0;
	j = 0;
	while (i < 4) {
		j = 0;
		while (j < 4) {
			digit = output[j + i * 4] + '0';
			write(1, &digit, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[]) {
	int	*inputs;
	int	*output;

	output = malloc(sizeof(int) * 16);  // Correct memory allocation for 16 integers
	if (argc <= 1 || argc > 32) {
		return (-1);
	}
	inputs = put_nums(argv);

	// Initialize output array with zeros
	for (int i = 0; i < 16; i++) {
		output[i] = 0;
	}

	// Call the necessary functions here to fill the output array
	output = check_rules_four(inputs, output);
	output = check_two_two(output, inputs);
	output = check_two_three(output, inputs);
	output = num_input_one_up_down(output, inputs);
	output = num_input_one_left_right(output, inputs);

	// Print the final result
	print(output);

	// Free the memory
	free(inputs);
	free(output);

	return (0);
}
