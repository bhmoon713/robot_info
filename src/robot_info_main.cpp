#include "agv_robot_info_class.cpp"  // ✅ Include both base and derived classes

int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_info_node");

    // ✅ Check for command-line argument
    bool use_agv = false;
    if (argc > 1) {
        std::string mode_arg = argv[1];
        if (mode_arg == "agv") {
            use_agv = true;
        }
    }

    ros::Rate rate(1); // 1Hz loop

    if (use_agv) {
        // ✅ Run AGV Mode (Hydraulic System Included)
        AGVRobotInfo robot("Mir100", "567A359", "169.254.5.180", "3.5.8", "100 Kg",
                           "45C", "100%", "250 bar");
        ROS_INFO("Running AGV Mode");

        while (ros::ok()) {
            robot.publish_data();
            ros::spinOnce();
            rate.sleep();
        }
    } else {
        // ✅ Run Normal Robot Mode
        RobotInfo robot("Mir100", "567A359", "169.254.5.180", "3.5.8");
        ROS_INFO("Running Normal Robot Mode");

        while (ros::ok()) {
            robot.publish_data();
            ros::spinOnce();
            rate.sleep();
        }
    }

    return 0;
}