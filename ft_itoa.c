/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:40:46 by vbritto-          #+#    #+#             */
/*   Updated: 2023/10/21 12:32:23 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		size;
	char	*str;

	neg = 1;
	if (n == 0)
		return (ft_strdup("0"));
	size = count(n);
	if (n < 0)
	{
		neg = -neg;
		size++;
	}
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size--] = 0;
	while (n != 0)
	{
		str[size--] = n % 10 * neg + 48 ;
		n /= 10;
	}
	if (size == 0)
		str[0] = '-';
	return (str);
}

int main ()
{
    printf("%s", ft_itoa(325));
}
