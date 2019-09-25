#include <stdlib.h>

typedef char *led_t;

led_t led_make(int n);
void led_on(led_t l);
void led_off(led_t l);
void led_remove_trigger(led_t l);
void led_free(led_t *l);

int
main(int argc, char *argv[])
{
	led_t l0 = led_make(0);
	led_on(l0);
	led_off(l0);
	led_free(&l0);

	exit(0);
}

#include <stdio.h>
#include <string.h>

led_t
led_make(int n)
{
	char p[200];
	sprintf(p, "/sys/class/leds/beaglebone:green:usr%d", n);
	return strdup(p);
}

void led_write(led_t l, char *f, char *v);

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
led_free(led_t *l)
{
	free(*l);
	*l = NULL;
}

void
led_write(led_t l, char *f, char *v)
{
	FILE *fp;
	char p[200];
	sprintf(p, "%s/%s", l, f);
	fp = fopen(p, "w");
	fprintf(fp, "%s", v);
	fclose(fp);
}

void
led_remove_trigger(led_t l)
{
	led_write(l, "trigger", "none");
}
