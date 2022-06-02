#include <iostream>
#include "units.hpp"
#include "constants.hpp"

using std::pow;
using std::sqrt;

int main()
{
    const auto mass  = 1.0 * units::gram;
    const auto dt    = 0.1 * units::s;
    const auto ell   = 1.0 * units::cm;

    const auto v = ell / dt;
    const auto a = v   / dt;

    const auto gram   = 2e33 * units::gram;
    const auto kilog  = gram.to(units::kg);
    const auto solar  = gram.to(units::mSun);
    const auto solarg = solar.to(units::gram);
    const auto solark = solar.to(units::kg);
    
    std::cout << "Sun's mass in grams:" << gram << "\n";
    std::cout << "Sun's mass in kilograms:" << kilog << "\n";
    std::cout << "Sun's mass in SolarMass:" << solar << "\n";
    std::cout << std::string(80, '=') << "\n";
    std::cout << " mass:" << solar << "\n";
    std::cout << "new mass:"   << solarg << "\n";
    std::cout << "new mass:"   << solark << "\n";

    const auto a2 = a * a;
    const auto nv = v.to(units::km / units::s);
    const auto na = a.to(units::km / units::s / units::s);
    std::cout << std::string(80, '=') << "\n";
    std::cout << "velocity in cgs: " << v  << "\n";
    std::cout << "acceleration: " << a  << "\n";
    std::cout << "velocity in kms:" << nv << "\n";
    std::cout << "acceleration in kms:" << na << "\n";
    std::cout << "Sqrt of squared acceleratio using sqrt: " << units::math::sqrt(a2) << "\n";
    std::cout << "Sqrt of squared acceleratio using pow: "  <<  units::math::pow<std::ratio<1,3>>(a2) << "\n";
    
    // Constants testing
    std::cout << std::string(80, '=') << "\n";
    std::cout << "Physical constants" << "\n";
    std::cout << "speed of light: "               <<  constants::c_light  << "\n";
    std::cout << "Planck constant: "              <<  constants::h_planck << "\n";
    std::cout << "Planck constant over 2Pi: "     <<  constants::h_bar    << "\n";
    std::cout << "Newton's G: "                   <<  constants::newtonG  << "\n";
    std::cout << "Elementary charge: "            <<  constants::e_charge << "\n";
    std::cout << "Mass of electron: "             <<  constants::m_e      << "\n";
    std::cout << "Mass of proton: "               <<  constants::m_p      << "\n";
    std::cout << "Mass of neutron: "              <<  constants::m_n      << "\n";
    std::cout << "Mass of hydrogen: "             <<  constants::m_H      << "\n";
    std::cout << "Atomic mass unit: "             <<  constants::amu      << "\n";
    std::cout << "Avagadro's number: "            <<  constants::nA       << "\n";
    std::cout << "Boltzmann constant: "           <<  constants::kB       << "\n";
    std::cout << "eV to ergs conversion: "        <<  constants::eV2erg   << "\n";
    std::cout << "Radiation density constant a: " <<  constants::aRad     << "\n";
    std::cout << "Stefan-Boltzmann constant: "    <<  constants::sigmaB   << "\n";
    std::cout << "Fine structure constant: "      <<  constants::alpha    << "\n";
    std::cout << "The Rydberg constant: "         <<  constants::rydB     << "\n";
    return 0;
}