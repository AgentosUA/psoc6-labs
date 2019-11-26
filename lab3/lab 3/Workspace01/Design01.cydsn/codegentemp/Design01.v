// ======================================================================
// Design01.v generated from TopDesign.cysch
// 11/26/2019 at 11:20
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4O 7
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 8
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 9
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 10
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 11
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 12
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 13
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 14
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 15
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 16
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 17
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 18
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 19
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 20
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 21
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 22
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 23
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 24
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 28
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 29
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 24
`define CYDEV_CHIP_REVISION_USED 33
// top
module top ;

    electrical  Net_13;
          wire  Net_5;
    electrical  Net_2;
    electrical  Net_54;
    electrical  Net_6;
    electrical  Net_21;
    electrical  Net_23;
    electrical  Net_25;
    electrical  Net_18;
    electrical  Net_15;

	wire [0:0] tmpFB_0__LED_Red_P0_3_net;
	wire [0:0] tmpIO_0__LED_Red_P0_3_net;
	electrical [0:0] tmpSIOVREF__LED_Red_P0_3_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		LED_Red_P0_3
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__LED_Red_P0_3_net[0:0]}),
		  .io({tmpIO_0__LED_Red_P0_3_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_Red_P0_3_net),
		  .annotation({Net_2}));



	cy_gsref_v1_0
		#(.guid("8C3B410E-0600-5ECF-95DD-0AF91BF8D8A7"))
		Port0_Interrupt
		 (.sig_out(Net_5));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SysInt_Port0
		 (.int_signal(Net_5));


    cy_annotation_universal_v1_0 SW2 (
        .connect({
            Net_6,
            Net_54
        })
    );
    defparam SW2.comp_name = "SwitchSPST_v1_0";
    defparam SW2.port_names = "T1, T2";
    defparam SW2.width = 2;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_6
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

	wire [0:0] tmpFB_0__LED_BLUE_P11_1_net;
	wire [0:0] tmpIO_0__LED_BLUE_P11_1_net;
	electrical [0:0] tmpSIOVREF__LED_BLUE_P11_1_net;

	cy_mxs40_gpio_v1_0
		#(.id("e03028c6-6b44-471f-b903-1d7d7cadb811"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		LED_BLUE_P11_1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__LED_BLUE_P11_1_net[0:0]}),
		  .io({tmpIO_0__LED_BLUE_P11_1_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_BLUE_P11_1_net),
		  .annotation({Net_23}));


    cy_annotation_universal_v1_0 R3 (
        .connect({
            Net_13,
            Net_15
        })
    );
    defparam R3.comp_name = "Resistor_v1_0";
    defparam R3.port_names = "T1, T2";
    defparam R3.width = 2;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_18
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 LED6_Red_NUM (
        .connect({
            Net_15,
            Net_18
        })
    );
    defparam LED6_Red_NUM.comp_name = "LED_v1_0";
    defparam LED6_Red_NUM.port_names = "A, K";
    defparam LED6_Red_NUM.width = 2;

    cy_annotation_universal_v1_0 LED6_Blue (
        .connect({
            Net_21,
            Net_25
        })
    );
    defparam LED6_Blue.comp_name = "LED_v1_0";
    defparam LED6_Blue.port_names = "A, K";
    defparam LED6_Blue.width = 2;

    cy_annotation_universal_v1_0 R_6 (
        .connect({
            Net_23,
            Net_21
        })
    );
    defparam R_6.comp_name = "Resistor_v1_0";
    defparam R_6.port_names = "T1, T2";
    defparam R_6.width = 2;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_25
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

	wire [6:0] tmpFB_6__Port5_net;
	wire [6:0] tmpIO_6__Port5_net;
	electrical [0:0] tmpSIOVREF__Port5_net;

	cy_mxs40_gpio_v1_0
		#(.id("db5d8c9a-fada-41ec-9a56-cf848dd02027"),
		  .width(7),
		  .sio_grp_cnt(0),
		  .drive_mode("6,6,6,6,6,6,6"),
		  .ibuf_enabled("0,0,0,0,0,0,0"),
		  .init_dr_st("0,0,0,0,0,0,0"),
		  .input_sync("0,0,0,0,0,0,0"),
		  .intr_mode("0,0,0,0,0,0,0"),
		  .io_voltage(",,,,,,"),
		  .output_conn("0,0,0,0,0,0,0"),
		  .oe_conn("0,0,0,0,0,0,0"),
		  .output_sync("0,0,0,0,0,0,0"),
		  .oe_sync("0,0,0,0,0,0,0"),
		  .drive_strength("0,0,0,0,0,0,0"),
		  .max_frequency("100,100,100,100,100,100,100"),
		  .i2c_mode("0,0,0,0,0,0,0"),
		  .output_current_cap("8,8,8,8,8,8,8"),
		  .pin_aliases(",,,,,,"),
		  .pin_mode("O,O,O,O,O,O,O"),
		  .slew_rate("0,0,0,0,0,0,0"),
		  .vtrip("0,0,0,0,0,0,0"),
		  .use_annotation("0,0,0,0,0,0,0"),
		  .hotswap_needed("0,0,0,0,0,0,0"))
		Port5
		 (.oe({7'b1111111}),
		  .y({7'b0}),
		  .fb({tmpFB_6__Port5_net[6:0]}),
		  .io({tmpIO_6__Port5_net[6:0]}),
		  .siovref(tmpSIOVREF__Port5_net));


	wire [0:0] tmpFB_0__SW2_P0_4_net;
	wire [0:0] tmpIO_0__SW2_P0_4_net;
	electrical [0:0] tmpSIOVREF__SW2_P0_4_net;

	cy_mxs40_gpio_v1_0
		#(.id("4cca878b-77b5-471d-8aeb-ad6925202455"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("1"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		SW2_P0_4
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__SW2_P0_4_net[0:0]}),
		  .io({tmpIO_0__SW2_P0_4_net[0:0]}),
		  .siovref(tmpSIOVREF__SW2_P0_4_net),
		  .annotation({Net_54}));




endmodule

