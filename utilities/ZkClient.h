#ifndef ZKCLIENT_H
#define ZKCLIENT_H


#include<string>
#include<zookeeper/zookeeper.h>

#include <semaphore.h>


class ZkClient
{
public:
    ZkClient();
    ~ZkClient();

    void start();

    int close();

    void create(const char*path,const char* data, int dataLen,int state = 0);

    std::string get(const char*path);

    void sendheartBeat();

    static void setRootPath(std::string path);

    static std::string getRootPath(){
        return rootNodePath;
    }


    static void global_watcher(zhandle_t *zh, int type, int state,
                const char*path, void* watchCtx);

    

private:
    zhandle_t *zhandle;

    static sem_t sem;

    static std::string rootNodePath;
    
};



#endif