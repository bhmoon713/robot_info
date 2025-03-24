#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>  // ✅ Use the existing message

class RobotInfo {
private:
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;    

protected:
    ros::NodeHandle nh;
    ros::Publisher pub;
    robotinfo_msgs::RobotInfo10Fields msg;  // ✅ Message structure

public:
    // ✅ Constructor
    RobotInfo(std::string robot_description, std::string serial_number, std::string ip_address, std::string firmware_version) {
        pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("/robot_info", 10);

        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;

        msg.data_field_05 = "";  // Placeholder for AGV max payload
        msg.data_field_06 = "";  // Empty fields for now
        msg.data_field_07 = "";
        msg.data_field_08 = "";
        msg.data_field_09 = "";
        msg.data_field_10 = "";
    }

    // ✅ Virtual Function for Publishing Data
    virtual void publish_data() {
        pub.publish(msg);
        ROS_INFO("Published RobotInfo:\n%s\n%s\n%s\n%s",
                 msg.data_field_01.c_str(), msg.data_field_02.c_str(),
                 msg.data_field_03.c_str(), msg.data_field_04.c_str());
    }

    virtual ~RobotInfo() {}  // Virtual Destructor
};