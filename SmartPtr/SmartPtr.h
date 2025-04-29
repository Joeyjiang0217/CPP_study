//
// Created by Joe on 2025/1/25.
//

#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <functional>
template<class T>
class SmartPtr {
public:
    SmartPtr(T* ptr)
        :_ptr(ptr)
    {
        cout << "SmartPtr(T* ptr)" << endl;
    }

    ~SmartPtr() {
        cout << "~SmartPtr()->" << _ptr << endl;
        delete _ptr;
    }

    T& operator*() {
        return *_ptr;
    }

    T* operator->() {
        return _ptr;
    }
private:
    T* _ptr;
};

namespace jlc {
    template<class T>
    class auto_ptr {
        public:
            auto_ptr(T* ptr)
                :_ptr(ptr)
            {
                cout << "SmartPtr(T* ptr)" << endl;
            }

            ~auto_ptr() {
                if (_ptr) {
                    cout << "delete->" << _ptr << endl;
                    delete _ptr;
                    _ptr = nullptr;
                }

            }

            auto_ptr(auto_ptr<T>& ap)
                :_ptr(ap._ptr)
            {
                ap._ptr = nullptr;
            }

            T& operator*() {
                return *_ptr;
            }

            T* operator->() {
                return _ptr;
            }
        private:
            T* _ptr;
        };

    template<class T>
    class unique_ptr {
    public:
        unique_ptr(T* ptr)
            :_ptr(ptr)
        {
            cout << "unique_ptr(T* ptr)" << endl;
        }

        ~unique_ptr() {
            cout << "delete->" << _ptr << endl;
            delete _ptr;
        }

        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }

        // unique_ptr(const unique_ptr<T>& up) {
        //     _ptr = nullptr;
        // }

        unique_ptr(const unique_ptr<T>& up) = delete;
        unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;
    private:
        T* _ptr;
    };


    template<class T>
    class shared_ptr {
    public:
        shared_ptr(T* ptr = nullptr )
            :_ptr(ptr)
            ,_pcount(new int(1))
        {
            cout << "unique_ptr(T* ptr)" << endl;
        }

        template<class D>
        shared_ptr(T* ptr, D del)
            :_ptr(ptr)
            ,_pcount(new int(1))
            ,_del(del)
        {
            cout << "shared_ptr(T* ptr, D del)" << endl;
        }

        void release() {
            if (--(*_pcount) == 0) {
                cout << "delete->" << _ptr << endl;
                // delete _ptr;
                _del(_ptr);
                delete _pcount;
            }
        }

        ~shared_ptr() {
            release();
        }

        shared_ptr(const shared_ptr<T>& sp)
            :_ptr(sp._ptr)
            ,_pcount(sp._pcount)
        {
            ++(*_pcount);
        }

        int use_count() const {
            return *_pcount;
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
            if (_ptr == sp._ptr) {
                return *this;
            }

            // if (*_pcount == 1) {
            //     delete _ptr;
            //     delete _pcount;
            //     _pcount = sp._pcount;
            //     _ptr = sp._ptr;
            //     ++(*_pcount);
            // }
            // else if (*_pcount > 1) {
            //     --(*_pcount);
            //     _pcount = sp._pcount;
            //     ++(*_pcount);
            //     _ptr = sp._ptr;
            // }
            release();

            _ptr = sp._ptr;
            _pcount = sp._pcount;

            ++(*_pcount);

            return *this;
        }

        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }

        T* get() const {
            return _ptr;
        }

    private:
        T* _ptr;
        int* _pcount;
        function<void(T*)> _del = [](T* ptr) {delete ptr;};
    };

    template<class T>
    class weak_ptr {
    public:
        weak_ptr()
           :_ptr(nullptr)
        {

        }
        weak_ptr(shared_ptr<T>& sp)
            :_ptr(sp.get())
        {

        }

        weak_ptr<T>& operator=(const shared_ptr<T>& sp) {
             _ptr = sp.get();
            return *this;
        }

        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }
    private:
        T* _ptr;
    };
}


#endif //SMARTPTR_H
