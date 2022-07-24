#pragma once

#include "ValueZeroMqLib.h"

#include "MyOccupancyGrid.pb.h"

namespace ZeroMqDeal
{
    /**************************************************************************/
    /* 订阅端订阅回调函数实现处 */
    template <typename MsgType = std::false_type::value_type>
    void SubscribeCallBack(void *msg)
    {
        spdlog::error("error callback msg !!!!");
    }

    template <>
    void SubscribeCallBack<LSLAM::MyOccupancyGrid>(void *msg)
    {
        LSLAM::MyOccupancyGrid *mmsg = static_cast<LSLAM::MyOccupancyGrid *>(msg);

        spdlog::info("saved_origin_x : {},saved_origin_y : {}", mmsg->saved_origin_x_(), mmsg->saved_origin_y_());
    }
    /**************************************************************************/

    /**
     * @brief 注册所有发布者节点
     *
     */
    void RegisterPublisher(void)
    {
        ZeroMqFactory::ValueZeroMqPublish::GetInstance().RegisterZMQNode<LSLAM::MyOccupancyGrid>("tcp://*:1234");
    }

    /**
     * @brief 注册所有订阅者节点
     *
     */
    void RegisterSubscriber(void)
    {
        ZeroMqFactory::ValueZeroMqSubscribe::GetInstance().RegisterZMQNode<LSLAM::MyOccupancyGrid>("tcp://localhost:1234", std::move(SubscribeCallBack<LSLAM::MyOccupancyGrid>));
    }

}; // namespace ZeroMqDeal
