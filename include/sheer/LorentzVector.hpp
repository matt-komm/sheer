#ifndef __SHEER_LORENTZVECTOR_H__
#define __SHEER_LORENTZVECTOR_H__

#include "sheer/Float16Converter.hpp"
#include "sheer/Float16.hpp"

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


template<class TYPE>
class LorentzVector
{
    protected:
        TYPE _px;
        TYPE _py;
        TYPE _pz;
        TYPE _mass;
    public:
        LorentzVector(
            const TYPE& px=0,
            const TYPE& py=0,
            const TYPE& pz=0,
            const TYPE& mass=0
        ):
            _px(px),
            _py(py),
            _pz(pz),
            _mass(mass)
        {
        }
        
        virtual TYPE energy() const
        {
            return sqrt(_mass*_mass+_px*_px+_py*_py+_pz*_pz);
        }
    
        virtual TYPE mass() const
        {
            return _mass;
        }
    
        virtual TYPE px() const
        {
            return _px;
        }
        
        virtual TYPE py() const
        {
            return _py;
        }
        
        virtual TYPE pz() const
        {
            return _pz;
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(
                cereal::make_nvp("px",_px),
                cereal::make_nvp("py",_py),
                cereal::make_nvp("pz",_pz),
                cereal::make_nvp("mass",_mass)
            );
        }
};

typedef LorentzVector<float16> LorentzVectorF16;
typedef LorentzVector<float32> LorentzVectorF32;
typedef LorentzVector<float64> LorentzVectorF64;

}


#endif


