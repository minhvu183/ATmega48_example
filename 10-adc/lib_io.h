#ifndef LIB_IO_H
#define LIB_IO_H

#define setHigh(port, pin) port |= 1<<pin
#define setLow(port, pin) port &= ~(1<<pin)
#define togglePin(port,pin) port ^= 1<<pin
#define checkPin(port, pin) ((port & (1<<pin)))

#endif