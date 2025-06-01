#include <omnetpp.h>
#include "./msg/DHCPMessages_m.h"

using namespace omnetpp;
using namespace dhcp;  // <— pull in the generated types

class DhcpClient : public cSimpleModule
{
  protected:
    virtual void initialize() override {
        EV << "Client: Sending DHCPDISCOVER\n";
        // schedule a DHCPDiscover message to ourselves at t=1s
        scheduleAt(simTime() + 1, new DHCPDiscover());
    }

    virtual void handleMessage(cMessage *msg) override {
        // Check type by dynamic_cast<> on dhcp message classes:
        if (dynamic_cast<DHCPOffer *>(msg)) {
            EV << "Client: Received DHCPOFFER\n";
            // upon offer, send a DHCPRequest
            send(new DHCPRequest(), "out");
        }
        else if (dynamic_cast<DHCPAck *>(msg)) {
            EV << "Client: Received DHCPACK, IP assigned!\n";
        }
        else if (dynamic_cast<DHCPDiscover *>(msg)) {
            // first-time: this is our own scheduled discover
            send(msg, "out");
            return;
        }
        delete msg;
    }
};

Define_Module(DhcpClient);
