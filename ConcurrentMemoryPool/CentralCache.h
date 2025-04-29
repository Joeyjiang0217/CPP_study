//
// Created by Joe on 2025/4/24.
//

#ifndef CONCURRENTMEMORYPOOL_CENTRALCACHE_H
#define CONCURRENTMEMORYPOOL_CENTRALCACHE_H
#include "Common.h"

class CentralCache
{
public:
    static CentralCache* GetInstance()
    {
        return &_sInst;
    }

    // 获取一个非空的span
    Span* GetOneSpan(SpanList& list, size_t byte_size);

    //从中⼼缓存获取⼀定数量的对象给thread cache
    size_t FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size);
private:
    SpanList _spanLists[NFREELISTS];

private:
    CentralCache()
    {

    }

    CentralCache(const CentralCache&) = delete;
    static CentralCache _sInst;
};


#endif //CONCURRENTMEMORYPOOL_CENTRALCACHE_H
