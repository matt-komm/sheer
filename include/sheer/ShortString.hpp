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


//allowed characters; all others will 
//"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_"

class ShortString
{
    protected:
        typedef std::bitset<6> SChar;
        std::vector<SChar> _characters;
        
        const static std::array<SChar,128> toSChar;
        const static std::array<char,64> toChar;
        
        
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
            //24 = 6*4 = 3*8; so 4 SChar can be stored as 3 bytes;
            std::vector<bool> data(_characters.size()*6);
            
            for (unsigned int ichar = 0; ichar < _characters.size(); ++ichar)
            {
                for (unsigned int ibit = 0; ibit < 6; ++ibit)
                {
                    data[ichar*6+ibit]=_characters[ichar][ibit];
                }
            }
            
            const char* data2 = reinterpret_cast<const char*>(_characters.data());
            for (unsigned int ibyte = 0; ibyte < 3*_characters.size()/4; ++ibyte)
            {
                for (unsigned int ibit = 0; ibit < 8; ++ibit)
                {
                    std::cout<<int(int(data2[ibyte]))<<" "; //& (0x01<<ibit))<<" ";//int( (0x01>>ibit))<<" ";
                }
                
            }
            
            //archive.saveBinaryValue(_characters.data(),3*(_characters.size()/4),"characters");
            archive(
                cereal::make_nvp("characters",data)
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

