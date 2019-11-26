// ======================================================================
// lab_3_1.v generated from TopDesign.cysch
// 09/18/2019 at 17:31
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
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 14
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 15
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 16
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 17
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 18
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 19
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 20
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 21
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 22
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 23
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 24
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 25
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 26
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 27
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 28
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 29
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 30
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 31
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 32
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 27
`define CYDEV_CHIP_REVISION_USED 33
// top
module top ;

          wire  Net_24;
    electrical  Net_17;
    electrical  Net_12;
    electrical  Net_9;
    electrical  Net_16;
    electrical  Net_14;
    electrical  Net_13;
    electrical  Net_6;
    electrical  Net_4;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_12,
            Net_13
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_9,
            Net_4
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 D_2 (
        .connect({
            Net_4,
            Net_6
        })
    );
    defparam D_2.comp_name = "LED_v1_0";
    defparam D_2.port_names = "A, K";
    defparam D_2.width = 2;

    cy_annotation_universal_v1_0 D_1 (
        .connect({
            Net_13,
            Net_14
        })
    );
    defparam D_1.comp_name = "LED_v1_0";
    defparam D_1.port_names = "A, K";
    defparam D_1.width = 2;


	cy_gsref_v1_0
		#(.guid("8C3B410E-0600-5ECF-95DD-0AF91BF8D8A7"))
		Port0_Interrupt
		 (.sig_out(Net_24));


    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_6
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

	wire [0:0] tmpFB_0__LED_Blue_P11_1_net;
	wire [0:0] tmpIO_0__LED_Blue_P11_1_net;
	electrical [0:0] tmpSIOVREF__LED_Blue_P11_1_net;

	cy_mxs40_gpio_v1_0
		#(.id("9ac5f4f6-d38f-434a-9b17-afab494961b6"),
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
		LED_Blue_P11_1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__LED_Blue_P11_1_net[0:0]}),
		  .io({tmpIO_0__LED_Blue_P11_1_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_Blue_P11_1_net),
		  .annotation({Net_12}));


    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_14
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

    cy_annotation_universal_v1_0 SW_1 (
        .connect({
            Net_17,
            Net_16
        })
    );
    defparam SW_1.comp_name = "SwitchSPST_v1_0";
    defparam SW_1.port_names = "T1, T2";
    defparam SW_1.width = 2;

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_17
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;

	wire [0:0] tmpFB_0__SW2_P0_4_net;
	wire [0:0] tmpIO_0__SW2_P0_4_net;
	electrical [0:0] tmpSIOVREF__SW2_P0_4_net;

	cy_mxs40_gpio_v1_0
		#(.id("6fb4e58b-fc61-450d-ab10-533363eee47b"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("2"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
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
		  .annotation({Net_16}));


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
		  .annotation({Net_9}));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SysInt_Port0
		 (.int_signal(Net_24));


	wire [6:0] tmpFB_6__Port5_net;
	wire [6:0] tmpIO_6__Port5_net;
	electrical [0:0] tmpSIOVREF__Port5_net;

	cy_mxs40_gpio_v1_0
		#(.id("fb6468c4-21ee-4b09-9dc9-2980e44e97b6"),
		  .width(7),
		  .sio_grp_cnt(0),
		  .drive_mode("6,6,6,6,6,6,6"),
		  .ibuf_enabled("0,0,0,0,0,0,1"),
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
		  .pin_mode("O,O,O,O,O,O,I"),
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




endmodule

