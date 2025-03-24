#include <string>

class HydraulicSystemMonitor {
private:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;

public:
    // ✅ Constructor
    HydraulicSystemMonitor(std::string temp, std::string fill_level, std::string pressure)
        : hydraulic_oil_temperature(temp), hydraulic_oil_tank_fill_level(fill_level), hydraulic_oil_pressure(pressure) {}

    // ✅ Getters
    std::string getOilTemperature() { return "hydraulic_oil_temperature: " + hydraulic_oil_temperature; }
    std::string getTankFillLevel() { return "hydraulic_oil_tank_fill_level: " + hydraulic_oil_tank_fill_level; }
    std::string getOilPressure() { return "hydraulic_oil_pressure: " + hydraulic_oil_pressure; }
};