
#include<cstdio>
#include<thread>
#include <chrono>

#include"ZkClient.h"

// sem_t ZkClient::sem;
//std::string ZkClient::rootNodePath = "/RpcService";
std::string ZkClient::rootNodePath = "/test";
const char * host = "127.0.0.1:2181";
const int ZK_TIMEOUT = 30000;

ZkClient::ZkClient():zhandle(nullptr){
    
    sem_init(&sem,0,0);


}

ZkClient::~ZkClient(){
    
    if(!zhandle){
        close();            //关闭连接
    }
    
}

void ZkClient::start(){
    // const char * host = ;

    //zhandle = zookeeper_init(host,global_watcher,ZK_TIMEOUT,nullptr,nullptr,0);
    //fixit: 多线程问题，在sem_wait之前，先执行了global_watcher
    zhandle = zookeeper_init(host,global_watcher,ZK_TIMEOUT,nullptr,(void*)&(sem),0);

    if(!zhandle){
        printf("connecting zookeeper error!\n");
        exit(-1);
    }

    sem_wait(&sem);

    printf("connecting zookeeper success.\n");
    
}

int ZkClient::close(){

    return zookeeper_close(zhandle);

}

void ZkClient::create(const char *path, const char *data, int datalen, int state){

    char pathBuf[128];
    int bufLen = sizeof(pathBuf);
    int flag = zoo_exists(zhandle,path,0,nullptr);
    if(ZNONODE == flag){
        flag = zoo_create(zhandle,path,data,datalen,&ZOO_OPEN_ACL_UNSAFE,state,pathBuf,bufLen);

        if(flag == ZOK){
            printf("znode create successfully. path %s\n",path);
        }else{
            printf("creating znode  falied. path %s\n",path);
            printf("flag:%d\n",flag);
            exit(-1);
        }

    }else{
        printf("znode exists. path:%s\n",path);
    }


}

std::string ZkClient::get(const char * path){

    char buffer[64];
    int buffLen = sizeof(buffer);

    int flag = zoo_get(zhandle,path,0,buffer,&buffLen,nullptr);

    if(flag != ZOK){
        printf("get znode error! path:%s\n",path);
        return "";
    }else{
        return buffer;
    }
}

void ZkClient::sendheartBeat(){

    std::thread t([&](){

        while(true){
            int time = ZK_TIMEOUT*1.0/3;

            std::this_thread::sleep_for(std::chrono::seconds(time));
            zoo_exists(zhandle,rootNodePath.c_str(),0,nullptr);
        }
    }
    );

    t.detach();

}

void ZkClient::setRootPath(std::string path)
{
	rootNodePath = path;
}

//使用回调函数传参的方式
void ZkClient::global_watcher(zhandle_t*zh, int type, int state, const char*path,void *wacherCtx){

    printf("watch type: %d\n",type);
    printf("watcher state: %d\n",state);
    printf("watcher path: %s\n",path);

    if(type == ZOO_SESSION_EVENT){
        if(state == ZOO_CONNECTED_STATE){
            sem_t *sem = (sem_t*)wacherCtx;
            sem_post(sem);
            //sem_post(&sem);         //通知调用线程
        }else if(state == ZOO_EXPIRED_SESSION_STATE){       //超时
            printf("time out! \n");
        }
    }

}
