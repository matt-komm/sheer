#ifndef __SHEER_PARTICLE_H__
#define __SHEER_PARTICLE_H__

#include "sheer/LorentzVector.hpp"

#include <cereal/cereal.hpp>
#include "cereal/types/array.hpp"

#include <array>
#include <memory>
#include <map>

namespace sheer
{

template<class LORENTZVECTOR>
class Particle
{
    protected:
        std::unique_ptr<LORENTZVECTOR> _lorentzVector;
    public:
        Particle():
            _lorentzVector(new LORENTZVECTOR())
        {
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(
                cereal::make_nvp("LorentzVector",_lorentzVector)
            );
        }
};

}

#endif

