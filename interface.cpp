#include "interface.hpp"
#include <graphics.h>
#include <fstream>

void Interface::addComponent(NetworkComponent* component) {
    components.push_back(component);
}

void Interface::removeComponent(int index) {
    components.erase(components.begin() + index);
}

NetworkComponent* Interface::findComponentByCoords(double x, double y) {
    for (auto* component : components) {
        if (component->getX() == x && component->getY() == y) {
            return component;
        }
    }
    return nullptr;
}

void Interface::addConnection(int index1, int index2, const std::string& type) {
    NetworkComponent* d1 = components[index1];
    NetworkComponent* d2 = components[index2];
    Connection* conn = new Connection(d1, d2, type, false);
    connections.push_back(conn);
}

NetworkComponent* Interface::checkHover(double cursorX, double cursorY) {
    for (auto* component : components) {
        if (component->isHovered(cursorX, cursorY)) {
            return component;
        }
    }
    return nullptr;
}

void Interface::saveDiagram(const std::string& filename) {
    std::ofstream file(filename);
    for (auto* component : components) {
        file << component->getName() << " " << component->getX() << " " << component->getY() << std::endl;
    }
    file.close();
}

void Interface::loadDiagram(const std::string& filename) {
    std::ifstream file(filename);
    std::string name;
    double x, y;
    while (file >> name >> x >> y) {
        NetworkComponent* component = new NetworkComponent(name, x, y, "", "");
        addComponent(component);
    }
    file.close();
}

void Interface::clearDiagram() {
    components.clear();
    connections.clear();
}

void Interface::draw() {
    for (auto* component : components) {
        component->draw();
    }
    for (auto* connection : connections) {
        connection->draw();
    }
}
