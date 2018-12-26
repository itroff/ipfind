#include "ipv4.h"

#include <iostream>
#include <arpa/inet.h>

/**
 * @brief IPv4::IPv4
 * making from string
 * @param ipstr - string with address
 */
IPv4::IPv4(const string &ipstr) : IP(IP::IP_VERSION, IP::MASK_IPV4)
{
    sa = 0;
    size_t pos = -1;
    for(int i = 0; i < 4; i++){
        size_t posOld = pos + 1;
        pos = ipstr.find(".", posOld);
        sa = sa << 8;
        if(string::npos !=pos){
            sa  = sa | stoi(ipstr.substr(posOld ,pos - posOld));
        }
        else{
            sa  = sa | stoi(ipstr.substr(posOld ,ipstr.size() - posOld));
        }
    }
}

/**
 * @brief IPv4::IPv4
 * making from number
 * @param ipint - number
 */
IPv4::IPv4(const uint32_t &ipint) : IP(IP::IP_VERSION, IP::MASK_IPV4)
{
    sa = ipint;
}

/**
 * @brief IPv4::toString
 * string
 * @return string
 */
string IPv4::toString()
{
    std::string address;
    for(int i = 0; i < 4; i++){
        uint32_t mask = 0xff;
        mask = mask << 24 - (i * 8);
        address.append(std::to_string((sa & mask ) >> (24 - (i * 8))));
        address.append(".");
    }
    address.pop_back();
    return address;

}

/**
 * @brief IPv4::equals
 * check equals
 * @param ip
 * @return
 */
bool IPv4::equals(IP *ip)
{
    if(ip->getVersion() != getVersion()){
        return false;
    }
    IPv4 *castIP = dynamic_cast<IPv4* > (ip);
    if(castIP != NULL){
        return castIP->toBinary() == this->sa;
    }
    else{
        return false;
    }
}

/**
 * @brief IPv4::toBinary
 * @return uint32_t of address
 */
uint32_t IPv4::toBinary() const
{
    return sa;
}

/**
 * @brief IPv4::toBinaryReverse
 * @return network order of address
 */
uint32_t IPv4::toBinaryReverse() const
{
    return ntohl(sa);
}
