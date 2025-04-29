//
// Created by Joe on 2025/4/28.
//

#ifndef CONCURRENTMEMORYPOOL_PAGECACHE_H
#define CONCURRENTMEMORYPOOL_PAGECACHE_H
#include "Common.h"

class PageCache
{
public:
    static PageCache* GetInstance()
    {
        return &_sInst;
    }

    // 获取一个K页的span
    Span* NewSpan(size_t k)
    {

    }

private:
    SpanList _spanLists[NPAGES];
    std::mutex _pageMtx;

    PageCache()
    {

    }

    PageCache(const PageCache&) = delete;
    static PageCache _sInst;
};


#endif //CONCURRENTMEMORYPOOL_PAGECACHE_H
