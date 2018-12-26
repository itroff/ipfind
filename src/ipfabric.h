#ifndef IPFABRIC_H
#define IPFABRIC_H

using namespace std;
#include "ip.h"
#include "ipv4.h"
#include "ipv6.h"

/**
 * @brief The IPFabric class
 * Creation network and host ipv4, ipv6
 */
class IPFabric
{
public:

    /**
     * @brief createIP
     * Make ip from string
     * @param ipStr - string
     * @return IP
     */
    static IP * createIP(string ipStr){
        IP *ipp = NULL;
        int mask = 0;
        string pureIp = ipStr;
        if(ipStr.find("/") != string::npos){
            mask = stoi(ipStr.substr(ipStr.find("/") + 1));
            pureIp = ipStr.substr(0, ipStr.find("/"));
        }

        if(ipStr.find(".") != string::npos){
            ipp = new IPv4(pureIp);
        }
        else if(ipStr.find(":") != string::npos){
            ipp = new IPv6(pureIp);
        }
        else{
            return NULL;
        }
        ipp->setMask(mask);

        return ipp;

    }
    /**
     * @brief createIP
     * create ipv4 from number (not network order!)
     * @param ipInt
     * @return IP
     */
    static IP* createIP(uint32_t ipInt){
        IP *ipp = new IPv4(ipInt);
        return ipp;
    }
    /**
     * @brief createIP
     * create IPv6 from uint32_t array
     * @param ipInt - uint32_t array, 4 elements
     * @param ntohl - with making, useful if array in network order
     * @return IP
     */
    static IP* createIP(uint32_t *ipInt, bool ntohl = false){
        IP *ipp = new IPv6(ipInt, ntohl);
        return ipp;
    }

};


#endif // IPFABRIC_H
