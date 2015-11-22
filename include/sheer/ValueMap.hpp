#ifndef __SHEER_VALUEMAP_H__
#define __SHEER_VALUEMAP_H__

namespace sheer
{

template<class OBJECT>
class ValueMap
{
    protected:
        std::map<std::shared_ptr<OBJECT>,float> _map;
    public:
        ValueMap()
        {
        }
        /*
        Class(const Class& c);
        Class(Class&& c);
        Class& operator=(const Class& c);
        Class& operator=(Class&& c);
        ~Class();
        */
};

}

#endif

