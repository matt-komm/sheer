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
        ShortString(const std::string str = "")
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
            archive(
                cereal::make_nvp("characters",_characters)
            );
        }
};

}



#endif

