#include "ipv6.h"
#include <list>
#include <iomanip>
#include <arpa/inet.h>

/**
 * @brief IPv6::IPv6
 * object from string
 * @param ipstr string
 */
IPv6::IPv6(const std::string &ipstr) : IP(IP::IPV6_VERSION, IP::MASK_IPV6)
{
    // нормализуем вид ip адреса до полного вида
    list<string> octets;
    string tmp;
    int indx = 0;

    for (int i = 0; i < ipstr.size(); i++){
        if(ipstr.at(i) == ':'){
            if(ipstr.at(i - 1) == ':'){//вставка 0 октетов
                indx = octets.size();
            }
            else{
                octets.push_back(tmp);
                tmp = "";
            }
        }
        else{
            tmp +=ipstr.at(i);
        }
    }
    if(tmp.size() > 0){
        octets.push_back(tmp);
    }
    if(indx > 0 ){
        list<string>::iterator it = octets.begin();
        advance(it, indx);
        octets.insert(it, 8 - octets.size(), "0000");
    }
    //переводим во внутреннюю структуру
    for (std::list<string>::iterator it=octets.begin(); it != octets.end(); ++it){
        uint32_t octet = stoi(*it, 0, 16);
        sa = sa << 16;
        sa = sa | octet;
    }
}

IPv6::IPv6(const uint32_t *ipInt, bool ntohlNeed) : IP(IP::IPV6_VERSION, IP::MASK_IPV6)
{
    if(ntohlNeed){
        for(int i = 0; i < 4; i++)
            sa.getAddress().saArr[i] = ipInt[i];
    }
    else{
        for(int i = 0; i < 4; i++)
            sa.getAddress().saArr[3 - i ] = ntohl(ipInt[i]);
    }
}
/**
 * @brief IPv6::toString
 * write a string
 * @return  string
 */
string IPv6::toString()
{
    std::stringstream stream;
    for(int i =0; i < 4; i++){
        uint tmp = sa.getAddress().saArr[i] >> 16;
        uint so = tmp & 0xffff;
        stream << std::hex << so;
        stream << ":" ;
        uint so2 = sa.getAddress().saArr[i] & 0xffff ;
        stream << std::hex << so2;
        if(i < 3){
            stream << ":" ;
        }
    }

    std::string result( stream.str() );
    return result;

}
/**
 * @brief IPv6::equals
 * check addresess for equals
 * @param ip - another
 * @return true or false
 */
bool IPv6::equals(IP * ip)
{
    if(ip->getVersion() != getVersion()){
        return false;
    }
    IPv6 *castIP = dynamic_cast<IPv6*> (ip);
    if(castIP != NULL){
        return castIP->toBinary() == this->sa;
    }
    else{
        return false;
    }
}

/**
 * @brief IPv6::toBinary
 * return binary from address
 * @return BigInt
 */
IPv6::BigInt IPv6::toBinary() const
{
    return sa;
}


