#include "ipfabric.h"
#include <iostream>

using namespace std;
int main (){

    IP *ip = IPFabric::createIP("192.168.0.1/32");
    cout <<ip->toString() << endl;

    IP *ip2 = IPFabric::createIP("fde1:eaef:66de:3601::1/128");
    cout <<ip2->toString() << endl;

    IPv6::BigInt asd(0xffffffff,0xffffffff,0xffffffff,0xfffffffe);
    IPv6::BigInt asd2(0x00,0x00,0x00,0x01);
    asd = asd << 126;

    IP *ip3 = IPFabric::createIP("0:0:66de:3601::12/128");
    IP *ip4 = IPFabric::createIP("0:0:66de:3601::12");
    cout << ip3->equals(ip4) <<endl;

    return 0;
}
