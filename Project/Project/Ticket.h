#pragma once

#include "Util.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum class TicketType{VIP,NORMAL};

class Ticket {
private:
    
    TicketType ticketType;
    double price = 0.0;
    char* ticketId=nullptr;
    int row = 0;
    int seat = 0;
 
    static int idIndex;
    static char allTicketIDS[500][9];
   static bool isOccupiedSeat[250];
   static bool isOccupiedRow[250];

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
        strcpy_s(allTicketIDS[idIndex++], strlen(ticketId) + 1, ticketId);
        return ticketId;
    }
     


public:
   

    const char* getTicketID() {
        return Util::copyString(this->ticketId);
    }
    
    static void showIDS() {
        for (int i = 0; i < idIndex; i++)
            cout << allTicketIDS[i] << endl;
 }
 
  

    void setTicketPrice(double price) {
        switch (this->ticketType) {
        case TicketType::VIP:
            this->price = 49.99;
            break;
       
        case TicketType::NORMAL:
            this->price = 29.99;
            break;
        default:
            throw exception(" Choose a valid type of ticket ");


        }
      
    }
    double getTicketPrice() {
        return this->price;
    }

    void setTicketType(TicketType ticketType)
    {
        this->ticketType = ticketType;
    }
    string getTicketType() {
        switch (ticketType) {
        case TicketType::VIP:
            return "VIP";
            break;
        
        case TicketType::NORMAL:
            return "NORMAL";
            break;
        default:
            return "Unknown";
        }
    }

    Ticket() :ticketId(generateTicketID()){
    }
    Ticket(TicketType ticketType) :ticketId(generateTicketID()){
        this->setTicketPrice(price);
        this->setTicketType(ticketType);
    }
    friend void operator<<(ostream& console, Ticket &ticket);
    friend void operator>>(istream& console, Ticket &ticket);

    int Valid(const char id[9]) {
        int ok = 0;
        for (int i = 0; i < idIndex; i++)
            if (!strcmp(allTicketIDS[i], id))
                ok = 1;
        return ok;
    }
    void saveData(ofstream& file) {
        if (!file.is_open())
        {
            throw exception("File not opened");
        }
        file.write((char*)&this->row, sizeof(int));
        file.write((char*)&this->seat, sizeof(int));
        file.write((char*)&this->ticketType, sizeof(Ticket));
        int idSize = strlen(ticketId);
        file.write((char*)&idSize, sizeof(int));
        file.write(this->ticketId, sizeof(char) * (strlen(ticketId) + 1));
        file.write((char*)&this->price, sizeof(double));
    }
    void readData(ifstream& file) {
        if (!file.is_open())
        {
            throw exception("File not opened");
        }
        file.read((char*)&this->row, sizeof(int));
        file.read((char*)&this->seat, sizeof(int));
        file.read((char*)&this->ticketType, sizeof(Ticket));
        int idSize = strlen(ticketId);
        file.read((char*)&idSize, sizeof(int));
        delete this->ticketId;
        ticketId = new char [idSize];
        file.read((char*)this->ticketId, sizeof(char) * (idSize+1));
        file.read((char*)&this->price, sizeof(int));



    }
};
int Ticket::idIndex = 0;
char Ticket::allTicketIDS[500][9] = { " " };
bool Ticket::isOccupiedRow[250] = { 0 };
bool Ticket::isOccupiedSeat[250] = { 0 };



void operator>>(istream& console, Ticket& ticket) {
    cout << " Choose your seat position (first type row index, then seat index): "<<endl;
    console >> ticket.row;
    console >> ticket.seat;
    if (ticket.isOccupiedRow[ticket.row] && ticket.isOccupiedSeat[ticket.seat]) {
        throw exception("Seat occupied");
    }
    else
    {
        ticket.isOccupiedRow[ticket.row] = 1;
        ticket.isOccupiedSeat[ticket.seat] = 1;
    }
    int input;
    cout << " Choose ticket type (0 for VIP, 1 for NORMAL): ";
    console >> input;
    ticket.ticketType = static_cast<TicketType>(input);
    ticket.setTicketPrice(ticket.price);

}
void operator<<(ostream& console,  Ticket& ticket) {
    console << endl << "Ticket Row: " << ticket.row;
    console << endl << "Ticket Seat: " << ticket.seat;
    console << endl << "Ticket ID: " << ticket.getTicketID();
    console << endl << ticket.getTicketType();
    console << endl << "Ticket price: " << ticket.getTicketPrice()<<endl;


}