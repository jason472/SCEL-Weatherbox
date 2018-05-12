/* File: Transmit.h */

/* Libraries */
#include "schema.h"
#include "config.h"
#include "sensors.h"

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

#define MAX_SIZE 80
/* Global Variable for Packet */
extern schema_1 Gpacket;

/* Gloabal XBee object */
extern XBee Gxbee;

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

/* Clear Packet */
void clear_packet(void);

/*Construct Packet */
void make_packet(int Gcount);

/* Transmit Packet */
void send_packet(void);

/* Test Packet */
void construct_Test(void);

#endif
