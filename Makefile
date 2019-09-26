CFLAGS = -g

all: led

led: led.c libled.c

clean:
	-rm led
