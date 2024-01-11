#if AP_CANOPEN_ENABLED

// table of user settable CAN bus parameters
const AP_Param::GroupInfo AP_CANopen::var_info[] = {
    // @Param: NODE
    // @DisplayName: CANopen node that is used for this network
    // @Description: CANopen node should be set implicitly
    // @Range: 1 250
    // @User: Advanced
    AP_GROUPINFO("NODE", 1, AP_CANopen, _canopen_node, 0),

    // @Param: SRV_BM
    // @DisplayName: RC Out channels to be transmitted as servo over CANopen
    // @Description: Bitmask with one set for channel to be transmitted as a servo command over CANopen
    // @Bitmask: 0: Servo 1, 1: Servo 2, 2: Servo 3, 3: Servo 4, 4: Servo 5, 5: Servo 6, 6: Servo 7, 7: Servo 8, 8: Servo 9, 9: Servo 10, 10: Servo 11, 11: Servo 12, 12: Servo 13, 13: Servo 14, 14: Servo 15
    // @User: Advanced
    AP_GROUPINFO("SRV_BM", 2, AP_CANopen, _servo_bm, 0),

    // @Param: ESC_BM
    // @DisplayName: RC Out channels to be transmitted as ESC over CANopen
    // @Description: Bitmask with one set for channel to be transmitted as a ESC command over CANopen
    // @Bitmask: 0: ESC 1, 1: ESC 2, 2: ESC 3, 3: ESC 4, 4: ESC 5, 5: ESC 6, 6: ESC 7, 7: ESC 8, 8: ESC 9, 9: ESC 10, 10: ESC 11, 11: ESC 12, 12: ESC 13, 13: ESC 14, 14: ESC 15, 15: ESC 16
    // @User: Advanced
    AP_GROUPINFO("ESC_BM", 3, AP_CANopen, _esc_bm, 15),

    // @Param: CTL_W
    // @DisplayName: Controlword
    // @Description: Controlword that is sent to motor controllers to turn them on.
    // @Range: 1 63
    // @User: Advanced
	AP_GROUPINFO("CTL_W", 4, AP_CANopen, _ctl, 3),

    // @Param: MAXRPM
    // @DisplayName: Full scale RPM
    // @Description: Sets the RPM value that corresponds to the maximum valid PPM value.
    // @Range: 0 15000
    // @User: Advanced
	AP_GROUPINFO("MAXRPM", 5, AP_CANopen, _rpm_max, 12000),

    // @Param: MOT_AC
    // @DisplayName: Acceleration of the motors.
    // @Description: Sets the rate at which the controllers will attempt to change the RPM.
    // @Range: 1 82000
    // @User: Advanced
	AP_GROUPINFO("MOT_AC", 6, AP_CANopen, _rpmps, 20000),

    // @Param: W_POL
    // @DisplayName: CAN message interval
    // @Description: Sets the minimum amount of time between sending CAN messages in microseconds.
    // @Range: 0 1000000
    // @User: Advanced
	AP_GROUPINFO("W_POL", 7, AP_CANopen, _can_interval_us, 2000),

	// @Param: R_POL
	// @DisplayName: CAN message interval
	// @Description: Sets the minimum amount of time between rpm reads in microseconds. 0 - return written value instead of attempting to read.
	// @Range: 0 1000000
	// @User: Advanced
	AP_GROUPINFO("R_POL", 8, AP_CANopen, _polling_interval_us, 50000),

    AP_GROUPEND
};

#endif // AP_CANOPEN_ENABLED