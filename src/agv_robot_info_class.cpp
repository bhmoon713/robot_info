#include "robot_info_class.cpp"

class AGVRobotInfo : public RobotInfo {
private:
    std::string max_payload;


public:
    // ✅ Constructor
    AGVRobotInfo(std::string description, std::string serial, std::string ip, std::string firmware, std::string payload)
        : RobotInfo(description, serial, ip, firmware), max_payload(payload) {}


    // ✅ Override `publish_data()`
    void publish_data() override {
        max_payload = "100Kg";
        msg.data_field_05 = "maximum_payload: " + max_payload;


        pub.publish(msg);

        ROS_INFO("📡 AGVRobotInfo Published: %s, %s, %s, %s, %s",
                 msg.data_field_01.c_str(), msg.data_field_02.c_str(), msg.data_field_03.c_str(), msg.data_field_04.c_str(),
                 msg.data_field_05.c_str());
    }
};
