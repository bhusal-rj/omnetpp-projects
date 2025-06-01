package ned;

network DhcpNetwork{
 submodules:
     client: DhcpClient{
      @display("p=100,100")   ;
     }   
     server: DhcpServer{
     @display("p=300,100");
     }
     
     connections:
         client.out --> server.in;
         server.out --> client.in;
}