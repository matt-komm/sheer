#ifndef __SHEER_EVENT_H__
#define __SHEER_EVENT_H__

#include <cereal/cereal.hpp>

#include <vector>
#include <map>

namespace sheer
{

class Event
{
    protected:
        uint32 run;
        uint32 lumi;
        uint32 number;
    public:
        Event():
            run(0),
            lumi(0),
            number(0)
        {
        }
        
        
        template<class Archive>
        void load(Archive& archive)
        {
            archive(
                run,
                lumi,
                number
            );
        }

        template<class Archive>
        void save(Archive& archive) const
        {
            archive(
                run,
                lumi,
                number
            );
        }
};

}

#endif

