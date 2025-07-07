#ifndef NETWORK_COMPONENT_HPP
#define NETWORK_COMPONENT_HPP

#include "diagram_object.hpp"
#include <string>

class NetworkComponent : public DiagramObject {
private:
    std::string ip_address;
    std::string type;
public:
    NetworkComponent(const std::string& name, double x, double y, const std::string& ip, const std::string& type);
    void draw() const override;
    std::string getIPAddress() const;
    void setIPAddress(const std::string& ip);
    double dotProduct(const double* vectorA, const double* vectorB, int size) const;
    double distanceToCursor(double cursorX, double cursorY) const;
    bool isHovered(double cursorX, double cursorY) const;
    double getX() const { return x; }
    double getY() const { return y; }
};

#endif
