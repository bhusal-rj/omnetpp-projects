#include <omnetpp.h>
#include "msg/DHCPMessages_m.h"

using namespace omnetpp;
using namespace dhcp;  // <— pull in the generated types

class DhcpServer : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override {
        // If it’s a DHCPDiscover, reply with DHCPOffer:
        if (dynamic_cast<DHCPDiscover *>(msg)) {
            EV << "Server: Received DHCPDISCOVER, sending DHCPOFFER\n";
            send(new DHCPOffer(), "out");
        }
        // If it’s a DHCPRequest, reply with DHCPAck:
        else if (dynamic_cast<DHCPRequest *>(msg)) {
            EV << "Server: Received DHCPREQUEST, sending DHCPACK\n";
            send(new DHCPAck(), "out");
        }
        delete msg;
    }
};

Define_Module(DhcpServer);
