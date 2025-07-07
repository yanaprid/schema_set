#include "button.hpp"
#include <graphics.h>

Button::Button(const std::string& label, double x, double y) : label(label), x(x), y(y) {}

void Button::draw() {
    setfillstyle(SOLID_FILL, BLUE); 
    bar(static_cast<int>(x), static_cast<int>(y), static_cast<int>(x) + 120, static_cast<int>(y) + 50);
    setcolor(WHITE);
    outtextxy(static_cast<int>(x) + 10, static_cast<int>(y) + 15, label.c_str());
}

IconButton::IconButton(int x, int y, const std::string& icon) : Button("Icon", x, y), icon(icon) {}

void IconButton::draw() {
    Button::draw();
    
    setfillstyle(SOLID_FILL, YELLOW);
    bar(static_cast<int>(x) + 40, static_cast<int>(y) + 10, static_cast<int>(x) + 80, static_cast<int>(y) + 40); // »конка
}



ToolButton::ToolButton(double x, double y, const std::string &label, void (*action)())
    : Button(x, y), label_(label), action_(action) {}

void ToolButton::draw() const {
   setfillstyle(SOLID_FILL, GREEN); 
    bar(static_cast<int>(x), static_cast<int>(y), static_cast<int>(x) + 120, static_cast<int>(y) + 50);
    setcolor(WHITE);
    outtextxy(static_cast<int>(x) + 10, static_cast<int>(y) + 15, label_.c_str());
}

void ToolButton::press() {
    if (action_) {
        action_();  
    }
}

CommandButton::CommandButton(int x, int y, const std::string& icon, fun_ptr a)
    : IconButton(x, y, icon), action(a) {}

void CommandButton::press() {
    if (action) {
        action(); 
    }
}

