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

class Particle
{
    protected:
        std::unique_ptr<LorentzVector> _lorentzVector;
    public:
        Particle(LorentzVector* lorentzVector=nullptr):
            _lorentzVector(std::move(lorentzVector))
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

