#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "network_component.hpp"
#include <string>

class Connection {
private:
    NetworkComponent* device1;
    NetworkComponent* device2;
    std::string connection_name;
    bool is_wireless;

public:
    Connection(NetworkComponent* d1, NetworkComponent* d2, const std::string& name, bool wireless);
    void draw() const;
    std::string getConnectionName() const;
    void setConnectionName(const std::string& name);
};

#endif
