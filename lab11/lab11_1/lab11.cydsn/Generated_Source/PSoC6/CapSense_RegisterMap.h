/***************************************************************************//**
* \file CapSense_RegisterMap.h
* \version 2.0
*
* \brief
*   This file provides the definitions for the Component data structure register.
*
* \see CapSense v2.0 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2017), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_SENSE_CapSense_REGISTER_MAP_H)
#define CY_SENSE_CapSense_REGISTER_MAP_H

#include "syslib/cy_syslib.h"
#include "CapSense_Configuration.h"
#include "CapSense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define CapSense_CONFIG_ID_VALUE                            (CapSense_dsRam.configId)
#define CapSense_CONFIG_ID_OFFSET                           (0u)
#define CapSense_CONFIG_ID_SIZE                             (2u)
#define CapSense_CONFIG_ID_PARAM_ID                         (0x87000000u)

#define CapSense_DEVICE_ID_VALUE                            (CapSense_dsRam.deviceId)
#define CapSense_DEVICE_ID_OFFSET                           (2u)
#define CapSense_DEVICE_ID_SIZE                             (2u)
#define CapSense_DEVICE_ID_PARAM_ID                         (0x8B000002u)

#define CapSense_HW_CLOCK_VALUE                             (CapSense_dsRam.hwClock)
#define CapSense_HW_CLOCK_OFFSET                            (4u)
#define CapSense_HW_CLOCK_SIZE                              (2u)
#define CapSense_HW_CLOCK_PARAM_ID                          (0x86000004u)

#define CapSense_TUNER_CMD_VALUE                            (CapSense_dsRam.tunerCmd)
#define CapSense_TUNER_CMD_OFFSET                           (6u)
#define CapSense_TUNER_CMD_SIZE                             (2u)
#define CapSense_TUNER_CMD_PARAM_ID                         (0xA1000006u)

#define CapSense_SCAN_COUNTER_VALUE                         (CapSense_dsRam.scanCounter)
#define CapSense_SCAN_COUNTER_OFFSET                        (8u)
#define CapSense_SCAN_COUNTER_SIZE                          (2u)
#define CapSense_SCAN_COUNTER_PARAM_ID                      (0x85000008u)

#define CapSense_STATUS_VALUE                               (CapSense_dsRam.status)
#define CapSense_STATUS_OFFSET                              (12u)
#define CapSense_STATUS_SIZE                                (4u)
#define CapSense_STATUS_PARAM_ID                            (0xCB00000Cu)

#define CapSense_WDGT_ENABLE0_VALUE                         (CapSense_dsRam.wdgtEnable[0u])
#define CapSense_WDGT_ENABLE0_OFFSET                        (16u)
#define CapSense_WDGT_ENABLE0_SIZE                          (4u)
#define CapSense_WDGT_ENABLE0_PARAM_ID                      (0xE6000010u)

#define CapSense_WDGT_STATUS0_VALUE                         (CapSense_dsRam.wdgtStatus[0u])
#define CapSense_WDGT_STATUS0_OFFSET                        (20u)
#define CapSense_WDGT_STATUS0_SIZE                          (4u)
#define CapSense_WDGT_STATUS0_PARAM_ID                      (0xCC000014u)

#define CapSense_SNS_STATUS0_VALUE                          (CapSense_dsRam.snsStatus[0u])
#define CapSense_SNS_STATUS0_OFFSET                         (24u)
#define CapSense_SNS_STATUS0_SIZE                           (1u)
#define CapSense_SNS_STATUS0_PARAM_ID                       (0x48000018u)

#define CapSense_SNS_STATUS1_VALUE                          (CapSense_dsRam.snsStatus[1u])
#define CapSense_SNS_STATUS1_OFFSET                         (25u)
#define CapSense_SNS_STATUS1_SIZE                           (1u)
#define CapSense_SNS_STATUS1_PARAM_ID                       (0x4E000019u)

#define CapSense_SNS_STATUS2_VALUE                          (CapSense_dsRam.snsStatus[2u])
#define CapSense_SNS_STATUS2_OFFSET                         (26u)
#define CapSense_SNS_STATUS2_SIZE                           (1u)
#define CapSense_SNS_STATUS2_PARAM_ID                       (0x4400001Au)

#define CapSense_CSD0_CONFIG_VALUE                          (CapSense_dsRam.csd0Config)
#define CapSense_CSD0_CONFIG_OFFSET                         (28u)
#define CapSense_CSD0_CONFIG_SIZE                           (2u)
#define CapSense_CSD0_CONFIG_PARAM_ID                       (0xA780001Cu)

#define CapSense_MOD_CSD_CLK_VALUE                          (CapSense_dsRam.modCsdClk)
#define CapSense_MOD_CSD_CLK_OFFSET                         (30u)
#define CapSense_MOD_CSD_CLK_SIZE                           (1u)
#define CapSense_MOD_CSD_CLK_PARAM_ID                       (0x6380001Eu)

#define CapSense_MOD_CSX_CLK_VALUE                          (CapSense_dsRam.modCsxClk)
#define CapSense_MOD_CSX_CLK_OFFSET                         (31u)
#define CapSense_MOD_CSX_CLK_SIZE                           (1u)
#define CapSense_MOD_CSX_CLK_PARAM_ID                       (0x6580001Fu)

#define CapSense_BUTTON0_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button0.resolution)
#define CapSense_BUTTON0_RESOLUTION_OFFSET                  (32u)
#define CapSense_BUTTON0_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON0_RESOLUTION_PARAM_ID                (0xAB800020u)

#define CapSense_BUTTON0_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button0.fingerTh)
#define CapSense_BUTTON0_FINGER_TH_OFFSET                   (34u)
#define CapSense_BUTTON0_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON0_FINGER_TH_PARAM_ID                 (0xA7800022u)

#define CapSense_BUTTON0_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button0.noiseTh)
#define CapSense_BUTTON0_NOISE_TH_OFFSET                    (36u)
#define CapSense_BUTTON0_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON0_NOISE_TH_PARAM_ID                  (0x62800024u)

#define CapSense_BUTTON0_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button0.nNoiseTh)
#define CapSense_BUTTON0_NNOISE_TH_OFFSET                   (37u)
#define CapSense_BUTTON0_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON0_NNOISE_TH_PARAM_ID                 (0x64800025u)

#define CapSense_BUTTON0_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button0.hysteresis)
#define CapSense_BUTTON0_HYSTERESIS_OFFSET                  (38u)
#define CapSense_BUTTON0_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON0_HYSTERESIS_PARAM_ID                (0x6E800026u)

#define CapSense_BUTTON0_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button0.onDebounce)
#define CapSense_BUTTON0_ON_DEBOUNCE_OFFSET                 (39u)
#define CapSense_BUTTON0_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON0_ON_DEBOUNCE_PARAM_ID               (0x68800027u)

#define CapSense_BUTTON0_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button0.lowBslnRst)
#define CapSense_BUTTON0_LOW_BSLN_RST_OFFSET                (40u)
#define CapSense_BUTTON0_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON0_LOW_BSLN_RST_PARAM_ID              (0x61800028u)

#define CapSense_BUTTON0_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button0.idacMod[0u])
#define CapSense_BUTTON0_IDAC_MOD0_OFFSET                   (41u)
#define CapSense_BUTTON0_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON0_IDAC_MOD0_PARAM_ID                 (0x41000029u)

#define CapSense_BUTTON0_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button0.snsClk)
#define CapSense_BUTTON0_SNS_CLK_OFFSET                     (42u)
#define CapSense_BUTTON0_SNS_CLK_SIZE                       (2u)
#define CapSense_BUTTON0_SNS_CLK_PARAM_ID                   (0xA580002Au)

#define CapSense_BUTTON0_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button0.snsClkSource)
#define CapSense_BUTTON0_SNS_CLK_SOURCE_OFFSET              (44u)
#define CapSense_BUTTON0_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON0_SNS_CLK_SOURCE_PARAM_ID            (0x4B80002Cu)

#define CapSense_BUTTON0_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button0.fingerCap)
#define CapSense_BUTTON0_FINGER_CAP_OFFSET                  (46u)
#define CapSense_BUTTON0_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON0_FINGER_CAP_PARAM_ID                (0xA900002Eu)

#define CapSense_BUTTON0_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button0.sigPFC)
#define CapSense_BUTTON0_SIGPFC_OFFSET                      (48u)
#define CapSense_BUTTON0_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON0_SIGPFC_PARAM_ID                    (0xA3000030u)

#define CapSense_BUTTON0_GESTURE_ID_VALUE                   (CapSense_dsRam.wdgtList.button0.gestureId)
#define CapSense_BUTTON0_GESTURE_ID_OFFSET                  (50u)
#define CapSense_BUTTON0_GESTURE_ID_SIZE                    (1u)
#define CapSense_BUTTON0_GESTURE_ID_PARAM_ID                (0x67000032u)

#define CapSense_BUTTON1_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button1.resolution)
#define CapSense_BUTTON1_RESOLUTION_OFFSET                  (52u)
#define CapSense_BUTTON1_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON1_RESOLUTION_PARAM_ID                (0xAC810034u)

#define CapSense_BUTTON1_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button1.fingerTh)
#define CapSense_BUTTON1_FINGER_TH_OFFSET                   (54u)
#define CapSense_BUTTON1_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON1_FINGER_TH_PARAM_ID                 (0xA0810036u)

#define CapSense_BUTTON1_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button1.noiseTh)
#define CapSense_BUTTON1_NOISE_TH_OFFSET                    (56u)
#define CapSense_BUTTON1_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON1_NOISE_TH_PARAM_ID                  (0x67810038u)

#define CapSense_BUTTON1_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button1.nNoiseTh)
#define CapSense_BUTTON1_NNOISE_TH_OFFSET                   (57u)
#define CapSense_BUTTON1_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON1_NNOISE_TH_PARAM_ID                 (0x61810039u)

#define CapSense_BUTTON1_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button1.hysteresis)
#define CapSense_BUTTON1_HYSTERESIS_OFFSET                  (58u)
#define CapSense_BUTTON1_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON1_HYSTERESIS_PARAM_ID                (0x6B81003Au)

#define CapSense_BUTTON1_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button1.onDebounce)
#define CapSense_BUTTON1_ON_DEBOUNCE_OFFSET                 (59u)
#define CapSense_BUTTON1_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON1_ON_DEBOUNCE_PARAM_ID               (0x6D81003Bu)

#define CapSense_BUTTON1_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button1.lowBslnRst)
#define CapSense_BUTTON1_LOW_BSLN_RST_OFFSET                (60u)
#define CapSense_BUTTON1_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON1_LOW_BSLN_RST_PARAM_ID              (0x6681003Cu)

#define CapSense_BUTTON1_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button1.idacMod[0u])
#define CapSense_BUTTON1_IDAC_MOD0_OFFSET                   (61u)
#define CapSense_BUTTON1_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON1_IDAC_MOD0_PARAM_ID                 (0x4601003Du)

#define CapSense_BUTTON1_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button1.snsClk)
#define CapSense_BUTTON1_SNS_CLK_OFFSET                     (62u)
#define CapSense_BUTTON1_SNS_CLK_SIZE                       (2u)
#define CapSense_BUTTON1_SNS_CLK_PARAM_ID                   (0xA281003Eu)

#define CapSense_BUTTON1_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button1.snsClkSource)
#define CapSense_BUTTON1_SNS_CLK_SOURCE_OFFSET              (64u)
#define CapSense_BUTTON1_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON1_SNS_CLK_SOURCE_PARAM_ID            (0x4C810040u)

#define CapSense_BUTTON1_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button1.fingerCap)
#define CapSense_BUTTON1_FINGER_CAP_OFFSET                  (66u)
#define CapSense_BUTTON1_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON1_FINGER_CAP_PARAM_ID                (0xAE010042u)

#define CapSense_BUTTON1_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button1.sigPFC)
#define CapSense_BUTTON1_SIGPFC_OFFSET                      (68u)
#define CapSense_BUTTON1_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON1_SIGPFC_PARAM_ID                    (0xA3010044u)

#define CapSense_BUTTON1_GESTURE_ID_VALUE                   (CapSense_dsRam.wdgtList.button1.gestureId)
#define CapSense_BUTTON1_GESTURE_ID_OFFSET                  (70u)
#define CapSense_BUTTON1_GESTURE_ID_SIZE                    (1u)
#define CapSense_BUTTON1_GESTURE_ID_PARAM_ID                (0x67010046u)

#define CapSense_LINEARSLIDER0_RESOLUTION_VALUE             (CapSense_dsRam.wdgtList.linearslider0.resolution)
#define CapSense_LINEARSLIDER0_RESOLUTION_OFFSET            (72u)
#define CapSense_LINEARSLIDER0_RESOLUTION_SIZE              (2u)
#define CapSense_LINEARSLIDER0_RESOLUTION_PARAM_ID          (0x83820048u)

#define CapSense_LINEARSLIDER0_FINGER_TH_VALUE              (CapSense_dsRam.wdgtList.linearslider0.fingerTh)
#define CapSense_LINEARSLIDER0_FINGER_TH_OFFSET             (74u)
#define CapSense_LINEARSLIDER0_FINGER_TH_SIZE               (2u)
#define CapSense_LINEARSLIDER0_FINGER_TH_PARAM_ID           (0x8F82004Au)

#define CapSense_LINEARSLIDER0_NOISE_TH_VALUE               (CapSense_dsRam.wdgtList.linearslider0.noiseTh)
#define CapSense_LINEARSLIDER0_NOISE_TH_OFFSET              (76u)
#define CapSense_LINEARSLIDER0_NOISE_TH_SIZE                (1u)
#define CapSense_LINEARSLIDER0_NOISE_TH_PARAM_ID            (0x4A82004Cu)

#define CapSense_LINEARSLIDER0_NNOISE_TH_VALUE              (CapSense_dsRam.wdgtList.linearslider0.nNoiseTh)
#define CapSense_LINEARSLIDER0_NNOISE_TH_OFFSET             (77u)
#define CapSense_LINEARSLIDER0_NNOISE_TH_SIZE               (1u)
#define CapSense_LINEARSLIDER0_NNOISE_TH_PARAM_ID           (0x4C82004Du)

#define CapSense_LINEARSLIDER0_HYSTERESIS_VALUE             (CapSense_dsRam.wdgtList.linearslider0.hysteresis)
#define CapSense_LINEARSLIDER0_HYSTERESIS_OFFSET            (78u)
#define CapSense_LINEARSLIDER0_HYSTERESIS_SIZE              (1u)
#define CapSense_LINEARSLIDER0_HYSTERESIS_PARAM_ID          (0x4682004Eu)

#define CapSense_LINEARSLIDER0_ON_DEBOUNCE_VALUE            (CapSense_dsRam.wdgtList.linearslider0.onDebounce)
#define CapSense_LINEARSLIDER0_ON_DEBOUNCE_OFFSET           (79u)
#define CapSense_LINEARSLIDER0_ON_DEBOUNCE_SIZE             (1u)
#define CapSense_LINEARSLIDER0_ON_DEBOUNCE_PARAM_ID         (0x4082004Fu)

#define CapSense_LINEARSLIDER0_LOW_BSLN_RST_VALUE           (CapSense_dsRam.wdgtList.linearslider0.lowBslnRst)
#define CapSense_LINEARSLIDER0_LOW_BSLN_RST_OFFSET          (80u)
#define CapSense_LINEARSLIDER0_LOW_BSLN_RST_SIZE            (1u)
#define CapSense_LINEARSLIDER0_LOW_BSLN_RST_PARAM_ID        (0x4C820050u)

#define CapSense_LINEARSLIDER0_IDAC_MOD0_VALUE              (CapSense_dsRam.wdgtList.linearslider0.idacMod[0u])
#define CapSense_LINEARSLIDER0_IDAC_MOD0_OFFSET             (81u)
#define CapSense_LINEARSLIDER0_IDAC_MOD0_SIZE               (1u)
#define CapSense_LINEARSLIDER0_IDAC_MOD0_PARAM_ID           (0x47020051u)

#define CapSense_LINEARSLIDER0_SNS_CLK_VALUE                (CapSense_dsRam.wdgtList.linearslider0.snsClk)
#define CapSense_LINEARSLIDER0_SNS_CLK_OFFSET               (82u)
#define CapSense_LINEARSLIDER0_SNS_CLK_SIZE                 (2u)
#define CapSense_LINEARSLIDER0_SNS_CLK_PARAM_ID             (0x88820052u)

#define CapSense_LINEARSLIDER0_SNS_CLK_SOURCE_VALUE         (CapSense_dsRam.wdgtList.linearslider0.snsClkSource)
#define CapSense_LINEARSLIDER0_SNS_CLK_SOURCE_OFFSET        (84u)
#define CapSense_LINEARSLIDER0_SNS_CLK_SOURCE_SIZE          (1u)
#define CapSense_LINEARSLIDER0_SNS_CLK_SOURCE_PARAM_ID      (0x4D820054u)

#define CapSense_LINEARSLIDER0_FINGER_CAP_VALUE             (CapSense_dsRam.wdgtList.linearslider0.fingerCap)
#define CapSense_LINEARSLIDER0_FINGER_CAP_OFFSET            (86u)
#define CapSense_LINEARSLIDER0_FINGER_CAP_SIZE              (2u)
#define CapSense_LINEARSLIDER0_FINGER_CAP_PARAM_ID          (0xAF020056u)

#define CapSense_LINEARSLIDER0_SIGPFC_VALUE                 (CapSense_dsRam.wdgtList.linearslider0.sigPFC)
#define CapSense_LINEARSLIDER0_SIGPFC_OFFSET                (88u)
#define CapSense_LINEARSLIDER0_SIGPFC_SIZE                  (2u)
#define CapSense_LINEARSLIDER0_SIGPFC_PARAM_ID              (0xA0020058u)

#define CapSense_LINEARSLIDER0_GESTURE_ID_VALUE             (CapSense_dsRam.wdgtList.linearslider0.gestureId)
#define CapSense_LINEARSLIDER0_GESTURE_ID_OFFSET            (90u)
#define CapSense_LINEARSLIDER0_GESTURE_ID_SIZE              (1u)
#define CapSense_LINEARSLIDER0_GESTURE_ID_PARAM_ID          (0x6402005Au)

#define CapSense_LINEARSLIDER0_POSITION0_VALUE              (CapSense_dsRam.wdgtList.linearslider0.position[0u])
#define CapSense_LINEARSLIDER0_POSITION0_OFFSET             (92u)
#define CapSense_LINEARSLIDER0_POSITION0_SIZE               (2u)
#define CapSense_LINEARSLIDER0_POSITION0_PARAM_ID           (0x8A02005Cu)

#define CapSense_BUTTON0_RX0_RAW0_VALUE                     (CapSense_dsRam.snsList.button0[0u].raw[0u])
#define CapSense_BUTTON0_RX0_RAW0_OFFSET                    (94u)
#define CapSense_BUTTON0_RX0_RAW0_SIZE                      (2u)
#define CapSense_BUTTON0_RX0_RAW0_PARAM_ID                  (0x8000005Eu)

#define CapSense_BUTTON0_RX0_BSLN0_VALUE                    (CapSense_dsRam.snsList.button0[0u].bsln[0u])
#define CapSense_BUTTON0_RX0_BSLN0_OFFSET                   (96u)
#define CapSense_BUTTON0_RX0_BSLN0_SIZE                     (2u)
#define CapSense_BUTTON0_RX0_BSLN0_PARAM_ID                 (0x80000060u)

#define CapSense_BUTTON0_RX0_BSLN_EXT0_VALUE                (CapSense_dsRam.snsList.button0[0u].bslnExt[0u])
#define CapSense_BUTTON0_RX0_BSLN_EXT0_OFFSET               (98u)
#define CapSense_BUTTON0_RX0_BSLN_EXT0_SIZE                 (1u)
#define CapSense_BUTTON0_RX0_BSLN_EXT0_PARAM_ID             (0x44000062u)

#define CapSense_BUTTON0_RX0_DIFF_VALUE                     (CapSense_dsRam.snsList.button0[0u].diff)
#define CapSense_BUTTON0_RX0_DIFF_OFFSET                    (100u)
#define CapSense_BUTTON0_RX0_DIFF_SIZE                      (2u)
#define CapSense_BUTTON0_RX0_DIFF_PARAM_ID                  (0x81000064u)

#define CapSense_BUTTON0_RX0_NEG_BSLN_RST_CNT0_VALUE        (CapSense_dsRam.snsList.button0[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON0_RX0_NEG_BSLN_RST_CNT0_OFFSET       (102u)
#define CapSense_BUTTON0_RX0_NEG_BSLN_RST_CNT0_SIZE         (1u)
#define CapSense_BUTTON0_RX0_NEG_BSLN_RST_CNT0_PARAM_ID     (0x45000066u)

#define CapSense_BUTTON0_RX0_IDAC_COMP0_VALUE               (CapSense_dsRam.snsList.button0[0u].idacComp[0u])
#define CapSense_BUTTON0_RX0_IDAC_COMP0_OFFSET              (103u)
#define CapSense_BUTTON0_RX0_IDAC_COMP0_SIZE                (1u)
#define CapSense_BUTTON0_RX0_IDAC_COMP0_PARAM_ID            (0x43000067u)

#define CapSense_BUTTON1_RX0_RAW0_VALUE                     (CapSense_dsRam.snsList.button1[0u].raw[0u])
#define CapSense_BUTTON1_RX0_RAW0_OFFSET                    (104u)
#define CapSense_BUTTON1_RX0_RAW0_SIZE                      (2u)
#define CapSense_BUTTON1_RX0_RAW0_PARAM_ID                  (0x82000068u)

#define CapSense_BUTTON1_RX0_BSLN0_VALUE                    (CapSense_dsRam.snsList.button1[0u].bsln[0u])
#define CapSense_BUTTON1_RX0_BSLN0_OFFSET                   (106u)
#define CapSense_BUTTON1_RX0_BSLN0_SIZE                     (2u)
#define CapSense_BUTTON1_RX0_BSLN0_PARAM_ID                 (0x8E00006Au)

#define CapSense_BUTTON1_RX0_BSLN_EXT0_VALUE                (CapSense_dsRam.snsList.button1[0u].bslnExt[0u])
#define CapSense_BUTTON1_RX0_BSLN_EXT0_OFFSET               (108u)
#define CapSense_BUTTON1_RX0_BSLN_EXT0_SIZE                 (1u)
#define CapSense_BUTTON1_RX0_BSLN_EXT0_PARAM_ID             (0x4B00006Cu)

#define CapSense_BUTTON1_RX0_DIFF_VALUE                     (CapSense_dsRam.snsList.button1[0u].diff)
#define CapSense_BUTTON1_RX0_DIFF_OFFSET                    (110u)
#define CapSense_BUTTON1_RX0_DIFF_SIZE                      (2u)
#define CapSense_BUTTON1_RX0_DIFF_PARAM_ID                  (0x8F00006Eu)

#define CapSense_BUTTON1_RX0_NEG_BSLN_RST_CNT0_VALUE        (CapSense_dsRam.snsList.button1[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON1_RX0_NEG_BSLN_RST_CNT0_OFFSET       (112u)
#define CapSense_BUTTON1_RX0_NEG_BSLN_RST_CNT0_SIZE         (1u)
#define CapSense_BUTTON1_RX0_NEG_BSLN_RST_CNT0_PARAM_ID     (0x4D000070u)

#define CapSense_BUTTON1_RX0_IDAC_COMP0_VALUE               (CapSense_dsRam.snsList.button1[0u].idacComp[0u])
#define CapSense_BUTTON1_RX0_IDAC_COMP0_OFFSET              (113u)
#define CapSense_BUTTON1_RX0_IDAC_COMP0_SIZE                (1u)
#define CapSense_BUTTON1_RX0_IDAC_COMP0_PARAM_ID            (0x4B000071u)

#define CapSense_LINEARSLIDER0_SNS0_RAW0_VALUE              (CapSense_dsRam.snsList.linearslider0[0u].raw[0u])
#define CapSense_LINEARSLIDER0_SNS0_RAW0_OFFSET             (114u)
#define CapSense_LINEARSLIDER0_SNS0_RAW0_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS0_RAW0_PARAM_ID           (0x89000072u)

#define CapSense_LINEARSLIDER0_SNS0_BSLN0_VALUE             (CapSense_dsRam.snsList.linearslider0[0u].bsln[0u])
#define CapSense_LINEARSLIDER0_SNS0_BSLN0_OFFSET            (116u)
#define CapSense_LINEARSLIDER0_SNS0_BSLN0_SIZE              (2u)
#define CapSense_LINEARSLIDER0_SNS0_BSLN0_PARAM_ID          (0x84000074u)

#define CapSense_LINEARSLIDER0_SNS0_BSLN_EXT0_VALUE         (CapSense_dsRam.snsList.linearslider0[0u].bslnExt[0u])
#define CapSense_LINEARSLIDER0_SNS0_BSLN_EXT0_OFFSET        (118u)
#define CapSense_LINEARSLIDER0_SNS0_BSLN_EXT0_SIZE          (1u)
#define CapSense_LINEARSLIDER0_SNS0_BSLN_EXT0_PARAM_ID      (0x40000076u)

#define CapSense_LINEARSLIDER0_SNS0_DIFF_VALUE              (CapSense_dsRam.snsList.linearslider0[0u].diff)
#define CapSense_LINEARSLIDER0_SNS0_DIFF_OFFSET             (120u)
#define CapSense_LINEARSLIDER0_SNS0_DIFF_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS0_DIFF_PARAM_ID           (0x87000078u)

#define CapSense_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_VALUE (CapSense_dsRam.snsList.linearslider0[0u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_OFFSET (122u)
#define CapSense_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_SIZE  (1u)
#define CapSense_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID (0x4300007Au)

#define CapSense_LINEARSLIDER0_SNS0_IDAC_COMP0_VALUE        (CapSense_dsRam.snsList.linearslider0[0u].idacComp[0u])
#define CapSense_LINEARSLIDER0_SNS0_IDAC_COMP0_OFFSET       (123u)
#define CapSense_LINEARSLIDER0_SNS0_IDAC_COMP0_SIZE         (1u)
#define CapSense_LINEARSLIDER0_SNS0_IDAC_COMP0_PARAM_ID     (0x4500007Bu)

#define CapSense_LINEARSLIDER0_SNS1_RAW0_VALUE              (CapSense_dsRam.snsList.linearslider0[1u].raw[0u])
#define CapSense_LINEARSLIDER0_SNS1_RAW0_OFFSET             (124u)
#define CapSense_LINEARSLIDER0_SNS1_RAW0_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS1_RAW0_PARAM_ID           (0x8600007Cu)

#define CapSense_LINEARSLIDER0_SNS1_BSLN0_VALUE             (CapSense_dsRam.snsList.linearslider0[1u].bsln[0u])
#define CapSense_LINEARSLIDER0_SNS1_BSLN0_OFFSET            (126u)
#define CapSense_LINEARSLIDER0_SNS1_BSLN0_SIZE              (2u)
#define CapSense_LINEARSLIDER0_SNS1_BSLN0_PARAM_ID          (0x8A00007Eu)

#define CapSense_LINEARSLIDER0_SNS1_BSLN_EXT0_VALUE         (CapSense_dsRam.snsList.linearslider0[1u].bslnExt[0u])
#define CapSense_LINEARSLIDER0_SNS1_BSLN_EXT0_OFFSET        (128u)
#define CapSense_LINEARSLIDER0_SNS1_BSLN_EXT0_SIZE          (1u)
#define CapSense_LINEARSLIDER0_SNS1_BSLN_EXT0_PARAM_ID      (0x4C000080u)

#define CapSense_LINEARSLIDER0_SNS1_DIFF_VALUE              (CapSense_dsRam.snsList.linearslider0[1u].diff)
#define CapSense_LINEARSLIDER0_SNS1_DIFF_OFFSET             (130u)
#define CapSense_LINEARSLIDER0_SNS1_DIFF_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS1_DIFF_PARAM_ID           (0x88000082u)

#define CapSense_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_VALUE (CapSense_dsRam.snsList.linearslider0[1u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_OFFSET (132u)
#define CapSense_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_SIZE  (1u)
#define CapSense_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_PARAM_ID (0x4D000084u)

#define CapSense_LINEARSLIDER0_SNS1_IDAC_COMP0_VALUE        (CapSense_dsRam.snsList.linearslider0[1u].idacComp[0u])
#define CapSense_LINEARSLIDER0_SNS1_IDAC_COMP0_OFFSET       (133u)
#define CapSense_LINEARSLIDER0_SNS1_IDAC_COMP0_SIZE         (1u)
#define CapSense_LINEARSLIDER0_SNS1_IDAC_COMP0_PARAM_ID     (0x4B000085u)

#define CapSense_LINEARSLIDER0_SNS2_RAW0_VALUE              (CapSense_dsRam.snsList.linearslider0[2u].raw[0u])
#define CapSense_LINEARSLIDER0_SNS2_RAW0_OFFSET             (134u)
#define CapSense_LINEARSLIDER0_SNS2_RAW0_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS2_RAW0_PARAM_ID           (0x89000086u)

#define CapSense_LINEARSLIDER0_SNS2_BSLN0_VALUE             (CapSense_dsRam.snsList.linearslider0[2u].bsln[0u])
#define CapSense_LINEARSLIDER0_SNS2_BSLN0_OFFSET            (136u)
#define CapSense_LINEARSLIDER0_SNS2_BSLN0_SIZE              (2u)
#define CapSense_LINEARSLIDER0_SNS2_BSLN0_PARAM_ID          (0x86000088u)

#define CapSense_LINEARSLIDER0_SNS2_BSLN_EXT0_VALUE         (CapSense_dsRam.snsList.linearslider0[2u].bslnExt[0u])
#define CapSense_LINEARSLIDER0_SNS2_BSLN_EXT0_OFFSET        (138u)
#define CapSense_LINEARSLIDER0_SNS2_BSLN_EXT0_SIZE          (1u)
#define CapSense_LINEARSLIDER0_SNS2_BSLN_EXT0_PARAM_ID      (0x4200008Au)

#define CapSense_LINEARSLIDER0_SNS2_DIFF_VALUE              (CapSense_dsRam.snsList.linearslider0[2u].diff)
#define CapSense_LINEARSLIDER0_SNS2_DIFF_OFFSET             (140u)
#define CapSense_LINEARSLIDER0_SNS2_DIFF_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS2_DIFF_PARAM_ID           (0x8700008Cu)

#define CapSense_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_VALUE (CapSense_dsRam.snsList.linearslider0[2u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_OFFSET (142u)
#define CapSense_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_SIZE  (1u)
#define CapSense_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_PARAM_ID (0x4300008Eu)

#define CapSense_LINEARSLIDER0_SNS2_IDAC_COMP0_VALUE        (CapSense_dsRam.snsList.linearslider0[2u].idacComp[0u])
#define CapSense_LINEARSLIDER0_SNS2_IDAC_COMP0_OFFSET       (143u)
#define CapSense_LINEARSLIDER0_SNS2_IDAC_COMP0_SIZE         (1u)
#define CapSense_LINEARSLIDER0_SNS2_IDAC_COMP0_PARAM_ID     (0x4500008Fu)

#define CapSense_LINEARSLIDER0_SNS3_RAW0_VALUE              (CapSense_dsRam.snsList.linearslider0[3u].raw[0u])
#define CapSense_LINEARSLIDER0_SNS3_RAW0_OFFSET             (144u)
#define CapSense_LINEARSLIDER0_SNS3_RAW0_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS3_RAW0_PARAM_ID           (0x81000090u)

#define CapSense_LINEARSLIDER0_SNS3_BSLN0_VALUE             (CapSense_dsRam.snsList.linearslider0[3u].bsln[0u])
#define CapSense_LINEARSLIDER0_SNS3_BSLN0_OFFSET            (146u)
#define CapSense_LINEARSLIDER0_SNS3_BSLN0_SIZE              (2u)
#define CapSense_LINEARSLIDER0_SNS3_BSLN0_PARAM_ID          (0x8D000092u)

#define CapSense_LINEARSLIDER0_SNS3_BSLN_EXT0_VALUE         (CapSense_dsRam.snsList.linearslider0[3u].bslnExt[0u])
#define CapSense_LINEARSLIDER0_SNS3_BSLN_EXT0_OFFSET        (148u)
#define CapSense_LINEARSLIDER0_SNS3_BSLN_EXT0_SIZE          (1u)
#define CapSense_LINEARSLIDER0_SNS3_BSLN_EXT0_PARAM_ID      (0x48000094u)

#define CapSense_LINEARSLIDER0_SNS3_DIFF_VALUE              (CapSense_dsRam.snsList.linearslider0[3u].diff)
#define CapSense_LINEARSLIDER0_SNS3_DIFF_OFFSET             (150u)
#define CapSense_LINEARSLIDER0_SNS3_DIFF_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS3_DIFF_PARAM_ID           (0x8C000096u)

#define CapSense_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_VALUE (CapSense_dsRam.snsList.linearslider0[3u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_OFFSET (152u)
#define CapSense_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_SIZE  (1u)
#define CapSense_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_PARAM_ID (0x4B000098u)

#define CapSense_LINEARSLIDER0_SNS3_IDAC_COMP0_VALUE        (CapSense_dsRam.snsList.linearslider0[3u].idacComp[0u])
#define CapSense_LINEARSLIDER0_SNS3_IDAC_COMP0_OFFSET       (153u)
#define CapSense_LINEARSLIDER0_SNS3_IDAC_COMP0_SIZE         (1u)
#define CapSense_LINEARSLIDER0_SNS3_IDAC_COMP0_PARAM_ID     (0x4D000099u)

#define CapSense_LINEARSLIDER0_SNS4_RAW0_VALUE              (CapSense_dsRam.snsList.linearslider0[4u].raw[0u])
#define CapSense_LINEARSLIDER0_SNS4_RAW0_OFFSET             (154u)
#define CapSense_LINEARSLIDER0_SNS4_RAW0_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS4_RAW0_PARAM_ID           (0x8F00009Au)

#define CapSense_LINEARSLIDER0_SNS4_BSLN0_VALUE             (CapSense_dsRam.snsList.linearslider0[4u].bsln[0u])
#define CapSense_LINEARSLIDER0_SNS4_BSLN0_OFFSET            (156u)
#define CapSense_LINEARSLIDER0_SNS4_BSLN0_SIZE              (2u)
#define CapSense_LINEARSLIDER0_SNS4_BSLN0_PARAM_ID          (0x8200009Cu)

#define CapSense_LINEARSLIDER0_SNS4_BSLN_EXT0_VALUE         (CapSense_dsRam.snsList.linearslider0[4u].bslnExt[0u])
#define CapSense_LINEARSLIDER0_SNS4_BSLN_EXT0_OFFSET        (158u)
#define CapSense_LINEARSLIDER0_SNS4_BSLN_EXT0_SIZE          (1u)
#define CapSense_LINEARSLIDER0_SNS4_BSLN_EXT0_PARAM_ID      (0x4600009Eu)

#define CapSense_LINEARSLIDER0_SNS4_DIFF_VALUE              (CapSense_dsRam.snsList.linearslider0[4u].diff)
#define CapSense_LINEARSLIDER0_SNS4_DIFF_OFFSET             (160u)
#define CapSense_LINEARSLIDER0_SNS4_DIFF_SIZE               (2u)
#define CapSense_LINEARSLIDER0_SNS4_DIFF_PARAM_ID           (0x8E0000A0u)

#define CapSense_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_VALUE (CapSense_dsRam.snsList.linearslider0[4u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_OFFSET (162u)
#define CapSense_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_SIZE  (1u)
#define CapSense_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_PARAM_ID (0x4A0000A2u)

#define CapSense_LINEARSLIDER0_SNS4_IDAC_COMP0_VALUE        (CapSense_dsRam.snsList.linearslider0[4u].idacComp[0u])
#define CapSense_LINEARSLIDER0_SNS4_IDAC_COMP0_OFFSET       (163u)
#define CapSense_LINEARSLIDER0_SNS4_IDAC_COMP0_SIZE         (1u)
#define CapSense_LINEARSLIDER0_SNS4_IDAC_COMP0_PARAM_ID     (0x4C0000A3u)

#define CapSense_LINEARSLIDER0_SIZE_VALUE                   (CapSense_dsRam.gestures.size)
#define CapSense_LINEARSLIDER0_SIZE_OFFSET                  (164u)
#define CapSense_LINEARSLIDER0_SIZE_SIZE                    (1u)
#define CapSense_LINEARSLIDER0_SIZE_PARAM_ID                (0x6A0200A4u)

#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_X_VALUE  (CapSense_dsRam.gestures.panActiveDistanceX)
#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_X_OFFSET (165u)
#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_X_SIZE   (1u)
#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_X_PARAM_ID (0x6C0200A5u)

#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_Y_VALUE  (CapSense_dsRam.gestures.panActiveDistanceY)
#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_Y_OFFSET (166u)
#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_Y_SIZE   (1u)
#define CapSense_LINEARSLIDER0_PAN_ACTIVE_DISTANCE_Y_PARAM_ID (0x660200A6u)

#define CapSense_LINEARSLIDER0_DTZM_XPOS_TH_VALUE           (CapSense_dsRam.gestures.zoomActiveDistanceX)
#define CapSense_LINEARSLIDER0_DTZM_XPOS_TH_OFFSET          (167u)
#define CapSense_LINEARSLIDER0_DTZM_XPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_DTZM_XPOS_TH_PARAM_ID        (0x600200A7u)

#define CapSense_LINEARSLIDER0_DTZM_YPOS_TH_VALUE           (CapSense_dsRam.gestures.zoomActiveDistanceY)
#define CapSense_LINEARSLIDER0_DTZM_YPOS_TH_OFFSET          (168u)
#define CapSense_LINEARSLIDER0_DTZM_YPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_DTZM_YPOS_TH_PARAM_ID        (0x690200A8u)

#define CapSense_LINEARSLIDER0_STFK_POS_TH_VALUE            (CapSense_dsRam.gestures.flickActiveDistanceX)
#define CapSense_LINEARSLIDER0_STFK_POS_TH_OFFSET           (169u)
#define CapSense_LINEARSLIDER0_STFK_POS_TH_SIZE             (1u)
#define CapSense_LINEARSLIDER0_STFK_POS_TH_PARAM_ID         (0x6F0200A9u)

#define CapSense_LINEARSLIDER0_STFK_YPOS_TH_VALUE           (CapSense_dsRam.gestures.flickActiveDistanceY)
#define CapSense_LINEARSLIDER0_STFK_YPOS_TH_OFFSET          (170u)
#define CapSense_LINEARSLIDER0_STFK_YPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_STFK_YPOS_TH_PARAM_ID        (0x650200AAu)

#define CapSense_LINEARSLIDER0_STSL_XPOS_TH1_VALUE          (CapSense_dsRam.gestures.stScrollThreshold1X)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH1_OFFSET         (171u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH1_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH1_PARAM_ID       (0x630200ABu)

#define CapSense_LINEARSLIDER0_STSL_XPOS_TH2_VALUE          (CapSense_dsRam.gestures.stScrollThreshold2X)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH2_OFFSET         (172u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH2_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH2_PARAM_ID       (0x680200ACu)

#define CapSense_LINEARSLIDER0_STSL_XPOS_TH3_VALUE          (CapSense_dsRam.gestures.stScrollThreshold3X)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH3_OFFSET         (173u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH3_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH3_PARAM_ID       (0x6E0200ADu)

#define CapSense_LINEARSLIDER0_STSL_XPOS_TH4_VALUE          (CapSense_dsRam.gestures.stScrollThreshold4X)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH4_OFFSET         (174u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH4_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH4_PARAM_ID       (0x640200AEu)

#define CapSense_LINEARSLIDER0_STSL_YPOS_TH1_VALUE          (CapSense_dsRam.gestures.stScrollThreshold1Y)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH1_OFFSET         (175u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH1_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH1_PARAM_ID       (0x620200AFu)

#define CapSense_LINEARSLIDER0_STSL_YPOS_TH2_VALUE          (CapSense_dsRam.gestures.stScrollThreshold2Y)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH2_OFFSET         (176u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH2_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH2_PARAM_ID       (0x6E0200B0u)

#define CapSense_LINEARSLIDER0_STSL_YPOS_TH3_VALUE          (CapSense_dsRam.gestures.stScrollThreshold3Y)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH3_OFFSET         (177u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH3_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH3_PARAM_ID       (0x680200B1u)

#define CapSense_LINEARSLIDER0_STSL_YPOS_TH4_VALUE          (CapSense_dsRam.gestures.stScrollThreshold4Y)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH4_OFFSET         (178u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH4_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH4_PARAM_ID       (0x620200B2u)

#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP1_VALUE      (CapSense_dsRam.gestures.stScrollStep1)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP1_OFFSET     (179u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP1_SIZE       (1u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP1_PARAM_ID   (0x640200B3u)

#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP2_VALUE      (CapSense_dsRam.gestures.stScrollStep2)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP2_OFFSET     (180u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP2_SIZE       (1u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP2_PARAM_ID   (0x6F0200B4u)

#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP3_VALUE      (CapSense_dsRam.gestures.stScrollStep3)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP3_OFFSET     (181u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP3_SIZE       (1u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP3_PARAM_ID   (0x690200B5u)

#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP4_VALUE      (CapSense_dsRam.gestures.stScrollStep4)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP4_OFFSET     (182u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP4_SIZE       (1u)
#define CapSense_LINEARSLIDER0_STSL_SCROLL_STEP4_PARAM_ID   (0x630200B6u)

#define CapSense_LINEARSLIDER0_STSL_DEBOUNCE_VALUE          (CapSense_dsRam.gestures.stScrollDebounce)
#define CapSense_LINEARSLIDER0_STSL_DEBOUNCE_OFFSET         (183u)
#define CapSense_LINEARSLIDER0_STSL_DEBOUNCE_SIZE           (1u)
#define CapSense_LINEARSLIDER0_STSL_DEBOUNCE_PARAM_ID       (0x650200B7u)

#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH1_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold1X)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH1_OFFSET         (184u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH1_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH1_PARAM_ID       (0x6C0200B8u)

#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH2_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold2X)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH2_OFFSET         (185u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH2_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH2_PARAM_ID       (0x6A0200B9u)

#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH3_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold3X)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH3_OFFSET         (186u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH3_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH3_PARAM_ID       (0x600200BAu)

#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH4_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold4X)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH4_OFFSET         (187u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH4_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH4_PARAM_ID       (0x660200BBu)

#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH1_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold1Y)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH1_OFFSET         (188u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH1_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH1_PARAM_ID       (0x6D0200BCu)

#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH2_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold2Y)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH2_OFFSET         (189u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH2_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH2_PARAM_ID       (0x6B0200BDu)

#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH3_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold3Y)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH3_OFFSET         (190u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH3_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH3_PARAM_ID       (0x610200BEu)

#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH4_VALUE          (CapSense_dsRam.gestures.dtScrollThreshold4Y)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH4_OFFSET         (191u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH4_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH4_PARAM_ID       (0x670200BFu)

#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP1_VALUE      (CapSense_dsRam.gestures.dtScrollStep1)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP1_OFFSET     (192u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP1_SIZE       (1u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP1_PARAM_ID   (0x6C0200C0u)

#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP2_VALUE      (CapSense_dsRam.gestures.dtScrollStep2)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP2_OFFSET     (193u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP2_SIZE       (1u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP2_PARAM_ID   (0x6A0200C1u)

#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP3_VALUE      (CapSense_dsRam.gestures.dtScrollStep3)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP3_OFFSET     (194u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP3_SIZE       (1u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP3_PARAM_ID   (0x600200C2u)

#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP4_VALUE      (CapSense_dsRam.gestures.dtScrollStep4)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP4_OFFSET     (195u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP4_SIZE       (1u)
#define CapSense_LINEARSLIDER0_DTSL_SCROLL_STEP4_PARAM_ID   (0x660200C3u)

#define CapSense_LINEARSLIDER0_DTSL_DEBOUNCE_VALUE          (CapSense_dsRam.gestures.dtScrollDebounce)
#define CapSense_LINEARSLIDER0_DTSL_DEBOUNCE_OFFSET         (196u)
#define CapSense_LINEARSLIDER0_DTSL_DEBOUNCE_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTSL_DEBOUNCE_PARAM_ID       (0x6D0200C4u)

#define CapSense_LINEARSLIDER0_DTZM_SCROLL_ZOOM_DEBOUNCE_VALUE (CapSense_dsRam.gestures.dtScrollToZoomDebounce)
#define CapSense_LINEARSLIDER0_DTZM_SCROLL_ZOOM_DEBOUNCE_OFFSET (197u)
#define CapSense_LINEARSLIDER0_DTZM_SCROLL_ZOOM_DEBOUNCE_SIZE (1u)
#define CapSense_LINEARSLIDER0_DTZM_SCROLL_ZOOM_DEBOUNCE_PARAM_ID (0x6B0200C5u)

#define CapSense_LINEARSLIDER0_STSL_XPOS_TH_VALUE           (CapSense_dsRam.gestures.stInScrActiveDistanceX)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH_OFFSET          (198u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_STSL_XPOS_TH_PARAM_ID        (0x610200C6u)

#define CapSense_LINEARSLIDER0_STSL_YPOS_TH_VALUE           (CapSense_dsRam.gestures.stInScrActiveDistanceY)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH_OFFSET          (199u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_STSL_YPOS_TH_PARAM_ID        (0x670200C7u)

#define CapSense_LINEARSLIDER0_STSL_COUNT_LEVEL_VALUE       (CapSense_dsRam.gestures.stInScrCountLevel)
#define CapSense_LINEARSLIDER0_STSL_COUNT_LEVEL_OFFSET      (200u)
#define CapSense_LINEARSLIDER0_STSL_COUNT_LEVEL_SIZE        (1u)
#define CapSense_LINEARSLIDER0_STSL_COUNT_LEVEL_PARAM_ID    (0x6E0200C8u)

#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH_VALUE           (CapSense_dsRam.gestures.dtInScrActiveDistanceX)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH_OFFSET          (201u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_DTSL_XPOS_TH_PARAM_ID        (0x680200C9u)

#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH_VALUE           (CapSense_dsRam.gestures.dtInScrActiveDistanceY)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH_OFFSET          (202u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH_SIZE            (1u)
#define CapSense_LINEARSLIDER0_DTSL_YPOS_TH_PARAM_ID        (0x620200CAu)

#define CapSense_LINEARSLIDER0_DTSL_COUNT_LEVEL_VALUE       (CapSense_dsRam.gestures.dtInScrCountLevel)
#define CapSense_LINEARSLIDER0_DTSL_COUNT_LEVEL_OFFSET      (203u)
#define CapSense_LINEARSLIDER0_DTSL_COUNT_LEVEL_SIZE        (1u)
#define CapSense_LINEARSLIDER0_DTSL_COUNT_LEVEL_PARAM_ID    (0x640200CBu)

#define CapSense_LINEARSLIDER0_STES_POS_TH_VALUE            (CapSense_dsRam.gestures.edgeSwipeActiveDistance)
#define CapSense_LINEARSLIDER0_STES_POS_TH_OFFSET           (204u)
#define CapSense_LINEARSLIDER0_STES_POS_TH_SIZE             (1u)
#define CapSense_LINEARSLIDER0_STES_POS_TH_PARAM_ID         (0x6F0200CCu)

#define CapSense_LINEARSLIDER0_STES_TOP_ANGLE_TH_VALUE      (CapSense_dsRam.gestures.topAngleThreshold)
#define CapSense_LINEARSLIDER0_STES_TOP_ANGLE_TH_OFFSET     (205u)
#define CapSense_LINEARSLIDER0_STES_TOP_ANGLE_TH_SIZE       (1u)
#define CapSense_LINEARSLIDER0_STES_TOP_ANGLE_TH_PARAM_ID   (0x690200CDu)

#define CapSense_LINEARSLIDER0_STES_BOTTOM_ANGLE_TH_VALUE   (CapSense_dsRam.gestures.bottomAngleThreshold)
#define CapSense_LINEARSLIDER0_STES_BOTTOM_ANGLE_TH_OFFSET  (206u)
#define CapSense_LINEARSLIDER0_STES_BOTTOM_ANGLE_TH_SIZE    (1u)
#define CapSense_LINEARSLIDER0_STES_BOTTOM_ANGLE_TH_PARAM_ID (0x630200CEu)

#define CapSense_LINEARSLIDER0_STES_DISAM_AREA_WIDTH_VALUE  (CapSense_dsRam.gestures.widthOfDisambiguation)
#define CapSense_LINEARSLIDER0_STES_DISAM_AREA_WIDTH_OFFSET (207u)
#define CapSense_LINEARSLIDER0_STES_DISAM_AREA_WIDTH_SIZE   (1u)
#define CapSense_LINEARSLIDER0_STES_DISAM_AREA_WIDTH_PARAM_ID (0x650200CFu)

#define CapSense_LINEARSLIDER0_ST_PAN_DEBOUNCE_VALUE        (CapSense_dsRam.gestures.stPanDebounce)
#define CapSense_LINEARSLIDER0_ST_PAN_DEBOUNCE_OFFSET       (208u)
#define CapSense_LINEARSLIDER0_ST_PAN_DEBOUNCE_SIZE         (1u)
#define CapSense_LINEARSLIDER0_ST_PAN_DEBOUNCE_PARAM_ID     (0x690200D0u)

#define CapSense_LINEARSLIDER0_DT_PAN_DEBOUNCE_VALUE        (CapSense_dsRam.gestures.dtPanDebounce)
#define CapSense_LINEARSLIDER0_DT_PAN_DEBOUNCE_OFFSET       (209u)
#define CapSense_LINEARSLIDER0_DT_PAN_DEBOUNCE_SIZE         (1u)
#define CapSense_LINEARSLIDER0_DT_PAN_DEBOUNCE_PARAM_ID     (0x6F0200D1u)

#define CapSense_LINEARSLIDER0_DTZM_DEBOUNCE_VALUE          (CapSense_dsRam.gestures.dtZoomDebounce)
#define CapSense_LINEARSLIDER0_DTZM_DEBOUNCE_OFFSET         (210u)
#define CapSense_LINEARSLIDER0_DTZM_DEBOUNCE_SIZE           (1u)
#define CapSense_LINEARSLIDER0_DTZM_DEBOUNCE_PARAM_ID       (0x650200D2u)

#define CapSense_LINEARSLIDER0_DT_PAN_TO_ZOOM_DEBOUNCE_VALUE (CapSense_dsRam.gestures.dtPanToZoomDebounce)
#define CapSense_LINEARSLIDER0_DT_PAN_TO_ZOOM_DEBOUNCE_OFFSET (211u)
#define CapSense_LINEARSLIDER0_DT_PAN_TO_ZOOM_DEBOUNCE_SIZE (1u)
#define CapSense_LINEARSLIDER0_DT_PAN_TO_ZOOM_DEBOUNCE_PARAM_ID (0x630200D3u)

#define CapSense_LINEARSLIDER0_STRT_ROTATE_DEBOUNCE_VALUE   (CapSense_dsRam.gestures.rotateDebounce)
#define CapSense_LINEARSLIDER0_STRT_ROTATE_DEBOUNCE_OFFSET  (212u)
#define CapSense_LINEARSLIDER0_STRT_ROTATE_DEBOUNCE_SIZE    (1u)
#define CapSense_LINEARSLIDER0_STRT_ROTATE_DEBOUNCE_PARAM_ID (0x680200D4u)

#define CapSense_LINEARSLIDER0_COMPLETED_DEBOUNCE_VALUE     (CapSense_dsRam.gestures.completedDebounce)
#define CapSense_LINEARSLIDER0_COMPLETED_DEBOUNCE_OFFSET    (213u)
#define CapSense_LINEARSLIDER0_COMPLETED_DEBOUNCE_SIZE      (1u)
#define CapSense_LINEARSLIDER0_COMPLETED_DEBOUNCE_PARAM_ID  (0x6E0200D5u)

#define CapSense_LINEARSLIDER0_STDC_MAX_RADIUS_DISPLACEMENT_VALUE (CapSense_dsRam.gestures.doubleClickRadius)
#define CapSense_LINEARSLIDER0_STDC_MAX_RADIUS_DISPLACEMENT_OFFSET (214u)
#define CapSense_LINEARSLIDER0_STDC_MAX_RADIUS_DISPLACEMENT_SIZE (1u)
#define CapSense_LINEARSLIDER0_STDC_MAX_RADIUS_DISPLACEMENT_PARAM_ID (0x640200D6u)

#define CapSense_LINEARSLIDER0_STSC_XMAX_POS_DISPLACEMENT_VALUE (CapSense_dsRam.gestures.clickRadiusX)
#define CapSense_LINEARSLIDER0_STSC_XMAX_POS_DISPLACEMENT_OFFSET (215u)
#define CapSense_LINEARSLIDER0_STSC_XMAX_POS_DISPLACEMENT_SIZE (1u)
#define CapSense_LINEARSLIDER0_STSC_XMAX_POS_DISPLACEMENT_PARAM_ID (0x620200D7u)

#define CapSense_LINEARSLIDER0_STSC_YMAX_POS_DISPLACEMENT_VALUE (CapSense_dsRam.gestures.clickRadiusY)
#define CapSense_LINEARSLIDER0_STSC_YMAX_POS_DISPLACEMENT_OFFSET (216u)
#define CapSense_LINEARSLIDER0_STSC_YMAX_POS_DISPLACEMENT_SIZE (1u)
#define CapSense_LINEARSLIDER0_STSC_YMAX_POS_DISPLACEMENT_PARAM_ID (0x6B0200D8u)

#define CapSense_LINEARSLIDER0_DT_SETTLING_TIME_VALUE       (CapSense_dsRam.gestures.settlingTimeout)
#define CapSense_LINEARSLIDER0_DT_SETTLING_TIME_OFFSET      (218u)
#define CapSense_LINEARSLIDER0_DT_SETTLING_TIME_SIZE        (2u)
#define CapSense_LINEARSLIDER0_DT_SETTLING_TIME_PARAM_ID    (0xAF0200DAu)

#define CapSense_LINEARSLIDER0_GES_X_RESOLUTION_VALUE       (CapSense_dsRam.gestures.resolutionX)
#define CapSense_LINEARSLIDER0_GES_X_RESOLUTION_OFFSET      (220u)
#define CapSense_LINEARSLIDER0_GES_X_RESOLUTION_SIZE        (2u)
#define CapSense_LINEARSLIDER0_GES_X_RESOLUTION_PARAM_ID    (0xA20200DCu)

#define CapSense_LINEARSLIDER0_GES_Y_RESOLUTION_VALUE       (CapSense_dsRam.gestures.resolutionY)
#define CapSense_LINEARSLIDER0_GES_Y_RESOLUTION_OFFSET      (222u)
#define CapSense_LINEARSLIDER0_GES_Y_RESOLUTION_SIZE        (2u)
#define CapSense_LINEARSLIDER0_GES_Y_RESOLUTION_PARAM_ID    (0xAE0200DEu)

#define CapSense_LINEARSLIDER0_STFK_MAX_SAMPLE_INTERVAL_VALUE (CapSense_dsRam.gestures.flickSampleTime)
#define CapSense_LINEARSLIDER0_STFK_MAX_SAMPLE_INTERVAL_OFFSET (224u)
#define CapSense_LINEARSLIDER0_STFK_MAX_SAMPLE_INTERVAL_SIZE (2u)
#define CapSense_LINEARSLIDER0_STFK_MAX_SAMPLE_INTERVAL_PARAM_ID (0xAE0200E0u)

#define CapSense_LINEARSLIDER0_STES_TIMEOUT_INTERVAL_VALUE  (CapSense_dsRam.gestures.edgeSwipeTimeout)
#define CapSense_LINEARSLIDER0_STES_TIMEOUT_INTERVAL_OFFSET (226u)
#define CapSense_LINEARSLIDER0_STES_TIMEOUT_INTERVAL_SIZE   (2u)
#define CapSense_LINEARSLIDER0_STES_TIMEOUT_INTERVAL_PARAM_ID (0xA20200E2u)

#define CapSense_LINEARSLIDER0_DTSC_MAX_TOUCH_DURATION_VALUE (CapSense_dsRam.gestures.dtClickTimeoutMax)
#define CapSense_LINEARSLIDER0_DTSC_MAX_TOUCH_DURATION_OFFSET (228u)
#define CapSense_LINEARSLIDER0_DTSC_MAX_TOUCH_DURATION_SIZE (2u)
#define CapSense_LINEARSLIDER0_DTSC_MAX_TOUCH_DURATION_PARAM_ID (0xAF0200E4u)

#define CapSense_LINEARSLIDER0_DTSC_MIN_TOUCH_DURATION_VALUE (CapSense_dsRam.gestures.dtClickTimeoutMin)
#define CapSense_LINEARSLIDER0_DTSC_MIN_TOUCH_DURATION_OFFSET (230u)
#define CapSense_LINEARSLIDER0_DTSC_MIN_TOUCH_DURATION_SIZE (2u)
#define CapSense_LINEARSLIDER0_DTSC_MIN_TOUCH_DURATION_PARAM_ID (0xA30200E6u)

#define CapSense_LINEARSLIDER0_STSC_MAX_TOUCH_DURATION_VALUE (CapSense_dsRam.gestures.stClickTimeoutMax)
#define CapSense_LINEARSLIDER0_STSC_MAX_TOUCH_DURATION_OFFSET (232u)
#define CapSense_LINEARSLIDER0_STSC_MAX_TOUCH_DURATION_SIZE (2u)
#define CapSense_LINEARSLIDER0_STSC_MAX_TOUCH_DURATION_PARAM_ID (0xAC0200E8u)

#define CapSense_LINEARSLIDER0_STSC_MIN_TOUCH_DURATION_VALUE (CapSense_dsRam.gestures.stClickTimeoutMin)
#define CapSense_LINEARSLIDER0_STSC_MIN_TOUCH_DURATION_OFFSET (234u)
#define CapSense_LINEARSLIDER0_STSC_MIN_TOUCH_DURATION_SIZE (2u)
#define CapSense_LINEARSLIDER0_STSC_MIN_TOUCH_DURATION_PARAM_ID (0xA00200EAu)

#define CapSense_LINEARSLIDER0_STDC_MAX_TOUCH_INTERVAL_VALUE (CapSense_dsRam.gestures.stDoubleClickTimeoutMax)
#define CapSense_LINEARSLIDER0_STDC_MAX_TOUCH_INTERVAL_OFFSET (236u)
#define CapSense_LINEARSLIDER0_STDC_MAX_TOUCH_INTERVAL_SIZE (2u)
#define CapSense_LINEARSLIDER0_STDC_MAX_TOUCH_INTERVAL_PARAM_ID (0xAD0200ECu)

#define CapSense_LINEARSLIDER0_STDC_MIN_TOUCH_INTERVAL_VALUE (CapSense_dsRam.gestures.stDoubleClickTimeoutMin)
#define CapSense_LINEARSLIDER0_STDC_MIN_TOUCH_INTERVAL_OFFSET (238u)
#define CapSense_LINEARSLIDER0_STDC_MIN_TOUCH_INTERVAL_SIZE (2u)
#define CapSense_LINEARSLIDER0_STDC_MIN_TOUCH_INTERVAL_PARAM_ID (0xA10200EEu)

#define CapSense_LINEARSLIDER0_GROUP_MASK_VALUE             (CapSense_dsRam.gestures.groupMask)
#define CapSense_LINEARSLIDER0_GROUP_MASK_OFFSET            (240u)
#define CapSense_LINEARSLIDER0_GROUP_MASK_SIZE              (1u)
#define CapSense_LINEARSLIDER0_GROUP_MASK_PARAM_ID          (0x630200F0u)

#define CapSense_LINEARSLIDER0_GROUP1_START_VALUE           (CapSense_dsRam.gestures.group1Start)
#define CapSense_LINEARSLIDER0_GROUP1_START_OFFSET          (241u)
#define CapSense_LINEARSLIDER0_GROUP1_START_SIZE            (1u)
#define CapSense_LINEARSLIDER0_GROUP1_START_PARAM_ID        (0x650200F1u)

#define CapSense_LINEARSLIDER0_GROUP1_END_VALUE             (CapSense_dsRam.gestures.group1End)
#define CapSense_LINEARSLIDER0_GROUP1_END_OFFSET            (242u)
#define CapSense_LINEARSLIDER0_GROUP1_END_SIZE              (1u)
#define CapSense_LINEARSLIDER0_GROUP1_END_PARAM_ID          (0x6F0200F2u)

#define CapSense_LINEARSLIDER0_GROUP2_START_VALUE           (CapSense_dsRam.gestures.group2Start)
#define CapSense_LINEARSLIDER0_GROUP2_START_OFFSET          (243u)
#define CapSense_LINEARSLIDER0_GROUP2_START_SIZE            (1u)
#define CapSense_LINEARSLIDER0_GROUP2_START_PARAM_ID        (0x690200F3u)

#define CapSense_LINEARSLIDER0_GROUP2_END_VALUE             (CapSense_dsRam.gestures.group2End)
#define CapSense_LINEARSLIDER0_GROUP2_END_OFFSET            (244u)
#define CapSense_LINEARSLIDER0_GROUP2_END_SIZE              (1u)
#define CapSense_LINEARSLIDER0_GROUP2_END_PARAM_ID          (0x620200F4u)

#define CapSense_LINEARSLIDER0_GROUP3_START_VALUE           (CapSense_dsRam.gestures.group3Start)
#define CapSense_LINEARSLIDER0_GROUP3_START_OFFSET          (245u)
#define CapSense_LINEARSLIDER0_GROUP3_START_SIZE            (1u)
#define CapSense_LINEARSLIDER0_GROUP3_START_PARAM_ID        (0x640200F5u)

#define CapSense_LINEARSLIDER0_GROUP3_END_VALUE             (CapSense_dsRam.gestures.group3End)
#define CapSense_LINEARSLIDER0_GROUP3_END_OFFSET            (246u)
#define CapSense_LINEARSLIDER0_GROUP3_END_SIZE              (1u)
#define CapSense_LINEARSLIDER0_GROUP3_END_PARAM_ID          (0x6E0200F6u)

#define CapSense_LINEARSLIDER0_GROUP4_START_VALUE           (CapSense_dsRam.gestures.group4Start)
#define CapSense_LINEARSLIDER0_GROUP4_START_OFFSET          (247u)
#define CapSense_LINEARSLIDER0_GROUP4_START_SIZE            (1u)
#define CapSense_LINEARSLIDER0_GROUP4_START_PARAM_ID        (0x680200F7u)

#define CapSense_LINEARSLIDER0_GROUP4_END_VALUE             (CapSense_dsRam.gestures.group4End)
#define CapSense_LINEARSLIDER0_GROUP4_END_OFFSET            (248u)
#define CapSense_LINEARSLIDER0_GROUP4_END_SIZE              (1u)
#define CapSense_LINEARSLIDER0_GROUP4_END_PARAM_ID          (0x610200F8u)

#define CapSense_TIMESTAMP_INTERVAL_VALUE                   (CapSense_dsRam.timestampInterval)
#define CapSense_TIMESTAMP_INTERVAL_OFFSET                  (252u)
#define CapSense_TIMESTAMP_INTERVAL_SIZE                    (4u)
#define CapSense_TIMESTAMP_INTERVAL_PARAM_ID                (0xCA0000FCu)

#define CapSense_TIMESTAMP_VALUE                            (CapSense_dsRam.timestamp)
#define CapSense_TIMESTAMP_OFFSET                           (256u)
#define CapSense_TIMESTAMP_SIZE                             (4u)
#define CapSense_TIMESTAMP_PARAM_ID                         (0xC3000100u)

#define CapSense_SNR_TEST_WIDGET_ID_VALUE                   (CapSense_dsRam.snrTestWidgetId)
#define CapSense_SNR_TEST_WIDGET_ID_OFFSET                  (260u)
#define CapSense_SNR_TEST_WIDGET_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_WIDGET_ID_PARAM_ID                (0x6E000104u)

#define CapSense_SNR_TEST_SENSOR_ID_VALUE                   (CapSense_dsRam.snrTestSensorId)
#define CapSense_SNR_TEST_SENSOR_ID_OFFSET                  (261u)
#define CapSense_SNR_TEST_SENSOR_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_SENSOR_ID_PARAM_ID                (0x68000105u)

#define CapSense_SNR_TEST_SCAN_COUNTER_VALUE                (CapSense_dsRam.snrTestScanCounter)
#define CapSense_SNR_TEST_SCAN_COUNTER_OFFSET               (262u)
#define CapSense_SNR_TEST_SCAN_COUNTER_SIZE                 (2u)
#define CapSense_SNR_TEST_SCAN_COUNTER_PARAM_ID             (0x81000106u)

#define CapSense_SNR_TEST_RAW_COUNT0_VALUE                  (CapSense_dsRam.snrTestRawCount[0u])
#define CapSense_SNR_TEST_RAW_COUNT0_OFFSET                 (264u)
#define CapSense_SNR_TEST_RAW_COUNT0_SIZE                   (2u)
#define CapSense_SNR_TEST_RAW_COUNT0_PARAM_ID               (0x8E000108u)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define CapSense_BUTTON0_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define CapSense_BUTTON0_PTR2SNS_FLASH_OFFSET               (0u)
#define CapSense_BUTTON0_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON0_PTR2SNS_FLASH_PARAM_ID             (0xD1000000u)

#define CapSense_BUTTON0_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define CapSense_BUTTON0_PTR2WD_RAM_OFFSET                  (4u)
#define CapSense_BUTTON0_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON0_PTR2WD_RAM_PARAM_ID                (0xD0000004u)

#define CapSense_BUTTON0_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define CapSense_BUTTON0_PTR2SNS_RAM_OFFSET                 (8u)
#define CapSense_BUTTON0_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON0_PTR2SNS_RAM_PARAM_ID               (0xD3000008u)

#define CapSense_BUTTON0_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define CapSense_BUTTON0_PTR2FLTR_HISTORY_OFFSET            (12u)
#define CapSense_BUTTON0_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON0_PTR2FLTR_HISTORY_PARAM_ID          (0xD200000Cu)

#define CapSense_BUTTON0_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define CapSense_BUTTON0_PTR2DEBOUNCE_OFFSET                (16u)
#define CapSense_BUTTON0_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON0_PTR2DEBOUNCE_PARAM_ID              (0xD4000010u)

#define CapSense_BUTTON0_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[0].staticConfig)
#define CapSense_BUTTON0_STATIC_CONFIG_OFFSET               (20u)
#define CapSense_BUTTON0_STATIC_CONFIG_SIZE                 (4u)
#define CapSense_BUTTON0_STATIC_CONFIG_PARAM_ID             (0xD5000014u)

#define CapSense_BUTTON0_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[0].totalNumSns)
#define CapSense_BUTTON0_TOTAL_NUM_SNS_OFFSET               (24u)
#define CapSense_BUTTON0_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON0_TOTAL_NUM_SNS_PARAM_ID             (0x99000018u)

#define CapSense_BUTTON0_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[0].wdgtType)
#define CapSense_BUTTON0_TYPE_OFFSET                        (26u)
#define CapSense_BUTTON0_TYPE_SIZE                          (1u)
#define CapSense_BUTTON0_TYPE_PARAM_ID                      (0x5D00001Au)

#define CapSense_BUTTON0_SENSE_METHOD_VALUE                 (CapSense_dsFlash.wdgtArray[0].senseMethod)
#define CapSense_BUTTON0_SENSE_METHOD_OFFSET                (27u)
#define CapSense_BUTTON0_SENSE_METHOD_SIZE                  (1u)
#define CapSense_BUTTON0_SENSE_METHOD_PARAM_ID              (0x5B00001Bu)

#define CapSense_BUTTON0_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[0].numCols)
#define CapSense_BUTTON0_NUM_COLS_OFFSET                    (28u)
#define CapSense_BUTTON0_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON0_NUM_COLS_PARAM_ID                  (0x5000001Cu)

#define CapSense_BUTTON0_NUM_ROWS_VALUE                     (CapSense_dsFlash.wdgtArray[0].numRows)
#define CapSense_BUTTON0_NUM_ROWS_OFFSET                    (29u)
#define CapSense_BUTTON0_NUM_ROWS_SIZE                      (1u)
#define CapSense_BUTTON0_NUM_ROWS_PARAM_ID                  (0x5600001Du)

#define CapSense_BUTTON0_X_RESOLUTION_VALUE                 (CapSense_dsFlash.wdgtArray[0].xResolution)
#define CapSense_BUTTON0_X_RESOLUTION_OFFSET                (30u)
#define CapSense_BUTTON0_X_RESOLUTION_SIZE                  (2u)
#define CapSense_BUTTON0_X_RESOLUTION_PARAM_ID              (0x9400001Eu)

#define CapSense_BUTTON0_X_CENT_MULT_VALUE                  (CapSense_dsFlash.wdgtArray[0].xCentroidMultiplier)
#define CapSense_BUTTON0_X_CENT_MULT_OFFSET                 (32u)
#define CapSense_BUTTON0_X_CENT_MULT_SIZE                   (4u)
#define CapSense_BUTTON0_X_CENT_MULT_PARAM_ID               (0xDB000020u)

#define CapSense_BUTTON0_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[0].ptr2NoiseEnvlp)
#define CapSense_BUTTON0_PTR2NOISE_ENVLP_OFFSET             (36u)
#define CapSense_BUTTON0_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON0_PTR2NOISE_ENVLP_PARAM_ID           (0xDA000024u)

#define CapSense_BUTTON0_PTR2POS_HISTORY_VALUE              (CapSense_dsFlash.wdgtArray[0].ptr2PosHistory)
#define CapSense_BUTTON0_PTR2POS_HISTORY_OFFSET             (40u)
#define CapSense_BUTTON0_PTR2POS_HISTORY_SIZE               (4u)
#define CapSense_BUTTON0_PTR2POS_HISTORY_PARAM_ID           (0xD9000028u)

#define CapSense_BUTTON0_IIR_FILTER_COEFF_VALUE             (CapSense_dsFlash.wdgtArray[0].iirFilterCoeff)
#define CapSense_BUTTON0_IIR_FILTER_COEFF_OFFSET            (44u)
#define CapSense_BUTTON0_IIR_FILTER_COEFF_SIZE              (1u)
#define CapSense_BUTTON0_IIR_FILTER_COEFF_PARAM_ID          (0x5F00002Cu)

#define CapSense_BUTTON1_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define CapSense_BUTTON1_PTR2SNS_FLASH_OFFSET               (48u)
#define CapSense_BUTTON1_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON1_PTR2SNS_FLASH_PARAM_ID             (0xDD010030u)

#define CapSense_BUTTON1_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define CapSense_BUTTON1_PTR2WD_RAM_OFFSET                  (52u)
#define CapSense_BUTTON1_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON1_PTR2WD_RAM_PARAM_ID                (0xDC010034u)

#define CapSense_BUTTON1_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[1].ptr2SnsRam)
#define CapSense_BUTTON1_PTR2SNS_RAM_OFFSET                 (56u)
#define CapSense_BUTTON1_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON1_PTR2SNS_RAM_PARAM_ID               (0xDF010038u)

#define CapSense_BUTTON1_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define CapSense_BUTTON1_PTR2FLTR_HISTORY_OFFSET            (60u)
#define CapSense_BUTTON1_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON1_PTR2FLTR_HISTORY_PARAM_ID          (0xDE01003Cu)

#define CapSense_BUTTON1_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define CapSense_BUTTON1_PTR2DEBOUNCE_OFFSET                (64u)
#define CapSense_BUTTON1_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON1_PTR2DEBOUNCE_PARAM_ID              (0xDF010040u)

#define CapSense_BUTTON1_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[1].staticConfig)
#define CapSense_BUTTON1_STATIC_CONFIG_OFFSET               (68u)
#define CapSense_BUTTON1_STATIC_CONFIG_SIZE                 (4u)
#define CapSense_BUTTON1_STATIC_CONFIG_PARAM_ID             (0xDE010044u)

#define CapSense_BUTTON1_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[1].totalNumSns)
#define CapSense_BUTTON1_TOTAL_NUM_SNS_OFFSET               (72u)
#define CapSense_BUTTON1_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON1_TOTAL_NUM_SNS_PARAM_ID             (0x92010048u)

#define CapSense_BUTTON1_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[1].wdgtType)
#define CapSense_BUTTON1_TYPE_OFFSET                        (74u)
#define CapSense_BUTTON1_TYPE_SIZE                          (1u)
#define CapSense_BUTTON1_TYPE_PARAM_ID                      (0x5601004Au)

#define CapSense_BUTTON1_SENSE_METHOD_VALUE                 (CapSense_dsFlash.wdgtArray[1].senseMethod)
#define CapSense_BUTTON1_SENSE_METHOD_OFFSET                (75u)
#define CapSense_BUTTON1_SENSE_METHOD_SIZE                  (1u)
#define CapSense_BUTTON1_SENSE_METHOD_PARAM_ID              (0x5001004Bu)

#define CapSense_BUTTON1_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[1].numCols)
#define CapSense_BUTTON1_NUM_COLS_OFFSET                    (76u)
#define CapSense_BUTTON1_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON1_NUM_COLS_PARAM_ID                  (0x5B01004Cu)

#define CapSense_BUTTON1_NUM_ROWS_VALUE                     (CapSense_dsFlash.wdgtArray[1].numRows)
#define CapSense_BUTTON1_NUM_ROWS_OFFSET                    (77u)
#define CapSense_BUTTON1_NUM_ROWS_SIZE                      (1u)
#define CapSense_BUTTON1_NUM_ROWS_PARAM_ID                  (0x5D01004Du)

#define CapSense_BUTTON1_X_RESOLUTION_VALUE                 (CapSense_dsFlash.wdgtArray[1].xResolution)
#define CapSense_BUTTON1_X_RESOLUTION_OFFSET                (78u)
#define CapSense_BUTTON1_X_RESOLUTION_SIZE                  (2u)
#define CapSense_BUTTON1_X_RESOLUTION_PARAM_ID              (0x9F01004Eu)

#define CapSense_BUTTON1_X_CENT_MULT_VALUE                  (CapSense_dsFlash.wdgtArray[1].xCentroidMultiplier)
#define CapSense_BUTTON1_X_CENT_MULT_OFFSET                 (80u)
#define CapSense_BUTTON1_X_CENT_MULT_SIZE                   (4u)
#define CapSense_BUTTON1_X_CENT_MULT_PARAM_ID               (0xDA010050u)

#define CapSense_BUTTON1_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[1].ptr2NoiseEnvlp)
#define CapSense_BUTTON1_PTR2NOISE_ENVLP_OFFSET             (84u)
#define CapSense_BUTTON1_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON1_PTR2NOISE_ENVLP_PARAM_ID           (0xDB010054u)

#define CapSense_BUTTON1_PTR2POS_HISTORY_VALUE              (CapSense_dsFlash.wdgtArray[1].ptr2PosHistory)
#define CapSense_BUTTON1_PTR2POS_HISTORY_OFFSET             (88u)
#define CapSense_BUTTON1_PTR2POS_HISTORY_SIZE               (4u)
#define CapSense_BUTTON1_PTR2POS_HISTORY_PARAM_ID           (0xD8010058u)

#define CapSense_BUTTON1_IIR_FILTER_COEFF_VALUE             (CapSense_dsFlash.wdgtArray[1].iirFilterCoeff)
#define CapSense_BUTTON1_IIR_FILTER_COEFF_OFFSET            (92u)
#define CapSense_BUTTON1_IIR_FILTER_COEFF_SIZE              (1u)
#define CapSense_BUTTON1_IIR_FILTER_COEFF_PARAM_ID          (0x5E01005Cu)

#define CapSense_LINEARSLIDER0_PTR2SNS_FLASH_VALUE          (CapSense_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define CapSense_LINEARSLIDER0_PTR2SNS_FLASH_OFFSET         (96u)
#define CapSense_LINEARSLIDER0_PTR2SNS_FLASH_SIZE           (4u)
#define CapSense_LINEARSLIDER0_PTR2SNS_FLASH_PARAM_ID       (0xD0020060u)

#define CapSense_LINEARSLIDER0_PTR2WD_RAM_VALUE             (CapSense_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define CapSense_LINEARSLIDER0_PTR2WD_RAM_OFFSET            (100u)
#define CapSense_LINEARSLIDER0_PTR2WD_RAM_SIZE              (4u)
#define CapSense_LINEARSLIDER0_PTR2WD_RAM_PARAM_ID          (0xD1020064u)

#define CapSense_LINEARSLIDER0_PTR2SNS_RAM_VALUE            (CapSense_dsFlash.wdgtArray[2].ptr2SnsRam)
#define CapSense_LINEARSLIDER0_PTR2SNS_RAM_OFFSET           (104u)
#define CapSense_LINEARSLIDER0_PTR2SNS_RAM_SIZE             (4u)
#define CapSense_LINEARSLIDER0_PTR2SNS_RAM_PARAM_ID         (0xD2020068u)

#define CapSense_LINEARSLIDER0_PTR2FLTR_HISTORY_VALUE       (CapSense_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define CapSense_LINEARSLIDER0_PTR2FLTR_HISTORY_OFFSET      (108u)
#define CapSense_LINEARSLIDER0_PTR2FLTR_HISTORY_SIZE        (4u)
#define CapSense_LINEARSLIDER0_PTR2FLTR_HISTORY_PARAM_ID    (0xD302006Cu)

#define CapSense_LINEARSLIDER0_PTR2DEBOUNCE_VALUE           (CapSense_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define CapSense_LINEARSLIDER0_PTR2DEBOUNCE_OFFSET          (112u)
#define CapSense_LINEARSLIDER0_PTR2DEBOUNCE_SIZE            (4u)
#define CapSense_LINEARSLIDER0_PTR2DEBOUNCE_PARAM_ID        (0xD5020070u)

#define CapSense_LINEARSLIDER0_STATIC_CONFIG_VALUE          (CapSense_dsFlash.wdgtArray[2].staticConfig)
#define CapSense_LINEARSLIDER0_STATIC_CONFIG_OFFSET         (116u)
#define CapSense_LINEARSLIDER0_STATIC_CONFIG_SIZE           (4u)
#define CapSense_LINEARSLIDER0_STATIC_CONFIG_PARAM_ID       (0xD4020074u)

#define CapSense_LINEARSLIDER0_TOTAL_NUM_SNS_VALUE          (CapSense_dsFlash.wdgtArray[2].totalNumSns)
#define CapSense_LINEARSLIDER0_TOTAL_NUM_SNS_OFFSET         (120u)
#define CapSense_LINEARSLIDER0_TOTAL_NUM_SNS_SIZE           (2u)
#define CapSense_LINEARSLIDER0_TOTAL_NUM_SNS_PARAM_ID       (0x98020078u)

#define CapSense_LINEARSLIDER0_TYPE_VALUE                   (CapSense_dsFlash.wdgtArray[2].wdgtType)
#define CapSense_LINEARSLIDER0_TYPE_OFFSET                  (122u)
#define CapSense_LINEARSLIDER0_TYPE_SIZE                    (1u)
#define CapSense_LINEARSLIDER0_TYPE_PARAM_ID                (0x5C02007Au)

#define CapSense_LINEARSLIDER0_SENSE_METHOD_VALUE           (CapSense_dsFlash.wdgtArray[2].senseMethod)
#define CapSense_LINEARSLIDER0_SENSE_METHOD_OFFSET          (123u)
#define CapSense_LINEARSLIDER0_SENSE_METHOD_SIZE            (1u)
#define CapSense_LINEARSLIDER0_SENSE_METHOD_PARAM_ID        (0x5A02007Bu)

#define CapSense_LINEARSLIDER0_NUM_COLS_VALUE               (CapSense_dsFlash.wdgtArray[2].numCols)
#define CapSense_LINEARSLIDER0_NUM_COLS_OFFSET              (124u)
#define CapSense_LINEARSLIDER0_NUM_COLS_SIZE                (1u)
#define CapSense_LINEARSLIDER0_NUM_COLS_PARAM_ID            (0x5102007Cu)

#define CapSense_LINEARSLIDER0_NUM_ROWS_VALUE               (CapSense_dsFlash.wdgtArray[2].numRows)
#define CapSense_LINEARSLIDER0_NUM_ROWS_OFFSET              (125u)
#define CapSense_LINEARSLIDER0_NUM_ROWS_SIZE                (1u)
#define CapSense_LINEARSLIDER0_NUM_ROWS_PARAM_ID            (0x5702007Du)

#define CapSense_LINEARSLIDER0_X_RESOLUTION_VALUE           (CapSense_dsFlash.wdgtArray[2].xResolution)
#define CapSense_LINEARSLIDER0_X_RESOLUTION_OFFSET          (126u)
#define CapSense_LINEARSLIDER0_X_RESOLUTION_SIZE            (2u)
#define CapSense_LINEARSLIDER0_X_RESOLUTION_PARAM_ID        (0x9502007Eu)

#define CapSense_LINEARSLIDER0_X_CENT_MULT_VALUE            (CapSense_dsFlash.wdgtArray[2].xCentroidMultiplier)
#define CapSense_LINEARSLIDER0_X_CENT_MULT_OFFSET           (128u)
#define CapSense_LINEARSLIDER0_X_CENT_MULT_SIZE             (4u)
#define CapSense_LINEARSLIDER0_X_CENT_MULT_PARAM_ID         (0xD4020080u)

#define CapSense_LINEARSLIDER0_PTR2NOISE_ENVLP_VALUE        (CapSense_dsFlash.wdgtArray[2].ptr2NoiseEnvlp)
#define CapSense_LINEARSLIDER0_PTR2NOISE_ENVLP_OFFSET       (132u)
#define CapSense_LINEARSLIDER0_PTR2NOISE_ENVLP_SIZE         (4u)
#define CapSense_LINEARSLIDER0_PTR2NOISE_ENVLP_PARAM_ID     (0xD5020084u)

#define CapSense_LINEARSLIDER0_PTR2POS_HISTORY_VALUE        (CapSense_dsFlash.wdgtArray[2].ptr2PosHistory)
#define CapSense_LINEARSLIDER0_PTR2POS_HISTORY_OFFSET       (136u)
#define CapSense_LINEARSLIDER0_PTR2POS_HISTORY_SIZE         (4u)
#define CapSense_LINEARSLIDER0_PTR2POS_HISTORY_PARAM_ID     (0xD6020088u)

#define CapSense_LINEARSLIDER0_IIR_FILTER_COEFF_VALUE       (CapSense_dsFlash.wdgtArray[2].iirFilterCoeff)
#define CapSense_LINEARSLIDER0_IIR_FILTER_COEFF_OFFSET      (140u)
#define CapSense_LINEARSLIDER0_IIR_FILTER_COEFF_SIZE        (1u)
#define CapSense_LINEARSLIDER0_IIR_FILTER_COEFF_PARAM_ID    (0x5002008Cu)


#endif /* End CY_SENSE_CapSense_REGISTER_MAP_H */


/* [] END OF FILE */
