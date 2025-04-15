#include<bits/stdc++.h>
#include<Ws2tcpip.h>
#include<WinSock2.h>
#include<tchar.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib");

bool Initialize(){
    WSADATA data;
    return WSAStartup(MAKEWORD(2,2), &data) == 0; 

}

int main()
{
    if(!Initialize()){
        cout<<"WinSock Initialization failed"<<endl;
    }
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    if(listenSocket == INVALID_SOCKET){
       cout<<"Socket Creation failed"<<endl;
       return 1;
    }
    
    //create address structure
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(1234);


    //convert the ip address (0.0.0.0) put it inside the sin_family in binary format
    if(InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1)
    {
       cout<<"setting address structure failed"<<endl;
       closesocket(listenSocket);
       WSACleanup();
       return 1;
    }

    
    WSACleanup();
    return 0;
}



// initialize winsock library
// create the socket
// get ip and port
// bind the ip and port with the socket
// start listening on the socket
// accept
// recieve and send
// close the socket
// cleanup the winsock