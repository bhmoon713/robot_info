#include "robot_info_class.cpp"  // ✅ Include base class

class AGVRobotInfo : public RobotInfo {
private:
    std::string max_payload;

public:
    // ✅ Constructor
    AGVRobotInfo(std::string description, std::string serial, std::string ip, std::string firmware, std::string payload)
        : RobotInfo(description, serial, ip, firmware), max_payload(payload) {}

    // ✅ Override `publish_data()`
    void publish_data() override {
        msg.data_field_05 = "maximum_payload: " + max_payload;
        msg.data_field_06 = "";  // Empty fields
        msg.data_field_07 = "";
        msg.data_field_08 = "";
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
