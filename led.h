#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

typedef char *led_t;

led_t led_make(int n);
void led_on(led_t l);
void led_off(led_t l);

#endif
