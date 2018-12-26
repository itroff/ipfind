#ifndef IP_H
#define IP_H

#include <string>

using namespace std;

/**
 * @brief The IP class
 * Abstract class for representation of IP
 */
class IP
{

private:
    int version;
    int mask;

public:
    static const int IP_VERSION     = 4;
    static const int IPV6_VERSION   = 6;
    static const int MASK_IPV4      = 32;
    static const int MASK_IPV6      = 128;

    IP(int version, int mask);

    virtual ~IP(){}

    int     getVersion() const;
    void    setVersion(int value);
    int     getMask() const;
    void    setMask(int value);

    virtual string toString() = 0;
    virtual bool equals(IP *ip) = 0;
    bool contains(const IP &ip);
    bool isNet();


};

#endif // IP_H
