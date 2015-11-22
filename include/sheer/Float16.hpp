#ifndef __SHEER_FLOAT16_H__
#define __SHEER_FLOAT16_H__

#include "sheer/BaseTypes.hpp"
#include "sheer/Float16Converter.hpp"

#include "cereal/cereal.hpp"

namespace sheer
{

class float16
{
    protected:
        uint8 _value;
    public:
        float16(const float32& value=0.0f):
            _value(Float16Converter::float32to16(value))
        {
        }
        
        float16(const float16& value):
            _value(value._value)
        {
        }

        float16& operator=(const float32& value)
        {
            _value = Float16Converter::float32to16(value);
            return *this;
        }
        
        float16& operator=(const float16& value)
        {
            _value = value._value;
            return *this;
        }
        
        inline operator float32() const
        {
            return Float16Converter::float16to32(_value);
        }
        
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(
                _value
            );
        }
};

}

#endif

