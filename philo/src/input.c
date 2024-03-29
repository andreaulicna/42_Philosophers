/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:37:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/17 15:29:58 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

/**
 * @brief	Eequivalent to isdigit() function written by me. It checks whether
 * the argument is a digit.
 * 
 * @param	c	int to check for being digit
*/
static int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
	{
		return (2048);
	}
	return (0);
}

/**
 * @brief	Similar to atoi() function written by me. It converts a string
 * into a number.
 * 
 * @param	nptr	string to convert into a number
*/
static int	ft_atoi(const char *nptr)
{
	int	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((7 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
		{
			sign *= -1;
		}
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (0 <= result && result <= INT_MAX)
		return (result * sign);
	return (-2);
}

/**
 * @brief	Prints an error message when invalid arguments are provided
 * to the program.
*/
static void	no_valid_argumets(void)
{
	printf("Input error: Invalid arguments received.\n\n");
	printf("Correct usage: ./philo number_of_philosophers time_to_die "
		"time_to_eat time_to_sleep "
		"[number_of_times_each_philosopher_must_eat]\n\n");
	printf("All the input arguments must be numbers. All of them, except "
		"the number_of_philosophers and "
		"the number_of_times_each_philosophers_must_eat, must be bigger "
		"than 0.\n");
	printf("The number_of_philosophers must be between 1 and 200.\n");
	printf("The number_of_times_each_philosophers_must_eat must be bigger or "
		"equal to 0.\n\n");
}

/**
 * @brief	Checks whether the provided command-line arguments include only
 * numerical characters. 
 * 
 * It is called before the red_input() function to ensure that ft_atoi
 * doesn't mistakenly process an argument that includes other characters
 * following the numerical ones.
 * 
 * @param	argc
 * @param	argv
*/
int	check_input_for_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				no_valid_argumets();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief	Reads the command-line arguments, converts them into numbers and
 * stores them in the input struct.
 * 
 * @param	input	struct for input
 * @param	argc
 * @param	argv
*/
int	read_input(t_input *input, int argc, char **argv)
{
	input->num_philos = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->must_eat = ft_atoi(argv[5]);
	else
		input->must_eat = -1;
	if (input->num_philos < 1 || input->num_philos > 200
		|| input->time_to_die <= 0 || input->time_to_eat <= 0
		|| input->time_to_sleep <= 0 || input->must_eat <= -2)
	{
		no_valid_argumets();
		return (0);
	}
	return (1);
}
