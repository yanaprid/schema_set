#include <graphics.h>
#include <conio.h>
#include <vector>
#include <string>
#include <cmath>
#include "network_component.hpp"
#include "connection.hpp"
#include "interface.hpp"
#include "button.hpp" 

using namespace std;

Interface networkInterface;
Button* buttons[10]; 


void addRouter() {
    NetworkComponent* router = new NetworkComponent("Router 1", 100, 100, "192.168.0.1", "Router");
    networkInterface.addComponent(router);
}

void addSwitch() {
    NetworkComponent* switch1 = new NetworkComponent("Switch 1", 300, 100, "192.168.0.2", "Switch");
    networkInterface.addComponent(switch1);
}

void init_controls() { 
   buttons[16]=new ToolButton(10,5,"load.bmp",load_command);
   buttons[17]=new ToolButton(45,5,"save.bmp",save_command);
   buttons[18]=new ToolButton(10,40,"pencil.bmp",);
   buttons[19]=new ToolButton(45,40,"line.bmp",);
   buttons[20]=new ToolButton(10,75,"rect.bmp",);
   buttons[21]=new ToolButton(45,75,"frect.bmp",);
   PaintArea::instance().set_tool(pencil_tool);
}
}

void draw_controls() {

    for (int i = 0; i < 2; ++i) {
        buttons[i]->draw();
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    init_controls();

    
    NetworkComponent* router = new NetworkComponent("Router 1", 100, 100, "192.168.0.1", "Router");
    NetworkComponent* switch1 = new NetworkComponent("Switch 1", 300, 100, "192.168.0.2", "Switch");

    networkInterface.addComponent(router);
    networkInterface.addComponent(switch1);

    
    networkInterface.addConnection(0, 1, "Ethernet");

    
    while (true) {
        cleardevice();

        networkInterface.draw(); 
        draw_controls();         

        
        int mouseX = mousex();
        int mouseY = mousey();

        
        NetworkComponent* hoveredComponent = networkInterface.checkHover(mouseX, mouseY);
        if (hoveredComponent) {
            
            setcolor(RED);
            rectangle(hoveredComponent->getX() - 10, hoveredComponent->getY() - 10, hoveredComponent->getX() + 50, hoveredComponent->getY() + 50);
        }

       
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int button = mousebutton();
            if (button == 1) {
                
                for (int i = 0; i < 2; ++i) {
                    if (buttons[i]->isClicked(mouseX, mouseY)) {
                        buttons[i]->press(); 
                    }
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }

        delay(10);  
    }

    closegraph();
    return 0;
}
