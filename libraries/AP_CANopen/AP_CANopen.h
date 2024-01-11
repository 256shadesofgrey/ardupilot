#pragma once

#include <AP_CANopen/AP_CANopen_config.h>

#if AP_CANOPEN_ENABLED

#include <AP_HAL/AP_HAL.h>

#include <AP_CANManager/AP_CANSensor.h>
#include <AP_Param/AP_Param.h>
#include <AP_ESC_Telem/AP_ESC_Telem_Backend.h>

#ifndef CANOPEN_NODE_POOL_SIZE
#define CANOPEN_NODE_POOL_SIZE 8192
#endif

#ifndef CANOPEN_NODE_POOL_BLOCK_SIZE
#define CANOPEN_NODE_POOL_BLOCK_SIZE 256
#endif

#ifndef CANOPEN_SRV_NUMBER
#define CANOPEN_SRV_NUMBER 16
#endif

class AP_CANopen : public AP_CANDriver
#if HAL_WITH_ESC_TELEM
, public AP_ESC_Telem_Backend
#endif
{
public:
    AP_CANopen();
    ~AP_CANopen();

    static const struct AP_Param::GroupInfo var_info[];

    void loop();

private:

    struct SRV_conf{
        uint8_t id;
        uint16_t pulse;
        bool servo_pending;
        bool esc_pending;
        uint16_t pulse_read; // Contains the value received from the controllers.
    } _srv_conf[CANOPEN_SRV_NUMBER];

    struct telemetry_info_t {
        uint64_t time;
        uint16_t voltage;
        uint16_t current;
        uint16_t rpm;
        uint8_t temp;
        bool new_data;
    } _telemetry[CANOPEN_SRV_NUMBER];

    AP_Int8 _canopen_node;
    AP_Int32 _servo_bm;
    AP_Int32 _esc_bm;
    AP_Int8 _ctl;
    AP_Int32 _rpm_max;
    AP_Int32 _rpmps;
    AP_Int32 _can_interval_us; // Sets the minimum amount of time between sending CAN messages.
    AP_Int32 _polling_interval_us; // Sets the minimum amount of time between rpm reads. 0 - return written value instead of attempting to read.
};

#endif // AP_CANOPEN_ENABLED