#ifndef DIAGRAM_OBJECT_HPP
#define DIAGRAM_OBJECT_HPP

#include <string>
#include <graphics.h>

class DiagramObject {
protected:
    std::string name;
    double x, y;

public:
    DiagramObject(const std::string& name, double x, double y);
    virtual ~DiagramObject() {}
    virtual std::string getName() const;
    virtual void setName(const std::string& name);
    virtual void draw() const = 0; 
};

#endif
