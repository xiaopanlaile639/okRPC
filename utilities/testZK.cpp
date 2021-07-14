#include "ZkClient.h"
#include <unistd.h>


int main(){
    ZkClient client;

    client.start();
    std::string data = "testData";
    client.create("/test-2021-7-14",data.c_str(),data.size(),ZOO_EPHEMERAL);

    printf("sleep...");
    sleep(30);

    std::string retData = client.get("/test-2021-7-14");

    printf("ret data:%s\n",retData.c_str());
    
}