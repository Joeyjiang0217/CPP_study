//
// Created by Joe on 2025/4/15.
//

#ifndef CONCURRENTMEMORYPOOL_THREADCACHE_H
#define CONCURRENTMEMORYPOOL_THREADCACHE_H
#include "Common.h"

class ThreadCache
{
public:
    // 申请和释放内存对象
    void* Allocte(size_t size);
    void Deallocate(void* ptr, size_t size);

    // 从中心缓存获取对象
    void* FetchFromCentralCache(size_t index, size_t size);
private:
    FreeList _freeLists[NFREELISTS];
};

// TLS thread local storage
static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;



#endif //CONCURRENTMEMORYPOOL_THREADCACHE_H
