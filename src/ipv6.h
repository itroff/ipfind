#ifndef IPV6_H
#define IPV6_H
#include "ip.h"
using namespace std;


/**
 * @brief The IPv6 class
 * working with ipv6 addresses
 */
class IPv6 : public IP
{
public:
    /**
     * @brief The BigInt class
     * for working with big integer
     */
    class BigInt{
        struct sa
        {
            uint32_t saArr[4] = {0};
        };
        sa address;
    public:
        BigInt(){}

        BigInt(uint32_t z){address.saArr[3] = z;}

        BigInt(uint32_t s1, uint32_t s2,uint32_t s3,uint32_t s4){
            address.saArr[0] = s1;
            address.saArr[1] = s2;
            address.saArr[2] = s3;
            address.saArr[3] = s4;
        }

        /*
         * Bitwise AND
         */
        const BigInt operator & (const BigInt &v1)
        {
            return BigInt(address.saArr[0] & v1.address.saArr[0],
                    address.saArr[1] & v1.address.saArr[1],
                    address.saArr[2] & v1.address.saArr[2],
                    address.saArr[3] & v1.address.saArr[3]);
        }

        /*
         * Bitwise OR
         */
        const BigInt operator | (const BigInt &v1)
        {
            return BigInt(address.saArr[0] | v1.address.saArr[0],
                    address.saArr[1] | v1.address.saArr[1],
                    address.saArr[2] | v1.address.saArr[2],
                    address.saArr[3] | v1.address.saArr[3]);
        }

        /*
         * operator equals
         */
        const bool operator == (const BigInt &v1)
        {
            return address.saArr[0] == v1.address.saArr[0] &&
                    address.saArr[1] == v1.address.saArr[1]&&
                    address.saArr[2] == v1.address.saArr[2]&&
                    address.saArr[3] == v1.address.saArr[3];
        }

        /*
         * binary shift
         */
        const BigInt operator << (int shift)
        {
            if(shift  > 128){ // not effect
                return BigInt();
            }

            for(int i = 0; i < 4; i++){
                uint32_t tmp = 0, tmpN = 0;

                int ciShift = shift % 32;
                if((shift / 32) > 0){
                    if(i + (shift / 32) >= 0 && i + (shift / 32) < 4){
                        tmp = address.saArr[i + (shift / 32)];
                        if(i + (shift / 32) + 1 < 4){
                            tmpN = address.saArr[i + (shift / 32) + 1];
                        }
                    }
                }
                else{
                    tmp = address.saArr[i];
                    if(i < 3){
                        tmpN = address.saArr[i + 1];
                    }
                }
                uint32_t left, right = 0;
                if(ciShift != 32){
                    left = tmp << ciShift;
                }
                if(32 - ciShift != 32){
                    right = tmpN >> (32 - ciShift);
                }
                address.saArr[i] = left | right;
            }
            return BigInt(address.saArr[0], address.saArr[1],address.saArr[2],address.saArr[3]);
        }

        sa getAddress() const{return address;}
    };

private:
    BigInt sa;

public:
    IPv6(const string& ipstr);
    IPv6(const uint32_t *ipint, bool ntohlNeed);
    string toString();
    bool equals(IP *ip);
    BigInt toBinary() const ;

};
#endif // IPV6_H
