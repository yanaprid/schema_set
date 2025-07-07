#include "network_component.hpp"
#include <graphics.h>
#include <cmath>
#include <string>

NetworkComponent::NetworkComponent(const std::string& name, double x, double y, const std::string& ip, const std::string& type)
    : DiagramObject(name, x, y), ip_address(ip), type(type) {}

void NetworkComponent::draw() const {
    setcolor(BLUE);
    rectangle(x - 20, y - 20, x + 20, y + 20);  
    outtextxy(x - 20, y - 25, name.c_str());  
}

std::string NetworkComponent::getIPAddress() const {
    return ip_address;
}

void NetworkComponent::setIPAddress(const std::string& ip) {
    ip_address = ip;
}

double NetworkComponent::dotProduct(const double* vectorA, const double* vectorB, int size) const {
    double product = 0;
    for (int i = 0; i < size; ++i) {
        product += vectorA[i] * vectorB[i];
    }
    return product;
}

double NetworkComponent::distanceToCursor(double cursorX, double cursorY) const {
    double dx = cursorX - x;
    double dy = cursorY - y;
    return sqrt(dx * dx + dy * dy);
}

bool NetworkComponent::isHovered(double cursorX, double cursorY) const {
    return distanceToCursor(cursorX, cursorY) <= 10.0;  
}
