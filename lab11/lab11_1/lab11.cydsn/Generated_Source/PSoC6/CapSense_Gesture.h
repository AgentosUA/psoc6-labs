/***************************************************************************//**
* \file CapSense_Gesture.h
* \version 2.0
*
* \brief
*   This file provides the function prototypes for the centroid calculation
*   methods.
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

#if !defined(CY_SENSE_GESTURE_CapSense_H)
#define CY_SENSE_GESTURE_CapSense_H

#include "CapSense_TMG.h"
#include "CapSense_Structure.h"


/*******************************************************************************
* Constant definitions
*******************************************************************************/
#define CapSense_SUPPORTED_FINGERS_NUM          (2uL)

#define CapSense_CLICK_EN                       (CapSense_TMG_CLICKS_ENABLED)
#define CapSense_ONE_FINGER_EDGE_SWIPE_EN       (CapSense_TMG_EDGE_SWIPE_ENABLED)
#define CapSense_ONE_FINGER_FLICK_EN            (CapSense_TMG_FLICKS_ENABLED)
#define CapSense_ONE_FINGER_ROTATE_EN           (CapSense_TMG_ROTATE_ENABLED)
#define CapSense_ONE_FINGER_SCROLL_EN           (CapSense_TMG_ST_SCROLLS_ENABLED)
#define CapSense_TWO_FINGER_SCROLL_EN           (CapSense_TMG_DT_SCROLLS_ENABLED)
#define CapSense_TWO_FINGER_ZOOM_EN             (CapSense_TMG_ZOOM_ENABLED)

#define CapSense_GESTURE_EN                     (CapSense_TMG_GESTURES_ENABLED)
    
/*******************************************************************************
* Types definition
*******************************************************************************/
typedef struct{
    int16 x;
    int16 y;
}CapSense_BALLISTIC_POS_TYPE;

typedef enum
{
    CapSense_TOUCH_VALID = 0x00u,
    CapSense_TOUCH_UNRECOGNIZED = 0x01u,
}CapSense_GESTURE_STATE_ENUM;

typedef struct{
    CapSense_TMG_POSITION_STRUCT currentPosition[CapSense_SUPPORTED_FINGERS_NUM];
    CapSense_GESTURE_STATE_ENUM touchState;
    uint8 touchNumber;
    uint8 maxTouchNumber;
} CapSense_TOUCH_PARAM_STRUCT;

/*******************************************************************************
* Function Prototypes - High-level API
*******************************************************************************/
/**
* \cond SECTION_CYSENSE_HIGH_LEVEL
* \addtogroup group_cysense_high_level
* \{
*/

#if (0u != CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
    uint32 CapSense_DecodeWidgetGestures(uint32 widgetId);
#endif

void CapSense_IncrementGestureTimestamp(void);
void CapSense_SetGestureTimestamp(uint32 timestampValue);

/** \}
* \endcond */

/*******************************************************************************
* Function Prototypes - Internal Functions
*******************************************************************************/
/**
* \cond SECTION_CYSENSE_INTERNAL
* \addtogroup group_cysense_internal
* \{
*/

#if (0u != CapSense_ENABLE == CapSense_GES_GLOBAL_EN)
    void  CapSense_GetTouchParams(uint32 wdgtIndex, CapSense_TOUCH_PARAM_STRUCT *touchParams);
#endif

void CapSense_InitializeGestures(void);
void CapSense_InitializeBallisticMultiplier(void);
void CapSense_RunBallisticMultiplier(uint32 wdgtIndex);

/** \}
* \endcond */


/*******************************************************************************
* Definitions
*******************************************************************************/
#define CapSense_FIRST_FINGER_ID                        (0uL)
#define CapSense_SECOND_FINGER_ID                       (1uL)
#define CapSense_X_COORDINATE_INDEX                     (0uL)
#define CapSense_Y_COORDINATE_INDEX                     (1uL)
#define CapSense_BALLISTIC_DIMENSIONS_NUM               (2uL)

/* Centroid Errors */
#define CapSense_POSITION_ERROR                         (0xFFFFFFFFu)
#define CapSense_FINGER_ERROR                           (0xFFu)

#define CapSense_GESTURE_GROUP_MASK                     (0xF0u)

/* Code for no gesture detected case */
#define CapSense_NO_GESTURE                             (CapSense_TMG_NO_GESTURE)
#define CapSense_NON_VALID_PARAMETER                    (0xFFu)
#define CapSense_UNRECOGNIZED_GESTURE                   (0xFEu)

/* TouchDown and Lift Off Gestures */
#define CapSense_ONE_FINGER_TOUCHDOWN                   (CapSense_TMG_TOUCHDOWN)
#define CapSense_ONE_FINGER_LIFT_OFF                    (CapSense_TMG_LIFT_OFF)

/* Single touch click gestures */
#define CapSense_ONE_FINGER_SINGLE_CLICK                (CapSense_TMG_ST_CLICK)
#define CapSense_ONE_FINGER_DOUBLE_CLICK                (CapSense_TMG_ST_DOUBLECLICK)
#define CapSense_ONE_FINGER_CLICK_AND_DRAG              (CapSense_TMG_CLICK_AND_DRAG)

/* Rotate gestures */
#define CapSense_ONE_FINGER_ROTATE_CW                   (CapSense_TMG_ROTATE_CW)
#define CapSense_ONE_FINGER_ROTATE_CCW                  (CapSense_TMG_ROTATE_CCW)

/* Scroll gestures */
#define CapSense_ONE_FINGER_SCROLL_INERTIAL_UP          (CapSense_TMG_INERTIAL_ST_SCROLL_VERTICAL_UP)
#define CapSense_ONE_FINGER_SCROLL_INERTIAL_DOWN        (CapSense_TMG_INERTIAL_ST_SCROLL_VERTICAL_DOWN)
#define CapSense_ONE_FINGER_SCROLL_INERTIAL_LEFT        (CapSense_TMG_INERTIAL_ST_SCROLL_HORIZONTAL_LEFT)
#define CapSense_ONE_FINGER_SCROLL_INERTIAL_RIGHT       (CapSense_TMG_INERTIAL_ST_SCROLL_HORIZONTAL_RIGHT)

#define CapSense_TWO_FINGER_SCROLL_INERTIAL_UP          (CapSense_TMG_INERTIAL_DT_SCROLL_VERTICAL_UP)
#define CapSense_TWO_FINGER_SCROLL_INERTIAL_DOWN        (CapSense_TMG_INERTIAL_DT_SCROLL_VERTICAL_DOWN)
#define CapSense_TWO_FINGER_SCROLL_INERTIAL_LEFT        (CapSense_TMG_INERTIAL_DT_SCROLL_HORIZONTAL_LEFT)
#define CapSense_TWO_FINGER_SCROLL_INERTIAL_RIGHT       (CapSense_TMG_INERTIAL_DT_SCROLL_HORIZONTAL_RIGHT)

#define CapSense_ONE_FINGER_SCROLL_UP                   (CapSense_TMG_ST_SCROLL_VERTICAL_UP)
#define CapSense_ONE_FINGER_SCROLL_DOWN                 (CapSense_TMG_ST_SCROLL_VERTICAL_DOWN)
#define CapSense_ONE_FINGER_SCROLL_LEFT                 (CapSense_TMG_ST_SCROLL_HORIZONTAL_LEFT)
#define CapSense_ONE_FINGER_SCROLL_RIGHT                (CapSense_TMG_ST_SCROLL_HORIZONTAL_RIGHT)

#define CapSense_TWO_FINGER_SCROLL_UP                   (CapSense_TMG_DT_SCROLL_VERTICAL_UP)
#define CapSense_TWO_FINGER_SCROLL_DOWN                 (CapSense_TMG_DT_SCROLL_VERTICAL_DOWN)
#define CapSense_TWO_FINGER_SCROLL_LEFT                 (CapSense_TMG_DT_SCROLL_HORIZONTAL_LEFT)
#define CapSense_TWO_FINGER_SCROLL_RIGHT                (CapSense_TMG_DT_SCROLL_HORIZONTAL_RIGHT)

/* Dual touch click gesture */
#define CapSense_TWO_FINGER_SINGLE_CLICK                (CapSense_TMG_DT_CLICK)

/* Zoom Gestures */
#define CapSense_TWO_FINGER_ZOOM_IN                     (CapSense_TMG_ZOOM_IN)
#define CapSense_TWO_FINGER_ZOOM_OUT                    (CapSense_TMG_ZOOM_OUT)

/* Flick gestures */
#define CapSense_ONE_FINGER_FLICK_UP                    (CapSense_TMG_FLICK_NORTH)
#define CapSense_ONE_FINGER_FLICK_UP_RIGHT              (CapSense_TMG_FLICK_NORTH_EAST)
#define CapSense_ONE_FINGER_FLICK_RIGHT                 (CapSense_TMG_FLICK_EAST)
#define CapSense_ONE_FINGER_FLICK_DOWN_RIGHT            (CapSense_TMG_FLICK_SOUTH_EAST)
#define CapSense_ONE_FINGER_FLICK_DOWN                  (CapSense_TMG_FLICK_SOUTH)
#define CapSense_ONE_FINGER_FLICK_DOWN_LEFT             (CapSense_TMG_FLICK_SOUTH_WEST)
#define CapSense_ONE_FINGER_FLICK_LEFT                  (CapSense_TMG_FLICK_WEST)
#define CapSense_ONE_FINGER_FLICK_UP_LEFT               (CapSense_TMG_FLICK_NORTH_WEST)

/* Edge swipe gestures */
#define CapSense_ONE_FINGER_EDGE_SWIPE_UP               (CapSense_TMG_EDGE_SWIPE_TOP)
#define CapSense_ONE_FINGER_EDGE_SWIPE_DOWN             (CapSense_TMG_EDGE_SWIPE_BOTTOM)
#define CapSense_ONE_FINGER_EDGE_SWIPE_LEFT             (CapSense_TMG_EDGE_SWIPE_LEFT)
#define CapSense_ONE_FINGER_EDGE_SWIPE_RIGTH            (CapSense_TMG_EDGE_SWIPE_RIGHT)
#define CapSense_ONE_FINGER_EDGE_SWIPE_GROUP            (CapSense_TMG_EDGE_SWIPE_LEFT &\
                                                                 CapSense_TMG_EDGE_SWIPE_RIGHT &\
                                                                 CapSense_TMG_EDGE_SWIPE_TOP &\
                                                                 CapSense_TMG_EDGE_SWIPE_BOTTOM)
#define CapSense_ONE_FINGER_EDGE_SWIPE_GESTURE          (CapSense_TMG_EDGE_SWIPE_LEFT |\
                                                                 CapSense_TMG_EDGE_SWIPE_RIGHT |\
                                                                 CapSense_TMG_EDGE_SWIPE_TOP |\
                                                                 CapSense_TMG_EDGE_SWIPE_BOTTOM)

#define CapSense_ONE_FINGER_EDGE_SWIPE_COMPLETE_TIMEOUT (CapSense_TMG_EDGE_SWIPE_COMPLETE_TIMEOUT)

/* Invalid coordinates */
#define CapSense_INVALID_COORDINATE                     (CapSense_TMG_INVALID_COORDINATE)


#endif /* CY_SENSE_GESTURE_CapSense_H */


/* [] END OF FILE */
