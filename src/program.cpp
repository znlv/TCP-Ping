#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define RESET_COLOR     "\033[0m"
#define GREEN_COLOR     "\033[32m"
#define RED_COLOR       "\033[31m"
#define YELLOW_COLOR    "\033[33m"
#define BLUE_COLOR      "\033[34m"
#define BOLD_COLOR      "\033[1m"

void paping(const char* hostname, const char* port) {
    struct addrinfo hints, *res;
    int sockfd;
    

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;       // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;   // TCP socket

    cout << BLUE_COLOR << "Resolving hostname " << hostname << "..." << RESET_COLOR << endl;
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        cerr << RED_COLOR << "Error: Could not resolve hostname." << RESET_COLOR << endl;
        return;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        cerr << RED_COLOR << "Error: Could not create socket." << RESET_COLOR << endl;
        freeaddrinfo(res);
        return;
    }

    auto start = high_resolution_clock::now();
    cout << YELLOW_COLOR << "Connecting to " << hostname << ":" << port << "..." << RESET_COLOR << endl;
    
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        cerr << RED_COLOR << "Error: Could not connect to host." << RESET_COLOR << endl;
        close(sockfd);
        freeaddrinfo(res);
        return;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << GREEN_COLOR << "Connected to " << hostname << ":" << port << " in " 
         << BOLD_COLOR << duration.count() << " ms" << RESET_COLOR << endl;


    close(sockfd);
    freeaddrinfo(res);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << RED_COLOR << "Usage: " << argv[0] << " <hostname> <port>" << RESET_COLOR << endl;
        return 1;
    }

    const char* hostname = argv[1];
    const char* port = argv[2];

    paping(hostname, port);

    return 0;
}
