#ifndef __SHEER_SHORTSTRING_H__
#define __SHEER_SHORTSTRING_H__

#include "sheer/BaseTypes.hpp"

#include <cereal/cereal.hpp>
#include "cereal/types/vector.hpp"
#include "cereal/types/bitset.hpp"

#include <array>
#include <vector>
#include <iostream>
#include <string>


namespace sheer
{


//allowed characters 
//"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_"

class ShortString
{
    protected:
        typedef std::bitset<6> SChar;
        std::vector<SChar> _characters;
        
        const static std::array<SChar,128> toSChar;
        const static std::array<char,64> toChar;
        
        constexpr static uint8 B_00_11_11_11 = 63;
        constexpr static uint8 B_11_00_00_00 = 192;
        
        constexpr static uint8 B_00_00_11_11 = 15;
        constexpr static uint8 B_11_11_00_00 = 240;
        
        constexpr static uint8 B_00_00_00_11 = 3;
        constexpr static uint8 B_11_11_11_00 = 252;
        
        constexpr static uint8 B_00_11_11_00 = 60;
        constexpr static uint8 B_00_11_00_00 = 48;
        
    public:
        ShortString(const std::string& str = "")
        {
            for (unsigned int i = 0; i < str.size(); ++i)
            {
                if (toSChar[str[i]]==0)
                {
                    continue;
                }
                _characters.push_back(toSChar[str[i]]);
            }
        }
        
        ShortString& operator=(const std::string& str)
        {
            _characters.clear();
            for (unsigned int i = 0; i < str.size(); ++i)
            {
                if (toSChar[str[i]]==0)
                {
                    continue;
                }
                _characters.push_back(toSChar[str[i]]);
            }
            return *this;
        }
        
        ShortString& operator+=(const std::string& str)
        {
            for (unsigned int i = 0; i < str.size(); ++i)
            {
                if (toSChar[str[i]]==0)
                {
                    continue;
                }
                _characters.push_back(toSChar[str[i]]);
            }
            return *this;
        }
        
        std::string getString() const
        {
            std::string output;
            for (unsigned int i = 0; i < _characters.size(); ++i)
            {
                output+=(char)toChar[_characters[i].to_ulong()];
            }
            return std::move(output);
        }
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            const uint8 ngroups = (_characters.size()+3)/4;
            std::vector<uint8> data(ngroups*3);
            
            for (unsigned int igroup = 0; igroup < ngroups; ++igroup)
            {
                
                unsigned long c1 = igroup*4   < _characters.size() ? _characters[igroup*4].to_ulong()  : 0;
                unsigned long c2 = igroup*4+1 < _characters.size() ? _characters[igroup*4+1].to_ulong(): 0;
                unsigned long c3 = igroup*4+2 < _characters.size() ? _characters[igroup*4+2].to_ulong(): 0;
                unsigned long c4 = igroup*4+3 < _characters.size() ? _characters[igroup*4+3].to_ulong(): 0;
                
                data[igroup*3]  = ((c1 & B_00_11_11_11) >> 0) + ((c2 & B_00_00_00_11) << 6);
                data[igroup*3+1]= ((c2 & B_00_11_11_00) >> 2) + ((c3 & B_00_00_11_11) << 4);            
                data[igroup*3+2]= ((c3 & B_00_11_00_00) >> 4) + ((c4 & B_00_11_11_11) << 2); 

            }
            
            
           
            
            //archive.saveBinaryValue(_characters.data(),3*(_characters.size()/4),"characters");
            archive(data
                //cereal::make_nvp("characters",data)
            );
            
            /*
            archive(
                cereal::make_nvp("characters",_characters)
            );
            */
        }
};

}



#endif

