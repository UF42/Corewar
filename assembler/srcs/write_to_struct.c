#include "asm.h"

void	initial(char *argv_name, t_asm *am)
{
	int		fd;
	char 	*file_name;
	char *test;

	file_name = generate_file_name(argv_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600); // append to the end of file;

	test = ft_to_binary(am->hd.prog_size);
	am->hd.prog_size = bstr_to_dec(test);
	free(test);

	test = ft_to_binary(15369203);
	am->hd.magic = bstr_to_dec(test);
	free(test);

	write(fd, am, sizeof(am->hd.magic) + sizeof(am->hd.prog_name)
			+ sizeof(am->hd.prog_size) + sizeof(am->hd.comment));
	close(fd);
	free(file_name);
}