#ifndef __SHEER_VARIANT_H__
#define __SHEER_VARIANT_H__

#include "sheer/BaseTypes.hpp"
#include "sheer/Float16.hpp"
#include "sheer/HepObject.hpp"

#include "cereal/cereal.hpp"
#include "cereal/types/polymorphic.hpp"

#include <typeinfo>


namespace sheer
{

class Variant
{
    protected:
    public:
        virtual const std::type_info& getType() const = 0;
};

template<class TYPE>
class VariantTmpl:
    public Variant
{
    protected:
        TYPE _value;
    public:
        VariantTmpl()
        {
        }
        
        VariantTmpl(const TYPE& value):
            _value(value)
        {
        }
        
        virtual const std::type_info& getType() const
        {
            return typeid(TYPE);
        }
        
        inline const TYPE& value() const
        {
            return _value;
        }
        
        inline TYPE& value()
        {
            return _value;
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(
                _value
            );
        }
};

typedef VariantTmpl<bool> VariantBool;

typedef VariantTmpl<int8> VariantInt8;
typedef VariantTmpl<uint8> VariantUInt8;

typedef VariantTmpl<int16> VariantInt16;
typedef VariantTmpl<uint16> VariantUInt16;

typedef VariantTmpl<int32> VariantInt32;
typedef VariantTmpl<uint32> VariantUInt32;

typedef VariantTmpl<int64> VariantInt64;
typedef VariantTmpl<uint64> VariantUInt64;

typedef VariantTmpl<float16> VariantFloat16;
typedef VariantTmpl<float32> VariantFloat32;
typedef VariantTmpl<float64> VariantFloat64;

typedef VariantTmpl<std::string> VariantString;
typedef VariantTmpl<ShortString> VariantShortString;

}

CEREAL_REGISTER_TYPE(sheer::VariantBool)

CEREAL_REGISTER_TYPE(sheer::VariantInt8)
CEREAL_REGISTER_TYPE(sheer::VariantUInt8)

CEREAL_REGISTER_TYPE(sheer::VariantInt16)
CEREAL_REGISTER_TYPE(sheer::VariantUInt16)

CEREAL_REGISTER_TYPE(sheer::VariantInt32)
CEREAL_REGISTER_TYPE(sheer::VariantUInt32)

CEREAL_REGISTER_TYPE(sheer::VariantInt64)
CEREAL_REGISTER_TYPE(sheer::VariantUInt64)

CEREAL_REGISTER_TYPE(sheer::VariantFloat16)
CEREAL_REGISTER_TYPE(sheer::VariantFloat32)
CEREAL_REGISTER_TYPE(sheer::VariantFloat64)

CEREAL_REGISTER_TYPE(sheer::VariantString)
CEREAL_REGISTER_TYPE(sheer::VariantShortString)


#endif

