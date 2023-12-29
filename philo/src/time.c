/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:07:11 by aulicna           #+#    #+#             */
/*   Updated: 2023/12/29 17:02:24 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incl/philosophers.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_sec / 1000);
}

int	get_time_to_print(int meet)
{
	return (get_time() - meet);
}

void	delay(t_philo *philo, time_t delay_by)
{
	time_t	delay_finish;

	delay_finish = get_time() + delay_by;
	while (get_time() < delay_finish)
	{
        if (!continue_run_party(philo->party))
            break ;
		usleep(100);
	}
}
