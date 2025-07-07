#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "network_component.hpp"
#include "connection.hpp"
#include <vector>

class Interface {
    std::vector<NetworkComponent*> components;
    std::vector<Connection*> connections;

public:
    void addComponent(NetworkComponent* component);
    void removeComponent(int index);
    NetworkComponent* findComponentByCoords(double x, double y);
    void addConnection(int index1, int index2, const std::string& type);
    NetworkComponent* checkHover(double cursorX, double cursorY);
    void saveDiagram(const std::string& filename);
    void loadDiagram(const std::string& filename);
    void clearDiagram();
    void draw();
};

class ControlObject {
public:
    virtual void draw() const = 0; 
    virtual ~ControlObject() = default; 
};


#endif
