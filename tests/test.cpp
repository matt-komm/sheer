#include "sheer/BaseTypes.hpp"

#include "sheer/Event.hpp"
#include "sheer/Particle.hpp"
#include "sheer/ShortString.hpp"
#include "sheer/Variant.hpp"
#include "sheer/Float16.hpp"

#include <cereal/archives/xml.hpp>

#include <iostream>
#include <sstream>

int main()
{
    std::unique_ptr<sheer::HepObject> event(new sheer::Event());
    sheer::Particle<sheer::float16> p1;
    sheer::Particle<sheer::float32> p2;
    sheer::Particle<sheer::float64> p3;
    sheer::ShortString str("sgm43k4osdvmsdkko3 ops");
    //std::unique_ptr<sheer::LorentzVector> p1(new sheer::LorentzVectorF32());
    
    std::unique_ptr<sheer::Variant> v(new sheer::VariantUInt32(3));
    
    std::stringstream ss;
    {
        cereal::XMLOutputArchive ar(ss);
        ar(cereal::make_nvp("Event",event));
        //ar(cereal::make_nvp("v",v));
        ar(cereal::make_nvp("Particle",p1));
        //ar(cereal::make_nvp("Particle",p2));
        //ar(cereal::make_nvp("Particle",p3));
        //ar(cereal::make_nvp("string",str));
    }
    std::cout<<ss.str()<<std::endl;
    
    return 0;
}


