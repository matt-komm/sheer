#ifndef __SHEER_PARTICLE_H__
#define __SHEER_PARTICLE_H__

#include "sheer/LorentzVector.hpp"
#include "sheer/HepObject.hpp"

#include <cereal/cereal.hpp>
#include "cereal/types/array.hpp"

#include <array>
#include <memory>
#include <map>

namespace sheer
{

template<class TYPE>
class Particle:
    public HepObject,
    public LorentzVector<TYPE>
{
    protected:
        std::string _name;
    public:
        DEFINE_TYPE(Particle,1)
    
        Particle(const std::string& name=""):
            _name(name)
        {
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            HepObject::serialize(archive);
            LorentzVector<TYPE>::serialize(archive);
            
            archive(
                cereal::make_nvp("name",_name)
            );
        }
};

}

#endif

