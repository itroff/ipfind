#ifndef IPV4_H
#define IPV4_H

#include "stdint.h"
#include <string>
#include "ip.h"

using namespace std;

/**
 * @brief The IPv4 class
 * working with ipv4 addresses
 */
class IPv4 : public IP
{
private:
    uint32_t sa;

public:
    IPv4(const string& ipstr);
    IPv4(const uint32_t &ipint);
    string toString();
    bool equals(IP *ip);
    uint32_t toBinary() const ;
    uint32_t toBinaryReverse() const;

};

#endif // IPV4_H
