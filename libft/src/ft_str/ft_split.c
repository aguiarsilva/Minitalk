/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:14:12 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/21 22:14:12 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int  flag_check(const char *str, char c, int *check)
{
    int flag;

    flag = 0;
    if (*str != c && *check == 0)
    {
        *check = 1;
        flag = 1;
    }
    else if(*str == c)
        *check = 0;
    return(flag);
}

static int  word_count(const char *str, char c)
{
    int words;
    int check;

    words = 0;
    check = 0;
    while(*str)
    {
        if(flag_check(str, c, &check))
            words++;
        str++;
    }
    return (words);
}

static int  word_fill(char **res, const char **str, char c, int word_index)
{
    int i;

    i = 0;
    while (**str && **str == c)
        (*str)++;
    while (str[0][i] && str[0][i] != c)
        i++;
    res[word_index] = ft_substr(*str, 0 , i);
    if (!res[word_index])
        return (0);
    *str = *str + i + 1;
    return (1);
}

static void free_words(char ***str, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        free(str[0][j]);
        j++;
    }
    free(*str);
    *str = NULL;
}

char    **ft_split(char const *s, char c)
{
    char **res;
    int     words;
    int     i;

    if(!s)
        return (NULL);
    i = 0;
    words = word_count(s, c);
    res = (char **)malloc(sizeof(char *) * (words + 1));
    if (!res)
        return (NULL);
    while (i < words)
    {
        if (!word_fill(res, &s, c, i))
        {
            free_words(&res, i);
            return (NULL);
        }
        i++;
    }
    res[words] = NULL;
    return (res);
}