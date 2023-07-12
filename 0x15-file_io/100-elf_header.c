#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUF_SIZE 1024

void error_exit(const char *message);
void check_elf(const Elf64_Ehdr *header);
void print_magic(const Elf64_Ehdr *header);
void print_class(const Elf64_Ehdr *header);
void print_data(const Elf64_Ehdr *header);
void print_version(const Elf64_Ehdr *header);
void print_abi(const Elf64_Ehdr *header);
void print_osabi(const Elf64_Ehdr *header);
void print_type(const Elf64_Ehdr *header);
void print_entry(const Elf64_Ehdr *header);
void close_file(int fd);

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't open file");
	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1)
		error_exit("Error: Can't read file");

	check_elf(&header);

	printf("ELF Header:\n");
	print_magic(&header);
	print_class(&header);
	print_data(&header);
	print_version(&header);
	print_abi(&header);
	print_osabi(&header);
	print_type(&header);
	print_entry(&header);

	close_file(fd);
	return (0);
}
void error_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
void check_elf(const Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
			header->e_ident[EI_MAG1] != ELFMAG1 ||
			header->e_ident[EI_MAG2] != ELFMAG2 ||
			header->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(EXIT_FAILURE);
	}
}
void print_magic(const Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
}

void print_class(const Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}
void print_data(const Elf64_Ehdr *header)
{
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}

void print_version(const Elf64_Ehdr *header)
{
	printf("  Version:                           %d", header->e_ident[EI_VERSION]);
	if (header->e_ident[EI_VERSION] == EV_CURRENT);
		printf(" (current)\n");
	else
		printf("\n");
}

void print_abi(const Elf64_Ehdr *header)
{
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
}

void print_osabi(const Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
	       	case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}

void print_type(const Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
				break;
		case ET_EXEC:
				printf("EXEC (Executable file)\n");
				break;
		case ET_DYN:
				printf("DYN (Shared object file)\n");
				break;
		case ET_CORE:
				printf("CORE (Core file)\n");
				break;
		default:
				printf("<unknown>\n");
				break;
	}
}

void print_entry(const Elf64_Ehdr *header)
{
	printf("  Entry point address:               %#lx\n", header->e_entry);
}

void close_file(int fd)
{
	if (close(fd) == -1)
		error_exit("Error: Can't close file");
}

