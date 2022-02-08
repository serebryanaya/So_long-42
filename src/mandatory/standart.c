/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:29:58 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 09:47:21 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	modif_atoi(char *s, int *flag, int i, unsigned int	number)
{
	int				sign;

	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] != 0 && *flag != -1)
	{
		if (s[i] < '0' || s[i] > '9')
			*flag = -1;
		while (s[i] >= '0' && s[i] <= '9' && *flag != -1)
		{
			number = 10 * number + (s[i++] - '0');
			if ((number > 2147483647 && sign == 1) || (number > 2147483648 && \
	sign == -1))
				*flag = -1;
		}
	}
	return (sign * number);
}

static int	num_len(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num / 10 > 0)
	{
		len++;
		num = num / 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	sign;
	int		len;
	char	*str;
	long	num;

	num = n;
	len = num_len(num);
	if (n < 0)
	{
		sign = '-';
		num = -num;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = 0;
	while ((num / 10) > 0)
	{
		str[len--] = (num % 10) + 48;
		num = num / 10;
	}
	str[len] = num + 48;
	if (sign == '-')
		str[len - 1] = '-';
	return (str);
}
