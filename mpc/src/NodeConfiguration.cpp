#include "NodeConfiguration.h"

NodeConfiguration::NodeConfiguration(){}

NodeConfiguration::NodeConfiguration(int nodeID, std::string configFile, int bits){
    id = nodeID;
    bits = bits;
    loadConfig(configFile);
}

int NodeConfiguration::getID(){
    return id;
}

int NodeConfiguration::getBits(){
    return bits;
}

std::string NodeConfiguration::getIP(){
    return ip;
}

int NodeConfiguration::getPort(){
    return port;
}

int NodeConfiguration::getPeerIndex(int id){
    int index = -1;
    for(int i = 0; i < peerID.size(); i++){
        if(peerID[i] == id){
            index = i;
            break;
        }
    }
    return index;
}

std::string NodeConfiguration::getPeerIP(int id){
    int index = -1;
    for(int i = 0; i < peerID.size(); i++){
        if(peerID[i] == id){
            index = i;
            break;
        }
    }
    return peerIP[index];
}

int NodeConfiguration::getPeerPort(int id){
    int index = -1;
    for(int i = 0; i < peerID.size(); i++){
        if(peerID[i] == id){
            index = i;
            break;
        }
    }
    return peerPort[index];
}

void NodeConfiguration::loadConfig(std::string configFile){
    std::ifstream ifs(configFile);

    std::string line, tk;
    std::vector<std::string> tokens;
    std::stringstream stream;
    while(getline(ifs, line)){
        tokens.clear();
        stream.str("");
        stream << line;
        while(getline(stream, tk, ',')){
            tokens.emplace_back(tk);
        }

        if(id == std::stoi(tokens[0])){
            ip = tokens[1];
            port = std::stoi(tokens[2]);
        } else {
            peerID.emplace_back(std::stoi(tokens[0]));
            peerIP.emplace_back(tokens[1]);
            peerPort.emplace_back(std::stoi(tokens[2]));
        }
    }

    ifs.close();
}

NodeConfiguration::~NodeConfiguration(){}