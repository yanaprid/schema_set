#include "diagram_object.hpp"

DiagramObject::DiagramObject(const std::string& name, double x, double y) : name(name), x(x), y(y) {}

std::string DiagramObject::getName() const {
    return name;
}

void DiagramObject::setName(const std::string& name) {
    this->name = name;
}
