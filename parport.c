#include <stdio.h>
#include <string.h>
#include <sys/io.h>

int usage();

int main(int argc, char *args[])
{
	switch (argc) 
	{
		case 2:
		{
			if(!strcmp(args[1], "-get"))
			{
				ioperm(0x378, 3, 1);//inicializa a porta paralela
				int getval;
				getval = inb(0x378);//retornando o valor da porta
				printf("%d\n",getval);
				return 0;
			}
			else
			{
				return usage();
			}
		}
		case 3:
		{
			if (!strcmp(args[1], "-set"))
			{
				ioperm(0x378, 3, 1);//inicializa a porta paralela
				int setval;
				sscanf(args[2], "%d", &setval);
				outb(setval, 0x378);//ajustando o valor da porta
				return 0;
			}
			else
			{
				return usage();
			}
		}
		default:
			return usage();
	}
}

int usage()
{
	printf("uso:\n");
	printf("    parport -set [int]; para ajustar a porta paralela\n");
	printf("    parport -get; para obter o valor da porta\n");
	printf("    bugs ou agradecimentos: mail-me mazin.z@hotmail.com\n");
	return 1;
}
