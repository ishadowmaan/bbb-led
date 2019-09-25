#include "led.h"
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	led_t l0 = led_make(0);
	led_on(l0);
	led_off(l0);

	exit(0);
}
