#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 260
#define LED_FMT "/sys/class/leds/beaglebone:green:usr%d"

/* BBB has four LEDs: USR0-USR3 */
static led_t leds[4];

static void led_remove_trigger(led_t l);
static void led_write(led_t l, char *f, char *v);

led_t
led_make(int n)
{
	char p[MAX_PATH];

	if (!leds[n]) {
		sprintf(p, LED_FMT, n);
		leds[n] = strdup(p);
	}
	return leds[n];
}

void
led_on(led_t l)
{
	led_remove_trigger(l);
	led_write(l, "brightness", "1");
}

void
led_off(led_t l)
{
	led_remove_trigger(l);
	led_write(l, "brightness", "0");
}

void
led_remove_trigger(led_t l)
{
	led_write(l, "trigger", "none");
}

void
led_write(led_t l, char *f, char *v)
{
	FILE *fp;
	char p[MAX_PATH];

	sprintf(p, "%s/%s", l, f);
	fp = fopen(p, "w");
	fprintf(fp, "%s", v);
	fclose(fp);
}
