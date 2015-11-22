#ifndef __SHEER_HASH_H__
#define __SHEER_HASH_H__

#include "sheer/BaseTypes.hpp"

#include <string>
#include <array>

namespace sheer
{

class Hash
{
    public:
        const static std::array<uint8,256> lookup;

    public:
        // Pearsong hashing algorithm as described in RFC 3074.
        // -> http://www.apps.ietf.org/rfc/rfc3074.html
        static uint8 get(const std::string& key) 
        {
            uint8 hash = key.size();
            for (size_t i = key.size(); i > 0;) 
            {
                hash = lookup[hash ^ key[--i]];
            }
            return hash;
        }
};

}

#endif

