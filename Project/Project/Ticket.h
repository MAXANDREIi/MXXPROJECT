#pragma once
//number, type, ID, price
#include "Util.h"
#include <iostream>
#include <string>
using namespace std;

enum class TicketType{VIP,TRIBUNE,LAWN,BOX};

class Ticket {
private:
    
    TicketType ticketType;
    double price = 0.0;
    char* ticketId=nullptr;
    
    char* generateTicketID() {
        const char* digits = "0123456789";
        const int idLenght = 8;
        char* id = new char[idLenght + 1];
        for (int i = 0; i < idLenght; i++) {
            id[i] = digits[rand() % (sizeof(digits) - 1)];
        }
        id[idLenght] = '\0';
        delete[] ticketId;
        ticketId = new char[strlen(id) + 1];
        strcpy_s(ticketId, strlen(id) + 1, id);
        return ticketId;
    }




public:

    const char* getTicketID() {
        return Util::copyString(this->ticketId);
    }

    
    Ticket() :ticketId(generateTicketID()) {}



};
