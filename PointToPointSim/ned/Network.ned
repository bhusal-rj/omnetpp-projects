package ned;

network PointToPointNetwork {
    
 submodules:
     nodeA: Node;
     nodeB: Node;
     
    connections:
        nodeA.out --> {delay=10ms;} --> nodeB.in;
        nodeB.out --> {delay=10ms;} --> nodeA.in;   
}