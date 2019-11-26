// ======================================================================
// lab9.v generated from TopDesign.cysch
// 11/13/2019 at 17:51
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
// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// cy_ctb_include_v1_0(CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=cy_ctb_include_v1_0, CY_CONFIG_TITLE=cy_ctb_include_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC_1:cy_ctb_include_1, CY_INSTANCE_SHORT_NAME=cy_ctb_include_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ctb, CY_PDL_DRIVER_REQ_VERSION=1.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=VDAC_1_cy_ctb_include_1, )
module cy_ctb_include_v1_0_0 ;





endmodule

// VDAC12_PDL_v1_0(DacCodeMode=0, DebugEnable=false, DeepSleep=false, DwrExtAfterCustomized=false, DwrRefExternal=0, GainBandwidth=2, InitialCode=0, InitialVoltage_mV=0, OpampIDD=2, OpAmpUsage=0, OutputBuffer=0, OutputBufferPower=2, OutputBufferRange=0, RefBufferRange=0, ReferenceCurrentHigh=true, SampleAndHold=false, ShowClk=true, ShowStrobe=false, ShowTrig=true, UpdateMode=1, VrefSource=1, VrefVoltage=1.2, VrefVoltage_mV=3300, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=VDAC12_PDL_v1_0, CY_CONFIG_TITLE=VDAC_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC_1, CY_INSTANCE_SHORT_NAME=VDAC_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ctdac, CY_PDL_DRIVER_REQ_VERSION=1.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=VDAC_1, )
module VDAC12_PDL_v1_0_1 (
    vref,
    strobe,
    clock,
    vout,
    trigger,
    vref_out);
    inout       vref;
    electrical  vref;
    input       strobe;
    input       clock;
    inout       vout;
    electrical  vout;
    output      trigger;
    inout       vref_out;
    electrical  vref_out;


    electrical  ct_vout_sw;
    electrical  ct_vout_buf;
    electrical  ct_vout;
    electrical  ref_drive;
          wire  Net_58;
          wire  Net_48;
          wire  Net_44;
    electrical  Net_43;
    electrical  Net_42;
          wire  Net_36;
          wire  Net_34;
    electrical  Net_3;
    electrical  Net_14;
    electrical  Net_16;
          wire  Net_1;
    electrical  Net_9;
    electrical  Net_10;

    cy_mxs40_ctdac_v1_0 CTDAC (
        .clock(Net_1),
        .ctdrefdrive(ref_drive),
        .ctdrefsense(Net_3),
        .ctdvout(ct_vout),
        .ctdvoutsw(ct_vout_sw),
        .dsi_ctdac_strobe(strobe),
        .tr_ctdac_empty(trigger));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(vout, ct_vout_sw);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(ct_vout_buf, Net_16);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_9));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_10, Net_42);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_42));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_4 (
        .noconnect(Net_3));

    assign Net_44 = 1'h0;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1 = clock;

    cy_ctb_include_v1_0_0 cy_ctb_include_1 ();


    cy_connect_v1_0 vref_out__cy_connect_v1_0(vref_out, ref_drive);
    defparam vref_out__cy_connect_v1_0.sig_width = 1;


endmodule

// DMA_PDL_v2_0(BUFFERABLE=false, CHAIN_TO_1=0, CHAIN_TO_2=0, CHAIN_TO_3=0, CHAIN_TO_4=0, CHANNEL_PRIORITY=3, DATA_ELEMENT_SIZE_1=2, DATA_ELEMENT_SIZE_2=2, DATA_ELEMENT_SIZE_3=2, DATA_ELEMENT_SIZE_4=2, DESCR_NAME_1=Descriptor_1, DESCR_NAME_2=Descriptor_2, DESCR_NAME_3=Descriptor_3, DESCR_NAME_4=Descriptor_4, DESCRIPTORS_XML_STR=<?xml version="1.0" encoding="utf-16"?> <ArrayOfCyDmaDescriptionProperties xmlns:Version="ystem.Collections.Generic">   <CyDmaDescriptionProperties>     <DescriptorName>Descriptor_1</DescriptorName>     <ChainToDescriptor>Descriptor_1</ChainToDescriptor>     <NumberOfDataElementsToTransfer>100</NumberOfDataElementsToTransfer>     <DestinationIncrementEveryCycleByX>0</DestinationIncrementEveryCycleByX>   </CyDmaDescriptionProperties> </ArrayOfCyDmaDescriptionProperties>, DST_WIDTH_1=0, DST_WIDTH_2=0, DST_WIDTH_3=0, DST_WIDTH_4=0, INTR_OUT_1=0, INTR_OUT_2=0, INTR_OUT_3=0, INTR_OUT_4=0, MIGRATION=false, NUM_OF_DESCRIPTORS=1, PREEMPTABLE=false, SRC_WIDTH_1=0, SRC_WIDTH_2=0, SRC_WIDTH_3=0, SRC_WIDTH_4=0, TRIG_DEACT_1=0, TRIG_DEACT_2=0, TRIG_DEACT_3=0, TRIG_DEACT_4=0, TRIG_IN_TYPE_1=0, TRIG_IN_TYPE_2=0, TRIG_IN_TYPE_3=0, TRIG_IN_TYPE_4=0, TRIG_INPUT=true, TRIG_OUT_TYPE_1=0, TRIG_OUT_TYPE_2=0, TRIG_OUT_TYPE_3=0, TRIG_OUT_TYPE_4=0, TRIG_OUTPUT=false, X_DST_INCREMENT_1=1, X_DST_INCREMENT_2=1, X_DST_INCREMENT_3=1, X_DST_INCREMENT_4=1, X_NUM_OF_ELEMENTS_1=1, X_NUM_OF_ELEMENTS_2=1, X_NUM_OF_ELEMENTS_3=1, X_NUM_OF_ELEMENTS_4=1, X_SRC_INCREMENT_1=1, X_SRC_INCREMENT_2=1, X_SRC_INCREMENT_3=1, X_SRC_INCREMENT_4=1, Y_DST_INCREMENT_1=1, Y_DST_INCREMENT_2=1, Y_DST_INCREMENT_3=1, Y_DST_INCREMENT_4=1, Y_NUM_OF_ELEMENTS_1=1, Y_NUM_OF_ELEMENTS_2=1, Y_NUM_OF_ELEMENTS_3=1, Y_NUM_OF_ELEMENTS_4=1, Y_SRC_INCREMENT_1=1, Y_SRC_INCREMENT_2=1, Y_SRC_INCREMENT_3=1, Y_SRC_INCREMENT_4=1, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=DMA_PDL_v2_0, CY_CONFIG_TITLE=DMA_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=DMA_1, CY_INSTANCE_SHORT_NAME=DMA_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=dma, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=DMA_1, )
module DMA_PDL_v2_0_2 (
    tr_in,
    tr_out,
    interrupt);
    input       tr_in;
    output      tr_out;
    output      interrupt;



    cy_mxs40_dw_v1_0 DW (
        .tr_in(tr_in),
        .tr_out(tr_out),
        .interrupt(interrupt));
    defparam DW.priority = 3;



endmodule

// top
module top ;

          wire  Net_17;
          wire  Net_16;
          wire  Net_14;
    electrical  Net_7;
          wire  Net_3;
    electrical  Net_2;
          wire  Net_18;
          wire  Net_4;
    electrical  Net_5;

	wire [0:0] tmpFB_0__VDAC_Out_P9_6_net;
	wire [0:0] tmpIO_0__VDAC_Out_P9_6_net;
	electrical [0:0] tmpSIOVREF__VDAC_Out_P9_6_net;

	cy_mxs40_gpio_v1_0
		#(.id("0113321b-4a37-46f6-8407-2f8646c68756"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
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
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		VDAC_Out_P9_6
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__VDAC_Out_P9_6_net[0:0]}),
		  .analog({Net_5}),
		  .io({tmpIO_0__VDAC_Out_P9_6_net[0:0]}),
		  .siovref(tmpSIOVREF__VDAC_Out_P9_6_net));


    VDAC12_PDL_v1_0_1 VDAC_1 (
        .vref(Net_2),
        .strobe(1'b0),
        .clock(Net_4),
        .vout(Net_5),
        .trigger(Net_18),
        .vref_out(Net_7));


	cy_clock_v1_0
		#(.id("ed8b1412-ca57-41be-bb33-1e1022cb02ba"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("20000000000"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_1
		 (.clock_out(Net_4));


    DMA_PDL_v2_0_2 DMA_1 (
        .tr_in(Net_18),
        .tr_out(Net_16),
        .interrupt(Net_17));



endmodule

