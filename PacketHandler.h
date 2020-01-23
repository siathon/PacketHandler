#ifndef PACKET_HANDLER_H
#define PACKET_HANDLER_H

#include "mbed.h"
#include <string>

#define UART_BUFFER_LENGTH 300

extern EventQueue ev_queue;
extern RawSerial serial;
extern RawSerial pc;
extern void onPacket(char* packet);

class PacketHandler{
public:
    PacketHandler(int t);
    void rx(void);
    void checkForPacket(void);

    bool processingPacket;
    bool receiving;
    bool newPacket;

    int indx;

    char buffer[UART_BUFFER_LENGTH];
    char c;
};

#endif
