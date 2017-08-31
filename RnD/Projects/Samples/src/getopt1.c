#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void print_args(int argc, char **argv)
{
	int i;

	printf("#args = %d\n", argc);
	for (i=0; i<argc; i++) {
		printf("arg%d = '%s'\n", i, argv[i]);
	}
	return;
}

int main(int argc, char *argv[])
{
	int flags, opt;
	int nsecs, tfnd;
           
	nsecs = 0;
	tfnd = 0;
	flags = 0;

	print_args(argc, argv);
           
	while ((opt = getopt(argc, argv, "nt:")) != -1) {
		switch (opt) {
		case 'n':
			flags = 1;
			printf("Option n\n");
			break;
		case 't':
			nsecs = atoi(optarg);
			tfnd = 1;
			printf("Option t: Arg = %d\n", nsecs);
			break;
		default: /* '?' */
			fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
			argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	printf("flags=%d; tfnd=%d; optind=%d\n", flags, tfnd, optind);

	if (optind >= argc) {
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}

	printf("name argument = %s\n", argv[optind]);

	print_args(argc, argv);
	/* Other code omitted */
	exit(EXIT_SUCCESS);
}

/*
int main(int argc, char *argv[])
{
	int o = -100;

	o = getopt(argc, argv, "ab:c");
	while (o != -1) {
		switch(o) {
		case 'a':
			printf("Option a\n");
			break;
		case 'b':
			printf("Option b\n");
			//printf("\toptarg = %d\n", atoi(optarg));
			printf("\toptarg = %s\n", optarg);
			break;
		case 'c':
			printf("Option c\n");
			break;
		default:
			printf("Default: opt = '%d' = '%c'\n", o, o);
		}
		o = getopt(argc, argv, "abc");
	}

	return 0;
}
*/		
