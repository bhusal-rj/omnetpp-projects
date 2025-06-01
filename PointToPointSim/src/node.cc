#include <omnetpp.h>
#include "msg/PingMessage_m.h"

using namespace omnetpp;

class Node : public cSimpleModule {
  protected:
    virtual void initialize() override {
        if (strcmp(getName(), "nodeA") == 0) {
            PingMessage *msg = new PingMessage("initialPing");
            msg->setMsg("Hello from A");
            send(msg, "out");
        }
    }

    virtual void handleMessage(cMessage *msg) override {
        PingMessage *ping = check_and_cast<PingMessage *>(msg);
        EV << getName() << " received: " << ping->getMsg() << "\n";
        delete msg;
    }
};

Define_Module(Node);
