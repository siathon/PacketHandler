#include "PacketHandler.h"
PacketHandler::PacketHandler(int t){
    newPacket = false;
    receiving = false;
    processingPacket = false;
    indx = 0;
}

void PacketHandler::rx(){
    if (processingPacket) {
        return;
    }
    c = serial.getc();
    buffer[indx] = c;
    indx++;
    if (!receiving) {
        newPacket = true;
    }
    receiving = true;
}

void PacketHandler::checkForPacket(){
    if (!newPacket) {
        return;
    }
    while (true) {
        receiving = false;
        wait_ms(10);
        if (!receiving) {
            newPacket = false;
            ev_queue.call(onPacket, buffer);
            indx = 0;
            return;
        }
    }
}
