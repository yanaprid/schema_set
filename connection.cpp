#include "connection.hpp"
#include <graphics.h>

Connection::Connection(NetworkComponent* d1, NetworkComponent* d2, const std::string& name, bool wireless)
    : device1(d1), device2(d2), connection_name(name), is_wireless(wireless) {}

void Connection::draw() const {
    setcolor(RED);
    line(device1->getX(), device1->getY(), device2->getX(), device2->getY());  // Рисуем линию соединения
    outtextxy((device1->getX() + device2->getX()) / 2, (device1->getY() + device2->getY()) / 2, connection_name.c_str());
}

std::string Connection::getConnectionName() const {
    return connection_name;
}

void Connection::setConnectionName(const std::string& name) {
    connection_name = name;
}
