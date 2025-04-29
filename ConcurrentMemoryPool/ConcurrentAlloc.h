//
// Created by Joe on 2025/4/24.
//

#ifndef CONCURRENTMEMORYPOOL_CONCURRENTALLOC_H
#define CONCURRENTMEMORYPOOL_CONCURRENTALLOC_H
#include "Common.h"
#include "ThreadCache.h"

static void* ConcurrentAlloc(size_t size)
{
    // 通过TLS 每个线程无锁的获取自己专属的ThreadCache对象
    if (pTLSThreadCache == nullptr)
    {
        pTLSThreadCache = new ThreadCache;
    }

    cout << std::this_thread::get_id() << ":" << pTLSThreadCache << endl;

    return pTLSThreadCache->Allocte(size);
}

static void* ConcurrentFree(void* ptr, size_t size)
{
    assert(pTLSThreadCache);

    pTLSThreadCache->Deallocate(ptr, size);
}

#endif //CONCURRENTMEMORYPOOL_CONCURRENTALLOC_H
