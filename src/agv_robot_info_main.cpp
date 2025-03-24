#include "agv_robot_info_class.cpp"  // ✅ Include AGV class

int main(int argc, char **argv) {
    ros::init(argc, argv, "agv_robot_info_node");

    // ✅ Create AGV Robot with Hydraulic System
    AGVRobotInfo agv("Mir100", "567A359", "169.254.5.180", "3.5.8", "100 Kg",
                     "45C", "100%", "250 bar");

    ros::Rate rate(1); // 1Hz loop
    while (ros::ok()) {
        agv.publish_data();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}