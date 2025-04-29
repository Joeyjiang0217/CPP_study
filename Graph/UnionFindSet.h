//
// Created by Joe on 2025/2/5.
//

#ifndef UNIONFINDSET_H
#define UNIONFINDSET_H

#include <vector>
#include <map>

//template<class T>
//class UnionFindSet
//{
//public:
//    UnionFindSet(const T* a, size_t n)
//    {
//        for (size_t i = 0; i < n; ++i)
//        {
//            _a.push_back(a[i]);
//            _indexMap[a[i]] = i;
//        }
//    }
//
//private:
//    vector<T> _a;
//    map<T, int> _indexMap;
//};

class UnionFindSet
{
public:
    UnionFindSet(size_t n)
        :_ufs(n, -1)
    {

    }

    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);
        // 如果本身就在一个集合就没必要合并
        if (root1 == root2)
        {
            return;
        }

        if (root1 > root2)
        {
            swap(root1, root2);
        }

        _ufs[root1] += _ufs[root2];
        _ufs[root2] = root1;
    }

    int FindRoot(int x)
    {
        int parent = x;
        while (_ufs[parent] >= 0)
        {
            parent = _ufs[parent];
        }
        return parent;
    }

    bool IsInSet(int x1, int x2)
    {
        return FindRoot(x1) == FindRoot(x2);
    }

    size_t SetSize()
    {
        int size = 0;
        for (size_t i = 0; i < _ufs.size(); ++i)
        {
            if (_ufs[i] < 0)
            {
                ++size;
            }
        }
        return size;
    }

private:
    vector<int> _ufs;
};


#endif //UNIONFINDSET_H
