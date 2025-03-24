#include "robot_info_class.cpp"  // ✅ Include base class
#include "hydraulic_system_monitor.cpp"  // ✅ Include hydraulic monitor class

class AGVRobotInfo : public RobotInfo {
private:
    std::string max_payload;
    HydraulicSystemMonitor hydraulicMonitor;  // ✅ Composition: Adding Hydraulic System Monitor

public:
    // ✅ Constructor with hydraulic system data
    AGVRobotInfo(std::string description, std::string serial, std::string ip, std::string firmware, std::string payload,
                 std::string temp, std::string fill_level, std::string pressure)
        : RobotInfo(description, serial, ip, firmware), max_payload(payload),
          hydraulicMonitor(temp, fill_level, pressure) {}

    // ✅ Override `publish_data()`
    void publish_data() override {
        msg.data_field_05 = "maximum_payload: " + max_payload;
        msg.data_field_06 = hydraulicMonitor.getOilTemperature();
        msg.data_field_07 = hydraulicMonitor.getTankFillLevel();
        msg.data_field_08 = hydraulicMonitor.getOilPressure();
        msg.data_field_09 = "";
        msg.data_field_10 = "";

        pub.publish(msg);

        ROS_INFO("📡 AGVRobotInfo Published:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                 msg.data_field_01.c_str(), msg.data_field_02.c_str(), msg.data_field_03.c_str(),
                 msg.data_field_04.c_str(), msg.data_field_05.c_str(), msg.data_field_06.c_str(),
                 msg.data_field_07.c_str(), msg.data_field_08.c_str(), msg.data_field_09.c_str(),
                 msg.data_field_10.c_str());
    }
};