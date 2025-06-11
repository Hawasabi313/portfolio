#pragma once

#include "mpc_setting.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>


class NodeConfiguration{
private:
    int id;
    int bits;
    std::string ip;
    int port;

    std::vector<int> peerID;
    std::vector<std::string> peerIP;
    std::vector<int> peerPort;

    void loadConfig(std::string configFile);

public:
    NodeConfiguration();
    NodeConfiguration(int nodeID, std::string configFile, int bits);
    int getID();
    int getBits();
    std::string getIP();
    int getPort();

    int getPeerIndex(int id);
    std::string getPeerIP(int id);
    int getPeerPort(int id);

    virtual ~NodeConfiguration();
};