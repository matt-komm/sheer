#ifndef __SHEER_HEPOBJECT_H__
#define __SHEER_HEPOBJECT_H__

#include <cereal/cereal.hpp>

#include "sheer/BaseTypes.hpp"
#include "sheer/Hash.hpp"


namespace sheer
{

class HepObject
{
    public:
        virtual uint8 getType() const = 0;
        virtual uint8 getVersion() const = 0;
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(
                cereal::make_nvp("type",getType()),
                cereal::make_nvp("version",getVersion())
            );
        }
        
        virtual ~HepObject()
        {
        }
};

}

#define DEFINE_TYPE(NAME, VERSION) \
    virtual uint8 getType() const {return sheer::Hash::get(#NAME);} \
    virtual uint8 getVersion() const {return VERSION;} 
    

#endif

