#ifndef __SHEER_FLOAT16CONVERTER_H__
#define __SHEER_FLOAT16CONVERTER_H__

#include "sheer/BaseTypes.hpp"

namespace sheer
{

//ftp://ftp.fox-toolkit.org/pub/fasthalffloatconversion.pdf
class Float16Converter
{
    private:
        static uint32 mantissatable[2048];
        static uint32 exponenttable[64];
        static uint16 offsettable[64];
        static uint16 basetable[512];
        static uint8  shifttable[512];
        static void filltables();
        
    public:
        Float16Converter();
        
        inline static float32 float16to32(uint16 h)
        {
            union { float32 flt; uint32 i32; } conv;
            conv.i32 = mantissatable[offsettable[h>>10]+(h&0x3ff)]+exponenttable[h>>10];
            return conv.flt;
        }
        inline static uint16 float32to16(float32 x)
        {
            return float32to16round(x);
        }
        /// Fast implementation, but it crops the number so it biases low
        inline static uint16 float32to16crop(float x)
        {
            union { float32 flt; uint32 i32; } conv;
            conv.flt = x;
            return basetable[(conv.i32>>23)&0x1ff]+((conv.i32&0x007fffff)>>shifttable[(conv.i32>>23)&0x1ff]);
        }
        /// Slower implementation, but it rounds to avoid biases
        inline static uint16 float32to16round(float x)
        {
            union { float32 flt; uint32 i32; } conv;
            conv.flt = x;
            uint8 shift = shifttable[(conv.i32>>23)&0x1ff];
            if (shift == 13) {
                uint16 base2 = (conv.i32&0x007fffff)>>12;
                uint16 base = base2 >> 1;
 
                if (((base2 & 1) != 0) && (base < 1023)) base++;
                return basetable[(conv.i32>>23)&0x1ff]+base; 
            } else {
                return basetable[(conv.i32>>23)&0x1ff]+((conv.i32&0x007fffff)>>shifttable[(conv.i32>>23)&0x1ff]);
            }
        }
        
        template<int32 bits>
        inline static float32 reduceMantissaToNbits(const float32 &f)
        {
            static_assert(bits <= 23,"max mantissa size is 23 bits");
            constexpr uint32 mask = (0xFFFFFFFF >> (23-bits)) << (23-bits);
            union { float32 flt; uint32 i32; } conv;
            conv.flt=f;
            conv.i32&=mask;
            return conv.flt;
        }
};

}

#endif

