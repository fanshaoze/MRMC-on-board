#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "meshclient.h"

int send_neighbor(int clientSocket,char * neigh_inform){
    send(clientSocket, neigh_inform , strlen(neigh_inform), 0);
    return 0;
}