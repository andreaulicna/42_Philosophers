/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:11:02 by aulicna           #+#    #+#             */
/*   Updated: 2023/11/11 22:56:43 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_S
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define DIED "has died"

typedef struct s_input
{
	int	num_philos;
	int	time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int	must_eat;
} t_input;

typedef struct s_philo
{
	int	id;
	int	meals_count;
	unsigned long	last_meal;

} t_philo;

typedef struct s_party
{
 t_input *input;
 t_philo *philos;
 
} t_party;

// input.c
void	read_input(t_input *input, int argc, char **argv);
void	check_input_for_numbers(int argc, char **argv);

#endif