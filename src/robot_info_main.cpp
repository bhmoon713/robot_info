#include "robot_info_class.cpp"  // ✅ Include base class directly

int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_info_node");

    RobotInfo robot("Mir100", "567A359", "169.254.5.180", "3.5.8");

    ros::Rate rate(1); // 1Hz loop
    while (ros::ok()) {
        robot.publish_data();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
