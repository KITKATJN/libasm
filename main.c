/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:41:28 by cmarguer          #+#    #+#             */
/*   Updated: 2021/04/08 01:17:28 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

# define WRITE(s, x)		printf("^%ld (`%s`:%ld)\n", ft_write(STDOUT_FILENO, s, x), s, x);
# define READ(b, x)			r = ft_read(STDIN_FILENO, buffer, x); printf("`%s`:%ld\n", buffer, r);
# define STRCMP(a, b)		printf("`%s`:`%s` = %d (%d = strcmp)\n", a, b, ft_strcmp(a, b), strcmp(a, b));

// void check_strlen()
// {
// 	char *empty = "";
// 	char *hello_world = "Hello world !";
// 	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

// 	printf("================================\n\n");
// 	printf("%-20s: \"%s\"\n", "char *", empty);
// 	printf("%-20s: 0\n", "expected lenght");
// 	printf("%-20s: %zu\n", "libc", strlen(empty));
// 	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char *", hello_world);
// 	printf("%-20s: 0\n", "expected lenght");
// 	printf("%-20s: %zu\n", "libc", strlen(hello_world));
// 	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char *", alphabet);
// 	printf("%-20s: 0\n", "expected lenght");
// 	printf("%-20s: %zu\n", "libc", strlen(alphabet));
// 	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
// 	printf("\n");

// 	//------- NULL = SEGFAULT;
// 	printf("%-20s: \"%s\"\n", "char *", alphabet);
// 	printf("%-20s: 0\n", "expected lenght");
// 	printf("%-20s: %zu\n", "libc", strlen("09gujed09gjn321u23rgt7f\n\twedfhsbahdsweriour!!!/*s4512cx-+\n\t"));
// 	printf("%-20s: %zu\n", "libasm", ft_strlen("09gujed09gjn321u23rgt7f\n\twedfhsbahdsweriour!!!/*s4512cx-+\n\t"));
// 	printf("\n");
// }

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

// void check_strcpy()
// {
// 	char buffer[30];

// 	char *empty = "";
// 	char *hello_world = "Hello world !";
// 	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

// 	printf("\n================================\n");
// 	printf("========== FT_STRCPY ===========\n");
// 	printf("================================\n\n");
// 	printf("%-20s: \"%s\"\n", "char []", empty);
// 	printf("%-20s: buffer[50]\n", "copy to");
// 	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));
// 	clear_buffer(buffer, 30);
// 	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));
// 	clear_buffer(buffer, 30);
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char []", hello_world);
// 	printf("%-20s: buffer[50]\n", "copy to");
// 	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));
// 	clear_buffer(buffer, 30);
// 	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));
// 	clear_buffer(buffer, 30);
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char []", alphabet);
// 	printf("%-20s: buffer[50]\n", "copy to");
// 	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));
// 	clear_buffer(buffer, 30);
// 	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
// 	clear_buffer(buffer, 30);
// 	printf("\n");

// 	// ------- NULL = SEGFAULT
// 	// printf("%-20s: \"%s\"\n", "char []", alphabet);
// 	// printf("%-20s: buffer[50]\n", "copy to");
// 	// printf("%-20s: \"%s\"\n", "libc", strcpy(NULL, NULL));
// 	// clear_buffer(buffer, 30);
// 	// printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(NULL, NULL));
// 	// clear_buffer(buffer, 30);
// 	// printf("\n");
// }

// void check_strcmp()
// {
// 	char *empty = "";
// 	char *hello_world = "Hello world !";
// 	char *hello_human = "Hello human !";
// 	char *hello_world2 = "Hello world !";

// 	printf("\n================================\n");
// 	printf("========== FT_STRCMP ===========\n");
// 	printf("================================\n\n");
// 	printf("%-20s: \"%s\"\n", "char *", hello_world);
// 	printf("%-20s: \"%s\"\n", "compared to", hello_human);
// 	printf("%-20s: \"%d = strcmp\"\n", "libc", strcmp(hello_world, hello_human));
// 	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_human));
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char *", hello_world);
// 	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
// 	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_world2));
// 	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_world2));
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char *", hello_world2);
// 	printf("%-20s: \"%s\"\n", "compared to", empty);
// 	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world2, empty));
// 	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world2, empty));
// 	printf("\n");
// 	// ------- NULL = SEGFAULT
// 	// printf("%-20s: \"%s\"\n", "char *", hello_world2);
// 	// printf("%-20s: %s\n", "compared to", "NULL");
// 	// printf("%-20s: \"%d\"\n", "libc", strcmp(NULL, hello_world2));
// 	// printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(NULL, empty));
// 	// printf("\n");
// }

// void check_write()
// {
// 	char *hello_world = "Coucou";
// 	char *empty = "";

// 	printf("\n================================\n");
// 	printf("========== FT_WRITE ============\n");
// 	printf("================================\n\n");

// 	printf("%-20s: \"%s!\"\n", "char *", hello_world);
// 	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
// 	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
// 	printf("\n");

// 	printf("%-20s: \"%s\"\n", "char *", empty);
// 	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
// 	// printf("\n");
// 	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, empty, 0));
// 	printf("\n");
// 	printf("%-20s: \"%s\"\n", "char *", hello_world);
// 	printf("%-20s: \"Libc:%zu\"\n", "libc", write(-7, NULL, 7));
// 	// printf("\n");
// 	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(-7, NULL, 7));
// 	// printf("\n");


// 	int fd1 = open("text.txt", O_RDWR);
// 	//printf("%-20s: \"Libasm:%zu\"\n", "libasm", write(fd1, "nice dock", strlen("nice dock")));
// 	printf("\n%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(fd1, "nice dock", strlen("nice dock")));
// 	printf("\n");


// 	printf("\n--write\n");
// 	WRITE("toto", 4L);
// 	WRITE("totototo", 4L);
// 	WRITE("totototo", 8L);
// 	WRITE("toto", 2L);
// 	printf("-done\n");
// }

// void check_read()
// {
// 	int fd = open("main.c", O_RDONLY);
// 	char buff1[891];
// 	int ret = 1;
// 	printf("\n================================\n");
// 	printf("========== FT_READ =============\n");
// 	printf("================================\n\n");
// 	printf("%-20s: \n", "header main.c | libc ");
// 	ret = read(fd, buff1, 890);
// 	buff1[ret] = 0;
// 	printf("[return : %d]\n|%s|\n", ret, buff1);
// 	printf("\n");
// 	close(fd);
// 	fd = open("main.c", O_RDONLY);
// 	clear_buffer(buff1, 891);
// 	printf("%-20s: \n", "header main.c | libasm ");
// 	ret = ft_read(fd, buff1, 890);
// 	buff1[ret] = 0;
// 	printf("[return : %d]\n|%s|\n", ret, buff1);
// 	printf("\n");
// 	clear_buffer(buff1, 891);
// 	close(fd);

// 	fd = open("test", O_RDONLY);
// 	printf("%-20s: \n", "file test | libc ");
// 	ret = read(fd, buff1, 890);
// 	buff1[ret] = 0;
// 	printf("[return : %d]\n|%s|\n", ret, buff1);
// 	printf("\n");
// 	close(fd);
// 	fd = open("test", O_RDONLY);
// 	clear_buffer(buff1, 891);
// 	printf("%-20s: \n", "file test | libasm ");
// 	ret = ft_read(fd, buff1, 890);
// 	buff1[ret] = 0;
// 	printf("[return : %d]\n|%s|\n", ret, buff1);
// 	printf("\n");
// 	clear_buffer(buff1, 891);
// 	close(fd);

// 	fd = open("wrong", O_RDONLY);
// 	printf("%-20s: \n", "wrong | libc ");
// 	ret = read(fd, buff1, 890);
// 	buff1[ret] = 0;
// 	printf("[return : %d]\n|%s|\n", ret, buff1);
// 	printf("\n");
// 	close(fd);
// 	fd = open("wrong", O_RDONLY);
// 	clear_buffer(buff1, 891);
// 	printf("%-20s: \n", "wrong | libasm ");
// 	ret = ft_read(fd, buff1, 890);
// 	buff1[ret] = 0;
// 	printf("[return : %d]\n|%s|\n", ret, buff1);
// 	printf("\n");
// 	clear_buffer(buff1, 891);
// 	close(fd);

// }

void check_strdup()
{
	char *hello_world = "Hello world !";
	char *empty = "";
	char *save;
	char *save2;

	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	printf("%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: NULL\n", "char *");
	// save = strdup(NULL);
	// printf("%-20s: \"%s\"\n", "libc", save);
	// free(save);
	// save = NULL;
	// save2 = ft_strdup(NULL);
	// printf("%-20s: \"%s\"\n", "libasm", save2);
	// free(save2);
	// save2 = NULL;
	// printf("\n");
}

int main()
{
	int		i;
	long	r;
	char	buffer[100];
	char	*tmp;
	char	*tmp2;

	r = 0;
	i = 0;
	while (i < 100)
		buffer[i++] = 0;
	//check_strlen();
	//check_strcpy();


	//  check_strcmp();
	//  printf("\n--strcmp\n");
	// STRCMP("", "");
	// STRCMP("toto", "toto");
	// STRCMP("", "toto");
	// STRCMP("toto", "");
	// STRCMP("toto", "totobar");
	// printf("`%s`:`%s` = %d\n", "TOTO", NULL, ft_strcmp("TOTO", NULL));
	// printf("`%s`:`%s` = %d\n", NULL, "TOTO", ft_strcmp(NULL, "TOTO"));
	// printf("`%s`:`%s` = %d\n", NULL, NULL, ft_strcmp(NULL, NULL));
	// printf("-done\n");


	//check_write();
	// check_read();

	// printf("\n--read (Makefile)\n");
	// READ(buffer, 50);
	// READ(buffer, 25);
	// READ(buffer, 4);
	// READ(buffer, 26);
	// READ(buffer, 14);
	// READ(buffer, 0);
	// printf("-done\n");
	check_strdup();
}
