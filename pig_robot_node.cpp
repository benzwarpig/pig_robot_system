/**
 * @file pig_robot_node.cpp
 * @author benzs_war_pig (benzwarpig@outlook.com)
 * @brief 机器人总调度相关工程
 * @version 1.0
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <behaviortree_cpp_v3/behavior_tree.h>

#include <spdlog/spdlog.h>

#include "ZeroMqMsgDeal.hpp"

int main(void)
{
    spdlog::info("Test Pig Robot");

    ZeroMqDeal::RegisterPublisher();
    ZeroMqDeal::RegisterSubscriber();

    while (1)
    {
        // LSLAM::MyOccupancyGrid msg;
        // msg.set_saved_origin_x_(1000);
        // msg.set_saved_origin_y_(2000);

        // ZeroMqFactory::ValueZeroMqPublish::GetInstance().PublishProtoMsg(msg);

        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
