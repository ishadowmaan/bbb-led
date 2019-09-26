#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	if (argc != 3) goto fail;

	int n = atoi(argv[1]);
	if (n > 3) goto fail;

	led_t l = led_make(n);

	if (strcmp(argv[2], "on") == 0)
		led_on(l);
	else if (strcmp(argv[2], "off") == 0)
		led_off(l);
	else
		goto fail;
	exit(0);

fail:
	usage();
	exit(1);
}

void
usage(void)
{
	printf("%s\n", "usage: led <n> <on|off>");
}
