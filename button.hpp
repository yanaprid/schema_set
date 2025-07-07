#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "interface.hpp" 
#include <string>

using fun_ptr = void(*)(); 

class Button : public ControlObject {
protected:
    double x, y;  
    std::string label; 

public:
    Button(const std::string& label, double x, double y);
    virtual void draw() const = 0; 
    virtual void press() = 0; 
    bool isClicked(double cursorX, double cursorY) const {
        return (cursorX >= x && cursorX <= x + 120 && cursorY >= y && cursorY <= y + 50);
    }
};

class IconButton : public Button {
private:
    std::string icon; 
    std::string label_;
    void (*action_)();

public:
    ToolButton(double x, double y, const std::string &label, void (*action)());
    void draw() const override; 
    IconButton(int x, int y, const std::string& icon);

    void press() override; 
};

class ToolButton : public IconButton {
private:
    fun_ptr tool; 

public:
    ToolButton(int x, int y, const std::string& icon, fun_ptr t);
    void press() override; 
};

class CommandButton : public IconButton {
private:
    fun_ptr action; 

public:
    CommandButton(int x, int y, const std::string& icon, fun_ptr a);
    void press() override; 
};

#endif

