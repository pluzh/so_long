/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmichel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:38:28 by lmichel           #+#    #+#             */
/*   Updated: 2021/10/11 17:39:20 by lmichel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_razrad(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_ret_helping(int n, size_t r, char *ret, int sign)
{
	ret[r] = '\0';
	r--;
	while (r > 0)
	{
		ret[r] = (n % 10) + '0';
		n = n / 10;
		r--;
	}
	ret[r] = (n % 10) + '0';
	if (sign == -1)
		ret[0] = '-';
	r--;
	return (ret);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

static int	ft_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char	*ft_itoa(int n)
{
	size_t	r;
	int		sign;
	char	*ret;

	sign = 1;
	if (n == -2147483648)
	{
		ret = ft_strjoin("-2", "147483648");
		return (ret);
	}
	sign = ft_sign(n);
	r = ft_razrad(n);
	n = ft_abs(n);
	ret = (char *)malloc((r + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_ret_helping(n, r, ret, sign);
	return (ret);
}
