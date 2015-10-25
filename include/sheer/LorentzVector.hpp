#ifndef __SHEER_LORENTZVECTOR_H__
#define __SHEER_LORENTZVECTOR_H__

#include "cereal/cereal.hpp"
#include "cereal/types/polymorphic.hpp"

#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>

#include <array>
#include <cmath>
#include <map>

namespace sheer
{

class LorentzVector
{
    public:
        virtual double energy() const = 0;
    
        virtual double mass() const = 0;
    
        virtual double px() const = 0;
        
        virtual double py() const = 0;
        
        virtual double pz() const = 0;
};


template<class TYPE>
class LorentzVectorTmpl:
    public LorentzVector
{
    protected:
        TYPE _mass;
        TYPE _px;
        TYPE _py;
        TYPE _pz;
    public:
        LorentzVectorTmpl():
            _mass(0),
            _px(0),
            _py(0),
            _pz(0)
        {
        }
        
        virtual double energy() const
        {
            return sqrt(_mass*_mass+_px*_px+_py*_py+_pz*_pz);
        }
    
        virtual double mass() const
        {
            return _mass;
        }
    
        virtual double px() const
        {
            return _px;
        }
        
        virtual double py() const
        {
            return _py;
        }
        
        virtual double pz() const
        {
            return _pz;
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(
                cereal::make_nvp("mass",_mass),
                cereal::make_nvp("px",_px),
                cereal::make_nvp("py",_py),
                cereal::make_nvp("pz",_pz)
            );
        }
};

typedef LorentzVectorTmpl<float32> LorentzVectorF32;
typedef LorentzVectorTmpl<float64> LorentzVectorF64;

}

CEREAL_REGISTER_TYPE(sheer::LorentzVectorF32);
CEREAL_REGISTER_TYPE(sheer::LorentzVectorF64);

#endif


