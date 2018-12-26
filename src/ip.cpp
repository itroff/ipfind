#include "ip.h"

int IP::getVersion() const
{
    return version;
}

void IP::setVersion(int value)
{
    version = value;
}

int IP::getMask() const
{
    return mask;
}

void IP::setMask(int value)
{
    mask = value;
}

/**
 * @brief IP::contains
 * TODO
 * check if is net contains ip
 * @param ip to check
 * @return true of false
 */
bool IP::contains(const IP &ip)
{

}
/**
 * @brief IP::isNet
 * check if is net
 * @return true or false
 */
bool IP::isNet()
{
    if(mask != IP::MASK_IPV4 && (mask != IP::MASK_IPV6 && version != IP::IPV6_VERSION))
    {
        return true;
    }
    return false;
}

IP::IP(int version, int mask){
    this->version = version;
    this->mask = mask;
}
