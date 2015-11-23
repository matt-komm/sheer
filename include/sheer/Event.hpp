#ifndef __SHEER_EVENT_H__
#define __SHEER_EVENT_H__

#include "cereal/cereal.hpp"
#include "cereal/types/polymorphic.hpp"

#include "sheer/HepObject.hpp"

#include <vector>
#include <map>

namespace sheer
{

class Event:
    public HepObject
{
    protected:
        uint32 run;
        uint32 lumi;
        uint32 number;
    public:
        DEFINE_TYPE(Event,1)
    
        Event():
            HepObject(),
            run(0),
            lumi(0),
            number(0)
        {
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            HepObject::serialize(archive);
            archive(
                run,
                lumi,
                number
            );
        }
};

}

CEREAL_REGISTER_TYPE(sheer::Event)

#endif

