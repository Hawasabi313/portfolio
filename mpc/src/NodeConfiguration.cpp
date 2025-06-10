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

    std::string line;
    while(getline(ifs, line)){
        
    }
}