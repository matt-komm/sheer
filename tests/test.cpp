#include "sheer/BaseTypes.hpp"

#include "sheer/Event.hpp"
#include "sheer/Particle.hpp"
#include "sheer/ShortString.hpp"

#include <cereal/archives/xml.hpp>

#include <iostream>
#include <sstream>

int main()
{
    sheer::Event event;
    sheer::Particle p1(new sheer::LorentzVectorF16());
    sheer::Particle p2(new sheer::LorentzVectorF32());
    sheer::Particle p3(new sheer::LorentzVectorF64());
    sheer::ShortString str("0test dsdgdfgasdf qe 30 __---klJBKBHNL*^(&*078");
    //std::unique_ptr<sheer::LorentzVector> p1(new sheer::LorentzVectorF32());
    
    std::stringstream ss;
    {
        cereal::XMLOutputArchive ar(ss);
        //ar(cereal::make_nvp("Particle",p1));
        //ar(cereal::make_nvp("Particle",p2));
        //ar(cereal::make_nvp("Particle",p3));
        ar(cereal::make_nvp("string",str));
    }
    std::cout<<ss.str()<<std::endl;
    
    return 0;
}


