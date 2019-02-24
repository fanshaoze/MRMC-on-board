#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "meshclient.h"

int decode_command(char recv_command[]){
    
    char * words = NULL;
    words = strtok(recv_command," ");
    printf("deconde %s\n",words);
    if(strcmp(words,"SHUTDOWN") == 0){
        return 1;
    }
    else if(strcmp(words,"SETLINK") == 0){
        return 2;
    }
    else if(strcmp(words,"DISCOVER") == 0){
        return 3;
    }
    return 0;
}

char command_no(){
    return 'd';
}

int get_channel_ssid(struct radio_type * radios,char * recv_commmand){
    int i = 0;
    int j = 0;
    char * words;
    char recv_temp[200];
    strcpy(recv_temp,recv_commmand);
    words = strtok(recv_temp," ");
    //printf("words %s\n",words);
    for(i = 0;i<radio_no;i++){
        char * splite_parameter;
        strcpy(recv_temp,recv_commmand);
        words = strtok(recv_temp," ");
        words = tok_forward(words,i+1," ");
        //printf("words %s\n",words);
        char paras[200];
        strcpy(paras,words);
        splite_parameter = strtok(paras,"#");
        //printf("splite_parameter %s\n",splite_parameter);
        for(j = 0;j<radio_no;j++){
            //printf("radios[j].mac_addr %s\n",radios[j].mac_addr);
            if(strcmp(splite_parameter,radios[j].mac_addr) == 0){
                splite_parameter = tok_forward(splite_parameter,1,"#");
                //printf("splite_parameter %s\n",splite_parameter);
                strrpc(splite_parameter,"\r\n","\0");
                if (strcmp(splite_parameter,"DISABLED") != 0){
                    strcpy(radios[j].channel,splite_parameter);
                    splite_parameter = tok_forward(splite_parameter,1,"#");
                    strrpc(splite_parameter,"\r\n","\0");
                    strcpy(radios[j].ssid, splite_parameter);
                }
                else{
                    radios[j].disabled = 1;
                    radio_disable(radios[j]);
                }
            }
        }
        
        splite_parameter[0] = '\0';
    }
    //printf("radios:0\n,%s\n,%s\n,%s\n,%s\n",radios[0].channel,radios[0].mac_addr,radios[0].ssid,radios[0].radio_id);
    //printf("fenge************************\n");
    //printf("radios:1\n,%s\n,%s\n,%s\n,%s\n",radios[1].channel,radios[1].mac_addr,radios[1].ssid,radios[1].radio_id);
    return 0;
}