#include "agv_robot_info_class.cpp"  // ✅ Include derived class directly

int main(int argc, char **argv) {
    ros::init(argc, argv, "agv_robot_info_node");

    AGVRobotInfo agv("Mir100", "567A359", "169.254.5.180", "3.5.8", "100 Kg");

    ros::Rate rate(1); // 1Hz loop
    while (ros::ok()) {
        agv.publish_data();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
